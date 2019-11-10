#ifndef LISTS_H_
#define LISTS_H_
#define TAM 30
#define red      "\x1B[31m"
#define green    "\x1B[32m"
#define yellow   "\x1B[33m"
#define blue     "\x1B[34m"
#define magenta  "\x1B[35m"
#define cyan     "\x1B[36m"
#define white    "\x1B[37m"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
FILE  *fp;

/*
struct tm
{
   int tm_sec;            Seconds. [0-60] (1 leap second)
   int tm_min;            Minutes. [0-59]
   int tm_hour;           Hours.   [0-23]
   int tm_mday;           Day.     [1-31]
   int tm_mon;            Month.   [0-11]
   int tm_year;           Year - 1900.
   int tm_wday;           Day of week. [0-6]
   int tm_yday;           Days in year.[0-365]
   int tm_isdst;          DST.     [-1/0/1]
}*/

struct mnode{
    void *data; // tipo de dados genericos que pode apontar por exemplo para tasks
    struct mnode *next,*prev;
};

struct person{
    int id;
    char name[TAM];
    char email[TAM];
    //struct tasks *task;
    struct mnode *tasks;
};

// definir ListaLigadaDeTasks

struct tasks{
    int id;
    int priority;
    int d,m,y; //date of
    int ox;
    char info[TAM];
    struct mnode *worker;
    int d1,m1,y1; //prazo de conclusão ou data de conclusão(char d1,m1,y1)
};

void outfile(void*p);

int valid(char *str);

int allcompare(void *a, void *b);

int donecompare(void *a, void *b);

int peoplecompare(void *a, void *b);

int todocompare(void *a, void *b);

void print_ptasks(void *p);

void print_taskf(void *p);

void swap(struct mnode *a, struct mnode *b);

void bubbleSort(struct mnode *start,int (*compare)(void *,void *));

void read(struct mnode *list,void (*imprime)(void *));

void unchain(struct mnode * list);

void print_taskt(void *p); ///test func

void print_taskd(void *p); ///test func

void print_person(void *p); /// test func

int idcomp(void *p,char *num);

int idcompt(void *p,char *num);

int dias(void *a,void *b);

int emailcomp(void *p,char *email);

int compare(struct mnode *list,char *str,int(*comp)(void *,char *));

struct mnode *head();

struct mnode *find(struct mnode *list,int (*compare)(void *,char *),char*id);

struct mnode *putss(struct mnode *list,void *pt);

struct mnode *out(struct mnode *list,int (*compare)(void *,char *),char *id);

#endif
