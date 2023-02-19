#include "WuZiQi.h"
#pragma comment(lib,"Winmm.lib")

IMAGE chessBlackImg;
IMAGE chessWhiteImg;
IMAGE GameOver;

ChessData Game;
int clickPoint_Y, clickPoint_X;
int num;

bool CheckOver(int GameMode){
    int ID;
    if(Game.Player_Flag==1){
        ID=-1;}
    else ID=1;
    Point p;

    if (GameMode==PVP_){
        p.x= clickPoint_X, p.y = clickPoint_Y;
    }

    if (GameMode==PVE_1){//1是玩家
        if (ID==1)
            p.x= clickPoint_X, p.y = clickPoint_Y;
        else
            p.x=AI_x,p.y=AI_y;
    }

    if (GameMode==PVE_2){//1是电脑
        if (ID==-1)
            p.x= clickPoint_X, p.y = clickPoint_Y;
        else
            p.x=AI_x,p.y=AI_y;
    }
    
        switch (1) {//横的方向
            case 1: {
                Point Tem_p;
                Tem_p.x=p.x;
                Tem_p.y=p.y;

                int flag = 1,Round=0;//判断方向

                for (int i = 1; i <= 4; i++) {
                    if (flag == 1) { Tem_p.x -= 1; }
                    else { Tem_p.x += 1; }

                    if (Game.Chess_Map[Tem_p.x][Tem_p.y] == ID && Is_inBoard(p)) {
                        Round+=1;
                        continue;
                    }
                    else {
                        if (flag==-1){
                            break;
                        }
                        flag=-1;
                        Tem_p.x += (i + 1);
                        if (Game.Chess_Map[Tem_p.x][Tem_p.y] == ID) {
                            Round+=1;
                            continue;
                            }
                        else {
                            break;
                        }
                    }

                }
                if(Round==4){return true;}
            }

            case 2:{//竖的方向
                Point Tem_p;
                Tem_p.x=p.x;
                Tem_p.y=p.y;

                int flag = 1,Round=0;
                for (int i = 1; i <= 4; i++) {
                    if (flag == 1) { Tem_p.y -= 1; }
                    else { Tem_p.y += 1; }

                    if (Game.Chess_Map[Tem_p.x][Tem_p.y] == ID) {
                        Round+=1;
                        continue;
                    }
                    else {
                        if (flag==-1){
                            break;
                        }
                        flag=-1;
                        Tem_p.y += (i + 1);
                        if (Game.Chess_Map[Tem_p.x][Tem_p.y] == ID) {
                            Round+=1;
                            continue;
                        }
                        else {
                            break;
                        }
                    }

                }
                if(Round==4){return true;}
            }
            case 3:{//左下到右上
                Point Tem_p;
                Tem_p.x=p.x;
                Tem_p.y=p.y;

                int flag = 1,Round=0;
                for (int i = 1; i <= 4; i++) {
                    if (flag == 1) { Tem_p.y += 1;Tem_p.x -= 1; }
                    else { Tem_p.y -=1;Tem_p.x += 1; }

                    if (Game.Chess_Map[Tem_p.x][Tem_p.y] == ID) {
                        Round+=1;
                        continue;
                    }
                    else {
                        if (flag==-1){
                            break;
                        }
                        flag=-1;
                        Tem_p.y -= (i + 1); Tem_p.x += (i + 1);
                        if (Game.Chess_Map[Tem_p.x][Tem_p.y] == ID) {
                            Round+=1;
                            continue;
                        }
                        else {
                            break;
                        }
                    }

                }
                if(Round==4){return true;}
            }
            case 4:{//左上到右下
                Point Tem_p;
                Tem_p.x=p.x;
                Tem_p.y=p.y;

                int flag = 1,Round=0;
                for (int i = 1; i <= 4; i++) {
                    if (flag == 1) { Tem_p.y -= 1;Tem_p.x -= 1; }
                    else { Tem_p.y +=1;Tem_p.x += 1; }

                    if (Game.Chess_Map[Tem_p.x][Tem_p.y] == ID) {
                        Round+=1;
                        continue;
                    }
                    else {
                        if (flag==-1){
                            break;
                        }
                        flag=-1;
                        Tem_p.y += (i + 1); Tem_p.x += (i + 1);
                        if (Game.Chess_Map[Tem_p.x][Tem_p.y] == ID) {
                            Round+=1;
                            continue;
                        }
                        else {
                            break;
                        }
                    }

                }
                if(Round==4){return true;}
            }
        } return false;
}

