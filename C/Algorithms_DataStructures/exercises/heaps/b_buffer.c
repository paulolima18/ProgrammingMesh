#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct buffer {
    int size,used, *values;
};

typedef struct buffer *Buffer;

// starts and allocates space
Buffer init (void){
    Buffer b = malloc(sizeof(struct buffer));
    b->values = malloc(sizeof(int)*SIZE);
    b->size = SIZE;
    b->used = 0;
    return b;
}

// check if empty
int empty(Buffer b) {

}

void resize(Buffer b) {

}

// insert an element
int add(Buffer b, int x) {
    if(2*b->used >= b->size) resize(b);

    b->values[b->used] = x;
    b->used++;
    return 1;
}

// next to be removed
int next(Buffer b, int* x) {

}

// remove next
int rem(Buffer b, int* x) {
    int r=1;
    if(b->used > 0)
        b->used--;
    else r = 0;
    return r;
}

int main() {
    Buffer b = init();


    add(b, 10);
    printf("%d\n",b->values[0]);

    return 0;
}
