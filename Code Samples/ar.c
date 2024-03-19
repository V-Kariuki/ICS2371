#include<stdio.h>

int main(){
    int i, marks[10];
    for(i=0;i<10 ;i++){
        scanf("%d", &marks[i]);
    }
    for(i=0;i<10 ;i++){
        printf("%d,",marks[i]);
    }
    return 0;
}
