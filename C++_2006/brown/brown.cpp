#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

enum {ib,ir,io,iw,in,ik,im,iv,ii,ie};

int ia[10];
char ca[10] = {66,82,79,87,78,75,77,86,73,69};

const int size = sizeof(ia)/sizeof(int);

void check();
void print();

int main()
{
  for(int i=0; i<size; i++)
    ia[i] = -1;
  ia[ik] = 4;

  cout << "BROWN\n+BOOK\n-----\nMOVIE\n";
  cout << "Enter value for 'O':"; flush(cout);
  cin >> ia[io];

  char w_gte_10;
  cout << "W+O >= 10?"; flush(cout);
  w_gte_10 = (char)(getchar());

  if(w_gte_10 == 'y')
    ia[iv] = 2*ia[io]+1;
  else
    ia[iv] = 2*ia[io];
  ia[iv] = ia[iv] - 10*(int)(ia[iv]/10);

  cout << "R:"; flush(cout);
  cin >> ia[ir];

  ia[ib] = 10 + ia[io] - (ia[ir] + ia[iv]/10);
  ia[im] = ia[ib]+1;

  check();
  print();

  return 0;
}

void check()
{
  int error=0;

  for(int i=0; i<size; i++)
  {
    if(i == ik)
      continue;
    if(ia[i] == 4 || ia[i] >9)
      error = 1;
  }

  if(ia[in] == 0 || ia[im] == 0 || ia[ib] == 0)
    error = 1;

  if(error)
  {
    print();
    cout << "\a";
    exit(0);
  }
}

void print()
{
  cout << "b:\tr:\to:\tw:\tn:\tk:\tm:\tv:\ti:\te:" << endl;
  for(int i=0; i<size; i++)
    cout << ia[i] << "\t";

  for(int i=0; i<5; i++)
  {
    if(ia[i]!=-1)
      cout << ia[i];
    else
      cout << ca[i];
  }

  cout << "\n ";

  int a=4,i;
  while(a<13)
  {
    switch(a){
    case 4:i=0;break; case 5:i=2;break; case 6:i=2;break; case 7:i=5;break; case 8:cout << "\n-----\n";i=6;break;
    case 9:i=2;break; case 10:i=7;break; case 11:i=8;break; case 12:i=9;break;}
    
    if(ia[i]!=-1)
      cout << ia[i];
    else
      cout << ca[i];
    a++;
  }
}