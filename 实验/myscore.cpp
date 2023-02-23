#include "WuZiQi.h"

//获取p点4个方向中延申的棋子信息  //d 用1234表示
void extend_info(struct Point p,int d,int way,int player,int *side){
    for (int i = 0; i < 4; i++)//i控制距离 w控制方向
    {
        struct Point np = nextPoint(p, d, way*i);
        if (Is_inBoard(np))//在棋盘内
            side[i] = Game.Chess_Map[np.x][np.y];//数据 1或0或-1
        else //遇到边界 视为对方子
            side[i] = -player;
    }
}

//获取p点连子的长度和 p 点 两边延伸4子的信息//就是说4个方向里 其中一条直线称作连子
int get_ChessLength(Point p,int d,int *left,int *right,int player)
{
    int i;
    int count=1;
    for(i=1; ;i++){//左边判断 直到边界或者 对方的棋子 返回count
        Point np = nextPoint(p,d,-i);
        if( Is_inBoard(np) && player == Game.Chess_Map[np.x][np.y])
            count++;
        else{
            extend_info(np,d,-1,player,left);
            break;
        }
    }
    for(i=1; ;i++){//右边判断
        Point np = nextPoint(p,d,i);
        if( Is_inBoard(np) && player == Game.Chess_Map[np.x][np.y])
            count++;
        else{
            extend_info(np,d,-1,player,right);
            break;
        }
    }
    return count;
}

//获取p点周围的棋型
Info get_ChessInfo(struct Point p,int player){
    Info temp = {0};
    for(int i=0;i<4;i++){
        Info info[4];
        int length;
        int left[4],right[4]; //要获取 p 点一条直线上的 8个位置

        length=get_ChessLength(p,i,left,right,player);
        info[i] = type_Analysis(length, left, right, player);

        temp.more += info[i].more;
        temp.win5 += info[i].win5;
        temp.alive4 += info[i].alive4;
        temp.dalive4 += info[i].dalive4;
        temp.dead4 += info[i].dead4;
        temp.alive3 += info[i].alive3;
        temp.dalive3 += info[i].dalive3;
        temp.dead3 += info[i].dead3;
        temp.alive2 += info[i].alive2;
        temp.dalive2 += info[i].dalive2;
        temp.dead2 += info[i].dead2;
        temp.alive1 += info[i].alive1;
        temp.dalive1 += info[i].dalive1;
        temp.dead1 += info[i].dead1;
    }
    return temp;
}

//返回p点d方向上相邻di距离的点 d为0，1，2，3 p为Point型坐标
struct Point nextPoint(struct Point p,int d,int distence){
    const int direction[4][2]={{1,0},{0,1},{1,1},{1,-1}};
    struct Point np;//np 的x y 点
    np.x = p.x + distence*direction[d][0];
    np.y = p.y + distence*direction[d][1];
    return np;
}

//计算单方面的分数总和
int count_singleScore(struct Point p,int player) {
    int score = 0;
    Info info = get_ChessInfo(p, player);//获取该点周围棋形

    //必胜条件
    if (info.more >= 1 || info.win5 >= 1){
        score += 20000000;
        }
    if (info.alive4 >= 1 || info.dalive4 >= 2 || info.alive3 >= 2 || (info.dalive4 >= 1 && info.alive3 >= 1)) {
        score += 1000000;
    }
        score += (info.alive4 * 100000 + info.dalive4 * 5000 + info.dead4 * 500
                  + info.alive3 * 10000 + info.dalive3 * 1000 + info.dead3 * 50
                  + info.alive2 * 1000 + info.dalive2 * 100 + info.dead2 * 5
                  + info.alive1 * 100 + info.dalive1 * 10 + info.dead1 * 1);
        return score;

}

int forbidden_Hand(Point p,int player){
    if(player==1){
        Info info= get_ChessInfo(p,player);
        if(info.more>0){//长连禁手
            return 1;
        }
        if(info.win5==0 && (info.alive3>=2 || info.alive4+info.dalive4>=2)) {//三三 四四及组合禁手
            return 1;
        }
    }
    return 0;
}

