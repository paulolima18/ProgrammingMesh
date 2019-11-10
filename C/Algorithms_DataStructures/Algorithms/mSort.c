#include <stdio.h>
#include "help.h"

/*
  Compile: $ gcc mSort.c help.c -o (exec_name)
  --------------------------------------------
    Complexity
 * Best    Case: (Log2N) * N
 * Worst   Case: (Log2N) * N
 * Average Case: (Log2N) * N
*/

/*
Merge function taken from https://www.geeksforgeeks.org/merge-sort/
*/
void f_merge(int v[], int N, int b[], int M) {
    int i, j, k;
       int n1 = N;
       int n2 =  M;

       /* create temp arrays */
       int L[n1], R[n2];

       /* Copy data to temp arrays L[] and R[] */
       for (i = 0; i < n1; i++)
           L[i] = v[i];
       for (j = 0; j < n2; j++)
           R[j] = v[N +  j];

       /* Merge the temp arrays back into arr[l..r]*/
       i = 0; // Initial index of first subarray
       j = 0; // Initial index of second subarray
       k = 0; // Initial index of merged subarray
       while (i < n1 && j < n2)
       {
           if (L[i] <= R[j])
           {
               v[k] = L[i];
               i++;
           }
           else
           {
               v[k] = R[j];
               j++;
           }
           k++;
       }

       /* Copy the remaining elements of L[], if there
          are any */
       while (i < n1)
       {
           v[k] = L[i];
           i++;
           k++;
       }

       /* Copy the remaining elements of R[], if there
          are any */
       while (j < n2)
       {
           v[k] = R[j];
           j++;
           k++;
       }
}

// Fast Merge sort algorithm
void mSort(int v[], int N) {
    int m;
    if(N > 1) {
        m = N/2;
        f_mSort(v, m);
        f_mSort(v+m, N-m);
        f_merge(v, m, v+m, N-m);
    }
}


int main() {
    start_rand();
    int N = 1000000; // change N to test speed/results
    int v[N];
    for (int i = 0; i < N; i++) { v[i] = rand_int(N); }
    printResults(v, N);
    mSort(v, N);
    printResults(v, N);
    return 0;
}
