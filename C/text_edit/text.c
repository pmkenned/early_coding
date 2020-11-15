#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

char * increase(char *, int);

int main(int argc, char * argv[])
{
  int c;
  int n = 0;
  char ofn[256];
  char * text = NULL;
  FILE * ofp = NULL;

  if(argc >= 2)
  {
    strcpy(ofn,argv[1]);
    ofp = fopen(ofn, "rb");
    if(ofp == NULL)
    {
      printf("Error opening file: %s", ofn);
      exit(1);
    }
  }

  while(c != 17)
  {
    c = getch();
    switch(c)
    {
    case 0x0d:
    putchar('\n');
    break;

    case 17:
    break;

    default:
    text = increase(text,n);
    text[n++] = c;
    text[n] = '\0';
    putchar(c);
    break;
    }
  }

  return 0;
}

char * increase(char * text, int n)
{
  char * temp = malloc( sizeof(char) * n );
  int i;

  for(i=0; i<n; i++)
    temp[i] = text[i];

  for(i=0; i<n; i++)
    free(text+i);

  text = malloc( sizeof(char) * (n+1) );

  for(i=0; i<n; i++)
    text[i] = temp[i];

  for(i=0; i<n; i++)
    free(temp+i);

  return text;
}