//根据连子数目和边缘信息判断棋型
Info type_Analysis(int length,int *left, int *right,int player)
{
    Info temp={0};
    if(length >5)
        temp.more++;
    else if (length == 5)//敲！ Length初始==1 所以每多测一次加1 刚好等于5
        temp.win5++;
    else if (length == 4)
    {
        if (left[0] == 0 && right[0] == 0)
            temp.alive4++;
        else if (left[0] == 0 || right[0] == 0)
            temp.dalive4++;
        else
            temp.dead4++;
    }
    else if (length == 3)
    {
        //  @ @@@ @  型
        if ((left[0] == 0 && left[1] == player) && (right[0] == 0 && right[1] == player))
            temp.dalive4+=2;
            //  @ @@@  型   或   @@@ @  型
        else if((left[0] == 0 && left[1] == player) || (right[0] == 0 && right[1] == player))
            temp.dalive4++;
        else if (left[0] == 0 && right[0] == 0 && (left[1] == 0 || right[1] == 0))
            temp.alive3++;
        else if ((left[0] == 0 && left[1] == 0) || (right[0] == 0 && right[1] == 0))
            temp.dalive3++;
        else
            temp.dead3++;
    }
    else if (length == 2)
    {
        // ’@@ @@ @@’
        if ((left[0] == 0 && left[1] == player && left[2] == player) &&
            (right[0] == 0 && right[1] == player && right[2] == player))
            temp.dalive4+=2;
        // ’@@ @@’
        else if ((left[0] == 0 && left[1] == player && left[2] == player) ||
                 (right[0] == 0 && right[1] == player && right[2] == player))
            temp.dalive4++;
        // ‘ @ @@ ’
        else if (left[0] == 0 && right[0] == 0 &&
                 ((left[1] == player && left[2] == 0 ) ||
                  (right[1] == player && right[2] == 0 )))
            temp.alive3++;
            //'#@ @@ '
        else if ((left[0] == 0 && left[2] == 0 && left[1] == player) ||
                 (right[0] == 0 && right[2] == 0 && right[1] == player))
            temp.dalive3++;
            //' @ @@#'
        else if ((left[0] == 0 && right[0] == 0) &&
                 (left[1] == player || right[1] == player))
            temp.dalive3++;
        else if ((left[0] == 0 && left[1] == 0 && left[2] == player) ||
                 (right[0] == 0 && right[1] == 0 && right[2] == player))
            temp.dalive3++;
        else if ((left[0] == 0 && right[0] == 0 && right[1] == 0 && right[2] == 0) ||
                 (left[0] == 0 && left[1] == 0 && right[0] == 0 && right[1] == 0) ||
                 (left[0] == 0 && left[1] == 0 && left[2] == 0 && right[0] == 0))
            temp.alive2++;
        else if ((left[0] == 0 && left[1] == 0 && left[2] == 0) ||
                 (right[0] == 0 && right[1] == 0 && right[2] == 0))
            temp.dalive2++;
    }
    else if (length == 1) {
            //'@@@ @ @@@'
        if ((left[0] == 0 && left[1] == player && left[2] == player && left[3] == player) &&
            (right[0] == 0 && right[1] == player && right[2] == player && right[3] == player))
            temp.dalive4+=2;
            //'@@@ @'
        else if ((left[0] == 0 && left[1] == player && left[2] == player && left[3] == player) ||
                 (right[0] == 0 && right[1] == player && right[2] == player && right[3] == player))
            temp.dalive4++;
        else if ((left[0] == 0 && right[0] == 0) && ((left[1] == player && left[2] == player && left[3] == 0) ||
                                                     (right[1] == player && right[2] == player && right[3] == 0)))
            temp.alive3++;
        else if ((left[0] == 0 && right[0] == 0) &&
                 ((left[1] == player && left[2] == player) || (right[1] == player && right[2] == player)))
            temp.dalive3++;
        else if ((left[0] == 0 && left[3] == 0 && left[1] == player && left[2] == player) ||
                 (right[0] == 0 && right[3] == 0 && right[1] == player && right[2] == player))
            temp.dalive3++;
        else if ((left[0] == 0 && left[1] == 0 && left[2] == player && left[3] == player) ||
                 (right[0] == 0 && right[1] == 0 && right[2] == player && right[3] == player))
            temp.dalive3++;
        else if ((left[0] == 0 && left[2] == 0 && left[1] == player && left[3] == player) ||
                 (right[0] == 0 && right[2] == 0 && right[1] == player && right[3] == player))
            temp.dalive3++;
        else if ((left[0] == 0 && right[0] == 0 && right[2] == 0 && right[1] == player)
                 && (left[1] == 0 || right[3] == 0))
            temp.alive2++;
        else if ((right[0] == 0 && left[0] == 0 && left[2] == 0 && left[1] == player) &&
                 (right[1] == 0 || left[3] == 0))
            temp.alive2++;
        else if ((left[0] == 0 && right[0] == 0 && right[1] == 0 && right[3] == 0 && right[2] == player) ||
                 (right[0] == 0 && left[0] == 0 && left[1] == 0 && left[3] == 0 && left[2] == player))
            temp.alive2++;
        else if ((left[0] == 0 && left[2] == 0 && left[3] == 0 && left[1] == player) ||
                 (right[0] == 0 && right[2] == 0 && right[3] == 0 && right[1] == player))
            temp.dalive2++;
        else if ((left[0] == 0 && right[0] == 0 && right[1] == 0 && left[1] == player) ||
                 (right[0] == 0 && left[0] == 0 && left[1] == 0 && right[1] == player))
            temp.dalive2++;
        else if ((left[0] == 0 && left[1] == 0 && left[3] == 0 && left[2] == player) ||
                 (right[0] == 0 && right[1] == 0 && right[3] == 0 && right[2] == player))
            temp.dalive2++;
        else if ((left[0] == 0 && left[1] == 0 && right[0] == 0 && left[2] == player) ||
                 (right[0] == 0 && right[1] == 0 && left[0] == 0 && right[2] == player))
            temp.dalive2++;
        else if ((left[0] == 0 && left[1] == 0 && left[2] == 0 && left[3] == player) ||
                 (right[0] == 0 && right[1] == 0 && right[2] == 0 && right[3] == player))
            temp.dalive2++;
        else if (left[0] == 0 && right[0] == 0)
            temp.alive1++;
        else if (left[0] == 0 || right[0] == 0)
            temp.dalive1++;
        else
            temp.dead1++;
    }
    return temp;
}