#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STR_LEN	256

int menu(void);
char * chop(char *);
int strglen(char *);
void flush(void);
int ctoi(char);
unsigned int atotm(char *);

int main()
{
  char ch;
  char date[STR_LEN];

  ch = (char) menu();

  ch = ctoi(ch);

  switch(ch)
  {
  case 1:
  {
/*
  printf("Entered date:\t%s\n", date);
  printf("Current date:\t%s", _strdate(date));
*/

    time_t encoded_time;
    struct tm *decoded_time;
    char* time_string;

    encoded_time = time(NULL);
    decoded_time = localtime(&encoded_time);
    time_string = asctime(decoded_time);

    printf ("Current date and time: %d\n", time(NULL));

    printf("Enter date (mm/dd/yy):");
    flush();
    fgets(date, STR_LEN - 1, stdin);
    chop(date);
    printf("Entered Date:\t%d", atotm(date));
  }
  break;

  case 2:
  break;

  default:
  break;
  }
  
  return 0;
}

int menu(void)
{
  int c;

  printf("What would you like to do?\n");
  printf("1. Add calender entry\n");
  printf("2. List entries\n");

  c = getchar();

  return c;
}

char * chop(char * str)
{
  str[strglen(str)-1] = '\0';
  return str;
}

int strglen(char * str)
{
  int i=0;
  while(str[i] != '\0')
    i++;
  return i;
}

void flush(void)
{
  int c = getchar();
  while(c != EOF && c != '\n')
    c = getchar();
}

int ctoi(char ch)
{
  int c = 0;

  if(ch >= 48 && ch <= 57)
    c = ch - '0';
  else
    return -1;

  return c;
}

unsigned int atotm(char * date)
{
  char mon[STR_LEN], day[STR_LEN], year[STR_LEN];
  unsigned long int i=0, sec = 0, a;

  for(i=0; i<STR_LEN; i++)
    mon[i] = day[i] = year[i] = 0;

  i=0;

  while(date[i] != '\0' && date[i] != '/' && i < STR_LEN)
  {
    mon[i] = date[i];
    i++;
  }
  i++;

  sec += atoi(mon) * 2592000;

  if(atoi(mon) != 4 && atoi(mon) != 6 && atoi(mon) != 9 && atoi(mon) != 11)
    sec += 864400;

  a=i;
  while(date[i] != '\0' && date[i] != '/' && i < STR_LEN)
  {
    day[i%a] = date[i];
    i++;
  }
  i++;

  sec += atoi(day) * 864400;

  a=i;
  while(date[i] != '\0' && date[i] != '/' && i < STR_LEN)
  {
    year[i%a] = date[i];
    i++;
  }
/*
  for(i=i; i<8; i++)
    year[0] = date[i];
  i++;
*/

  sec += (atou(year) - 68) * 31536000;

  printf("%s\n%s\n%s\n", mon, day, year);

  return sec;
}