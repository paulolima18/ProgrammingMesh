#include <stdio.h>
#include "help.h"

/*
  Compile: $ gcc isort.c help.c -o (exec_name)
  --------------------------------------------
    Complexity
 * Best    Case: (N-1)*(N-1)
 * Worst   Case: (N-1)*(N-1)
 * Average Case: (N-1)*(N-1)
*/

// Insertion sort algorithm
void iSort(int v[], int N) {
    int i,j,temp;
    for (i = 0; i < N-1; i++)
    {
        for (j = i+1; j < N; j++)
        {
            if (v[i] > v[j])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
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
