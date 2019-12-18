#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define BAL 1
#define RIGHT 2

typedef struct edge {
    int info;
    int bal;
    struct edge *left, *right;
} Edge;

typedef Edge *Tree;

Tree rr(Tree rv) {
    Tree b;
    b = rv -> left;
    rv ->left = b -> right;
    b -> right = rv;

    if(b -> bal ==  BAL)
        b -> bal = RIGHT;
    else if(b -> bal ==  LEFT)
        b -> bal = BAL;

    return b;
}

int main() {
    return 0;
}
