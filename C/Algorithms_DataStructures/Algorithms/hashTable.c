#include <stdio.h>
#include <string.h>

#define TABLE_CAP 10
#define NUM_KEYS 4
/*
[CAP] Capacity factor = (Number of keys) / (Table capacity)
CAP <= 0.5, Complexity | Case: T(N) = O(1)
CAP >  0.7, Complexity | Case: T(N) = O(N)
*/

enum Status {BUSY, DELETED, FREE};

typedef struct HashTable {
    enum Status status;
    int key;
    char info[100];
} HashTable;

int hash(int k, int N) {
    return (k%N);
}

int add(HashTable t[], int N, int key, char* i) {
    int p,s=1;
    p = hash(key, N);

    /* Normal p=(p+1)%N;
     * Quadratic Probing
     */
    while(t[p].status == BUSY) p=(p+(s++))%N;

    t[p].status = BUSY;
    t[p].key = key;
    strcpy(t[p].info, i);

    return 0;
}
char* getStatusString(enum Status status)  {
    switch (status) {
        case BUSY: return "BUSY";
        case FREE: return "FREE";
        case DELETED: return "DELETED";
        default: return "";
    }
}

void printHash(HashTable t[], int N) {
    int i;
    for(i = 0; i< N; i++) {
        printf("Index: %d | ",i);
        printf("Status: %s | Key: %d | Value/Info: %s\n",getStatusString(t[i].status), t[i].key, t[i].info);
    }
}

void emptyHash(HashTable t[], int N) {
    int i;
    for(i = 0; i< N; i++) {
        t[i].status = FREE;
        t[i].key = 0;
        strcpy(t[i].info, "");
    }
}


int main() {
    HashTable table[TABLE_CAP];

    emptyHash(table, TABLE_CAP);

    for(int i;i< NUM_KEYS;i++) { add(table, TABLE_CAP, i+42, "stringer"); }

    printHash(table, TABLE_CAP);
    printf("Capacity factor = %.2f\n",((float)NUM_KEYS/TABLE_CAP));
    return 0;
}
