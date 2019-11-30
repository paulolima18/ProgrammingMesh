#include <stdlib.h>
#include <stdio.h>
#include "../help.h"

#define V 7

/* Compile with: gcc -o graph graph.c ../help.c */

typedef struct a {
    int dest;
    struct a *next;
}*List;

typedef List Graph[V];
/*  (V,E)
    V -> Amount of [List] in array [Graph];
    E -> Amount of not null in a certain [List];
*/
void bubbleDown(int h[], int N) { // remove element from heap
    int i,p;
    i = 0; p = (2*i)+2;
    while(p < N) {
        if(h[p-1] < h[p]) p--;
        if(h[i] <= h[p]) break;
        swap(h,i,p);
        i = p; p = (2*i)+2;
    }
    p = (2*i) +1;
    if(p < N && h[i] > h[p]) swap(h, i , p);
}

void bubbleUp(int h[], int N, int x) { // add element to heap
    int i,p;
    h[N] = x;
    i = N; p = (i-1)/2;
    while(i > 0 && h[i] < h[p])  {
        swap(h,i,p);
        i = p; p = (i-1)/2;
    }
}

void heapSort(int v[], int N) {
    int i;

    for(i = 1; i< N; i++)
        bubbleUp(v,i,v[i]);

    for(i = N-1; i > 0; i--) {
        swap(v,0,i);
        bubbleDown(v,i);
    }
}

/* edge: Check if an adjacent path between origin and destination exists */
int edge(Graph g, int origin, int dest) {
    List node = g[origin];
    while(node != NULL && node -> dest != dest) node = node->next;
    return (node -> dest == dest);
}

/*  OutDegree: Calculates the amount of adjacent nodes starting from a certain origin node
    Example:    C <-- A --> B (Orientation out)
                outD(g=ex, origin=A) = 2;
    Complexity: T(V,E) = O(V)
                worst case: V
*/
int outD(Graph g,int origin) {
    List node;
    int r = 0;
    for(node = g[origin]; node != NULL; node = node -> next) r++;
    return r;
}


/*  InDegree: Calculates the amount of adjacent nodes going into a certain origin node
    Example:    C --> A <-- B (Orientation in)
                inD(g=ex, origin=A) = 2;
    Complexity: T(V,E) = 0(V+E)
                worst case: V+E
*/
int inD(Graph g,int origin) {
    int i,r=0;
    List node;
    for (i = 0; i < V; i++) {
        for(node = g[i]; node != NULL && node->dest != origin; node = node -> next);
        if(node -> dest == origin) r++;
    }
    return r;
}

/* Graph In Degree: calculates the biggest InDegree in a graph */
int graph_inD(Graph g) {
    int a[7],i;
    List node;
    for(i=0;i<V;i++) a[i]=0;
    for(i=0;i<V;i++)
        for(node = g[i];node != NULL;node = node->next)
            a[node->dest]++;
    heapSort(a,V);
    return a[0];
}

/* Search Aux: */
int search_aux(Graph g, int origin, int destination, int visited[]){
    int r = 0;
    List x;
    if(origin == destination) r = 1;
    for(x = g[origin]; x != NULL && !r; x = x -> next)
        if(visited[x->dest] == 0) {
            visited[x->dest] = 1;
            if(search_aux(g,x->dest,destination,visited))
                r = 1;
        }
    return r;
}

/* Search Depth First:  Find a path between the origin node and the destination node
                        returns -> 0 if path doesn't exist
                                -> 1 else
*/
int searchDF(Graph g, int origin, int destination) {
    int visited[V],i;
    for(i = 0; i < V; visited[i++] = 0);
    visited[origin] = 1;
    return search_aux(g, origin, destination, visited);
}

/* Count Aux: Sum the amount o nodes reachable and returns to count_graph */
int count_aux(Graph g, int o, int visited[]) {
    List x;
    int r = 0;
    visited[o] = 1;
    for(x = g[o]; x != NULL; x=x->next)
        if(visited[x->dest] == 0)
            r = r + 1 + count_aux(g, x->dest, visited);
    return r;
}

/* Count Graph: Returns the amount of nodes that a given origin node can reach
        Complexity: Tcount_graph(V,E) = Tcount_aux(V,E)
*/
int count_graph(Graph g, int origin) {
    int visited[V], i;
    for(i=0; i<V; visited[i++]=0);
    return count_aux(g, origin, visited);
}

/* Path Depth First:  */
int pathDF(Graph g, int origin, int visited[], int parents[]) {

}

/* Path Breadth First:  */
int pathBF(Graph g, int origin, int visited[], int parents[]) {
    int q[V], start, end, i, x, r = 0;
    List aux;
    for(i = 0; i<V; visited[i]=0,parents[i++]=-1);
    start = end = 0;
    q[end++] = origin;
    while(start != end) {
        r++;
        x = q[start++];
        visited[x] = 1;
        for(aux = g[x]; aux!=NULL; aux=aux->next) {
            if(visited[aux->dest] == 0) {
                q[end++] = aux->dest;
                parents[aux->dest] = x;
            }
        }
    }
    return r;
}

int main() {
    /* Graph Creation */
    Graph a;
    List aux;
    int i;
    for(i=0;i<V;i++) a[i] = malloc(sizeof(List));
    a[0] -> dest = 2;
    a[0] -> next = NULL;

    a[1] -> dest = 0;
    a[1] -> next = NULL;

    a[2] -> dest = 1;
    a[2] -> next = NULL;

    a[3] -> dest = 2;
    a[3] -> next = malloc(sizeof(List));
    a[3] -> next -> dest = 0;
    a[3] -> next -> next = NULL;

    a[4] -> dest = 5;
    a[4] -> next = NULL;

    a[5] = NULL;

    a[6] = NULL;
    /* -------- */
    printf("%d\n",graph_inD(a));
    printf("Is there a path between 0 and 4? %d\n",searchDF(a, 0, 1));
    printf("Reachable nodes through 0? %d\n",count_graph(a, 0));
    return 0;
}
