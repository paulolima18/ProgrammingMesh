#include <stdio.h>
#include <stdlib.h>
#include "../help.h"

#define PARENT(i)  (i-1)/2     // index starts at 0
#define LEFT(i)    2*i + 1
#define RIGHT(i)   2*i + 2
#define MAX 100

typedef int Elem;  // heap elements
typedef struct {
    int   size, used;
    Elem  *values;
} Heap;

Heap *newHeap  (int size) {
    Heap * new;
    new = malloc(sizeof(Heap));
    new -> size = MAX;
    new -> used = 0;
    new -> values = malloc(sizeof(Elem)*size);
    return new;
}

void bubbleUp  (Elem h[], int i) {
    int p;
    p = PARENT(i);
    while(i>0 && h[i] < h[p]) {
        swap(h, i, p);
        i = p;
        p = PARENT(i);
    }
}

int insertHeap(Heap *h, Elem x) {
    int i;
    if(h->used == h->size) {
        printf("Max size!\n");
        return 0;
    }
    h -> values[h->used] = x;
    bubbleUp(h->values,h->used);
    h -> used = h -> used + 1;
    return 1;
}

void bubbleDown(Elem h[], int N) {
    int i=0, f=RIGHT(i);
    while(f<N) {
        if(h[f] > h[f-1]) f--;
        if(h[f] >= h[i]) break;
        swap(h, i, f);
        i = f; f = RIGHT(i);
    }
    if((f=LEFT(i)) < N && h[i] > h[f] ) swap(h, i, f);
}

int extractMin(Heap *h, Elem *x) {
    bubbleDown(x, h->used);
    h->values = x;
    h->used--;
    // x++;
    // h->values = x;
    // h->used--;
    // return 1;
}

int minHeapOK(Heap h) {
    // r == 1; Min heap ok
    int i,r=1;
    for(i=0;r && i < h.used;i++)
        if((LEFT(i) < h.used && h.values[i] > h.values[LEFT(i)]) || (RIGHT(i) < h.used && h.values[i] > h.values[RIGHT(i)]))
            r = 0;
    return r;
}

int main() {
    Heap *heap = newHeap(MAX);
    int i;

    insertHeap(heap, 4);
    insertHeap(heap, 10);
    insertHeap(heap, 21);
    insertHeap(heap, 45);
    insertHeap(heap, 13);
    insertHeap(heap, 25);
    insertHeap(heap, 22);
    insertHeap(heap, 60);
    insertHeap(heap, 100);
    insertHeap(heap, 20);

    insertHeap(heap, 6);
    // bubbleDown(heap->values, heap->used);
    // extractMin(heap, heap->values);
    printf("Size: %d | Used: %d\n",heap->size, heap->used);
    for (i = 0; i < heap->used; i++) {
        printf("Elem %d is: %d\n", i, heap->values[i]);
    }
    printf("Min-Heap ok? %d\n",minHeapOK(*heap));
    return 0;
}
