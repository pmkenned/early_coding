#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  FILE * ifp = fopen(argv[1], "r");
  char ch = '\0';
  char tag[128];

  int flip = 1;
  int i=0;

  int a;
  for(a=0; a<128; a++)
    tag[a] = 0;

  while(ch != EOF)
  {
    ch = (char)fgetc(ifp);

    if(ch == '<')
      flip = 0;
    if(ch == '>')
      flip = 1;

    if(flip == 0 && ch != '<')
    {
      tag[i] = ch;
      i++;
    }
    else
    {
      if(strncmp(tag,"br",2) == 0)
        printf("\n");
      if(strncmp(tag,"title",5) == 0)
        printf("\n---");
      if(strncmp(tag,"/title",6) == 0)
        printf("---\n\n");
      if(strncmp(tag,"p",1) == 0)
        printf("\n\n");
      if(strncmp(tag,"li",2) == 0)
        printf("\n* ");
      if(strncmp(tag,"h1",2) == 0)
        printf("\n");
      i=0;
      for(a=0; a<128; a++)
        tag[a] = 0;
    }

    if(flip == 1 && ch != '>' && ch != '\n')
      printf("%c", ch);
  }

  fclose(ifp);

  return 0;
}