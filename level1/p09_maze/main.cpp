#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

int main()
{
    int i = 1, j = 1;
    while (1)
    {
        char map[20][20] = { "##################",
                             "# # ###   #### ###",
                             "#   #       ## ###",
                             "### # ## ## ###  #",
                             "##    ##      ## #",
                             "## ## #  #### ## #",
                             "#    ##  #### #  #",
                             "############# ####" };
        map[i][j] = '*';
        for (int i = 0; i < 8; i++)
            cout << map[i] << endl;
        if (i == 7 && j == 13)
        {
            cout << "win!";
            break;
        }
        int ch = _getch();
        if (ch == 72 && map[i-1][j] != '#')
            i--;
        if (ch == 80 && map[i+1][j] != '#')
            i++;
        if (ch == 75 && map[i][j-1] != '#')
            j--;
        if (ch == 77 && map[i][j+1] != '#')
            j++;
        system("cls");
    }
        return 0;
}