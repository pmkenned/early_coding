#include <stdio.h>
#include <malloc.h>
#include <conio.h>

struct list_node
{
  char * assigned;
  char * subject;
  char * assignment;
  char * due;
  char * status;
  struct list_node * next;
};

int menu(void);
struct list_node * create_list(void);
void add_node(struct list_node *);
struct list_node * list_move(struct list_node *, int);
void print_assignments(struct list_node *);

int main()
{
  struct list_node * list = NULL;
  struct list_node * start = NULL;

  int x, index;
  int choice = 0;

  list = start = create_list();
  list->next = start->next = NULL;

  while(choice != 5)
  {
    clrscr();
    choice = menu();
    clrscr();

    switch(choice)
    {
    case 1:
    print_assignments(start);
    getch();
    break;

    case 2:
    printf("Add after which node? ");
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
    break;

    case 4:
    break;

    case 5:
    break;

    default:
    printf("You did not enter a valid choice\n");
    break;
    }
  }

  return 0;
}

int menu(void)
{
  int choice;

  printf("1. View list\n");
  printf("2. Add assignment\n");
  printf("3. Edit assignment\n");
  printf("4. Remove assignment\n");
  printf("5. Exit Program\n");

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


struct list_node * list_move(struct list_node * list, int offset)
{
  int i;
  for(i = 0; i != offset && list != NULL; i++)
    list = list->next;
  return list;
}

void print_assignments(struct list_node * list)
{
  int i=0;
  if(list != NULL)
    list = list->next;
  while(list != NULL)
  {
    printf("%s:\t%d\n", ++i, list->assigned);
    list = list_move(list,1);
  }
}