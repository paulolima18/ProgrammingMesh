/* gcc -o out weighted_graph.c help.c */
#include <stdio.h>
#include <stdlib.h>
#include "../help.h"

#define FRINGE 1
#define NOT_VISITED 0
#define VISITED 2
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


/* sizeCC_recursive: Auxiliar function to sizeCC */
int sizeCC_recursive(Graph g, int x, int visited[]) {
    int r=1;
    struct edge * aux;
    visited[x] = 1;
    for(aux=g[x]; aux!=NULL; aux=aux->next)
        if(visited[aux->dest] == 0)
            r += sizeCC_recursive(g, aux->dest, visited);
    return r;
}

/* sizeCC: Gives the size of a connected component with a certain node */
int sizeCC(Graph g, int x) {
    int visited[V], i;
    for(i=0; i<V; visited[i++]=0);
    return sizeCC_recursive(g, x, visited);
}

/* maxCC: Connected component with the biggest size
    Complexity: always T(N) = V+E
*/
int maxCC(Graph g) {
    int visited[V], i, val, r=0;
    for(i=0; i<V; visited[i++]=0);
    for(i=0;i<V;i++)
        if(visited[i]==0)
            if(r < (val=sizeCC_recursive(g, i, visited)))
                r = val;
    return r;
}

/* number_of_CC: Returns the amount of connected components in a graph */
int number_of_CC(Graph g) {
    int visited[V], i, r=0;
    for(i=0; i<V; visited[i++]=0);
    for(i=0;i<V;i++)
        if(visited[i]==0) {
            sizeCC_recursive(g, i, visited);
            r++;
        }
    return r;
}

int cc_recursive(Graph g, int i, int c[], int label) {
    c[i] = label;
    struct edge * aux;
    for(aux=g[i]; aux!=NULL; aux=aux->next)
        if(c[aux->dest] == -1)
            cc_recursive(g, aux->dest, c, label);
}

/* cc: Returns the amount of connected components and fills the given array
        with a label for its components */
int cc(Graph g, int c[]) {
    int i, r=0;
    for(i=0; i<V; c[i++]=-1);
    for(i=0;i<V;i++)
        if(c[i]==-1)
            cc_recursive(g, i, c, r++);
    return r;
}

/* distance: Give the distance between two nodes, if path doesn't exist, returns -1 */
int distance(Graph g, int x, int y) {
    int queue[V], visited[V], dist[V], start, end, i, t, r = -1;
    struct edge * aux;
    for(i=0; i<V; visited[i++]=0);
    start=end=0;
    dist[x]=0;
    visited[x]=1;
    queue[end++]=x;
    while(start != end && r == -1) {
        t = queue[start++];
        if(t==y) r = dist[t];
        for(aux=g[t]; aux!=NULL; aux=aux->next)
            if(visited[aux->dest]==0) {
                queue[start++] = aux->dest;
                visited[aux->dest] = 1;
                dist[aux->dest] = dist[t] +1;
            }
    }
    return r;
}


int connected_R(Graph g, int origin, int destination, int min_weight, int visited[]) {
    int r = 0;
    struct edge * aux;
    visited[origin] = 1;
    if(origin == destination) r = 1;

    if(r == 0)
        for(aux = g[origin]; aux!=NULL && !r; aux=aux->next)
            if(aux->weight > min_weight && visited[aux->dest] == 0)
                r += connected_R(g, aux->dest, destination, min_weight, visited);
    return r;
}

int connected(Graph g, int origin, int destination, int min_weight) {
    int visited[V], i;
    for(i = 0; i<V; visited[i++] = 0);
    return connected_R(g, origin, destination, min_weight, visited);
}

void reachable_R(Graph g, int o, int visited[]) {
    struct edge * aux;
    visited[o] = 1;
    for(aux = g[o]; aux!=NULL; aux=aux->next) {
        if(visited[aux->dest] == 0)
            reachable_R(g, aux->dest, visited);
    }
}

int reachable(Graph g, int o) {
    int visited[V], i, r = -1;
    for(i = 0; i<V; visited[i++] = 0);
    reachable_R(g, o, visited);
    for(i = 0; i<V && r == -1; i++)
        if(visited[i] == 0)
            r = i;
    return r;
}

