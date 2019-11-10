#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "help.h"

// Prints the array of integers
void printResults(int v[], int N) {
    for (int i = 0; i < N; i++) { printf("%d ", v[i]); }
    printf("\n");
}

// Initialize random seed
void start_rand() {
    srand(time(NULL));
}

// Returns a random integer
int rand_int(int N) {
    return (rand() % N);
}

// Changes i index with j
void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
