#include <stdio.h>
#include <string.h>

void flush(FILE *);
void chop(char *);

int main(int argc, char * argv[])
{
  char ifn[256];
  FILE * ifp;
  int ifs, i;
  char ch;

  if(argc < 2)
  {
    printf("Enter filename:");
    fgets(ifn,255,stdin);
    chop(ifn);
  }
  else
    strcpy(ifn,argv[1]);

  ifp = fopen(ifn,"rb");

  if(ifp == NULL)
  {
    printf("Error opening file: %s", ifn);
    return 1;
  }
  ifs = filesize(ifn);

  for(i=0; i<ifs; i++)
  {
    if(i%26 == 0)
      putchar('\n');
    ch = fgetc(ifp);
    printf("%.2x ",ch);
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
  str[strlen(str)-1] = '\0';
}