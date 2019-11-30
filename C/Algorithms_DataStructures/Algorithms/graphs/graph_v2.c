#include <stdio.h>

#define V 7

typedef int GraphM[V][V];

typedef struct edge {
    int dest;
    struct edge *next;
}*Graph[V];

void matGraph(GraphM a, Graph b) {
    int i,j;
    struct edge *t;
    for(i = 0; i<V; i++) {
        b[i] = NULL;
        for(j = 0; j<V; j++)
            if(a[i][j]!=0) {
                // edge i -> j
                t = malloc(sizeof(struct edge));
                t -> dest = j;
                t -> next = b[i];
                b[i] = t;
            }
    }
}
/* Reverse: reverses the direction of all edges on the graph */
void reverse(Graph a, Graph b) {
    int i;
    struct edge *t, *aux;
    for(i=0; i<V; b[i++]=NULL);
    for(i = 0; i<V; i++) {
        for(aux = a[i]; aux!= NULL; aux=aux->next) {
            t = malloc(sizeof(struct edge));
            t -> dest = i;
            t -> next = b[aux->dest];
            b[aux->dest] = t;
        }
    }
}

/* Is Edge: Checks if there is a valid path between node x and y
            Complexity: Tedge(V,E) = worst case -> O(V)*/
int isEdge(Graph g, int x, int y) {
    struct edge *aux;
    for(aux=g[x]; aux!=NULL && aux -> dest != y; aux=aux->next);
    return aux != NULL;
}

/* Path OK: */
int pathOK(Graph g, int c[], int k) {
    int i;
    for(i=0; i+1<k && edge(g,c[i],c[i+1]); i++);
    return i+1 == k;
}

/* Color OK:
Complexity: TcolorOK(V,E)= worst case -> (V+E) */
int colorOK(Graph g, int color[]) {
    int i, r=1;
    struct edge *aux;
    for(i=0;i<V && r;i++)
        for(aux=g[i];aux!=NULL;aux=aux->next)
            if(color[i]==color[aux->dest])
                r = 0;
    return r;
}

int main() {

    return 0;
}
