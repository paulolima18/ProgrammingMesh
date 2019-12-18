#include <stdio.h>
#include <stdlib.h>

#define V 7
#define FRINGE 1
#define NOT_VISITED 0
#define VISITED 2

typedef struct edge {
    int weight, dest;
    struct edge * next;
} Node, *Graph[V];


int find_smallest(int fringe[], int weight[], int fringe_size) {
    int r=fringe[0], i;
    for(i=0; i<fringe_size; i++) {
        if(weight[fringe[i]] < r)
            r = fringe[i];
        if(fringe[i]==-1)
            break;
    }
    return r;
}

int remove_x(int fringe[], int x) {
    int r=0, i;
    for(i=0; i<V; i++) if(fringe[i]==x) break;

    for(i; i+1<V; i++) {
        fringe[i] = fringe[i+1];
    }
    return r;
}
int dijkstra(Graph g, int origin, int weight[], int parents[]) {
    int color[V],fringe[V], i, fringe_size=0, x, r=0;
    for(i=0; i<V; i++) {
        color[i]=NOT_VISITED;
        fringe[i]=-1;
    }
    struct edge *aux;

    // insert "origin" in fringe
    // fringe_size = 1;
    fringe[fringe_size++] = origin;

    color[origin] = FRINGE;
    weight[origin] = 0;

    /*  no parents if value "-1"
    *   origin -> origin */
    parents[origin] = -1;

    while(fringe_size > 0) {
        // x <- element with smallest weight in fringe
        x = find_smallest(fringe, weight, fringe_size);

        // remove x from fringe
        remove_x(fringe, x);
        
        fringe_size--;
        color[x] = VISITED;
        for(aux = g[x]; aux != NULL; aux=aux->next)
            if(color[aux->dest] == 0) {
                if(color[aux->dest] == NOT_VISITED) {
                    weight[aux->dest] = weight[x]+aux->weight;

                    // add aux->dest to fringe
                    fringe[fringe_size++] = aux->dest;

                    parents[aux->dest] = x;
                    color[aux->dest] = FRINGE;
                }
                else if(color[aux->dest] == FRINGE && weight[x]+aux->weight < weight[aux->dest]) {
                    weight[aux->dest] = weight[x]+aux->weight;
                    parents[aux->dest] = x;

                    // update aux->dest to fringe
                }
            }
    }
    for(i = 1; i<V; i++)
        if(weight[i] > weight[r])
            r = i;
    return r;
}

void fill_test_1(Graph a) {
    struct edge *aux;
    int i;
    for(i=0;i<V;i++) a[i] = malloc(sizeof(struct edge));
    a[0] -> dest = 2;
    a[0] -> weight = 1;
    a[0] -> next = NULL;

    a[1] = NULL;

    a[2] -> dest = 1;
    a[2] -> weight = 3;
    a[2] -> next = malloc(sizeof(struct edge));
    a[2] -> next -> dest = 4;
    a[2] -> next -> weight = 6;
    a[2] -> next -> next = NULL;


    a[3] -> dest = 2;
    a[3] -> weight = 4;
    a[3] -> next = malloc(sizeof(struct edge));
    a[3] -> next -> dest = 0;
    a[3] -> next -> weight = 5;
    a[3] -> next -> next = NULL;

    a[4] -> dest = 5;
    a[4] -> weight = 10;
    a[4] -> next = NULL;

    a[5] -> dest = 6;
    a[5] -> weight = 3;
    a[5] -> next = NULL;

    a[6] = NULL;
}

int main() {
    Graph g;
    fill_test_1(g);

    Node * aux;
    for(int i = 0; i<V; i++)
        for(aux = g[i]; aux != NULL; aux=aux->next)
            printf("dest: %d | weight: %d\n", aux->dest, aux->weight);

    int weight[V], parents[V];
    for(int i = 0; i<V; weight[i]=parents[i]=-2,i++);
    printf("%d\n",dijkstra(g, 3, weight, parents));
    printf("Weight -> ");
    for(int i = 0; i<V; i++) printf("%d ",weight[i]);
    printf("\nParents -> ");
    for(int i = 0; i<V; i++) printf("%d ",parents[i]);
    printf("\n");
    return 0;
}
