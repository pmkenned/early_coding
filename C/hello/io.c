#include <stdio.h>

void flush();

int main()
{
  int x;
  char ch;
  char str[255];

  printf("Enter a number:");
  scanf("%d", &x);

  flush();

  printf("Enter a character:");
  scanf("%c", &ch);

  flush();

  printf("Enter a string:");
  fgets(str, 255, stdin);

  printf("\n");
  printf("Number:\t\t%d\n", x);
  printf("Character:\t%c\n", ch);
  printf("String:\t\t%s\n", str);

  return 0;
}

void flush()
{
  char ch;
  while (ch != '\n' && ch != EOF)
    ch = getchar();
}