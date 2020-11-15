#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct list_node
{
  int data;
  struct list_node * next;
};

void chop(char *);
void flush(FILE *);
int menu(void);
struct list_node * create_list(void);
void add_node(struct list_node *);
void set_node(struct list_node *, int);
void del_node(struct list_node *);
struct list_node * list_move(struct list_node *, int);
void print_list(struct list_node * list);
void set_list(struct list_node *, int);

int main()
{
  struct list_node * list = NULL;
  struct list_node * start = NULL;

  int x, index;
  int choice;

  list = start = create_list();
  list->next = start->next = NULL;

  while(choice != 6)
  {
    clrscr();
    choice = menu();
    clrscr();

    switch(choice)
    {
    case 1:
    print_list(start);
    getch();
    break;

    case 2:
    printf("After which node would you like to add the new node? ");
    scanf("%d", &index);
    list = list_move(start,index);

    if(list == NULL)
    {
      printf("Node %d is beyond the bounds of this list\n", index);
      getch();
      break;
    }

    add_node(list);
    list = list_move(list,1);
    break;

    case 3:
    printf("Set which node? ");
    scanf("%d", &index);
    list = list_move(start,index);

    if(list == NULL)
    {
      printf("Node %d is beyond the bounds of this list\n", index);
      getch();
      break;
    }

    printf("Enter data:");
    scanf("%d", &x);
    set_node(list,x);
    break;

    case 4:
    printf("After which node would you like to start adding nodes? ");
    scanf("%d", &index);
    list = list_move(start, index);
    set_list(list, index);
    break;

    case 5:
    printf("Delete which node? ");
    scanf("%d", &index);
    list = list_move(start,--index);

    if(list == NULL || list->next == NULL)
    {
      printf("Node %d is beyond the bounds of this list\n", index+1);
      getch();
      break;
    }

    del_node(list);

    break;

    case 6:
    break;

    default:
    printf("You did not enter a valid choice\n");
    getch();
    break;
    }
  }

  return 0;
}

void flush(FILE * ifp)
{
  char ch = '\0';
  while(ch != EOF && ch != '\n')
    ch = fgetc(ifp);
}

void chop(char * str)
{
  if(strlen(str) > 0)
    str[strlen(str) - 1] = '\0';
}

int menu(void)
{
  int choice = 0;

  printf("1. Print the list\n");
  printf("2. Add a node\n");
  printf("3. Set a node\n");
  printf("4. Add and set multiple nodes\n");
  printf("5. Delete a node\n");
  printf("6. Exit this program\n");
  scanf("%d", &choice);

  return choice;
}

struct list_node * create_list(void)
{
  return (struct list_node *) malloc(sizeof(struct list_node *) * 1);
}

void add_node(struct list_node * list)
{
  struct list_node * temp = NULL;

  if(list == NULL)
    return;

  temp = list->next;

  list->next = (struct list_node *) malloc(sizeof(struct list_node *) * 1);
  list->next->next = temp;
}

void set_node(struct list_node * list, int x)
{
  if(list == NULL)
    return;
  list->data = x;
}

void del_node(struct list_node * list)
{
  struct list_node * temp = NULL;

  temp = list->next->next;
  free(list->next);
  list->next = temp;
}

struct list_node * list_move(struct list_node * list, int offset)
{
  int i;
  for(i = 0; i != offset && list != NULL; i++)
    list = list->next;
  return list;
}

void print_list(struct list_node * list)
{
  int i=0;
  if(list != NULL)
    list = list->next;
  while(list != NULL)
  {
    printf("%d:\t%d\n", ++i, list->data);
    list = list_move(list,1);
  }
}

void set_list(struct list_node * list, int index)
{
  char str[256];
  int x;

  if(list == NULL)
  {
     printf("Node %d is beyond the bounds of this list\n", index);
     return;
  }

  flush(stdin);
  while(str[0] != 4)
  {
    fgets(str, 255, stdin);
    chop(str);
    x = atoi(str);
    if(x == 0 && str[0] != '0' && str[0] != 4)
    {
      printf("Please enter an integer\n");
      continue;
    }
    if(str[0] == 4)
      break;
    add_node(list);
    list = list_move(list,1);
    set_node(list,x);
  }
}