/* Find Shortest paths */
int dijkstraSP(Graph g, int origin, int weight[], int parents[]) {
    int color[V], i, fringe_size, x, r=0;
    for(i=0; i<V; color[i++]=NOT_VISITED);
    struct edge *aux;
    // insert "origin" in fringe [MISSING]
    color[origin] = FRINGE;
    weight[origin] = 0;
    /*  no parents if value "-1"
    *   origin -> origin */
    parents[origin] = -1;
    fringe_size = 1;
    while(fringe_size > 0) {
        // x <- element with smallest weight in fringe [MISSING]
        // remove x from fringe [MISSING]
        fringe_size--;
        color[x] = VISITED;
        for(aux = g[x]; aux != NULL; aux=aux->next)
            if(color[aux->dest] == 0) {
                if(color[aux->dest] == NOT_VISITED) {
                    weight[aux->dest] = weight[x]+aux->weight;
                    // add aux->dest to fringe [MISSING]
                    parents[aux->dest] = x;
                    color[aux->dest] = FRINGE;
                }
                else if(color[aux->dest] == FRINGE && weight[x]+aux->weight < weight[aux->dest]) {
                    weight[aux->dest] = weight[x]+aux->weight;
                    parents[aux->dest] = x;
                    // update aux->dest to fringe [MISSING]
                }
            }
    }
    for(i = 1; i<V; i++)
        if(weight[i] > weight[r])
            r = i;
    return r;
}

/* returns the node furthest from given node "x"
    (within the shortest path to that node "x")
*/
int furthest(Graph g, int x, int path[]) {
    int weight[V], parents[V], max, i, r;
    dijkstraSP(g, x, weight, parents);
    max = 0;
    for(i = 1; i<V; i++)
        if(weight[i] > weight[max])
            max = i;
    i = 0; path[i] = max; r = max;
    while (max != x) {
        max = parents[max];
        i++;
        path[i] = max;
    }
    max = 0;
    while(max != i)
        swap(path, max++, i--);
    return r;
}

/*  Topologic Sorting:
    Returns the number of elements in the array and fills the given array
*/
int topSort(Graph g, int sort[]) {
    int entry[V], queue[V], i, start, end, r = 0;
    struct edge * aux;
    for(i=0; i<V; entry[i++] = 0);
    for(i=0; i<V; i++)
        for(aux = g[i]; aux!= NULL; aux=aux->next)
            entry[aux->dest]++;

    for(i=0; i<V; i++)
        if(entry[i]==0)
            queue[end++]=i;

    while(start < end) {
        i = queue[start++];
        sort[r++] = i;
        for(aux = g[i]; aux!= NULL; aux=aux->next) {
            // x -> (aux->dest)
            entry[aux->dest]--;
            if(entry[aux->dest]==0)
                queue[end++] = aux->dest;
        }
    }
    return r;
}

/* Longest: returns the cost of the longest path in a given graph */
int longest(Graph g) {
    int sort[V], longer[V], i, v;
    struct edge * aux;
    topSort(g, sort);
    for(i=0; i<V; longer[i++] = 0);
    for(i=0; i<V; i++) {
        v = sort[i];
        for(aux = g[i]; aux!= NULL; aux=aux->next) // v -> (aux->dest)
            if (longer[aux->dest] < longer[v] + aux->weight)
                longer[aux->dest] = longer[v] + aux->weight;
    }
    v=0;
    for(i=1; i<V; i++)
        if(longer[v] < longer[i])
            v = i;
    return v;
}

void fill_test_1(Graph a) {
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
}
void fill_test_2(Graph a) {
    struct edge *aux;
    int i;
    for(i=0;i<V;i++) a[i] = malloc(sizeof(struct edge));
    a[0] -> dest = 2;
    a[0] -> weight = 1;
    a[0] -> next = NULL;

    a[1] = NULL;

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
}
int main() {
    /* Graph Creation */
    Graph a;
    fill_test_1(a);
    int i;
    /*struct edge *aux;
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

    a[6] = NULL;*/

    /* -------- */
    int biggest = maxCap(a);
    printf("Capacity in %d is: %d\n", biggest,capacity(a, biggest));
    for(i = 0;i<V;i++)
        printf("Capacity Normal in %d is: %d\n", i, capacity(a, i));
    printf("Connected? %d\n",connected(a, 4, 5, 9));
    printf("Not reachable? %d\n",reachable(a, 0));

    Graph b;
    fill_test_2(b);
    printf("This is the Topologic Order: ");
    int sort[V];
    topSort(b, sort);
    for(i = 0;i<V;i++)
        printf(" %d ", sort[i]);
    printf("\n");
    return 0;
}
