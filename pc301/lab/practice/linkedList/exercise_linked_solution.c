#include <stdlib.h>
#include <stdio.h>
#include "omp.h"

#ifndef N
#define N 24
#endif
#ifndef FS
#define FS 20
#endif

struct node {
   int data;
   int fibdata;
   struct node* next;
};

int fib(int n) {
   int x, y;
   if (n < 2) {
      return (n);
   } else {
      x = fib(n - 1);
      y = fib(n - 2);
	  return (x + y);
   }
}

void processwork(struct node* p) 
{
   int n;
   n = p->data;
   p->fibdata = fib(n);
}

struct node* init_list(struct node* p) {
    int i;
    struct node* head = NULL;
    struct node* temp = NULL;
    
    head = malloc(sizeof(struct node));
    p = head;
    p->data = FS;
    p->fibdata = 0;
    for (i=0; i< N; i++) {
       temp  = malloc(sizeof(struct node));
       p->next = temp;
       p = temp;
       p->data = FS + i + 1;
       p->fibdata = i+1;
    }
    p->next = NULL;
    return head;
}

int main(int argc, char *argv[]) {
     double start, end;
     struct node *p=NULL;
     struct node *temp=NULL;
     struct node *head=NULL;
     
	  printf("Process linked list\n");
     printf("  Each linked list node will be processed by function 'processwork()'\n");
     printf("  Each ll node will compute %d fibonacci numbers beginning with %d\n",N,FS);      
 
     p = init_list(p);
     head = p;
     //MY SOLUTION
     int i=0;
     start = omp_get_wtime();
     #pragma omp parallel for private(p,i) schedule(static,3)
     for(i=0; i<N+1; i++) {
       p=head; 
       int j = i;
       while(j > 0) {
           p = p->next;
           j -= 1;
       }
       printf("%d\n", p->data);
       processwork(p);
     }
     end = omp_get_wtime();
     printf("\ntotal time taken: sol1=%f\n",end-start);
     //SOLUTION 2
     //traverse the linked list to find the length of the linked list
     int count = 0;
     p = head;
     while(p!=NULL) {
        p = p -> next;
        count += 1;
     }

     struct node** parr = (struct node**) malloc (count * sizeof(struct node*));
     p = head;

     i=0;
     while(p!=NULL) {
        parr[i] = p;
        p = p->next;
        i+=1;
     }

     start = omp_get_wtime();
     #pragma omp parallel for schedule(static,3)
        for(int i=0; i<count; i++) {
           processwork(parr[i]);
        }
      end = omp_get_wtime(); 
      printf("\ntotal time taken: sol2=%f\n",end-start);
      
     p = head;
	 while (p != NULL) {
        printf("%d : %d\n",p->data, p->fibdata);
        temp = p->next;
        free (p);
        p = temp;
     }  
	 free (p);
    return 0;
}
