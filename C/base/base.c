#include <stdio.h>
#include <stdlib.h>

void flush(FILE *);

int main()
{
  char str[256];
  char b = 0;
  int x = 0;

  getb:
  printf("Enter base [b/d/h/o]:");
  b = getchar();
  if(b != 'b' && b != 'd' && b!= 'h' && b!= 'o')
  {
    printf("Invalid base\n");
    flush(stdin);
    goto getb;
  }

  getx:
  printf("Enter an integer:");
  switch(b)
  {
    case 'b':
    scanf("%b",&x);
    break;

    case 'd':
    scanf("%d",&x);
    break;

    case 'h':
    scanf("%x",&x);
    break;

    case 'o':
    scanf("%o",&x);
    break;
  }

  printf("Bin:\t%b\nDec:\t%d\nHex:\t%x\nOct:\t%o\n",x,x,x,x);

  return 0;
}

void flush(FILE * ifp)
{
  char ch = '\0';
  while(ch != EOF && ch != '\n')
    ch = fgetc(ifp);
}