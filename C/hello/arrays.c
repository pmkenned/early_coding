#include <stdio.h>

void flush();
char * cpystr(char str1[], char str2[]);
int lenstr(char str1[]);

int main()
{
  int x=3, a=2;
  int * pa = &a;
  int * px = &x;
  char str1[128], str2[128];

  printf("&x:\t%d\n&a:\t%d\n", &x,&a);
  printf("x:\t%d\na:\t%d\n\n", x,a);
  pa[1] = a;
  printf("x:\t%d\na:\t%d\n", x,a);
  getchar();

  printf("Enter value for x:");
  scanf("%d", &x);
  printf("x:\t%d\n&x:\t%d\n*px:\t%d\npx:\t%d\n", x,&x,*px,px);

  flush();

  printf("Enter a string:");
  fgets(str1, 127, stdin);
  printf("%s", str1);

  printf("str1:\t%d\n*str1:\t%c\nstr[0]:\t%c\n",str1,*str1,str1[0]);
  cpystr(str1, str2);
  printf("str2:\t%s", str2);

  return 0;
}

void flush()
{
  char ch = NULL;
  while( ch != EOF && ch != '\n')
    ch = getchar();
}

char * cpystr(char str1[], char str2[])
{
  int len = lenstr(str1);
  int i;
  for(i=0; i<len; i++)
    str2[i] = str1[i];

  return str2;
}

int lenstr(char str1[])
{
  int i=0;
  while(str1[i] != '\0')
    i++;
  return i;
}
