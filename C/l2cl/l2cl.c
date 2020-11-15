#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
  char ifn[256], ofn[256];
  char c;
  FILE * ifp;
  FILE * ofp;

  if(argc < 3)
  {
    printf("usage: l2lc [src] [dest]\n");
    return 0;
  }

  strncpy(ifn,argv[1],255);
  strncpy(ofn,argv[2],255);

  ifp = fopen(ifn,"r");
  ofp = fopen(ofn,"w");

  if(ifp == NULL)
  {
    printf("Error opening %s",ifn);
    return 1;
  }

  if(ofp == NULL)
  {
    printf("Error opening %s",ofn);
    return 1;
  }

  c = getc(ifp);
  while(c != EOF)
  {
    if(c == 10)
      putc('\n',ofp);
    else
      putc(c,ofp);
    c = getc(ifp);
  }

  fclose(ifp);

  return 0;
}