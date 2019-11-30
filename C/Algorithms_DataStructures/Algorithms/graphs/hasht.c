#include <stdlib.h>

#define FREE 0
#define OCUPIED 1
#define DELETED 2

struct entry {
    int status;
    int v;
};

typedef struct hasht {
    int size, num_ocupied;
    struct entry *t;
}HashTable;

/* Hash function for this Hash Table implementation */
int hash(int key, int size) {
    return (key%size);
}

/* new: Creates an empty hash table, with a given size */
HashTable* new(int size) {
    int i;
    HashTable* a;
    a = malloc(sizeof(HashTable));
    a -> size = size;
    a -> num_ocupied = 0;
    a -> t = malloc(size * sizeof(struct entry));
    for(i = 0; i<size; i++) {
        a->t[i].status = FREE;
        a->t[i].v = 0;
    }
    return a;
}

/* resize: doubles the size */
void resize(HashTable* h) {
    struct entry *node;
    int n = 2 * h->size,i,p;
    node = malloc(n*(sizeof(struct entry)));
    for(i=0; i < n; i++) {
        node[i].status = FREE;
        node[i].v = 0;
    }
    for(i=0; i < h->size; i++) {
        if(h->t[i].status == OCUPIED) {
            p = hash(h->t[i].v, n);
            while(node[p].status == OCUPIED) p = (p+1)%h->size;
            node[p].status = OCUPIED;
            node[p].v = h->t[i].v;
        }
    }
    free(h -> t);
    h -> t = node;
    h -> size = n;
}

/* add: Adds a new value to the table
        returns 0 if x doesn't exist in the HashTable
        returns 1 if x exists in the HashTable
*/
int add(HashTable* h, int x) {
    int i;
    if(2*h->num_ocupied > h->size) resize(h);
    for (i = hash(x,h->size); h->t[i].status == OCUPIED && h->t[i].v != x; i=(i+1)%h->size);
    if(h->t[i].status == OCUPIED) return 1;
    h->t[i].status = OCUPIED;
    h->t[i].v = x;
    h->num_ocupied = h->num_ocupied + 1;
    return 0;
}

/* exists: Finds if a certain x exists in the HashTable */
int exists(HashTable* h, int x) {
    int i;
    for(i = hash(x,h->size);h->t[i].status == OCUPIED && h->t[i].v != x;i=(i+1)%h->size);
    return h->t[i].status == OCUPIED;
}

int main() {
    HashTable *a = new(10);
    return 0;
}
