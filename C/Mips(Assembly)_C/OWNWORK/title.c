#include "title.h"
#include <stdio.h>
#include <stdlib.h>

void title(void){
  printf("------------------------------------------------\n");
  for(int i = 0;i<20;i++){
    if(i == 10){
      printf("|KANBAN|");
    }
    else printf("||");
  }
  printf("\n------------------------------------------------\n");
}
