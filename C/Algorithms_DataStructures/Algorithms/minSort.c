#include <stdio.h>
#include "help.h"

/*
  Compile: $ gcc minSort.c help.c -o (exec_name)
  --------------------------------------------
    Complexity
 * Best    Case: (N-1)*(N-1)
 * Worst   Case: ((N-1)*N) / 2
 * Average Case: ---
*/

// Minimum sort algorithm
void minSort(int v[], int N) {
    int i,j,temp;
    for (i = 0; i < N-1; i++)
        for (j = i+1; j < N; j++)
            if(v[j] < v[i])
                swap(v, i, j);
}

int main() {
    start_rand();
    int N = 10; // change N to test speed/results
    int v[N];
    for (int i = 0; i < N; i++) { v[i] = rand_int(N); }
    printResults(v, N);
    minSort(v, N);
    printResults(v, N);
    return 0;
}
