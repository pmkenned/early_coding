#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Single-lined */
#define ULC	218
#define URC	191
#define BLC	192
#define BRC	217

#define HOR	196
#define VER	179

#define FOR	197
#define BIN	193
#define UIN	194
#define RIN	195
#define LIN	180


/* Double-lined
#define ULC	201
#define URC	187
#define BLC	200
#define BRC	188

#define HOR	205
#define VER	186

#define FOR	206
#define BIN	202
#define UIN	203
#define RIN	204
#define LIN	185
*/

void flush(void);
char * chop(char * str);
void table(int x_pos, int y_pos, int width, int height, int cols, int rows, char * str);

int main()
{
  char str[256];
  int x,y,c,r,w,h;

/*
  printf("Enter x position:");
  scanf("%d", &x);

  flush();

  printf("Enter y position:");
  scanf("%d", &y);

  flush();

  printf("Enter width:");
  scanf("%d", &w);

  flush();

  printf("Enter height:");
  scanf("%d", &h);

  flush();

  printf("Enter number of columns:");
  scanf("%d", &c);

  flush();

  printf("Enter number of rows:");
  scanf("%d", &r);

  flush();

  printf("Enter string:");
  fgets(str, 256, stdin);
  chop(str);

*/

  x=y=0; h=w=5; c=r=3;
  strcpy(str, "this is a test 123 456 789");
  table(x,y,w,h,c,r,str); 

  return 0;
}

void flush(void)
{
  int c ='\0';
  while(c != EOF && c != '\n')
    c = getchar();
}

char * chop(char * str)
{
  str[strlen(str)-1] = '\0';
  return str;
}

void table(int x_pos, int y_pos, int width, int height, int cols, int rows, char * str)
{
  int i,j,k,l;

  for(i=0; i<y_pos; i++)
    putchar('\n');
  for(i=0; i<x_pos; i++)
    putchar(' ');
  putchar(ULC);
  for(i=0; i<cols; i++)
  {
    for(j=0; j<width; j++)
      putchar(HOR);
    if(i!=cols-1)
      putchar(UIN);
  }
  putchar(URC);
  putchar('\n');
  for(l=0; l<rows; l++)
  {
    for(i=0; i<height; i++)
    {
      for(k=0; k<x_pos; k++)
        putchar(' ');
      for(j=0; j<cols; j++)
      {
        putchar(VER);
        for(k=0; k<width; k++)
          putchar(' ');
      }
      putchar(VER);
      for(j=0; j<(width+1)*cols; j++)
        putchar('\b');
      for(j=0; j<width; j++)
      {
        if(str[i*width+j] == '\n')
          break;
        if( !(i*width+j > strlen(str)) )
          putchar(str[i*width+j]);
      }
      putchar('\n');
    }
    if(l!=rows-1)
    {
      for(j=0; j<x_pos; j++)
        putchar(' ');
      putchar(RIN);
      for(j=0; j<cols; j++)
      {
        for(k=0; k<width; k++)
          putchar(HOR);
        if(j!=cols-1)
          putchar(FOR);
      }
      putchar(LIN);
      putchar('\n');
    }
  }
  for(i=0; i<x_pos; i++)
    putchar(' ');
  putchar(BLC);
  for(i=0; i<cols; i++)
  {
    for(j=0; j<width; j++)
      putchar(HOR);
    if(i!=cols-1)
      putchar(BIN);
  }
  putchar(BRC);
  putchar('\n');
}