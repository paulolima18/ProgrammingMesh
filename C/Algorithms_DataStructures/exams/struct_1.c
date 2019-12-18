/* gcc -o struct struct_exam.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

typedef struct edge {
    char plate[6];
    struct edge * next;
} No;

typedef No *Graph[SIZE];

int hash(char plate[]) {
    int i, r=0;
    for(i=0; i<6; i++)
        r += plate[i];
    return r%SIZE;
}

int compare(char str1[], char str2[]) {
    for (int i = 0; i < 6; i++) {
        if(str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
    }
    return 0;
}
int insert(Graph g, char plate[]) {
    int i, count = 0;
    No * aux;
    for(i = hash(plate); count<SIZE; i=(i+1)%SIZE, count++)
        for(aux=g[i]; aux!=NULL; aux=aux->next)
            if(compare(aux->plate, plate) == 0)
                return 0;
    No * t;
    t = malloc(sizeof(struct edge));
    sprintf(t->plate, plate);
    t -> next = g[i];
    g[i] = t;
    /* inserir nesta posicao "i" */
    return 1;
}

int main() {
    Graph g;

    printf("%d\n", insert(g, "AAABBB"));
    printf("two\n");
    printf("%d\n", insert(g, "AAACCC"));
    printf("%d\n", insert(g, "AAADDD"));
    printf("%d\n", insert(g, "AAAEEE"));
    printf("%d\n", insert(g, "AAAFFF"));
    printf("%d\n", insert(g, "AAAGGG"));
    printf("%d\n", insert(g, "AAAHHH"));
    printf("%d\n", insert(g, "AAAJJJ"));
    printf("%d\n", insert(g, "AAAKKK"));
    printf("%d\n", insert(g, "AAALLL"));
    printf("%d\n", insert(g, "AAAUUU"));
    No * aux;
    for(int i =0; i<SIZE; i++) {
        printf("%d : \n", i);
        for(aux = g[i]; aux != NULL; aux=aux->next)
            printf("%s ", aux -> plate);
        printf("\n");
    }
}
