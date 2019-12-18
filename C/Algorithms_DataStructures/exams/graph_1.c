#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 * A -- Defining data structures.
 *******************************************************************************/
#define RED 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3
#define EMPTY_STATION -1
#define V 10

typedef struct road {
    int dest, road_color;
    char station_name[40], dest_name[40];
    struct road * next;
} Node, *Graph[V];

char * colorToString(int color);

/*******************************************************************************
 * B -- Defining functions.
 *******************************************************************************/

void init(Graph g) {
    int i;
    for(i=0;i<V;i++) g[i] = NULL;
}

void insert(Graph g, char station_name[]) {
    int i=0;
    while(g[i] != NULL && i < V) i++;
    if(i < V) {
        g[i] = malloc(sizeof(struct road));
        sprintf(g[i] -> station_name, station_name);
        g[i] -> dest = EMPTY_STATION;
        g[i] -> next = NULL;
    }
}

void addTrip(Graph g, int station_x, int station_y, int road_color) {
    int i;
    struct road * aux, *t;
    for (i = 0; i < V; i++) {
        if(station_x == i || station_y == i) {
            t = malloc(sizeof(struct road));
            t -> road_color = road_color;
            t -> dest = (station_x == i ? station_y : station_x);
            sprintf(t -> station_name, g[i] -> station_name);

            if(g[i]->dest == EMPTY_STATION) {
                sprintf(t -> dest_name, g[t -> dest] -> station_name);
                t -> next = NULL;
            }
            else {
                sprintf(t -> dest_name, g[t -> dest] -> station_name);
                t -> next = g[i];
            }

            g[i] = t;
        }
    }
}

/*******************************************************************************
 * C -- Lines/Roads that lead to a certain station.
 *******************************************************************************/

void roadToStation(Graph g, int station) {
    struct road * aux;
    for(aux = g[station]; aux!= NULL; aux = aux->next)
        printf("%s\n",colorToString(aux->road_color));
}

/*******************************************************************************
 * D -- Find path bettwen two stations, given a certain line/road.
 *******************************************************************************/

int isPath_R(Graph g, int origin, int dest, int visisted[], int road_color) {
    int r = 0;
    struct road * aux;
    visisted[origin] = 1;

    if(origin == dest && g[origin] -> road_color == road_color)
        r = 1;

    for(aux = g[origin]; r == 0 && aux!=NULL; aux=aux->next)
        if(visisted[aux->dest] == 0)
            r = isPath_R(g, aux->dest, dest, visisted, road_color);

    return r;
}

int isPath(Graph g, int station_x, int station_y, int road_color) {
    int visisted[V], i;
    for(i=0;i<V;visisted[i++]=0);
    return isPath_R(g, station_x, station_y, visisted, road_color);
}

int main() {
    Graph g;
    struct road * aux;
    init(g);
    insert(g, "Santa Apolonia"); // 0
    insert(g, "Rossio"); // 1
    insert(g, "Faro"); // 2
    addTrip(g, 0, 1, RED);
    addTrip(g, 1, 2, YELLOW);
    addTrip(g, 0, 2, GREEN);
    roadToStation(g, 0);
    int i,used=3;
    for(i=0;i<used;i++)
        for(aux=g[i];aux!=NULL ;aux=aux->next)
            printf("Station: %s ; Destination: %s ; Road: %s .\n", aux->station_name, aux->dest_name, colorToString(aux->road_color));
    return 0;
}

/*******************************************************************************
 * Auxiliar functions.
 *******************************************************************************/

char * colorToString(int color) {
    char * color_str = malloc(sizeof(char)*40);
    switch (color) {
        case RED:
            sprintf(color_str, "RED");
            break;
        case YELLOW:
            sprintf(color_str, "YELLOW");
            break;
        case BLUE:
            sprintf(color_str, "BLUE");
            break;
        case GREEN:
            sprintf(color_str, "GREEN");
            break;
    }
    return color_str;
}
