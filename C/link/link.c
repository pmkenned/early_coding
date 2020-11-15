#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define END	-1
#define NEXT	-2

int menu(void);
void get_list(struct node *);
void set_list(struct node *, int, double);
struct node * list_move(struct node *, int);
void print_list(struct node *);
void flush(FILE *);

struct node
{
  double data;
  struct node * next;
};

int main()
{
  struct node * start = NULL;
  struct node * list = NULL;
  struct node * temp = NULL;
  int choice = 0;
  int index;
  float x;

  start = list = (struct node *) malloc( sizeof(struct node) );
  list->next = NULL;

  while(choice != 5)
  {
    choice = menu();
    clrscr();

    switch(choice)
    {
      case 1:
      list = start;
      print_list(list);
      break;

      case 2:
      list = list_move(list, END);
      get_list(list);
      break;

      case 3:
      list = temp = start;
      printf("Delete which element? ");
      scanf("%d", &index);
      flush(stdin);
      list = temp = list_move(list, index);
      temp = temp->next;
      list->next = temp->next;
      free(temp);
      list = start;
      break;

      case 4:
      list = start;
      printf("Edit what element? ");
      scanf("%d", &index);
      flush(stdin);
      printf("Change it to what? ");
      scanf("%f", &x);
      flush(stdin);
      set_list(list,index,x);
      break;

      case 5:
      break;

      default:
      printf("You did not enter a valid choice\n");
      flush(stdin);
      break;
    }
    clrscr();
  }

  return 0;
}

int menu(void)
{
  int choice = 0;

  printf("What would you like to do?\n");
  printf("1. View list\n");
  printf("2. Add elements to list\n");
  printf("3. Remove elements from list\n");
  printf("4. Edit an element in the list\n");
  printf("5. Quit this program\n");

  scanf("%d", &choice);
  flush(stdin);

  return choice;
}

void get_list(struct node * list)
{
  char str[256];
  double x;

  while(1)
  {
    fgets(str,255,stdin);

    if(str[0] == '\4')
      break;

    x = atof(str);

    list->data = x;
    list->next = (struct node *) malloc( sizeof(struct node) );
    list = list->next;
  }
  list->next = NULL;
}

void set_list(struct node * list, int index, double d)
{
  int i;
  for(i=0; i<index; i++)
    list = list->next;

  list->data = d;
}

struct node * list_move(struct node * list, int whence)
{
  int i;

  if(whence == NEXT)
    list = list->next;
  if(whence == END)
  {
    while(list->next != NULL)
      list = list->next;
  }
  if(whence > 0)
  {
    for(i=1; i<whence; i++)
      list = list->next;
  }

  return list;
}

void print_list(struct node * list)
{
  if(list->next == NULL)
    printf("There are no elements in the list\n");

  while(list->next != NULL)
  {
    printf("%f\n", list->data);
    list = list->next;
  }

  flush(stdin);
}

void flush(FILE * ifp)
{
  char ch = '\0';
  while(ch != EOF && ch != '\n')
    ch = fgetc(ifp);
}