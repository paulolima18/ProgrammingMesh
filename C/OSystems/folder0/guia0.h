#ifndef GUIA0_H_
#define GUIA0_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
  char *name;
  int currentAge;
}Person;

Person new_person(char *name, int age);
Person clone_person(Person *p);
void destroy_person(Person *p);
int person_age(Person *p);
void person_change_age(Person *p, int age);

#endif
