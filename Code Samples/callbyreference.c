#include<stdio.h>
void add(int *);
int main(){
    int y = 2;
    printf("\n The value of new before called function add is %d", y);
    add(&y);
    printf("\n The value of new after calling add function is %d", y);
    return 0;
}

void add(int *x){
    *x = *x+10;
    printf("\n The value of a in the called function is %d", *x);
}