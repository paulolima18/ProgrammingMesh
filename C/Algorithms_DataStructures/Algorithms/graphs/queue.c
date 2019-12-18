#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int value;
    struct queue * next;
}*PQueue;

void add(PQueue q, int x) {
    PQueue new = malloc(sizeof(struct queue)),aux;
    new -> value = x;
    new -> next = NULL;
    aux=q;
    while (aux->next!=NULL) {
        aux=aux->next;
    }
    aux->next =new;
}

int main() {
    PQueue a,aux;
    a = malloc(sizeof(struct queue));
    a -> value = 1;
    a -> next = NULL;
    add(a, 2);
    for(aux = a; aux!=NULL; aux=aux->next)
        printf("%d\n", aux->value);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int value;
    struct queue * next;
}*PQueue;

PQueue add(PQueue q, int x) {
    PQueue new;
    new = malloc(sizeof(struct queue));
    new -> value = x;
    new -> next = q;
    q = new;
    printf("NEW:%d %d\n",q->value,q->next->value);
    return q;
}

int main() {
    PQueue a,aux;
    a = malloc(sizeof(struct queue));
    a -> value = 1;
    a -> next = NULL;
    a = add(a,2);
    for(aux = a;aux!=NULL;aux=aux->next)
        printf("%d\n", aux->value);
    return 0;
}
*/
