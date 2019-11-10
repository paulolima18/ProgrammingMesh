#include <stdio.h>
#include "help.h"

/*
  Compile: $ gcc bsearch.c help.c -o (exec_name)
  --------------------------------------------
    Complexity
 * Best    Case: 1
 * Worst   Case: Log2 N (ln N/ ln 2)
 * Average Case: Log2 N (ln N/ ln 2)
*/

// Find a certain value in a sorted array
int bSearch(int x, int v[], int N) {
    int i,s,m,c;
    i = 0; s = N;
    while (i < s) {
        m = (i+s) / 2; c = v[m] - x;
        if(!c) i=s=m;
        else if(c > 0) s = m-1;
        else i = m+1;
    }
    return (i==s && !c);
}

int main() {
    int N = 10; // change N to test speed/results
    int v[N];
    for (int i = 0; i < N; i++) { v[i] = i; }
    printResults(v, N);
    int result = bSearch(0, v, N);
    printf("%d\n",result);
    return 0;
}
