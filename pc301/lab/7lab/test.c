#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<math.h>
#include<omp.h>

void initSensorPos(float sensors[][2]){
    for(int i = 0;i < 1000;i++){
        sensors[i][0] = rand()%1000;
        sensors[i][1] = rand()%1000;        
    }
}

float dist(float pos1[2], float pos2[2]){
    float x = pos1[0] - pos2[0];
    float y = pos1[1] - pos2[1];    
    return sqrt((double)(x*x + y*y));
}

void addToMean(float means[][2], int idx, int n, float sensor[2]){
    means[idx][0] = ((n-1)*means[idx][0] + sensor[0])/n;
    means[idx][1] = ((n-1)*means[idx][1] + sensor[1])/n;
}

void subFromMean(float means[][2], int idx, int n, float sensor[2]){
    means[idx][0] = ((n+1)*means[idx][0] - sensor[0])/n;
    means[idx][1] = ((n+1)*means[idx][1] - sensor[1])/n;
}

int classify(float sensor[], float means[][2], int k){
    float ans = FLT_MAX;
    int idx = -1;
    for(int i = 0;i < k;i++){
        float d = dist(sensor, means[i]);
        if(ans > d){
            ans = d;
            idx = i;
        }
    }
    return idx;
}

int initClusters(float sensors[][2], float means[][2], int cluster[], int clusterSize[], int k){
    for(int i = 0;i < k;i++){
        means[i][0] = sensors[i][0];
        means[i][1] = sensors[i][1];
        cluster[i] = i;
        clusterSize[i] = 1;
    }
    for(int i = k;i < 1000;i++){
        int idx = classify(sensors[i], means, k);
        cluster[i] = idx;
        clusterSize[idx]++;
        addToMean(means, idx, clusterSize[idx], sensors[i]);
    }
}

int main(){
    //Initialize sensor position
    float sensors[1000][2];
    initSensorPos(sensors);

    //Read k
    int k;
    printf("Enter number of clusters : ");
    scanf("%d", &k);

    //Initialize k clusters
    float means[k][2];
    int cluster[1000] = {0}, clusterSize[k];
    initClusters(sensors, means, cluster, clusterSize, k);

    int iters = 10000, it;
    double st, et;
    //Sequential k means
    st = omp_get_wtime();
    for(it = 0;it < iters;it++){
        int stop = 1;
        for(int i = 0;i < 1000;i++){
            int idx = classify(sensors[i], means, k);
            if(cluster[i] == idx)
                continue;
            clusterSize[idx]++;
            clusterSize[cluster[i]]--;
            addToMean(means, idx, clusterSize[idx], sensors[i]);
            subFromMean(means, cluster[i], clusterSize[cluster[i]], sensors[i]);
            cluster[i] = idx;
            stop = 0;
        }
        if(stop)
            break;
    }
    et = omp_get_wtime();
    printf("Sequential Time = %fs\n", et - st);
  
    //Write sensor position and cluster to file
    FILE *fp = fopen("data.txt", "w");
    for(int i = 0;i < 1000;i++){
        fprintf(fp, "%f %f %d\n", sensors[i][0], sensors[i][1], cluster[i]);
    }
    fclose(fp);
}