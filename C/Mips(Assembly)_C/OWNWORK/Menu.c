#include "lists.h"
#include "title.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
  int a;
  int limit;//
  int eva = 1,x = 1;
  int arrayDias[]={31,28,31,30,31,30,31,31,30,31,30,31};

  char str[TAM];
  //---------------------------------------------------------------------------
  struct mnode *alltasks = head(); // alltasks
  struct mnode *todo = head();
  struct mnode *doing = head();
  struct mnode *done = head();
  struct mnode *worker = head();
  //struct mnode *pointertasks = head();
  //---------------------------------------------------------------------------

  time_t now = time(0);
  struct tm *data = localtime(&now);
  title(); //Imprime o Titulo KANBAN

  //Maximo de tarefas(setup inicial)
  printf("What is the maximum number of tasks for each individual?\n");
  fgets(str,TAM,stdin);
  limit = atoi(str);
/*
  fp = fopen("pessoas.txt","w");
  fprintf(fp,"Name");
  fprintf(fp,"Other name\n");
  fclose(fp);
  fp = fopen("pessoas.txt","r");
  char loles[20];
  char loles2[20];
  fgets(loles2,sizeof(loles2),fp);
  fgets(loles,sizeof(loles),fp);
  printf("%s%s\n",loles2,loles);
  fclose(fp);
*/
  fp = fopen("pessoas.txt","r");
  while(1)
  {
    struct person *work = malloc(sizeof(struct person));
    //str[strlen(str) - 1] = '\0';
    if(fgets(str,sizeof(str),fp) == NULL) break;
    work -> id = atoi(str);
    fgets(work -> name,TAM,fp);

    fgets(str,sizeof(str),fp);
    x = atoi(str);
    while( x != 0)
    {
      fgets(str,sizeof(str),fp);
      x = atoi(str);
    }
    //fgets(work -> email,TAM,fp);
    strcpy(work -> email,str);
    work -> tasks = head();
    putss(worker, work);
  }
  fclose(fp);
  fp = fopen("tarefas.txt","r");
  do
  {
    struct tasks *task = malloc(sizeof(struct tasks));
    str[strlen(str) - 1] = '\0';
    if(fgets(str,sizeof(str),fp) == NULL) break;
    x = atoi(str);
    if(x == -1 || x == -2 || x == -3)
    {
      task -> worker = head();
      fgets(str,sizeof(str),fp);
      task -> id = atoi(str);
      fgets(str,sizeof(str),fp);
      task -> priority = atoi(str);
      fgets(str,sizeof(str),fp);
      task -> d = atoi(str);
      fgets(str,sizeof(str),fp);
      task -> m = atoi(str);
      fgets(str,sizeof(str),fp);
      task -> y = atoi(str);
      if(x == -2 || x == -3)
      {
        fgets(str,sizeof(str),fp);
        task -> d1 = atoi(str);
        fgets(str,sizeof(str),fp);
        task -> m1 = atoi(str);
        fgets(str,sizeof(str),fp);
        task -> y1 = atoi(str);
        fgets(task->info,TAM,fp);
        if(x == -2)
        {
          task -> ox = 0;
          putss(doing, task);
          putss(alltasks,task);
        }
        else
        {
          task -> ox = 1;
          putss(done, task);
          putss(alltasks,task);
        }
      }
      else
      {
        fgets(task->info,TAM,fp);
        putss(todo, task);
        putss(alltasks,task);
      }
    }
  }while(1);
    fclose(fp);
  struct mnode *ptr;
  struct person *person;
  struct tasks *task;
  fp = fopen("pessoas.txt","r");
  do
  {
    ptr = worker -> next;
    person = ptr -> data;
    if(fgets(str,sizeof(str),fp) == NULL) break;
    a = atoi(str);
    while(person -> id != a)
    {
      ptr = ptr -> next;
      person = ptr -> data;
    }
    fgets(str,sizeof(str),fp);
    fgets(str,sizeof(str),fp);
    while(atoi(str) != 0)
    {
      ptr = doing;
      while(ptr -> next != NULL)
      {
        ptr = ptr -> next;
        task = ptr -> data;
        if(task-> id == atoi(str))
        {
          putss(task->worker,person);
          putss(person->tasks,task);
          fgets(str,sizeof(str),fp);
        }
      }
      ptr = done;
      while(ptr -> next != NULL)
      {
        ptr = ptr -> next;
        task = ptr -> data;
        if(task-> id == atoi(str))
        {
          putss(task->worker,person);
          putss(person->tasks,task);
          fgets(str,sizeof(str),fp);
        }
      }
    }
  }while(1);
  fclose(fp);
  bubbleSort(doing,peoplecompare);
  while(eva){
    printf(green"\nPress 1 to add person[Name/E-mail/ID] \nPress 2 to redefine the maximum number of tasks per person\nPress 3 to insert a new task in 'To Do'\nPress 4 to see all people\n");
    printf("Press 5 to pass from 'to do' to 'doing' \nPress 6 to pass from 'doing' to 'to do'\nPress 7 to change person responsible for a task in doing\n");
    printf("Press 8 to send  from 'Doing to 'Done' \nPress 9 to send from 'Done' to 'To do' \nPress 10 to see all tasks of one person\n");
    printf("Press 11 to see KANBAN \nPress 12 to save\nPress 13 to see all tasks\nPress other to exit\n");

    printf("\nSelect an option:" );
    fgets(str,TAM,stdin);
    a = atoi(str);

    switch(a){
      case 1:
      {
        struct person *work = malloc(sizeof(struct person));
        printf("Put Name :");
        fgets(str,TAM,stdin);

        //fp = fopen("pessoas.txt","a");
        //fprintf(fp,"%s",str);

        str[strlen(str) - 1] = '\0';
        strcpy(work -> name,str);
        x = 1;
        work -> tasks = head();
        while(x)
        {
          do
          {
            printf("Put Email :");
            fgets(str,TAM,stdin);
          }while(valid(str));

          strcpy(work -> email,str);
          if(compare(worker,work->email,emailcomp))
            continue;
          else
            x = 0;
        }
        x = 1;
        while(x)
        {
          printf("Put ID:");
          fgets(str,TAM,stdin);
          if(atoi(str) == 0)continue;
          if(compare(worker,str,idcomp))
            continue;
          else
          {
            work -> id = atoi(str);
            x = 0;
          }
        }
        //fprintf(fp,"%s\n",work->email);
        //fprintf(fp,"%d\n",work->id);

        //fclose(fp);
        putss(worker, work);
        /*fp = fopen("pessoas.txt","r");
        char loles[20];
        char loles2[20];

        fgets(loles2,sizeof(loles2),fp);
        fgets(loles,sizeof(loles),fp);
        a = atoi(loles);
        printf("%s %d\n",loles2,a);
        fclose(fp);*/
        break;
      }
      case 2:
        printf("What is the maximum number of tasks for each individual? ");
        fgets(str,TAM,stdin);
        limit = atoi(str);
        break;
      case 3:
      {
        struct tasks *task = malloc(sizeof(struct tasks));

        printf("Task information:");
        fgets(str,TAM,stdin);
        strcpy(task -> info,str);

        task -> y = data -> tm_year + 1900;
        task -> m = data -> tm_mon +1;
        task -> d = data -> tm_mday;
        do
        {
          printf("Put task priority:");
          fgets(str,TAM,stdin);
          task -> priority = atoi(str);
        }while(task -> priority > 10 || task -> priority < 1);

        x = 1;
        while(x)
        {
          printf("Put ID:");
          fgets(str,TAM,stdin);
          if(atoi(str) == 0)continue;
          if(compare(todo,str,idcompt) == 1 || compare(doing,str,idcompt) == 1 || compare(done,str,idcompt) == 1)
            continue;
          else
          {
            task -> id = atoi(str);
            x = 0;
          }
        }
        task -> ox = -1;
        task -> worker = head();
        putss(todo,task);
        putss(alltasks,task);
        bubbleSort(todo,todocompare);
        bubbleSort(alltasks,allcompare);
        break;
      }
      case 4:
      {
        read(worker,print_person);
      }
        break;
      case 5:
      {
        printf("Action TODO PARA DOING\n");
        struct tasks *task;// = malloc(sizeof(struct tasks));
        //struct mnode *fake;//malloc(sizeof(struct mnode));
        struct person *person;// malloc(sizeof(struct person));
        struct mnode *fperson;
        if(todo -> next == NULL)
        {
          printf("Insert new 'To Do' first\n");
          break;
        }
        if(worker -> next == NULL)
        {
          printf("Add Person first\n");
          break;
        }
        task  = todo -> next -> data; //task com maior prioridade

        do
        {
          printf("What's the ID of the person you want to give the task to?\n");
          fgets(str,TAM,stdin);
          if(find(worker,idcompt,str) != 0)
            person = find(worker,idcompt,str) -> data;
        } while(find(worker,idcompt,str) == 0);
        x = 7;
        do
        {
        printf("Deadline\n");
          do
          {
            printf("Year\n");
            fgets(str,TAM,stdin);
            task -> y1 = atoi(str);
          }while(task -> y1 < data -> tm_year + 1900);

          do
          {
            printf("Month\n");
            fgets(str,TAM,stdin);
            task -> m1 = atoi(str);
          } while(task->m1 > 12 || task->m1 < data -> tm_mon+1);

          if ( (task->y1%4 == 0 && task->y1%100 != 0) || (task->y1%400 == 0 && task->y1%100 == 0) )
            arrayDias[1]=29;

          do
          {
            printf("Day\n");
            fgets(str,TAM,stdin);
            task -> d1 = atoi(str);
          } while(task -> d1 < 1 || task -> d1 > arrayDias[task->m1-1]);

          fperson = person -> tasks;
          while(fperson -> next != NULL)
          {
            fperson = fperson -> next;
            if(dias(task,fperson->data) < x)
              x = dias(task,fperson -> data);
          }
        }while(x < 7);

        /*do
        {
          printf("What's the ID of the person you want to give the task to?\n");
          fgets(str,TAM,stdin);
          a = atoi(str);
          if( a < 0) break;
          fake = worker -> next;
          person = fake -> data;
          while( person -> id != a && fake -> next != NULL)
          {
            fake = fake -> next;
            person = fake -> data;
          }
          if(person -> id == a)
            a = -1;*/

        x = 1;
        do
        {
          int cont = 0;
          fperson = person -> tasks;
          while( fperson  -> next != NULL)
          {
            cont++;
            fperson = fperson -> next;
          }
          if(cont > limit)
            printf("Select other Person ID(Negative number if no other person available)\n");
          else
            x = 0;
        } while(x);

        task -> ox = 0;
        putss(task -> worker, person);
        putss(person -> tasks,task);
        putss(doing,task);
        sprintf(str,"%d",task -> id);
        out(todo,idcompt,str);
        bubbleSort(doing,peoplecompare);
        bubbleSort(person->tasks,todocompare);
        break;
      }
      case 6:
      {
        printf("Action 'DOING' PARA 'TO DO'\n");
        struct tasks *task;
        //struct mnode *ptr;
        struct person *work;
        struct mnode *fake;

        if(doing -> next == NULL)
        {
          printf("Insert new 'Doing' first\n");
          break;
        }
        /*
          ptr = doing -> next;
          printf("What's the ID of the task you want in 'To Do'?\n");
          fgets(str,TAM,stdin);
          a = atoi(str);
          while(ptr != NULL)
          {
            task  = ptr -> data;
            if(task -> id == a)
            {
              a = -1;
              break;
            }
            ptr = ptr -> next;
          }*/
          do
          {
            printf("What is the ID of the task you want to change?\n");
            fgets(str,TAM,stdin);
            if(find(doing,idcompt,str) != 0)
              task = find(doing,idcompt,str) -> data;
          } while(find(doing,idcompt,str) == 0);

          struct mnode *thing;
          struct person *other;
          fake = task -> worker -> next;
          while(fake != NULL)
          {
            work = fake -> data;
            thing = work -> tasks -> next;
            other = thing -> data;

            sprintf(str,"%d",other -> id);
            if(task -> id == other -> id)
            {
              out(work -> tasks,idcompt,str);
            }
            fake = fake -> next;
          }
          task -> ox = -1;
          unchain(task -> worker);
          task -> worker = head();
          putss(todo,task);
          sprintf(str,"%d",task -> id);
          out(doing,idcompt,str);
          x = 0;
        bubbleSort(todo,todocompare);
        break;
      }
      case 7:
      {
        //struct mnode *task;
        struct tasks *task2;
        //struct mnode *fake;//malloc(sizeof(struct mnode));
        struct person *person;
        struct mnode *fperson;
        if(doing -> next == NULL)
        {
          printf("Insert new 'Doing' first\n");
          break;
        }
        if(worker -> next -> next == NULL)
        {
          printf("Add more people first\n");
          break;
        }/*
        do
        {
          task  = doing -> next;
          task2 = task -> data;
          printf("What is the ID of the task you want to change?\n");
          fgets(str,TAM,stdin);
          a = atoi(str);
          while(task2 -> id != a && task -> next != NULL)
          {
            task = task -> next;
            task2 = task -> data;
          }
        }while(task2 -> id != a);*/
        //HHHHHHHHHHHHHHHHHERRRRROEEEEEEEEEEEEEEE
        do
        {
          printf("What is the ID of the task you want to change?\n");
          fgets(str,TAM,stdin);
          if(find(doing,idcompt,str) != 0)
            task2 = find(doing,idcompt,str) -> data;
        } while(find(doing,idcompt,str) == 0);
        /*
        do
        {
          printf("What's the ID of the person you want to remove the task?\n");
          fgets(str,TAM,stdin);
          a = atoi(str);
          fake = worker -> next;
          person = fake -> data;
          while( person -> id != a && fake -> next != NULL)
          {
            fake = fake -> next;
            person = fake -> data;
          }
        }while(person -> id != a);
        */
        do
        {
          printf("What's the ID of the person you want to remove the task?\n");
          fgets(str,TAM,stdin);
          if(find(worker,idcomp,str) != 0)
            person = find(worker,idcomp,str) -> data;
        } while(find(worker,idcomp,str) == 0);

        x = 1;
        while(x)
        {
          int cont = 0;
          fperson = person -> tasks;
          while( fperson -> next != NULL)
          {
            cont++;
            fperson = fperson -> next;
          }
          if(cont > limit)
          {
            printf("Select other Person ID\n");
            break;
          }
          else
            x = 0;
        }
        sprintf(str,"%d",person-> id);
        out(task2 -> worker,idcomp,str);
        sprintf(str,"%d",task2 -> id);
        out(person -> tasks,idcompt,str);

        x = 1;
        while(x)
        {
          /*
          printf("What's the ID of the person you want to give the task to?\n");
          fgets(str,TAM,stdin);
          a = atoi(str);
          fake = worker;
          while(fake -> next != NULL)
          {
            fake = worker -> next;
            person = fake -> data;
            if(person -> id == a)
            {
              a = -1;
              break;
            }
          }*/
          do
          {
            printf("What's the ID of the person you want to give the task to?\n");
            fgets(str,TAM,stdin);
            if(find(doing,idcompt,str) != 0)
              person = find(doing,idcompt,str) -> data;
          } while(find(worker,idcomp,str) == 0);

          if(a == -1)
          {
            int cont = 0;
            fperson = person -> tasks;
            while( fperson -> next!= NULL)
            {
              cont++;
              fperson = fperson -> next;
            }
            if(cont > limit)
              printf("Select other Person ID\n");
            else
              x = 0;
          }
          else
            printf("Select a valid Person ID\n");
        }
        putss(person-> tasks,task2);
        putss(task2 -> worker,person);
        break;
      }
      case 8:
      {
        printf("Send task To 'Done'\n");
        struct tasks *task;
        //struct mnode *ptr;
        if(doing -> next == NULL)
        {
          printf("Insert new 'Doing' first\n");
          break;
        }

        x = 1;
        while(x)
        {
          /*
          ptr = doing;
          printf("What's the ID of the task you ended?\n");
          fgets(str,TAM,stdin);
          a = atoi(str);
          while(ptr -> next != NULL && x == 1)
          {
            ptr = ptr -> next;
            task  = ptr -> data;
            if(task -> id == a)
            {
              a = -1;
              x = 2;
            }
          }*/
          do
          {
            printf("What's the ID of the task you ended?\n");
            fgets(str,TAM,stdin);
            //if()
            //{
            if(find(doing,idcompt,str) != 0)
              task = find(doing,idcompt,str) -> data;
              //task = ptr -> data;
            a = -1;
            //  x = 2;
            //}
          }while(find(doing,idcompt,str) == 0);

          if(a == -1)
          {
            task -> ox = 1;
            task -> y1 = data -> tm_year + 1900;
            task -> m1 = data -> tm_mon +1;
            task -> d1 = data -> tm_mday;
            //unchain(task -> worker);
            task -> ox = 1;
            putss(done,task);
            sprintf(str,"%d",task -> id);
            out(doing,idcompt,str);
            x = 0;
          }
        }
        bubbleSort(done,donecompare);
        break;
      }
      case 9:
      {
        struct tasks *task;
        struct mnode *ptr;
        struct person *person;
        x = 1;
        while(x)
        {
          /*
          ptr = done -> next;
          while(ptr != NULL || x == 1)
          {
            task  = ptr -> data;
            printf("What's the ID of the task you want to Re-open?\n");
            fgets(str,TAM,stdin);
            a = atoi(str);
            if(task -> id == a)
            {
              a = -1;
              x = 2;
            }
            ptr = ptr -> next;
          }*/
          do
          {
            printf("What's the ID of the task you want to Re-open?\n");
            fgets(str,TAM,stdin);
            //if()
            //{
            if(find(done,idcompt,str) != 0)
            {
              ptr = find(done,idcompt,str);
              task = ptr -> data;
            }
            a = -1;
              //x = 2;
            //}
          }while(find(done,idcompt,str) == 0);

          if(a == -1)
          {
            task -> y = data -> tm_year + 1900;
            task -> m = data -> tm_mon +1;
            task -> d = data -> tm_mday;
            ptr = task -> worker -> next;
            person = ptr -> data;
            ptr = person -> tasks;
            unchain(task->worker);
            sprintf(str,"%d",task -> id);
            out(ptr,idcompt,str);
            x = 0;
          }
        }
        task -> ox = -1;
        putss(todo,task);
        sprintf(str,"%d",task -> id);
        out(done,idcompt,str);
        bubbleSort(todo,todocompare);
        break;
      }
      case 10:
      {
        struct mnode *ptr;
        struct person *p;
        //ptr = worker;
        printf("What's the ID of the Person you want to see the tasks?\n");
        fgets(str,TAM,stdin);
        //a = atoi(str);
        ptr = find(worker,idcomp,str);
        p = ptr -> data;
        print_person(p);
        read(p->tasks,print_ptasks);
        /*while(ptr -> next != NULL)
        {
          ptr = ptr -> next;
          p = ptr -> data;
          if(p -> id == a)
          {
            print_person(p);
            read(p->tasks,print_ptasks);
            continue;
          }
        }*/
        break;
      }
      case 11:
        printf(red"\n***************'To Do'***************\n\n");
        read(todo,print_taskt);
        printf(yellow"***************'Doing'***************\n\n");
        read(doing,print_taskd);
        printf(blue"***************'Done'***************\n\n");
        read(done,print_taskf);
        break;
      case 12:
      {
        fp = fopen("pessoas.txt","w");
        struct person *work;
        struct mnode *ptr;
        struct tasks *task;
        struct mnode *ptr2;
        ptr = worker;
        while(ptr -> next != NULL)
        {
          ptr = ptr -> next;
          work = ptr -> data;
          fprintf(fp,"%d\n",work->id);
          fprintf(fp,"%s",work -> name);
          ptr2 = work -> tasks;
          while(ptr2 -> next != NULL)
          {
            ptr2 = ptr2 -> next;
            task = ptr2 -> data;
            fprintf(fp,"%d\n",task->id);
          }
          fprintf(fp,"%s",work -> email);
        }
        fclose(fp);

        fp = fopen("tarefas.txt","w");
        do
        {
          ptr = todo;
          while(ptr -> next != NULL)
          {
            ptr = ptr -> next;
            task = ptr -> data;
            fprintf(fp,"-1\n");
            outfile(task);
            fprintf(fp,"%s",task->info);
          }
          //-1 todo
          ptr = doing;
          while(ptr -> next != NULL)
          {
            ptr = ptr -> next;
            task = ptr -> data;
            fprintf(fp,"-2\n");
            outfile(task);
            fprintf(fp,"%d\n",task->d1);
            fprintf(fp,"%d\n",task->m1);
            fprintf(fp,"%d\n",task->y1);
            fprintf(fp,"%s",task->info);
          }
          //-2 doing
          ptr = done;
          while(ptr -> next != NULL)
          {
            ptr = ptr -> next;
            task = ptr -> data;
            fprintf(fp,"-3\n");
            outfile(task);
            fprintf(fp,"%d\n",task->d1);
            fprintf(fp,"%d\n",task->m1);
            fprintf(fp,"%d\n",task->y1);
            fprintf(fp,"%s",task->info);
          }
          //-3 done
          break;
        }while(1);
        fclose(fp);
        break;
      }
      case 13:
          read(alltasks,print_ptasks);
          break;
      default:
        printf("QUIT\n");
        eva = 0;
    }
  }
  return 0;
}
