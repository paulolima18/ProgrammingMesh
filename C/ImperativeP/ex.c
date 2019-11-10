#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//PARTE A

typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

//1
char *mystrcpy(char *dest, char source[])
{
  int i;
  dest = malloc(sizeof(char*));
  for(i=0; source[i]; i++)
  {
    dest[i] = source[i];
  }
  dest[i] = '\0';
  return dest;
}

//2
int isVowel(char s)
{
  s = toupper(s);
  if(s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') return 0;
  return 1;
}

void strnoV(char s[])
{
  int i,j=0;
  char* new = malloc(sizeof(char*));

  for(i=0; s[i]; i++)
  {
    if(isVowel(s[i]) == 1)
    {
      new[j] = s[i];
      j++;
    }
  }
  new[i] = '\0';
  strcpy(s,new);
}

ABin newABin (int no, ABin e, ABin d)
{
	ABin new = malloc (sizeof (struct nodo));

	if (new!=NULL){
    new->valor = no;
		new->esq  = e;
		new->dir  = d;
	}
	return new;
}

void pint(ABin a)
{
  if(a != NULL)
    printf("%d\n",a->valor);
  if(a -> esq != NULL)
  {
    printf("ESQ: ");
    pint(a->esq);
  }
  if(a -> dir != NULL)
  {
    printf("DIR: ");
    pint(a->dir);
  }
}

//3
int dumpAbin(ABin a, int v[], int N)
{
  int i, r=0;

  dumpAbin(a->esq, v, N);

  v[]

  dumpAbin(a->dir, v, N);

  return r;
}

//4
int lookupAB(ABin a, int x)
{
  while(a != NULL)
  {
    if(x < a->valor) a = a->esq;
    else if(x > a -> valor) a = a->dir;
    else return 0;
  }
  return 1;
}

//PARTE B

typedef struct listaP {
  char *pal;
  int cont;
  struct listaP *prox;
} Nodo, *Hist;

//1
int inc(Hist *h, char *pal)
{
  while(*h)
  {
    if(strcmp((*h)->pal,pal)==0) {
      ++((*h)->cont);
      return (*h)->cont;
    }
    else if(strcmp((*h)->pal,pal)>0) {
      Hist new = malloc(sizeof(struct listaP));
      Hist aux = malloc(sizeof(struct listaP));
      aux = (*h)->prox;
      strcpy(new->pal, pal);
      new->cont = 1;
      new->prox = aux;
      (*h) = new;
    }
    (*h) = (*h)->prox;
  }
  return 0;
}

//2

int main()
{
  char *f;
  f = mystrcpy(f,"abcda");
  for(int i=0;f[i];i++) printf("%c ",f[i]);
  printf("\n");

  strnoV(f);
  for(int i=0;f[i];i++) printf("%c ",f[i]);
  printf("\n");

  ABin a = malloc(sizeof(ABin));
  a = newABin(3,NULL,NULL); a = newABin(8,a,NULL); a = newABin(2,NULL,a);
  pint(a);
  printf("%d\n",lookupAB(a,2));
  return 0;
}
