#include <stdio.h>
#include <time.h>
#include <string.h>

void chop(char *);

int main(int argc, char * argv[])
{
  char times[256];
  long t1;

  time(&t1);

  printf("%s", ctime(&t1));

  printf("Enter time:");
  fgets(times,255,stdin);
  chop(times);
  printf("%s",times);

  return 0;
}

void chop(char * str)
{
  if(strlen(str) > 0)
    str[strlen(str) - 1] = '\0';
}