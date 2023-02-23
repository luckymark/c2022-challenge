# include <stdio.h>
# include <windows.h>
const int L_Border =180,R_Border=0;

int main(void) {

    int step = 1, Flash;
    while (1) {
        Flash += step;

        if (Flash == L_Border || Flash == R_Border) {
            step = -step;
        }

        system("cls");

        for (int i = 1; i <= Flash; ++i) {
            printf(" ");
        }

        printf("Running");
        Sleep(1);


    }
}



