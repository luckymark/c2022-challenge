#include <stdio.h>
#include <math.h>
#include <time.h>
//#include <sys/time.h>

int judge(int Number);

int main() {

    clock_t start = clock();
//    struct timeval begin, end;
//    gettimeofday(&begin, 0);

    for (int i=3 ; i<10000 ; ++i){

        if(judge(i)==1){
            printf("%d\n",i);
        }
    }

    clock_t end = clock();

    double elaped = (double)(end - start)/CLOCKS_PER_SEC;
    printf("%ld\n%ld\nTime is %.5f",start,end,elaped);

//    gettimeofday(&end, 0);
//    long seconds = end.tv_sec - begin.tv_sec;
//    long microseconds = end.tv_usec - begin.tv_usec;
//    double elapsed = seconds + microseconds*1e-6;

}

int judge(int j) {
    for (int c = 2; c <= sqrt(j); ++c) {
        if (j % c == 0)
            return 0;
    }
    return 1;
}
