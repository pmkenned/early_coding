#include <stdio.h>

#define SIZE	10

int pow(int,int);
int base(int,int,int);
int place(int,int);
int half_add(int,int,int*);
int eor(int,int);

int main()
{
  int x,y,c1=0,c2=0,c3=0,i;
  int a[SIZE],b[SIZE],s[SIZE];

  printf("Enter x:");
  scanf("%d",&x);
  printf("Enter y:");
  scanf("%d",&y);

  x = base(x,10,2);
  y = base(y,10,2);

  for(i=0; i<SIZE; i++)
  {
    a[i] = place(x,i+1);
    b[i] = place(y,i+1);
  }

  printf("\nx:");
  for(i=0; i<SIZE; i++)
    printf("%d", a[(SIZE-1)-i]);
  printf("\ny:");
  for(i=0; i<SIZE; i++)
    printf("%d", b[(SIZE-1)-i]);

  printf("\n");
  for(i=0; i<SIZE; i++)
  {
    s[i] = half_add(a[i],b[i], &c1);
    s[i] = half_add(s[i],c3,&c2);
    if(c1 || c2)
      c3 = 1;
    else
      c3=0;
  }

  printf("----------\n  ");
  for(i=0; i<SIZE; i++)
    printf("%d", s[(SIZE-1)-i]);

  return 0;
}

int pow(int x, int y)
{
  int i;
  int a = x;
  if(y==0)
    return 1;
  for(i=0; i<y-1; i++)
    x*=a;
  return x;
}

int base(int x, int a, int b)
{
  int n=0;
  while(x>0)
  {
    int i=0;
    while(x-pow(b,i)>=0)
      i++;
    n+=pow(a,i-1);
    x-=pow(b,i-1);
  }

  return n;
}

int place(int x, int p)
{
  return (int)((x-(int)(x/pow(10,p))*pow(10,p))/pow(10,p-1));
}

int half_add(int a, int b, int * c)
{
  if(a && b)
    *c = 1;
  else
    *c = 0;
  if( eor(a,b) )
    return 1;
  return 0;
}

int eor(int a,int b)
{
  if( (a && !b) || (!a && b) )
    return 1;
  return 0;
}