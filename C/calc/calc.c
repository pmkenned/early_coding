#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

void chop(char *);
int get_token(char*,char *);
char type(char);

int main()
{
  char * str0 = malloc(256);
  char * str1 = malloc(256);
  float num[10];
  float ans[10];
  char op[10];
  int order[10];
  int done[10];
  int offset = 0;
  int n = 0, o = 0, c = 0;
  int t = 0, p = 0;
  int j,x,a;

  fgets(str0, 255, stdin);
  chop(str0);

  do
  {
    offset += get_token(str1, str0+offset);

    if(str1[0] == '(' && ( t == 'n' || t == ')' ) )
    {
      op[o] = '*';
      order[o] = 2; order[o] += 4*p;
      o++;
    }
    if(type(str1[0]) == 'n' && t == ')' )
    {
      op[o] = '*';
      order[o] = 2; order[o] += 4*p;
      o++;
    }

    t = type(str1[0]);

    if(t == '(')
      p++;
    if(t == ')')
      p--;

    if(t == 'n')
      num[n++] = atof(str1);
    if(t == 'o')
    {
      op[o] = str1[0];
      switch(op[o])
      {
        case '^': order[o] = 3; break;
        case '*': case '/': order[o] = 2; break;
        case '+': case '-': order[o] = 1; break;
      }
      order[o] += 4*p;
      o++;
    }
  }
  while(str1[0] != '\0');

  printf("\nNumbers entered:\n");
  for(j=0; j<n; j++)
    printf("%f\n", num[j]);

  printf("Operators entered:\n");
  for(j=0; j<o; j++)
    printf("%c\t%d\n", op[j], order[j]);


  for(a = 0; a < o; a++)
  {
    x = 0;
    for(j=0; j<o; j++)
      if(order[j] > order[x])
        x = j;
    order[x] = 0;

    putchar(x+'0');
    putchar(' ');

    switch(op[x])
    {
      case '^': ans[a] = pow(num[x],num[x+1]); break;
      case '*': ans[a] = num[x]*num[x+1]; break;
      case '/': ans[a] = num[x]/num[x+1]; break;
      case '+': ans[a] = num[x]+num[x+1]; break;
      case '-': ans[a] = num[x]-num[x+1]; break;
    }
    done[a] = x;
    for(j=0; j<a+1; j++)
      num[done[j]] = num[done[j]+1] = ans[a];
    putchar(op[x]);

    printf(" %f\n", ans[a]);
  }

  return 0;
}

void chop(char * str)
{
  str[strlen(str)-1] = '\0';
}

int get_token(char* str1, char * str0)
{
  char c = str0[0];
  char t;
  int i = 0, j = 0;

  while(c == ' ' || c == '\t')
    c = str0[++i];

  t = type(c);

  for(j = i; j < 256 && t == type(c); j++)
  {
    str1[j - i] = c;
    c = str0[j+1];
  }
  str1[j-i] = '\0';

  return strlen(str1);
}

char type(char c)
{
  if(c >= '0' && c <= '9' || c == '.')
    return 'n';
  if( (c >= 'A' && c<= 'Z') || ( c >= 'a' && c <= 'z') )
    return 'c';
  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    return 'o';
  if(c == '(')
    return '(';
  if(c == ')')
    return ')';
  return 0;
}