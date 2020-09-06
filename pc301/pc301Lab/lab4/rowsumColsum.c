#include<stdio.h>

int main() {
    int rowsum[3];
    int colsum[3];
    int mat1[3][3] = {
        {1,5,2},
        {6,7,8},
        {3,4,9}
    };
    for(int i=0; i<3; ++i) {
        rowsum[i] = 0;
        colsum[i] = 0; 
        for(int j=0; j<3; ++j) {
            rowsum[i] += mat1[i][j];
            colsum[i] += mat1[j][i];
        }
    }

    for(int i=0; i<3; ++i) {
        printf("row(%d)=%d column(%d)=%d\n",i,rowsum[i],i,colsum[i]);
    }
    return 0;
}
