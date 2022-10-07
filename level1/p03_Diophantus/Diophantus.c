#include <stdio.h>

const float Childhood = (1.0/6);
const float Teenager = (1.0/12);
const float Singer = (1.0/7);
const float After_marriage = 5;
const float Son_Father = 1.0/2;
const float Father_alone = 4;

int main(void) {
    int F_age ;  //爸爸的寿命

//    F_age = F_age * (Childhood + Teenager + Singer) + After_marriage + Son_Father * F_age + Father_alone

F_age = (After_marriage + Father_alone)/(1-(Childhood + Teenager + Singer + Son_Father));

    printf("%d\n",F_age);

}