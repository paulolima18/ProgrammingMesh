#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct node {
    int value;
    struct node *left, *right;
} Node, *Tree;

typedef int Heap[SIZE];


Tree aux(Heap h, int i) {
    Tree tree = NULL;
    if(i < SIZE) {
        tree = malloc(sizeof(Tree));
        tree -> value = h[i];
        tree -> left  = aux(h, (2*i)+1);
        tree -> right = aux(h, (2*i)+2);
    }
    return tree;
}

Tree toMinHeap(Heap h) {
    Tree a;
    a = aux(h, 0);
    return a;
}

void prinTree(Tree a) {
    if(a != NULL) {
        printf("%d\n",a->value);
        prinTree(a->left);
        prinTree(a->right);
    }
}

int main() {
    Heap min_heap;
    int i;
    for(i=0;i<SIZE;i++)
        min_heap[i]=i;

    printf("ARRAY\n");
    for(i=0;i<SIZE;printf("%d\n", i++));
    printf("TREE\n");
    Tree heap = toMinHeap(min_heap);
    prinTree(heap);
    return 0;
}
