#include "guia0.h"

Person new_person(char *name, int age)
{
  size_t n = strlen(name)+1;
  char* s = malloc(sizeof(char[n]));
  memcpy(s,name,n);
  //char* s = strdup(name);
  //-----
  /*
  return (Person)
  {
    .currentAge = age,
    .name = name,
  };
  */
  Person p;
  p.currentAge = age;
  p.name = s;
  return p;
}

Person clone_person(Person *p)
{
  Person q;
  q.currentAge = p -> currentAge;
  q.name = strdup(p -> name);
  return q;
}

void destroy_person(Person *p)
{
  free(p->name);
}

int person_age(Person *p)
{
  return (p -> currentAge);
}

void person_change_age(Person *p, int age)
{
  p -> currentAge = age;
}
