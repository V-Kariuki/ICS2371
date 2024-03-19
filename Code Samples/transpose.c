#include <stdio.h>
int main(){
    int transpose[3][3]={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpose[i][j] = matrix[j][i];
            printf("%d", transpose[i][j]);
        }
    }
    return 0;
}