#include <stdio.h>
#include "help.h"

/*
  Compile: $ gcc qsort.c help.c -o (exec_name)
  --------------------------------------------
    Complexity
 * Best    Case: ---
 * Worst   Case: ((N+2)*(N-1)) / 2
 * Average Case: ---
*/

void partition(int v[], int N) {

}

// Quick sort algorithm
void qSort(int v[], int N) {
    int m;
    if(N > 1) {
        m = partition(v, N);
        qSort(v, m);
        qSort(v+m, N-m-1);
    }
}

int main() {
    start_rand();
    int N = 10; // change N to test speed/results
    int v[N];
    for (int i = 0; i < N; i++) { v[i] = rand_int(N); }
    // printResults(v, N);
    qSort(v, N);
    // printResults(v, N);
    return 0;
}
