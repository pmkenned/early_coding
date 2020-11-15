#include <stdio.h>
#include <string.h>

void chop(char *);

int main(int argc, char * argv[])
{
  int c;
  FILE * ifp;
  char ifn[256];

  if(argc < 2)
  {
    printf("Enter filename:");
    fgets(ifn,255,stdin);
    chop(ifn);
  }
  else
    strcpy(ifn, argv[1]);

  ifp = fopen(ifn, "rb");

  c = getc(ifp);
  while(c != EOF)
  {
    putchar(c);
    c = getc(ifp);
  }

  return 0;
}

void chop(char * str)
{
  if(strlen(str) > 0)
    str[strlen(str) - 1] = '\0';
}