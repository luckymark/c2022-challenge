#include <graphics.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>

#define width 20
#define length 20

typedef struct Road{
    struct Road* father;
}Road;

Road* road[width][length]; // road[0][1]-start road[10][9]-end

void creat(int vWall[width][length+1],int hWall[width+1][length]);
Road* find(Road* road);
void join(Road* road1,Road* road2);
void paint(int vWall[width][length+1],int hWall[width+1][length],int i,int j);

int main(){
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < length; ++j) {
            road[i][j] = (Road*)malloc(sizeof(Road));
            road[i][j]->father = nullptr;
        }
    }
    int i = 0,j = 0;
    int vWall[width][length+1] = {0}; // o-exist 1
    int hWall[width+1][length] = {0};
    srand(time(nullptr));
    vWall[0][0] = 1;
    hWall[width][length-2] = 1;
    creat(vWall,hWall);

    initgraph(720, 720);
    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLACK);
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID,1);
    paint(vWall,hWall,i,j);
    while(true){

        int a = getch();
        switch (a) { // i行 j列
            case 75: // left
                if ((j-1) >= 0 && vWall[i][j] == 1) --j;
                break;
            case 72: // up
                if ((i-1) >= 0 && hWall[i][j] == 1) --i;
                break;
            case 77: // right
                if ((j+1) <= length && vWall[i][j+1] == 1) ++j;
                break;
            case 80: // down
                if ((i+1) <= width && hWall[i+1][j] == 1) ++i;
                break;
            default:
                break;
        }
        cleardevice();
        paint(vWall,hWall,i,j);
        if (i == width && j == length-2) break;
    }
    getch();
    closegraph();
    return 0;
}

void creat(int vWall[width][length+1],int hWall[width+1][length]){
    while(true){
        if(rand()%2 == 0){ // vWall
            int w = rand()%width;
            int l = rand()%(length-1)+1; // randomly choose a v-wall
            if(find(road[w][l-1])== find(road[w][l])) continue; //check if connected
            vWall[w][l] = 1;
            join(road[w][l-1],road[w][l]);
        }else{ // hWall
            int w = rand()%(width-1)+1;
            int l = rand()%length; // randomly choose a h-wall
            if(find(road[w][l]) == find(road[w-1][l])) continue;
            hWall[w][l] = 1;
            join(road[w-1][l],road[w][l]);
        }
        if(find(road[0][0]) == find(road[width-1][length-2])){
            return;
        }
    }
}

Road* find(Road* road1){
    if(road1->father == nullptr) return road1;
    if(road1->father->father == nullptr) return road1->father;
    road1->father = road1->father->father;
    return find(road1);
}

void join(Road* road1,Road* road2){
    find(road1)->father = find(road2);
}

void paint(int vWall[width][length+1],int hWall[width+1][length],int i,int j){
    for (int k = 0; k < width; ++k) {
        for (int h = 0; h < length+1; ++h) {
            if (vWall[k][h] == 0) line(50+h*30,50+k*30,50+h*30,80+k*30);
        }
    }
    for (int k = 0; k < width+1; ++k) {
        for (int h = 0; h < length; ++h) {
            if (hWall[k][h] == 0) line(50+h*30,50+k*30,80+h*30,50+k*30);
        }
    }
    circle(65+j*30,65+i*30,10);
}
