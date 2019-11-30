#define NV 6
#define NE 0 // Weight of a non existent edge

typedef int GraphMat [NV] [NV];

int int main() {
    GraphMat g = {}
    GraphMat   g1=  {{NE, 2  , 7  , NE , NE , NE},
                     {NE, NE , NE , 1  , NE , NE},
                     {NE, NE , NE , NE , NE , 1},
                     {5 , NE , NE , NE , 8  , NE},
                     {3 , NE , NE , NE , NE , NE},
                     {4 , NE , NE , 3  , 2  , NE}};
    return 0;
}
