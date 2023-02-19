#include "WuZiQi.h"
int AI_x,AI_y;//AI的最终落点

//初始化地图
void initChess_Data(ChessData *data){
    if(!data)return;

    memset(data,0, sizeof(data->Chess_Map));
    memset(data,0, sizeof(data->Score_Map));

data->Player_Flag = 1;// 决定黑白棋子的先手 1是白棋，-1是黑棋
num=0;
}

//持续更新 棋盘的黑白数据 以及换手
void update_ChessDate(ChessData *data, int col, int row){//
    if (data->Player_Flag==1){
        data->Chess_Map[col][row]=1;
    }
    else {
        data->Chess_Map[col][row]=-1;
    }
    data->Player_Flag=-(data->Player_Flag);
}

//判断落子点，周围有没有棋子 省效率
int Judge_has_Neighbor(Point p){
    for(int i=0;i<4;i++){//找棋盘上有落子点2个距离内 5*5的范围
        for(int j=-2;j<=2;j++){//左右距离2
            if(j!=0){
                Point np=nextPoint(p,i,j);
                if(Is_inBoard(np) && Game.Chess_Map[np.x][np.y]!=0)
                    return 1;
            }
        }
    }
return 0;//没有邻居
}

//启发式搜索  传回空点的数目 指针Move传分数和 x,y点 //player 传的是flag 即 1先手 2后手
int inspireFind(point_Data *scoreBoard,int player) {
    int length = 0;//空点的数量

    for (int i = 0; i < Broad_SizeNum; i++) {
        for (int j = 0; j < Broad_SizeNum; j++) {
            if (Game.Chess_Map[i][j] == 0) {//只看棋盘上的空位
                Point p = {i, j};//干 cul 和 row 才是指的 x 和 y

                if ((Judge_has_Neighbor(p) && !forbidden_Hand(p, player))) {//判断该点周围有棋子 以及该点不是禁手点
                    scoreBoard[length].score = count_singleScore(p, player);//我方适合进攻的点
                    if (!forbidden_Hand(p, -player)) {
                        scoreBoard[length].score += count_singleScore(p, -player);//对方需要防守的点
                    }
                    scoreBoard[length++].p = p;
                }
            }
        }
    }
    shellSort(scoreBoard,length);//希尔排序 增加剪枝效率
    return length;
}

LL minmaxSearch(int depth,LL alpha,LL beta,int player) {

    point_Data moves[323];//18^2 -1
    int length=inspireFind(moves,player);//启发式搜索可落子点

    if(length>WIDTH){
        length=WIDTH;//设置搜索广度
    }

    for (int i = 0; i < length; i++) {//对该广度进行搜索
        mock_chess_Down(moves[i].p, player);//模拟落子
        LL temp = -alphaBeta(depth - 1, -beta, -alpha,-player,moves[i].p);//开始递归
        unmock_chess_Down(moves[i].p);//取消模拟落子
        if (temp >= beta) {
            return beta;//剪枝
        }
        if (temp > alpha) {
            alpha = temp;
            AI_x = moves[i].p.x;//记录zui好的落子点位
            AI_y = moves[i].p.y;
        }
    }
    return alpha;
}

LL alphaBeta(int depth,LL alpha,LL beta,int player,Point p) {
    if (JudgeFive(p,player))//有连5直接返回分数
        return count_wholeScore(player);//返回当前局面分
    if (depth == 0 || num==Broad_SizeNum*Broad_SizeNum) {//到达最低层
        return count_wholeScore(player);
    }


    point_Data moves[323];
    int length=inspireFind(moves,player);

    if(length>WIDTH){//设置搜索广度
        length=WIDTH;
    }

    for (int i = 0; i < length; i++) {
        mock_chess_Down(moves[i].p, player);//模拟落子
        LL temp = -alphaBeta(depth - 1, -beta, -alpha,-player,moves[i].p);
        unmock_chess_Down(moves[i].p);//还原落子
        if (temp >= beta) {
            return beta;//剪枝
        }
        if (temp > alpha) {
            alpha = temp;
        }
    }
    return alpha;
}

int JudgeFive(Point p,int player){
    int i;
    int count=1;
    for (int d=0; d<4;d++) {
        for (i = 1;; i++) {//左边判断 直到边界或者 对方的棋子 返回count
            Point np = nextPoint(p, d, -i);
            if (Is_inBoard(np) && player == Game.Chess_Map[np.x][np.y])
                count++;
            else {
                break;
            }
        }
        for (i = 1;; i++) {//右边判断
            Point np = nextPoint(p, d, i);
            if (Is_inBoard(np) && player == Game.Chess_Map[np.x][np.y])
                count++;
            else {
                break;
            }
        }
        if(count>=5) {
            return 1; }
    }
    return 0;
}
//棋盘整体局面分
LL count_wholeScore(int player){
    LL AIScore=0,humScore=0;
    for(int i=0;i<Broad_SizeNum;i++){
        for(int j=0;j<Broad_SizeNum;j++) {
            struct Point p={i,j};
            if(Game.Chess_Map[i][j]==player)//己方落子的单点分相加
                AIScore += count_singleScore(p,player);
            else if(Game.Chess_Map[i][j]==-player)//对方落子的单点分相加
                humScore += count_singleScore(p,-player);
        }
    }
    return AIScore-humScore;//己方总分减对方总分 得到当前对己方来说的局势分
}

//希尔排序  从大到小
void shellSort(point_Data *point,int len){
    int i,j,gap; //len 空点的数量 //gap 增量
    point_Data temp;
    for (gap=(len>>1);gap>0;gap>>=1){//位运算
        for(i=gap;i<len;i++){
            for(j=i-gap;j>=0&&point[j].score<point[j+gap].score;j-=gap){
                temp=point[i];
                point[j+gap]=point[j];
                point[j]=temp;
            }
        }
    }
//        for(int c=0;c<len;c++){ //测试排序效果
//        printf("%d x:%d y:%d\n",point[c].score,point[c].p.x,point[c].p.y);
//        fflush(stdout);
//    }
//    printf("\n");
}