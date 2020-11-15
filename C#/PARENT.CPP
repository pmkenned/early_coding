#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

int main()
{
  char child1[] = "child.exe";
  char child2[BUFSIZ];
  
  /* 
   * Execute by passing the name directly 
   */
  system ("child.exe");
  
  /*
   * Execute by passing an array name
   */
  system (child1);
  
  /*
   * Build a buffer, and execute the commands within it
   */
  strcpy (child2, "child.exe");
  strcat (child2, " -aparm -b");
  
  printf ("Executing %s\n", child2);
  system (child2);
  
  return 0;
}