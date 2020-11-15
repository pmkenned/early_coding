#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Single-lined
#define ULC	218
#define URC	191
#define BLC	192
#define BRC	217

#define HOR	196
#define VER	179

#define FOR	197
#define BIN	193
#define UIN	194
#define RIT	195
#define LIT	180
*/

/* Double-lined */
#define ULC	201
#define URC	187
#define BLC	200
#define BRC	188

#define HOR	205
#define VER	186

#define FOR	206
#define BIN	202
#define UIN	203
#define RIT	204
#define LIT	185

void flush(void);
char * chop(char * str);
void draw_box(int x_pos, int y_pos, int width, int height, char * str);

int main()
{
  char str[256];
  int x,y,w,h;

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

  printf("Enter string:");
  fgets(str, 256, stdin);
  chop(str);

  draw_box(x,y,w,h,str); 

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

void draw_box(int x_pos, int y_pos, int width, int height, char * str)
{
  int i,j;

  for(i=0; i<y_pos; i++)
    putchar('\n');
  for(i=0; i<x_pos; i++)
    putchar(' ');
  putchar(ULC);
  for(i=0; i<width; i++)
    putchar(HOR);
  putchar(URC);
  putchar('\n');
  for(i=0; i<height; i++)
  {
    for(j=0; j<x_pos; j++)
      putchar(' ');
    putchar(VER);
    for(j=0; j<width; j++)
      putchar(' ');
    putchar(VER);
    for(j=0; j<width+1; j++)    
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
  for(i=0; i<x_pos; i++)
    putchar(' ');
  putchar(BLC);
  for(i=0; i<width; i++)
    putchar(HOR);
  putchar(BRC);
}