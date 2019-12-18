#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE    31      // numero primo
#define EMPTY       ""
#define DELETED     "-"

typedef char KeyType[9];
typedef void *Info;

typedef struct entry {
    KeyType  key;
    Info info;
    // struct entry *next;
} Entry, HashTable[HASHSIZE];

// hash fuction
int hash(KeyType key) {
    int r,i;
    for(i=0;i<9;r=key[i++]);
    return r%HASHSIZE;
}

// inititialize hash table
void initializeTable(HashTable table) {
    int i;
    for(i = 0;i<HASHSIZE;i++) {
        sprintf(table[i].key,"000000000");
        table[i].info = malloc(sizeof(int)*10);
        sprintf(table[i].info,"%d",i);
    }
}

// clear hash table
void clearTable(HashTable table) {
    int i;
    for(i = 0;i<HASHSIZE;i++) {
        free(table[i].info);
    }
}

void printTable(HashTable table) {
    int i;
    // struct entry  * aux;
    for(i = 0;i<HASHSIZE;i++) {
        printf("From %d to:\n",i);
        // for(aux = table[i];aux!=NULL;aux=aux->next)
        printf("%s\n",table[i].info);
    }
}

// insert a new association between a key and the information
void insertTable_LP(HashTable table, KeyType key, Info info) {
    int i;
    for(i=hash(key);table[i])
}

int main() {
    HashTable table;

    initializeTable(table);
    printTable(table);
    clearTable(table);
    printTable(table);

    return 0;
}
