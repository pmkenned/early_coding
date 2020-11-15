#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
  char ifn[256];
  char ofn[256];
  char c;
  int i=0;
  int p=0;
  FILE * ifp;
  FILE * ofp;

  if(argv[1] == NULL)
  {
    printf("Usage: num_lin input_filename [output_filename] [-p]\n\t-p\tprint output\n");
    exit(0);
  }
  else
   strncpy(ifn, argv[1], 255);

  if(argv[2] == NULL)
  {
    strcpy(ofn, ifn);
    strcat(ofn, "_out");
  }
  else
  {
    if(strcmp(argv[2], "-p") == 0)
      p=1;
    else
      strncpy(ofn, argv[2], 252);
  }

  printf("%d", p);

  ifp = fopen(ifn, "r");

  if(p==0)
    ofp = fopen(ofn, "w");
  else
    ofp = stdout;

  while(c != EOF)
  {
    c = fgetc(ifp);
    fputc(c,ofp);
    if(c == '\n')
    {
      fprintf(ofp, "\\*%d*\\", i);
      i++;
    }
  }

  fclose(ofp);
  fclose(ifp);

  return 0;
}