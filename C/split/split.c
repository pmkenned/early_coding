#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int filesize(char filename[]);

int main(int argc, char* argv[])
{
  char filename[256], outname[256], ofsuffix[2], ch;
  int outsize, i, j, k, infsize;
  FILE * ifp;
  FILE * ofp;

  if(argv[1] == NULL)
  {
    printf("Usage: split filename [split_size]\n");
    exit(0);
  }
  else
    strncpy(filename, argv[1], 255);

  if(argv[2] != NULL)
    outsize = atoi(argv[2]);
  else
    outsize = 1047552;

  ifp = fopen(filename, "rb");

  infsize = filesize(filename);

  printf("%d\n", infsize);
  printf("%s\n", filename);
  printf("%d\n", outsize);

  for(i=0; i<infsize/outsize+1; i++)
  {
    for(k=0; k<255; k++)
      outname[k] = 0;
    strncpy(outname, filename, 254);
    ofsuffix[0] = '0'+i; ofsuffix[1] = 0;
    strcat(outname, ofsuffix);

    ofp = fopen(outname, "wb");

    for(j=0; j<outsize; j++)
    {
      ch = fgetc(ifp);
      if(i*outsize+j>=infsize)
        break;
      fprintf(ofp, "%c", ch);
    }
    
    fclose(ofp);
  }

  fclose(ifp);

  return 0;
}

int filesize(char filename[])
{
  FILE * ifp = fopen(filename, "rb");
  long int begin, end;
  begin = ftell(ifp);
  fseek(ifp, SEEK_END, SEEK_SET);
  end = ftell(ifp);
  return end-begin;
}