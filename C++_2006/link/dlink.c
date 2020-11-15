#include <stdio.h>
#include <malloc.h>

struct node
{
  double data;
  struct node * prev;
  struct node * next;
};

int menu(void);
void add_node(struct node *, int);
struct node * list_move(struct node *, int);
void print_list(struct node *);
void flush(FILE *);

int main()
{
  struct node * start = NULL;
  struct node * list = NULL;
  int choice;
  int index;
  float x;

  start = list = (struct node *) malloc( sizeof(struct node) );
  list->prev = list->next = NULL;

  while(choice != 5)
  {
    choice = menu();

    switch(choice)
    {
      case 1:
      list = start;
      print_list(list);
      flush(stdin);
      break;

      case 2:
      list = start;

      printf("Add new node where? ");
      scanf("%d", &index);
      flush(stdin);

      add_node(list, index);
      list = start;
      break;

      case 3:
      break;

      case 4:
      list = start;

      printf("Edit which element? ");
      scanf("%d", &index);
      flush(stdin);

      list = list_move(list,index);

      printf("Enter data:");
      scanf("%f", &x);
      flush(stdin);

      list->data = x;
      list = start;
      break;

      case 5:
      break;

      default:
      printf("You did not enter a valid choice\n");
      flush(stdin);
      break;
    }
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

void add_node(struct node * list, int index)
{
  struct node * temp = NULL;

  int i;
  for(i=0; i<index; i++)
    list = list->next;

  temp = list;
  list->next = (struct node*) malloc( sizeof(struct node) );
  list = list->next;
  list->prev = temp;
}

struct node * list_move(struct node * list, int whence)
{
  int i;
  for(i=0; i<whence && list != NULL; i++)
    list = list->next;
  return list;
}

void print_list(struct node * list)
{
  int i=0;
  while(list != NULL)
  {
    printf("node %d:\tprev: %p\t data: %f\tnext:%p\n", i++, list->prev, list->data, list->next);
    list = list->next;
  }
}

void flush(FILE * ifp)
{
  char ch = '\0';
  while(ch != EOF && ch != '\n')
    ch = fgetc(ifp);
}