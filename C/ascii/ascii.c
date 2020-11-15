#include <stdio.h>

int main(int argc, char * argv[])
{
  int i;
  char s[][4] = {"NUL","SOH","STX","ETX","EOT","EZQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI","DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","FS","GS","RS","US"};

  printf("Bin\t\tHex\tDec\tOct\tASCII\n");

  for(i=0; i<32; i++)
  {
    switch(i)
    {
    case '\b': case '\a': case '\t': case '\n': case 0xd:
    printf("%8.8b\t%x\t%d\t%o\t\t%s\n",i,i,i,i,s[i]);
    break;

    default:
    printf("%8.8b\t%x\t%d\t%o\t%c\t%s\n",i,i,i,i,i,s[i]);
    break;
    }
  }

  for(i=32; i<255; i++)
    printf("%8.8b\t%x\t%d\t%o\t%c\n",i,i,i,i,i);

  return 0;
}