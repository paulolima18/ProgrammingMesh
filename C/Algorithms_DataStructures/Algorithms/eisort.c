#include <stdio.h>
#include "help.h"

/*
  Compile: $ gcc eisort.c help.c -o (exec_name)
  --------------------------------------------
    Complexity
 * Best    Case: N-1
 * Worst   Case: ((N-1)*N) / 2
 * Average Case: ((N-1)*N) / 4
*/

// Efficient insertion sort algorithm
void iSort(int v[], int N) {
    int i,j,temp;
    for (i = 1; i < N; i++)
    {
        temp = v[i];
        for (j = i-1; j >= 0 && v[j] > temp; j--)
            v[j+1] = v[j];
        v[j+1] = temp;
    }
}

int main() {
    start_rand();
    int N = 100000; // change N to test speed/results
    int v[N];
    for (int i = 0; i < N; i++) { v[i] = rand_int(N); }
    // printResults(v, N);
    iSort(v, N);
    // printResults(v, N);
    return 0;
}
