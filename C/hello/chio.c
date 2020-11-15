#include <stdio.h>

/*
* int fgetc(FILE *stream)
* char *fgets(char *, int n, FILE *stream)
* int fputc(int c, FILE *stream)
* int fputs(const char *s, FILE *stream)
* int getc(FILE *stream)
* int getchar(void)
* char *gets(char *s)
* int putc(int c, FILE *stream)
* int putchar(int c)
* int puts(const char *s)
* int ungetc(int c, FILE *stream)
*/

void flush();

int main()
{
  char ch;
  char str[128];
  int c = 65;
  char s[128] = "String";

  printf("Enter character:");
  ch = fgetc(stdin);
  printf("%c", ch);

  flush();

  printf("\nEnter a string:");
  fgets(str, 127, stdin);
  printf("%s", str);

  printf("printf():");
  fputc(c, stdout);

  printf("\nfputs():");
  fputs(s, stdout);

  printf("\nEnter a character:");
  ch = getc(stdin);
  printf("%c", ch);

  flush();

  printf("\nEnter a character:");
  ch = getchar();
  printf("%c", ch);

  flush();

  printf("\nEnter a string:");
  gets(str);
  printf("%s", str);

  printf("\nputc():");
  putc(c, stdout);

  printf("\nputchar():");
  putchar(c);

  printf("\nputs():");
  puts(s);

  printf("ungetc():");
  ungetc(c, stdout);

  return 0;
}

void flush()
{
  char ch = '\0';
  while(ch != EOF && ch != '\n')
    ch = getchar();
}