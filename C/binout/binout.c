#include <stdio.h>
#include <string.h>

void flush(FILE *);
void chop(char *);

int main(int argc, char * argv[])
{
  char choice = 'n';
  char ofn[256];
  int n,i,x;
  FILE * ofp;

  if(argc < 2)
  {
    printf("Enter filename:");
    fgets(ofn,255,stdin);
    chop(ofn);
  }
  else
    strncpy(ofn,argv[1],255);

  ofp = fopen(ofn,"w");

  if(ofp == NULL)
  {
    printf("Error opening file: %s", ofn);
    return 1;
  }

  while(choice != 'y' && choice != 'Y')
  {
    printf("How many numbers? ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
      scanf("%d",&x);
      fputc(x,ofp);
    }

    printf("Done? [y/n] ");
    flush(stdin);
    choice = getchar();
  }

  fclose(ofp);

  return 0;
}

void flush(FILE * ifp)
{
  char ch = NULL;
  while(ch != EOF && ch != '\n')
    ch = fgetc(ifp);
}

void chop(char * str)
{
  str[strlen(str)-1] = '\0';
}