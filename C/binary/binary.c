#include <stdio.h>
#include <string.h>

void flush(FILE *);
void chop(char *);

int main(int argc, char * argv[])
{
  char ifn[256];
  FILE * ifp;
  int ifs, i;
  int c;

  if(argc < 2)
  {
    printf("Enter filename:");
    fgets(ifn,255,stdin);
    chop(ifn);
  }
  else
    strncpy(ifn,argv[1],255);

  ifp = fopen(ifn,"rb");

  if(ifp == NULL)
  {
    printf("Error opening file: %s", ifn);
    return 1;
  }

  ifs = filesize(ifn);

  for(i=0; i<ifs; i++)
  {
    if(i%8 == 0)
      putchar('\n');
    c = fgetc(ifp);
    printf("%8b ",c);
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