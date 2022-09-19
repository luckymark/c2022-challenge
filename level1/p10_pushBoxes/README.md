### 题目：推箱子小游戏（基于console）

### 功能要求：

1. 将p09迷宫游戏改造为“推箱子”游戏；
1. 在地图中增加箱子、箱子目标位置等图形；
1. 当玩家将所有箱子归位，则显示玩家赢得了游戏；
1. 按玩家走动步数记分；
1. 设计多个关卡，每一关的地图从文件中读取，玩家每关的分数记录到文件中；
```
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<Windows.h>
using namespace std;

int map[9][12];
int i = 7, j = 8,k;
void moveup()
{
    if (map[i - 1][j] == 0 || map[i - 1][j] ==3 )
    {
        map[i - 1][j] += 5;
        map[i][j] -= 5;
        i--;
    }
    else if (map[i - 1][j] == 4 || map[i - 1][j] == 7)
    {
        if (map[i - 2][j] == 0 || map[i - 2][j] == 3)
        {
            map[i - 2][j] += 4;
            map[i - 1][j] += 1;
            map[i][j] -= 5;
            i--;
        }
    }
}
void movedown()
{
    {
        if (map[i + 1][j] == 0 || map[i + 1][j] == 3)
        {
            map[i + 1][j] += 5;
            map[i][j] -= 5;
            i++;
        }
        else if (map[i + 1][j] == 4 || map[i + 1][j] == 7)
        {
            if (map[i + 2][j] == 0 || map[i + 2][j] == 3)
            {
                map[i + 2][j] += 4;
                map[i + 1][j] += 1;
                map[i][j] -= 5;
                i++;
            }
        }
    }
}
void moveleft()
{
        if (map[i][j-1] == 0 || map[i][j-1] == 3)
        {
            map[i][j-1] += 5;
            map[i][j] -= 5;
            j--;
        }
        else if (map[i][j-1] == 4 || map[i][j-1] == 7)
        {
            if (map[i][j-2] == 0 || map[i][j-2] == 3)
            {
                map[i][j-2] += 4;
                map[i][j-1] +=1;
                map[i][j] -= 5;
                j--;
            }
        }
    
}
void moveright()
{
    if (map[i][j +1] == 0 || map[i][j +1] == 3)
    {
        map[i][j +1] += 5;
        map[i][j] -= 5;
        j++;
    }
    else if (map[i][j+1] == 4 || map[i][j+1] == 7)
    {
        if (map[i][j+2] == 0 || map[i][j+2] == 3)
        {
            map[i][j + 2] += 4;
            map[i][j + 1] += 1;
            map[i][j] -= 5;
            j++;
        }
    }
}
void play()
{
    int n = _getch();
    switch (n)
    {
    case 72://shang
        moveup();
        break;
    case 80://xia
        movedown();
        break;
    case 75://zuo
        moveleft();
        break;
    case 77://you
        moveright();
        break;
    }
}
int win(int n)
{
    int sum = 0;
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            if (map[i][j] == 7)
                sum++;
        }
    }
    if (sum == n)
    {
        printf("Win!");
        return 1;
    }
    return 0;
}
int lose()
{
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            if (map[i][j] == 4)
            {
                if (map[i + 1][j] == 1 && map[i][j + 1] == 1 || map[i + 1][j] == 1 && map[i][j - 1] == 1)
                    return 1;
                if (map[i - 1][j] == 1 && map[i][j - 1] == 1 || map[i - 1][j] == 1 && map[i][j + 1] == 1)
                    return 1;
            }
        }
    }
    return 0;
}
void printm()
{
    for (int i = 0; i <= 8; i++)
    {
        for (int j=0;j<=10;j++)
        {
            switch (map[i][j])
            {
            case 0:
                printf("  ");
                break;
            case 1:
                printf("■");
                break;
            case 3:
                printf("☆");
                break;
            case 4:
                printf("□");
                break;
            case 5:
                printf("♀");  
                break;
            case 7:     
                printf("★");
                break;
            case 8:     
                printf("♀");
                break;
            }
        }
        cout << endl;
    }
}
void fcin()
{
    printf("    请输入关卡:1,2,3: ");
    cin >> k;
    FILE *fptr;
    switch (k)
    {
    case 1:
        fptr= fopen("map1.txt", "r");
        break;
    case 2:
        fptr = fopen("map2.txt", "r");
        break;
    case 3:
        fptr = fopen("map3.txt", "r");
        break;
    } 
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 11; j++)
        {
                fscanf(fptr, "%d", &map[i][j]);
        }
    }
    fclose(fptr);
}
int kaishi()
{
    printf("\n");
    printf("   请输入任意键开始游戏\n");
    printf("      输入ESC退出\n");
    int n = getch();
    if (n == 27)
        return 0;
    else
        return 1;
}
void fenshu(int m)
{
    FILE* fptr;
    switch (k)
    {
    case 1:
        fptr = fopen("map1.txt", "a");
        break;
    case 2:
        fptr = fopen("map2.txt", "a");
        break;
    case 3:
        fptr = fopen("map3.txt", "a");
        break;
    }
    fprintf(fptr, "\n%d",m);
}
int main()  
{
    if (kaishi() == 0)
        return 0;
    fcin();
    int n = 0;
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            if (map[i][j] == 3)
                n++;
        }
    }
    int m = 0;
    while (true)
    {
        system("cls");
        printm();
        if (win(n) == 1)
            break;
        if (lose() == 1)
        {
            printf("Lose");
            return 0;
        }
        play();
        m++;
    }
    fenshu(m);
    return 0;
}
```