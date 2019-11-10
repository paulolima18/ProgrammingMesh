#include "lists.h"

//out (removes one element)
//read (read string)
//unchain (delete list)
//putrev  (insert void in decrescent order)
//putss (insert void in correct order)
//bubbleSort
int valid(char *str)
{
  int k = -1;
  if (str[0] == '@') return 1;
  for (int i = 0;i < strlen(str)-1;i++)
  {
  //  printf("%c\n",str[i]);
    if ( (str[i] == '@') && k < 0) k = i;
    if ( (str[i] == '.') && i <= k+1) return 1;
    if ( (str[i] < 'a') || (str[i] > 'z') )
      if (str[i] != '.' && k < 0)
        return 1;
  }
  return 0;
}
int dias(void *a,void *b)
{
  /*
  struct tasks *d1 = a;
  struct tasks *d2 = b;
  int n = 0;
  if (compare(d2,d1))
      n=1;

  int arrayDias[]={31,28,31,30,31,30,31,31,30,31,30,31};
  if ( (d1->y1%4 == 0 && d1->y1%100 != 0) || (d1->y1%400 == 0 && d1->y1%100 == 0) )
    arrayDias[1]=29;

  if (((d1->y1==d2->y1) && ((d1->m1==d2->m1) || (d2->m1==d1->m1))) || ( ( (d1->m1==12 && d2->m1==1) || (d1->m1==1 && d2->m1==12) ) && ((d1->y1==d2->y1) || (d2->y1 == d1->y1++)) ))
  {
    if ((d1 -> m1==d2 -> m1) && n==1)
      return d2 -> d1 - d1 -> d1;
    if ((d1 -> m1 == d2 -> m1) && n==0)
      return d1 -> d1 - d2 -> d1;
    if (d1->m1==d2->m1++)
      return ((arrayDias[d2->m1]-d2->d1)+d1->d1);
    if (d2->m1==d1->m1++)
      return ((arrayDias[d1->m1]-d1->d1)+d2->d1);
    if (d1->m1==12 && d2->m1==1)
      return ((arrayDias[d1->m1]-d1->d1)+d2->d1);
    if (d2->m1==12 && d1->m1==1)
      return ((arrayDias[d2 -> m1]-d2 -> d1)+d1 -> d1 );
  }
  return 0;
*/
  struct tasks *d1 = a;
  struct tasks *d2 = b;
  if (d1 -> y1 == d2 -> y1)
  {
    if (d1 -> m1 == d2 -> m1)
    {
      if (d1 -> d1 != d2 -> d1)
      {
        return abs( (d1 -> d1) - (d2 -> d1) );
      }
    }
  }
  return 10;
}

void outfile(void*p)
{
  struct tasks *task = p;
  fprintf(fp,"%d\n",task->id);
  fprintf(fp,"%d\n",task->priority);
  fprintf(fp,"%d\n",task->d);
  fprintf(fp,"%d\n",task->m);
  fprintf(fp,"%d\n",task->y);
}

void bubbleSort(struct mnode *start,int (*compare)(void *,void *))
{
  struct mnode *pointer; // ponteiro para estrutura geral
  struct mnode *pointer2;
  struct mnode *fake;
	//struct tasks *ptr1; //ponteiro para estrutura especifica (neste caso task)(primeiro ptr)
  //struct tasks *ptr2; //2º ptr

  pointer = start -> next;
  pointer2 = pointer;
	/* Checking for empty list */
	if (pointer -> next == NULL)
		return;

  fake = start -> next;
  while(fake -> next != NULL)
  {
    while (pointer -> next != NULL)
	  {
      //ptr1 = pointer -> data; // pointer -> data é o mesmo que igual ptr1 ao primeiro elemento da lista de tarefas(neste caso)
      //ptr2 = pointer -> next -> data;
		  if (compare(pointer -> data,pointer -> next -> data))
		  {
			   swap(pointer, pointer -> next);
		  }
      pointer = pointer -> next;
	  }
    pointer = pointer2;
    fake = fake -> next;
  }
}

void swap(struct mnode *a, struct mnode *b)
{
  struct mnode *temp;
  temp = a -> data;
	a -> data = b -> data;
	b -> data = temp;
}

void unchain(struct mnode * list){
    struct mnode *aux;
    aux = list -> next;
    free(list);
    list = aux;
    while(list != NULL){
        aux = list -> next;
        free(list);
        list = aux;
    }
}

int todocompare(void *a, void *b)
{
  struct tasks *d1 = a;
  struct tasks *d2 = b;
  if(d1 -> priority < d2 -> priority)
    return 1;
  else if(d1 -> priority == d2 -> priority)
  {
    if (d1 -> y > d2 -> y)
        return 1;
    if (d1 -> y == d2 -> y && d1 -> m > d2 -> m)
        return 1;
    if (d1 -> y == d2 -> y && d1 -> m == d2 -> m && d1 -> d > d2 -> d)
        return 1;
  }
  return 0;
}

