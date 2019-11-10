#include "guia0.h"

int main(int argc,char* argv[])
{
  Person john = new_person("John",19);

  printf("previous John's age %d\n",john.currentAge);
  person_change_age(&john,20);
  printf("changed john's age to %d\n",john.currentAge);

  Person jon = clone_person(&john);

  person_change_age(&jon,30);
  printf("john's age %d\n",john.currentAge);
  printf("new jon age %d\n",jon.currentAge);

  destroy_person(&jon);
  destroy_person(&john);

  return 0;
}
