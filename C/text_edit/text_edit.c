#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

void flush(FILE *);
void chop(char *);
void print(char *, int, FILE * ofp);
int save(char *, int, char[], char []);
char * increase(char *, int);

int main(int argc, char * argv[])
{
  char * text = (char *) malloc(sizeof(char) * 0);
  char ofn[256], mode[4] = "w";
  FILE * ofp = NULL;
  int c = getch(), q;
  int n = 0, i, change = 0;

  for(i=0; i<256; i++)
    ofn[i] = '\0';

  while(c != 17)
  {
    switch(c)
    {
    case (int)'\b':
    change = 1;
    putchar('\b');
    putchar('\0');
    putchar('\b');
    n--;
    break;

    case 15:					// Ctrl-O
    printf("\nEnter filename: ");
    fgets(ofn, 255, stdin);
    chop(ofn);
    ofp = fopen(ofn, "r");
    if(ofp == NULL)
      printf("Error opening file: %s", ofn);
    else
    {
      print(NULL,0,ofp);
      fclose(ofp);
      strcpy(mode,"a+");
      ofp = fopen(ofn, mode);
    }
    break;

    case 19:					// Ctrl-S
    if(save(text,n,ofn,mode) == 0)
      printf("File saved.\n");
    change = 0;
    print(text,n,ofp);
    break;

    default:
    change = 1;
    putchar(c);
    if(c == 0x0d)
    {
      putchar('\n');
      c = 0x0a;
    }
    text = increase(text,n);
    text[n++] = c;
    break;
    }
    c = getch();

    if(c == 17 && change == 1)
    {
      printf("\nQuit without saving changes? (y/n) ");
      q = getch();
      if(q == 'y' || q == 'Y')
        break;
      putchar('\n');
      print(text,n,ofp);
      c = getch();
    }
  }

  fclose(ofp);

  return 0;
}

void flush(FILE * ifp)
{
  char ch = '\0';
  while(ch != EOF && ch != '\n')
    fgetc(ifp);
}

void chop(char * str)
{
  if(strlen(str) > 0)
    str[strlen(str) - 1] = '\0';
}

void print(char * text, int n, FILE * ofp)
{
  int i;
  char c;

  if(ofp != NULL)
  {
    c = fgetc(ofp);
    while(c!=EOF)
    {
      putchar(c);
      c = fgetc(ofp);
    }
  }
  else
  {
    for(i=0; i<n; i++)
      putchar(text[i]);
  }
}

int save(char * text, int n, char ofn[], char mode[])
{
  FILE * ofp = NULL;
  int i;

  if(ofn[0] == 0)
  {
    printf("\nEnter filename: ");
    fgets(ofn, 255, stdin);
    chop(ofn);
  }
  else
    putchar('\n');

  ofp = fopen(ofn, mode);

  if(ofp == NULL)
  {
    printf("\nError opening file: %s\n", ofn);
    return 1;
  }

  for(i=0; i<n; i++)
    fputc(text[i], ofp);

  fclose(ofp);

  return 0;
}

char * increase(char * text, int n)
{
  char * temp = NULL;
  int i;

  temp = (char *) malloc(sizeof(char) * n );

  for(i=0; i<n; i++)
    temp[i] = text[i];

  for(i=0; i<n; i++)
    free(text+i);

  text = (char *) malloc(sizeof(char) * (n+1) );

  for(i=0; i<n; i++)
    text[i] = temp[i];

  for(i=0; i<n; i++)
    free(temp+i);

  return text;
}