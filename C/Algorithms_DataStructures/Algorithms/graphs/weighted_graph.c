#include <stdio.h>
#include <stdlib.h>

#define V 7

typedef struct edge {
    int dest, weight;
    struct edge *next;
}*Graph[V];

/* Capacity:
    Complexity: Tcapacity(V,E) = worst case -> (V+E)
*/
int capacity(Graph g, int x) {
    int i, r = 0;
    struct edge *aux;
    for(i=0;i<V;i++) {
        for(aux=g[i];aux!=NULL;aux=aux->next) {
            if(i==x)
                r -= aux->weight;
            else if(aux->dest == x)
                r += aux->weight;
        }
    }
    return r;
}

int maxCap(Graph g){
    int i, r = 0, cap[V];
    // cap = malloc(sizeof(int)*V);
    struct edge *aux;
    for(i=0;i<V;cap[i++]=0);
    for(i=0;i<V;i++)
        for(aux=g[i];aux!=NULL;aux=aux->next) {
            cap[i] -= aux->weight;
            cap[aux->dest] += aux->weight;
            // if(cap[r] < cap[i])
            //     r = i;
            // if(cap[r] < cap[aux->dest])
            //     r = aux->dest;
        }
    for(i=1;i+1<V;i++)
        if(cap[r]<cap[i])
            r = i;
    return r;
}

int main() {
    /* Graph Creation */
    Graph a;
    struct edge *aux;
    int i;
    for(i=0;i<V;i++) a[i] = malloc(sizeof(struct edge));
    a[0] -> dest = 2;
    a[0] -> weight = 1;
    a[0] -> next = NULL;

    a[1] -> dest = 0;
    a[1] -> weight = 2;
    a[1] -> next = NULL;

    a[2] -> dest = 1;
    a[2] -> weight = 3;
    a[2] -> next = NULL;

    a[3] -> dest = 2;
    a[3] -> weight = 4;
    a[3] -> next = malloc(sizeof(struct edge));
    a[3] -> next -> dest = 0;
    a[3] -> next -> weight = 5;
    a[3] -> next -> next = NULL;

    a[4] -> dest = 5;
    a[4] -> weight = 10;
    a[4] -> next = NULL;

    a[5] = NULL;

    a[6] = NULL;
    /* -------- */
    int biggest = maxCap(a);
    printf("Capacity in %d is: %d\n", biggest,capacity(a, biggest));
    for(i = 0;i<V;i++)
        printf("Capacity Normal in %d is: %d\n", i, capacity(a, i));
    return 0;
}
