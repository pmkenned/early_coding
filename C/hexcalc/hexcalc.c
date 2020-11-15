#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STR_LEN	256

int ten2bin(int);
int byte2nibble(int, char);
char bin2hex(int);
void print_chart(void);

int main(int argc, char * argv[])
{
  char buffer[STR_LEN];
  int x, ho, lo;

  if(argc <= 2)
    print_chart();
  else if(argc == 3 && strncmp(argv[2], "h", 1) == 0)
  {
    strncpy(buffer, argv[1], STR_LEN);
    x = atoi(buffer);
    x = ten2bin(x);

    ho = byte2nibble(x, 'h');
    lo = byte2nibble(x, 'l');

    printf("%c", bin2hex(ho));
    printf("%c", bin2hex(lo));
  }
  else if(argc == 3 && strncmp(argv[2], "d", 1) == 0)
  {
    printf("Not yet coded\n");
  }
  else
  {
    printf("Usage: hexcalc [n b]\n n\tnumber to be converted\n b\t base of argument\n");
  }

  return 0;
}

int ten2bin(int x)		// converts base ten numbers to binary
{
  int n=0, i;
  while(x>0)
  {
    i=0;
    while(x-pow(2,i)>=0)	// increment i until 2^i is greater than x
      i++;
    n+=pow(10,i-1);		// add 10^(i-1) to n
    x-=pow(2,i-1);		// reduce x by 2^(i-1)
  }

  return n;
}

int byte2nibble(int x, char order)	// returns H.O. or L.O. nibble of byte
{
  if(order == 'h')			// if order = high
    x = (int)(x/pow(10,4));		// strip low order bits
  if(order == 'l')			// if order = low
    x = x-pow(10,4)*(int)(x/pow(10,4));	// subtract high order
  return x;
}

char bin2hex(int x)	// returns a char from 0-F, converting a nibble to a hex value
{
  switch(x)
  {
  case 0:	return '0';
  case 1:	return '1'; case 100:	return '4'; case 111:	return '7'; case 1010:	return 'A'; case 1101:	return 'D';
  case 10:	return '2'; case 101:	return '5'; case 1000:	return '8'; case 1011:	return 'B'; case 1110:	return 'E';
  case 11:	return '3'; case 110:	return '6'; case 1001:	return '9'; case 1100:	return 'C'; case 1111:	return 'F';
  default: printf("ERROR:%d out of range\n"); break;
  }
  return 1;
}

void print_chart(void)
{
  int i, c, ho,lo;

  for(i=0; i < 256; i++)
  {
    printf("%d:", i);
    c = ten2bin(i);
    ho = byte2nibble(c, 'h');
    lo = byte2nibble(c, 'l');

    printf("%c", bin2hex(ho));
    printf("%c", bin2hex(lo));
    printf("\t");
  }
}