int allcompare(void *a, void *b)
{
  struct tasks *d1 = a;
  struct tasks *d2 = b;
  if (d1 -> y > d2 -> y)
      return 1;
  if (d1 -> y == d2 -> y && d1 -> m > d2 -> m)
      return 1;
  if (d1 -> y == d2 -> y && d1 -> m == d2 -> m && d1 -> d > d2 -> d)
      return 1;
  return 0;
}

int peoplecompare(void *a, void *b)
{
  struct tasks *d1 = a;
  struct tasks *d2 = b;
  struct mnode *test;
  struct mnode *test2;
  struct person *p;
  struct person *p2;
  if(d1 -> worker -> next != NULL)
  {
    test = d1 -> worker -> next;
    p = test -> data;
  }
  if(d2 -> worker -> next != NULL)
  {
    test2 = d2 -> worker -> next;
    p2 = test2 -> data;
  }
  int i;
  i = 0;
  do {
    if ((p->name)[i] > (p2->name)[i])
        return 1;
    else return 0;
    i++;
  } while((p->name)[i] || (p2->name)[i] != ('\n' || '\0') );
  return 0;
}

int donecompare(void *a, void *b)
{
  struct tasks *d1 = a;
  struct tasks *d2 = b;
  if (d1 -> y1 > d2 -> y1)
      return 1;
  if (d1 -> y1 == d2 -> y1 && d1 -> m1 > d2 -> m1)
      return 1;
  if (d1 -> y1 == d2 -> y1 && d1 -> m1 == d2 -> m1 && d1 -> d1 > d2 -> d1)
      return 1;
  return 0;
}

struct mnode *head(){
    struct mnode *header = malloc(sizeof(struct mnode));
    if(header == NULL)return NULL;
    header -> next = NULL;
    return header;
};

int idcomp(void *p,char *num)
{
  struct person *person = p;
  int x = atoi(num);
  if(person -> id == x)
    return 1;
  else
    return 0;
}

int idcompt(void *p,char *num)
{
  struct tasks *task = p;
  int x = atoi(num);
  if(task -> id == x)
    return 1;
  else
    return 0;
}

int emailcomp(void *p,char *email){
  struct person *person = p;
  if(strcmp(person -> email,email))
    return 0;
  else
    return 1;
}

int compare(struct mnode *list,char *str,int(*comp)(void *,char *)){
  char c[TAM];
  list = list -> next;
  strcpy(c,str);
  while(list != NULL)
  {
    if(comp(list->data,c))
      return 1;
    list = list -> next;
  }
  return 0;
}

struct mnode *find(struct mnode *list,int (*compare)(void *,char *),char*id)
{
  while(list -> next != NULL)
  {
    list = list -> next;
    if(compare(list -> data,id))
    {
      return list;
    }
  }
  return 0;
};

struct mnode *out(struct mnode *list,int (*compare)(void *,char *),char *id) { //struct mnode *out(listapessoas,strnode,10);
    struct mnode **pptr = &list;
    struct mnode *aux;
    aux = list;
    list = list -> next;
    while(list  != NULL){
        pptr = &(aux -> next);
        if(compare(list->data,id))
        {
            *pptr = list -> next;
            free(list);
            break;
        }
        aux = aux -> next;
        list = list -> next;
    }
    return 0;
};

struct mnode *putss(struct mnode * list,void *pt)
{
  struct mnode *newp = malloc(sizeof(struct mnode));
  if(newp == NULL) return NULL;
  while(list -> next != NULL)
    list = list -> next;

  newp -> prev = newp;
  newp -> data = pt;
  list -> next = newp;
  newp -> next = NULL;
  return newp;
};

void print_person(void *p)
{
  struct person *person = p;
  strtok(person->name,"\n");
  printf(magenta"\n*************%s*************\n",person->name);
  printf("E-Mail: %sID: %d \n\n",person->email,person ->id);
}

void print_taskd(void *p)
{
  struct tasks *task = p;
  printf("ID: %d \nPriority: %d \nStart Date: %d/%d/%d \nEnd Date: %d/%d/%d\nInformation: %s \n\n",task->id,task -> priority,task->d,task->m,task->y,task->d1,task->m1,task->y1,task->info);
}

void print_taskt(void *p)
{
  struct tasks *task = p;
  printf("\nID: %d \nPriority: %d \nStart Date: %d/%d/%d \nInformation: %s \n",task->id,task -> priority,task->d,task->m,task->y,task->info);
}

void print_taskf(void *p)
{
  struct tasks *task = p;
  printf("ID: %d \nPriority: %d \nStart Date: %d/%d/%d \nFinish Date: %d/%d/%d \nInformation: %s \n",task->id,task -> priority,task->d,task->m,task->y,task->d1,task->m1,task->y1,task->info);
}

