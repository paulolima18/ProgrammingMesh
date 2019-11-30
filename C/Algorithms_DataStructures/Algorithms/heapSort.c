#include <stdlib.h>
#include <stdio.h>
#include "help.h"

/*
  Compile: $ gcc isort.c help.c -o (exec_name)
  --------------------------------------------
    Complexity
 * Best    Case: (Log2N) * N
 * Worst   Case: (Log2N) * N
 * Average Case: (Log2N) * N

                                (0)
            (1)                                 (2)
    (3)             (4)                 (5)             (6)
(7)     (8)     (9)     (10)
*/
void bubbleDown(int h[], int N) { // remove element from heap
    int i,p;
    i = 0; p = (2*i)+2;
    while(p < N) {
        if(h[p-1] < h[p]) p--;
        if(h[i] <= h[p]) break;
        swap(h,i,p);
        i = p; p = (2*i)+2;
    }
    p = (2*i) +1;
    if(p < N && h[i] > h[p]) swap(h, i , p);
}

void bubbleUp(int h[], int N, int x) { // add element to heap
    int i,p;
    h[N] = x;
    i = N; p = (i-1)/2;
    while(i > 0 && h[i] < h[p])  {
        swap(h,i,p);
        i = p; p = (i-1)/2;
    }
}

void heapSort(int v[], int N) {
    int i;

    for(i = 1; i< N; i++)
        bubbleUp(v,i,v[i]);

    for(i = N-1; i > 0; i--) {
        swap(v,0,i);
        bubbleDown(v,i);
    }
}

int main() {
    int n = 10,k=0;
    int x[] = {0,1,2,3,4,5,6,7,8,9};

    for (int i = 0; i < n; i++) {printf("%d ",x[i]);}
    printf("\n");
    heapSort(x,n);
    for (int i = 0; i < n; i++) {printf("%d ",x[i]);}
    printf("\n%d\n",x[k]);

    return 0;
}