void init(){


    IMAGE background;//定义一个图片名.
    initgraph(rW,rH);
    loadimage(&background,"Source\\BackG.png",rH,rH,0);//加载背景
    putimage(rW/2-rH/2, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)

    mciSendString("open Source\\StartGame.mp3 alias StartGame", NULL, 0, NULL);// 播放音乐
    mciSendString("play StartGame wait", NULL, 0, NULL);
    mciSendString("close StartGame", NULL, 0, NULL);

    loadimage(&chessBlackImg,"Source\\Black.png",BlockSize,BlockSize,1);//加载黑白子
    loadimage(&chessWhiteImg,"Source\\White.png",BlockSize,BlockSize,1);

    initChess_Data(&Game); //重置数据
}

//落子函数
void chess_Down(int col, int row,chess_kind_j kind){

    num++;

    int x = margin_X + col*BlockSize;
    int y = margin_Y + row*BlockSize;

    if (kind == 1){
        drawAlpha(&chessWhiteImg,x,y);
    }
    else{
        drawAlpha(&chessBlackImg,x,y);
    }
//    mciSendString("open Source\\DownChess.mp3 alias DownChess", NULL, 0, NULL);
//    mciSendString("play DownChess wait", NULL, 0, NULL);
//    mciSendString("close DownChess", NULL, 0, NULL);
}

//模拟落子函数
void mock_chess_Down(struct Point p,int player){
    Game.Chess_Map[p.x][p.y]=player;
    num++;
}

//取消模拟落子
void unmock_chess_Down(struct Point p){
    Game.Chess_Map[p.x][p.y]=0;
    num--;
}


bool Judge_Player_Down(MOUSEMSG msg) { //返回落点坐标

    int x = msg.x, y = msg.y;//获取鼠标位置
    int select_Point = false;

    if (x<margin_X || y<margin_Y){  //避免超出棋盘大小
        return select_Point;
    }
    int col = (x - margin_X) / BlockSize;//计算第第几列
    int row = (y - margin_Y) / BlockSize;

    if (col<0||col>Broad_SizeNum-1||row<0||row>Broad_SizeNum-1){ //避免超出棋盘大小
        return select_Point;
    }
    clickPoint_X = col;
    clickPoint_Y = row;
    if (Game.Chess_Map[clickPoint_X][clickPoint_Y] == 0) {
        select_Point = true;
    }

    return select_Point;
}

//极大极小值搜索 下子 更新数据
void AI_go(){

    minmaxSearch(DEPTH, LONG_LONG_MIN+1, LONG_LONG_MAX, Game.Player_Flag);


    if (Game.Player_Flag==-1) {
        chess_Down(AI_x, AI_y, Chess_Black);
    }
    else {
        chess_Down(AI_x, AI_y, Chess_White);
    }
    update_ChessDate(&Game,AI_x ,AI_y);
}

//落棋
void Player_go(MOUSEMSG msg){

    if (Game.Player_Flag==1){
        chess_Down(clickPoint_X, clickPoint_Y,Chess_White);
    }
    else{
        chess_Down(clickPoint_X, clickPoint_Y,Chess_Black);
    }
    update_ChessDate(&Game, clickPoint_X, clickPoint_Y);
}

void EndGame()
{
    if(Game.Player_Flag==1){
        loadimage(&GameOver,"Source\\HeiZiHuoSheng.png");
    }
    else{
        loadimage(&GameOver,"Source\\BaiZiHuoSheng.png");
    }
    drawAlpha(&GameOver,rW/2-355,rH/2-105);
    _getch();
    closegraph();
}

//UI测试棋子大小用
void test(){
    int N=18;

    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++){chess_Down(i,j,Chess_Black);}
    chess_Down(0,0,Chess_Black);
    _getch();
}

//判断P 点有没有越界 越界返回0
int Is_inBoard(struct Point p){
    if(p.x>=0 && p.x<=Broad_SizeNum && p.y>=0 && p.y<=Broad_SizeNum)//已修改
        return 1;
    else
        return 0;
}