void print_ptasks(void *p)
{
  struct tasks *task = p;
  if(task -> ox == 0 || task -> ox == 1)
  {
    if(task -> ox == 0)
      printf(blue"'Doing'\n");
      else
      printf(white"'Done'\n");
      printf("ID: %d \nPriority: %d \nStart Date: %d/%d/%d \nEnd Date: %d/%d/%d\nInformation: %s \n\n",task->id,task -> priority,task->d,task->m,task->y,task->d1,task->m1,task->y1,task->info);
  }
  else
  {
    printf(magenta"'To Do'\n");
    printf("ID: %d \nPriority: %d \nStart Date: %d/%d/%d \nInformation: %s \n",task->id,task -> priority,task->d,task->m,task->y,task->info);
  }
  //read(task -> worker,print_person);
}
void read(struct mnode *list,void (*imprime)(void *)){
    list = list -> next;
    while(list != NULL)
    {
      imprime(list->data);
      list = list -> next;
    }
}

/*

struct mnode *putrev(struct mnode *list,void *pt)
{
    //Top to bottom
    struct mnode *newp = malloc(sizeof(struct mnode));
    if(newp == NULL) return NULL;
    newp -> data = pt;
    newp -> next = list -> next;
    list -> next = newp;
    return newp;
};

void print_kanban(void *t,void *d,void *f)
{
  if(t != NULL)
  {
    struct tasks *tasktodo = t;
    printf(cyan"'To Do' operation %s\n",tasktodo -> info);
  }
  if(d != NULL)
  {
    struct tasks *taskdoing = d;
    printf(cyan"'Doing' operation %s\n",taskdoing -> info);
  }
  if(f != NULL)
  {
    struct tasks *taskdone = f;
    printf(cyan"'Done' operation %s\n",taskdone -> info);
  }
}

void read_kanban(struct mnode *list,struct mnode *list1,struct mnode *list2,void (*imprime)(void *,void *,void *)){

    while(list -> next != NULL || list1 -> next != NULL || list2 -> next != NULL)
    {
      if(list -> next != NULL)
        list = list -> next;
      if(list1 -> next != NULL)
        list1 = list1 -> next;
      if(list2 -> next!= NULL)
        list2 = list2 -> next;
      imprime(list->data,list1->data,list2->data);
    }
}
*/

//Criar funcções de comparações de tipo
/*
int main(){
    struct mnode *listgeral = head();
    struct mnode *todo = head();
    struct mnode *doing = head();
    struct mnode *done = head();
    struct mnode *worker = head();//malloc por cada nova pessoa
    //struct tasks *task = head();
    for(int i = 0;i<5;i++){
      struct person *work = malloc(sizeof(struct person));
      strcpy(work -> name,"Guy Homem");
      strcpy(work -> email,"guyfakemail@gmail->com");
      scanf("%d",&work->id);
      putss(worker, work);
    }
  read(worker,print_person);*/
    /*
    struct  person *worker2 = malloc (sizeof(struct person));
    strcpy(worker2 -> name,"Arkadi Lenon");
    strcpy(worker2 -> email,"otherfakemail@hotmail->com");
    worker2 -> id = 12391223;
    putss(listapessoas, worker2);

    struct  person *worker3 = malloc (sizeof(struct person));
    strcpy(worker3 -> name,"John");
    strcpy(worker3 -> email,"johntopnochmail@hulu->us");
    worker3 -> id = 18749813;
    putss(listapessoas,worker3);

    //out(listapessoas,stnode,30);

    task -> id = 1;
    task -> priority = 8;
    task -> d = 13;
    task -> m = 5;
    task -> y = 2018;

    strcpy(task -> info,"Make a burguer");
    task -> d1 = 20;
    task -> m1 = 5;
    task -> y1 = 2018;
    task -> worker = worker2;
    putss(listatarefas,task);
    */
    //read(listatarefas,print_task);
/*
struct node *invputin(struct node *list,int val){
    //bottom to Top
    struct node *newp = malloc(sizeof(struct node));
    if(newp == NULL) return NULL;
    while(list -> prox != NULL){
        list = list -> prox;
    }
    newp -> a = val;
    list -> prox = newp;
    newp -> prox = NULL;
    return newp;
};
*/


/*
struct node *out(struct node *list,int val){
    struct node **pptr = &list;
    struct node *aux;
    aux = list;
    list = list -> prox;
    while(list  != NULL){
        pptr = &(aux -> prox);
        if(list -> a == val){
            *pptr = list -> prox;
            free(list);
            break;
        }
        aux = aux -> prox;
        list = list -> prox;
    }
};

struct node *outst(struct node *list,char name[TAM]){ //void function of comparing(começar a fazer funções de comparação)
  struct node **pptr = &list;
  struct node *aux;
  aux = list;
  list = list -> prox;

  while(list  != NULL){

      pptr = &(aux -> prox);
      if(strcmp(list -> name,name) == 0){
          *pptr = list -> prox;
          free(list);
          break;
      }
      aux = aux -> prox;
      list = list -> prox;
  }
};*/
