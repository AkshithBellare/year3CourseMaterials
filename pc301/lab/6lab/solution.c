#include<stdio.h>
#include<omp.h>
#define ROWS 300*300

void rgbToGrayscale(int RGB[ROWS][3]) {
    double grayscale = 0.0;
    for(int i=0; i<ROWS; i++) {
        grayscale = 0.21*RGB[i][0] + 0.72*RGB[i][1] + 0.07*RGB[i][2];
   }
}

void rgbToYIQ(int RGB[ROWS][3]) {
    double Y = 0.0, I = 0.0, Q = 0.0;
    for(int i=0; i<ROWS; i++)  {
        Y = 0.299*RGB[i][0] + 0.587*RGB[i][1] + 0.114*RGB[i][2];
        I = 0.596*RGB[i][0] - 0.275*RGB[i][1] - 0.321*RGB[i][2];
        Q = 0.212*RGB[i][0] - 0.523*RGB[i][1] + 0.311*RGB[i][2];
    }
}

void rgbToGrayscale_parallel(int RGB[ROWS][3], int n_threads) {
    double grayscale = 0.0;
    #pragma omp parallel for private(grayscale) num_threads(n_threads) schedule(guided, 3)
    for(int i=0; i<ROWS; i++) {
        grayscale = 0.21*RGB[i][0] + 0.72*RGB[i][1] + 0.07*RGB[i][2];
    }
}

void rgbToYIQ_parallel(int RGB[ROWS][3], int n_threads) {
    double Y=0,I=0,Q=0.0;
    #pragma omp parallel for private(Y,I,Q) num_threads(n_threads) schedule(guided, 3)
    for(int i=0; i<ROWS; i++) {
        Y = 0.299*RGB[i][0] + 0.587*RGB[i][1] + 0.114*RGB[i][2];
        I = 0.596*RGB[i][0] - 0.275*RGB[i][1] - 0.321*RGB[i][2];
        Q = 0.212*RGB[i][0] - 0.523*RGB[i][1] + 0.311*RGB[i][2];       
    }
}

int main() {
    char ch;
    FILE* fp = fopen("KittenRGB.txt", "r"); 
    int RGB[ROWS][3];
    int row = 0, col = 0;
    do {
        fscanf(fp, "%d", &RGB[row][col]);
        fscanf(fp, "%d", &RGB[row][col+1]);
        fscanf(fp, "%d", &RGB[row][col+2]);
        row += 1;
    } while((ch = fgetc(fp))!=EOF);

    double et = 0.0, st = 0.0;

    for(int i=2; i<=16; i=i*2) {
        st = omp_get_wtime();
        rgbToYIQ_parallel(RGB, i);
        et = omp_get_wtime();
        printf("RGB --> YIQ PARALLEL TIME TAKEN=%f\n", et-st);
    }
    printf("\n");
    
    for(int i=2; i<=16; i=i*2) {
        st = omp_get_wtime();
        rgbToGrayscale_parallel(RGB, i);
        et = omp_get_wtime();
        printf("RGB --> GRAYSCALE PARALLEL TIME TAKEN=%f\n", et-st);
    }
    printf("\n");

    st = omp_get_wtime();
    rgbToYIQ(RGB);
    et = omp_get_wtime();
    printf("RGB-->YIQ SERIAL TIME TAKEN=%f\n", et - st);
    printf("\n");

    st = omp_get_wtime();
    rgbToGrayscale(RGB);
    et = omp_get_wtime();
    printf("RGB-->GRAYSCALE SERIAL TIME TAKEN=%f\n", et - st);
    printf("\n");

}