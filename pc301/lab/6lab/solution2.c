#include<stdio.h>
#include <stdlib.h> 
#include <omp.h>

void convertLumiParallel(int RGB[300*300][3],int numt){
    double G=0;
    #pragma omp parallel for num_threads(numt) schedule(guided,3)
            for(int i=0;i<300*300;i++){
                G=RGB[i][0]*0.21;
                G+=RGB[i][1]*0.72;
                G+=RGB[i][2]*0.07;
            }
}

void convertYIQParallel(int RGB[300*300][3],int numt){
    double Y=0,I=0,Q=0;
    #pragma omp parallel for num_threads(numt) schedule(guided,3)
            for(int i=0;i<300*300;i++){
                Y=RGB[i][0]*0.299+0.587*RGB[i][1]+0.114*RGB[i][2];
                I=RGB[i][0]*0.596-0.275*RGB[i][1]-0.321*RGB[i][2];
                Q=RGB[i][0]*0.212-0.523*RGB[i][1]+0.311*RGB[i][2];
            }
}

void convertLumiSerial(int RGB[300*300][3]){
    double G=0;
    for(int i=0;i<300*300;i++){
        G=RGB[i][0]*0.21;
        G+=RGB[i][1]*0.72;
        G+=RGB[i][2]*0.07;
    }
}
void convertYIQSerial(int RGB[300*300][3]){
    double Y=0,I=0,Q=0;
    for(int i=0;i<300*300;i++){
        Y=RGB[i][0]*0.299+0.587*RGB[i][1]+0.114*RGB[i][2];
        I=RGB[i][0]*0.596+0.275*RGB[i][1]+0.321*RGB[i][2];
        Q=RGB[i][0]*0.212+0.523*RGB[i][1]+0.311*RGB[i][2];
    }
}
int main(){
    FILE *file=fopen("KittenRGB.txt","r");
    int RGB[300*300][3];
    char c;
    int cur=0,row=0,col=0;
    while((c=fgetc(file))!=EOF){
        if(c==' '||c=='\n'){
            RGB[row][col]=cur;
            if(col==2){
                col=0;
                row++;
            }
            else{
                col++;
            }
            cur=0;
        }
        else{
            cur=(c-'0')+cur*10;
        }
    }
    double st=0,et=0;

    printf("GRAYSCALE \n");
    st=omp_get_wtime();
    convertLumiSerial(RGB);
    et=omp_get_wtime();
    printf("SERIAL TIME TAKE GRAYSCALE: %f\n",(et-st));

    for(int i=2;i<=16 ;i*=2){
        st=omp_get_wtime();
        convertLumiParallel(RGB,i);
        et=omp_get_wtime();
        printf("PARALLEL TIME TAKE GRAYSCALE %d threads: %f\n",i,(et-st));
    }

    printf("YIQ\n");
    st=omp_get_wtime();
    convertYIQSerial(RGB);
    et=omp_get_wtime();
    printf("SERIAL TIME TAKE YIQ: %f\n",(et-st));

    for(int i=2;i<=16 ;i*=2){
        st=omp_get_wtime();
        convertYIQParallel(RGB,i);
        et=omp_get_wtime();
        printf("PARALLEL TIME TAKE YIQ %d threads: %f\n",i,(et-st));
    }

    for(int i=0; i<300*300; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", RGB[i][j]);
        }
        printf("\n");
    }

}