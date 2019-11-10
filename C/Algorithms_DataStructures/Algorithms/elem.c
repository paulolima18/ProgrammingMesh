#include <stdio.h>
#include "help.h"

/*
  Compile: $ gcc elem.c help.c -o (exec_name)
  --------------------------------------------
    Complexity
 * Best    Case: 1
 * Worst   Case: N
 * Average Case: N/2
*/

// Find a certain value in a sorted array
int elem(int x, int v[], int N) {
    int i;
    for (i = 0; i < N && x > v[i]; i++);
    return (i < N && v[i] == x);
}

int main() {
    int N = 10; // change N to test speed/results
    int v[N];
    for (int i = 0; i < N; i++) { v[i] = i; }
    printResults(v, N);
    int result = elem(0, v, N);
    printf("%d\n",result);
    return 0;
}
