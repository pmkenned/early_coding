#include <iostream.h>

int main(int argc, _TCHAR* argv[2])
{
  short int unknown[9][9][9], known[9][9];

  if(argv[1]!=NULL)	// obtains input from file
  {
    FILE *input = fopen(argv[1], "r+");

    for(int i=0; i<9; i++){	// init known array
      for(int j=0; j<9; j++){
        known[i][j] = (int)fgetc(input) - 48;}}
  }
  else			// obtains input from user
  {
    cout << "Enter Given elements:\n";
    for(int i=0; i<9; i++){	// init known array
      for(int j=0; j<9; j++){
        cout << "[" << i << "," << j << "]:";
        cin >> known[i][j];}}
  }

  for(int i=0; i<9; i++){	// init unknown array
    for(int j=0; j<9; j++){
      for(int k=0; k<9; k++){
        unknown[i][j][k] = 1;}}}

  int n=2;

  do{ n--;

  for(int i=0; i<9; i++)
  {
    for(int j=0; j<9; j++)
    {
      if(known[i][j]!=0){	// if already known
        int x=known[i][j];
        for(int k=0; k<9; k++){
          if(k!=x-1){
            unknown[i][j][k]=0;}}
        continue;}

      for(int k=0; k<9; k++){	// scan row
        if(known[i][k]!=0){
          int x=known[i][k];
          unknown[i][j][x-1]=0;}}

      for(int k=0; k<9; k++){	// scan column
        if(known[k][j]!=0){
          int x=known[k][j];
          unknown[i][j][x-1]=0;}}

      for(int k=(i/3)*3; k<=(i/3)*3+2; k++){	// scan 3x3 square
        for(int l=(j/3)*3; l<=(j/3)*3+2; l++){
          if(known[k][l]!=0){
            int x=known[k][l];
            unknown[i][j][x-1]=0;}}}

      int sum=0;		// stores last option to known array
      for(int k=0; k<9; k++){
        sum+=unknown[i][j][k];}
      if(sum==1){
        short int x=0;
        for(short int k=0; unknown[i][j][k]!=1; k++){x=k;}
        known[i][j]=x+2; n++;}

      for(int a=0; a<9; a++){
        int x=0;
        for(int k=0; k<9; k++){	// scan row
          if(k==j)
            continue;
          x+=unknown[i][k][a];}
        if(x==0){
          known[i][j]=a+1; n++;}}

      for(int a=0; a<9; a++){
        int x=0;
        for(int k=0; k<9; k++){	// scan column
          if(k==i)
            continue;
          x+=unknown[k][j][a];}
        if(x==0){
          known[i][j]=a+1; n++;}}

      for(int a=0; a<9; a++){	// scan 3x3 square
        int x=0;
        for(int k=(i/3)*3; k<=(i/3)*3+2; k++){
          for(int l=(j/3)*3; l<=(j/3)*3+2; l++){
            if(k==i && l==j)
              continue;
            x+=unknown[k][l][a];}}
        if(x==0){
          known[i][j]=a+1; n++;}}
    }
  }

  }while(n!=0);

  for(int i=0; i<9; i++){
  cout << "Number " << i+1 << ":\n";
    for(int j=0; j<9; j++){
      for(int k=0; k<9; k++){
        cout << unknown[j][k][i];}
      cout << endl; } cout << endl;}

  cout << "Known:\n";

  for(int i=0; i<9; i++){	// print known array
    for(int j=0; j<9; j++){
      cout << known[i][j];}
    cout << endl;}

  return 0;
}