#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct s {
    char *sins;
    struct s *next;
} Sin;

typedef struct p {
    char *word;
    Sin *sins;
    struct p *next;
} Pal;

typedef Pal *Dic[SIZE];

int hash(char *word) {
    return 0;
}

void synonym(Dic d, char* word) {
    int i, count=0;
    for(i= hash(word); count<SIZE; i=(i+1)%SIZE,count++)
        if(strcmp(d[i] -> word, word) == 0)
            break;

    if(count == SIZE) printf("NOT FOUND\n");

    Sin *aux;
    printf("The synonyms of: \'%s\', are...\n", word);
    for(aux=(d[i] -> sins); aux != NULL;aux=aux->next)
        printf("-> %s\n",aux->sins);
}

int main() {
    Dic d;
    d[0] = malloc(sizeof(Pal));
    Sin *good = malloc(sizeof(struct s)*2);
    good->sins =malloc(sizeof(char)*20);
    sprintf(good->sins, "prosperity");
    good->next = malloc(sizeof(struct s));
    good->next->sins =malloc(sizeof(char)*20);
    sprintf(good->next->sins , "welfare");

    d[0] -> word = malloc(sizeof(char)*20);
    d[0] -> sins = good;
    sprintf(d[0] -> word, "good");

    synonym(d, "good");
    return 0;
}
