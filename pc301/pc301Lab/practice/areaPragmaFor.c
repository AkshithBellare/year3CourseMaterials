#include<stdio.h>
#include<omp.h>
static long num_steps = 100000000;
double step;
int main() {
   int i; double x, pi,sum=0.0;
   
   step = 1.0/(double)num_steps;
   double start = omp_get_wtime();
   omp_sched_t kind;
   int chunk_size;
   omp_set_schedule(omp_sched_static, 4);
   omp_get_schedule(&kind, &chunk_size);
   switch(kind) {
        case omp_sched_static:
            printf("Static");
            break;
        case omp_sched_dynamic:
            printf("Dynamic");
            break;
        case omp_sched_guided:
            printf("Guided");
            break;
        case omp_sched_auto:
            printf("Auto");
            break;
        default:
            printf("Other");
            break;
   }
   #pragma omp parallel for reduction(+: sum) schedule(runtime)
   for(i=0; i<num_steps; ++i) {
       x = (i + 0.5)*step;
       sum = sum + 4.0/(1.0 + x*x);
   }
   double end = omp_get_wtime();
   printf("final time: %f\n", end-start);
   printf("%f", step * sum);
   return 0;
}