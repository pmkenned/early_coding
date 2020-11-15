#include <stdio.h>

int main()
{
  printf("What would you like to do?\n");

  printf("1. Print the ASCII table\n");
  printf("2. Convert int to char\n");
  printf("3. Convert char to int\n");
  printf("4. Exit program\n");

  int choice;

  scanf("%d", &choice);

  char ch;
  while ((ch = getchar()) != '\n' && ch != EOF) ;

  switch(choice)
  {
    case 1:
      for(int i=0; i<256; i++)
        printf("%i:\t%c\n", i, i);
      break;

    case 2:
    {
      int n;
      printf("Enter integer:");
      scanf("%i", &n);
      printf("%c", n);
    }
      break;

    case 3:
    {
      char c;
      printf("Enter character:");
      scanf("%c", &c);
      printf("%i", c);
    }
      break;

   case 4:
      printf("You didn't enter a valid choice.\n");
      break;

    default:
      break;
  }

  return 0;
}