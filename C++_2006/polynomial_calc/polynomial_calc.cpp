/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/



//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
void intro(void);
typedef struct node {
float coef;
float exp1;
float exp2;
float exp3;
struct node *next;
char var1,var2,var3;
}list;

void main(void)
{ int i,cf1,size,tmpexp;
  list *fx,*fxptr,*gx,*gxptr,*added,*addedptr,*sum,*sumptr,*dx,*dxptr,
        *dy,*dyptr,*dz,*dzptr,*head,*current,*tmp,*mult,*tmpptr,*multptr;
  char c,fofx[100],cf[10],ex,sign,ans,tmpvar;

size=100; /*size of input buffer*/

/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/


/****************************INTRODUCTION**************************************/
intro();
 for(;;)
      {ans=getch();
       if(ans=='C'||ans=='c')
       {  break;}
       else if(ans=='X'||ans=='x')
       {  exit(0);}
       else
       {}
      }
/***************************end of introduction********************************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/**************************PROMPT FOR DESIRED OPERATIONS***********************/
clrscr();
for(;;)    {      /*loop forever*/
 BACK:
 sign='+';        /*initialized sign to positive*/
   for(;;)                    /*this one ask for command*/
     {clrscr();
      printf("\noperations");
      printf("\nA -> Addition\nS -> Subtraction\nD -> Differentiate\nE -> Exit\n ");
         ans=getch();
          if(ans=='a'||ans=='A'||ans=='s'||ans=='S'||ans=='d'||ans=='D')
          { break; }
          else if(ans=='e'||ans=='E')

   }/*end of for loop*/




/*************************PROMPT FOR INPUT************************************/
 while(i<size)
  ';
   i++;}
  clrscr();
  if(ans=='s'||ans=='S')

  else if(ans=='a'||ans=='A')

  else
    printf("DIFFERENTIATE\n\n");

  printf("\n   f(x,y,z)= ");
  scanf("%s",&fofx);
 i=0;
 while(fofx[i]!='')
 {if(fofx[i]=='^'&&fofx[i+1]=='-')
  {printf("\nERROR: Enter only non-negative exponent!! :)");
   printf("\npress any key to reset...");
   getch();
   goto BACK;}
  i++;
  }
/**********end*/

/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/


/*****************************************************************************/
/***********store the input to linked list*/
/***************************************************************************/

  fxptr=NULL;
  i=0;
  if(fofx[i]=='+')
  
  if(fofx[i]=='-')
  
  while(fofx[i]!='')
  {
    for(cf1=0;cf1<10;cf1++)  /*initialized cf1 */
    ';}

     cf1=0;                              /*scan the coeffecient and store it*/
     while(isdigit(fofx[i])!=0)
     {cf[cf1]=fofx[i];
      cf1++;i++;}
     if(cf1==0)
     

      fx=(list*)malloc(sizeof(list));
      fx->coef=fx->exp1=fx->exp2=fx->exp3=0;
      fx->var1=fx->var2=fx->var3='';
      if(sign=='-')                /*determines the sign of the coef*/
      
      else
                       /*end*/

    for(;;) {
    if(isdigit(fofx[i])==0&&fofx[i]!=''&&fofx[i]!='+'&&fofx[i]!='-')   /*for 1rst variable*/
       {fx->var1=fofx[i];
        i++;
        if(fofx[i]=='^')
        {i++;
         for(cf1=0;cf1<10;cf1++)  /*initialized cf1 */
          ';}

           cf1=0;
           while(isdigit(fofx[i])!=0)
           {cf[cf1]=fofx[i];
            cf1++;i++;}
            fx->exp1=atof(cf);}
         else
          
      } /*endif*/
      if(fofx[i]=='-'||fofx[i]=='+'||fofx[i]=='')
      

      if(isdigit(fofx[i])==0&&fofx[i]!='')   /*for 2nd variable*/
       {fx->var2=fofx[i];
        i++;
        if(fofx[i]=='^')
        {i++;
         for(cf1=0;cf1<10;cf1++)  /*initialized cf1 */
          ';}
           cf1=0;
           while(isdigit(fofx[i])!=0)
           {cf[cf1]=fofx[i];
            cf1++;i++;}
            fx->exp2=atof(cf);}
         else
          
         } /*end of if*/
      if(fofx[i]=='-'||fofx[i]=='+'||fofx[i]=='')
      

      if(isdigit(fofx[i])==0&&fofx[i]!='')   /*for 3rd variable*/
       {fx->var3=fofx[i];
        i++;
        if(fofx[i]=='^')
        {i++;
         for(cf1=0;cf1<10;cf1++)  /*initialized cf1 */
          ';}
           cf1=0;
           while(isdigit(fofx[i])!=0)
           {cf[cf1]=fofx[i];
            cf1++;i++;}
            fx->exp3=atof(cf);}
         else
          
         } /*end of if*/
      if(fofx[i]=='-'||fofx[i]=='+'||fofx[i]=='')
      
    } /*endfor*/

 if(fofx[i]=='+')
 
 if(fofx[i]=='-')
 {i++; sign='-';}
 if(fxptr==NULL)
  {fxptr=fx;
   current=fx;
   }
  else
  {  current->next=fx;
   current=fx;
   }
 }
current->next=NULL;
/***************************************end***********************************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/***************************ORDERED THE INPUT*********************************/
fx=fxptr;
if(fx!=NULL);                      {
for(;;)
{if(fx==NULL)
 
 for(;;) {
 if(fx->var2=='x')
 {tmpvar=fx->var1;
  tmpexp=fx->exp1;
  fx->var1=fx->var2;
  fx->exp1=fx->exp2;
  fx->var2=tmpvar;
  fx->exp2=tmpexp;
  }
 else if(fx->var3=='x')
 {tmpvar=fx->var1;
  tmpexp=fx->exp1;
  fx->var1=fx->var3;
  fx->exp1=fx->exp3;
  fx->var3=tmpvar;
  fx->exp3=tmpexp;
  }
  else
  
 }
 for(;;) {
 if(fx->var1=='y')
 {tmpvar=fx->var2;
  tmpexp=fx->exp2;
  fx->var2=fx->var1;
  fx->exp2=fx->exp1;
  fx->var1=tmpvar;
  fx->exp1=tmpexp;
  }
 else if(fx->var3=='y')
 {tmpvar=fx->var2;
  tmpexp=fx->exp2;
  fx->var2=fx->var3;
  fx->exp2=fx->exp3;
  fx->var3=tmpvar;
  fx->exp3=tmpexp;
  }
  else
  
 }
for(;;) {
 if(fx->var1=='z')
 {tmpvar=fx->var3;
  tmpexp=fx->exp3;
  fx->var3=fx->var1;
  fx->exp3=fx->exp1;
  fx->var1=tmpvar;
  fx->exp1=tmpexp;
  }
 else if(fx->var2=='z')
 {tmpvar=fx->var3;
  tmpexp=fx->exp3;
  fx->var3=fx->var2;
  fx->exp3=fx->exp2;
  fx->var2=tmpvar;
  fx->exp2=tmpexp;
  }
  else
  
 }
 if(fx->var1!='x'&&fx->var1!='')
  {printf("\nERROR: variables must be x,y,and z only!! :=>....\nPress any key to reset");
   getch();
   goto BACK;}
 if(fx->var2!='y'&&fx->var2!='')
  {printf("\nERROR: variables must be x,y,and z only!! :=>....\nPress any key to reset");
   getch();
   goto BACK;}
 if(fx->var3!='z'&&fx->var3!='')
  {printf("\nERROR: variables must be x,y,and z only!! :=>....\nPress any key to reset");
   getch();
   goto BACK;}

 fx=fx->next;
}
                                              }

if(ans=='d'||ans=='D')
{goto DIFF;}
else if(ans=='A'||ans=='a'||ans=='S'||ans=='s')
{goto ADD;}
/******************************INPUT G(X)*************************************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/******************************************************************************/
/*prompt for input*/
/******************************************************************************/
ADD:
BACK2:
sign='+';
  i=0;
  while(i<size)
  ';
   i++;}
  if(ans=='s'||ans=='S')
  {printf(" -");}
  else
  
  printf("\n   g(x,y,z)= ");
  scanf("%s",&fofx);
  i=0;
 while(fofx[i]!='')
 {if(fofx[i]=='^'&&fofx[i+1]=='-')
  {printf("\nERROR: Enter only non-negative exponent!! :)");
   printf("\npress any key to reset...");
   getch();
   goto BACK2;}
  i++;
 }
  /**********end*/

/*****************************************************************************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/***********store the input to linked list*/
/***************************************************************************/

 gxptr=NULL;
  i=0;
  sign='+';
  if(fofx[i]=='+')
  
  if(fofx[i]=='-')
  
  while(fofx[i]!='')
  {
    for(cf1=0;cf1<10;cf1++)  /*initialized cf1 */
    ';}

     cf1=0;                              /*scan the coeffecient and store it*/
     while(isdigit(fofx[i])!=0)
     {cf[cf1]=fofx[i];
      cf1++;i++;}
     if(cf1==0)
     

      gx=(list*)malloc(sizeof(list));
      gx->coef=gx->exp1=gx->exp2=gx->exp3=0;
      gx->var1=gx->var2=gx->var3='';
      if(sign=='-')                /*determines the sign of the coef*/
      
      else
                       /*end*/

    for(;;) {
    if(isdigit(fofx[i])==0&&fofx[i]!=''&&fofx[i]!='+'&&fofx[i]!='-')   /*for 1rst variable*/
       {gx->var1=fofx[i];
        i++;
        if(fofx[i]=='^')
        {i++;
         for(cf1=0;cf1<10;cf1++)  /*initialized cf1 */
          ';}

           cf1=0;
           while(isdigit(fofx[i])!=0)
           {cf[cf1]=fofx[i];
            cf1++;i++;}
            gx->exp1=atof(cf);}
         else
          
      } /*endif*/
      if(fofx[i]=='-'||fofx[i]=='+'||fofx[i]=='')
      

      if(isdigit(fofx[i])==0&&fofx[i]!='')   /*for 2nd variable*/
       {gx->var2=fofx[i];
        i++;
        if(fofx[i]=='^')
        {i++;
         for(cf1=0;cf1<10;cf1++)  /*initialized cf1 */
          ';}
           cf1=0;
           while(isdigit(fofx[i])!=0)
           {cf[cf1]=fofx[i];
            cf1++;i++;}
            gx->exp2=atof(cf);}
         else
          
         } /*end of if*/
      if(fofx[i]=='-'||fofx[i]=='+'||fofx[i]=='')
      

      if(isdigit(fofx[i])==0&&fofx[i]!='')   /*for 3rd variable*/
       {gx->var3=fofx[i];
        i++;
        if(fofx[i]=='^')
        {i++;
         for(cf1=0;cf1<10;cf1++)  /*initialized cf1 */
          ';}
           cf1=0;
           while(isdigit(fofx[i])!=0)
           {cf[cf1]=fofx[i];
            cf1++;i++;}
            gx->exp3=atof(cf);}
         else
          
         } /*end of if*/
      if(fofx[i]=='-'||fofx[i]=='+'||fofx[i]=='')
      
    } /*endfor*/

 if(fofx[i]=='+')
 
 if(fofx[i]=='-')
 {i++; sign='-';}
 if(gxptr==NULL)
  {gxptr=gx;
   current=gx;}
  else
  { current->next=gx;
   current=gx;
   }
 }
current->next=NULL;
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/***************************************end***********************************/
gx=gxptr;
if(gx!=NULL);                      {
for(;;)
{if(gx==NULL)
 
 for(;;) {
 if(gx->var2=='x')
 {tmpvar=gx->var1;
  tmpexp=gx->exp1;
  gx->var1=gx->var2;
  gx->exp1=gx->exp2;
  gx->var2=tmpvar;
  gx->exp2=tmpexp;
  }
 else if(gx->var3=='x')
 {tmpvar=gx->var1;
  tmpexp=gx->exp1;
  gx->var1=gx->var3;
  gx->exp1=gx->exp3;
  gx->var3=tmpvar;
  gx->exp3=tmpexp;
  }
  else
  
 }
 for(;;) {
 if(gx->var1=='y')
 {tmpvar=gx->var2;
  tmpexp=gx->exp2;
  gx->var2=gx->var1;
  gx->exp2=gx->exp1;
  gx->var1=tmpvar;
  gx->exp1=tmpexp;
  }
 else if(gx->var3=='y')
 {tmpvar=gx->var2;
  tmpexp=gx->exp2;
  gx->var2=gx->var3;
  gx->exp2=gx->exp3;
  gx->var3=tmpvar;
  gx->exp3=tmpexp;
  }
  else
  
 }
for(;;) {
 if(gx->var1=='z')
 {tmpvar=gx->var3;
  tmpexp=gx->exp3;
  gx->var3=gx->var1;
  gx->exp3=gx->exp1;
  gx->var1=tmpvar;
  gx->exp1=tmpexp;
  }
 else if(gx->var2=='z')
 {tmpvar=gx->var3;
  tmpexp=gx->exp3;
  gx->var3=gx->var2;
  gx->exp3=gx->exp2;
  gx->var2=tmpvar;
  gx->exp2=tmpexp;
  }
  else
  
 }
if(gx->var1!='x'&&gx->var1!='')
  {printf("\nERROR: variables must be x,y,and z only!! :=>....\nPress any key to reset");
   getch();
   goto BACK2;}
 if(gx->var2!='y'&&gx->var2!='')
  {printf("\nERROR: variables must be x,y,and z only!! :=>....\nPress any key to reset");
   getch();
   goto BACK2;}
 if(gx->var3!='z'&&gx->var3!='')
  {printf("\nERROR: variables must be x,y,and z only!! :=>....\nPress any key to reset");
   getch();
   goto BACK2;}


 gx=gx->next;
}
                                              }


/***************************************************************************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/**************      ADDITION                                    ***********/
/**************************************************************************/

sumptr=NULL;
fx=fxptr;
if(fx!=NULL)
{for(;;)
 { sum=(list*)malloc(sizeof(list));
   *sum=*fx;
  if(sumptr==NULL)
  { sumptr=sum;
   current=sum;
   }
  else
  {  current->next=sum;
   current=sum;
   }
  fx=fx->next;
  if(fx==NULL)
  
}/*end for*/
}/*endif*/




addedptr=NULL;
gx=gxptr;
sum=sumptr;
for(;;)
{for(;;)
  {if(sum->exp1==gx->exp1&&sum->exp2==gx->exp2&&sum->exp3==gx->exp3)
    {if(ans=='s'||ans=='S')
     
     else
      
      added=(list*)malloc(sizeof(list));
      *added=*gx;
     if(addedptr==NULL)
     {addedptr=added;
      current=added;
      }
     else
     {current->next=added;
      current=added;}
    }
   else
   {}
   if(gx->next==NULL)
   
   else
   
 }
 if(sum->next==NULL)
 {gx=gxptr;
  current->next=NULL;
  break;}
 else
 {sum=sum->next;
  gx=gxptr;}
}
/**********************alternative to insertion**************/
/******** */

current=sum;
gx=gxptr;             /*just insert the term which is not added*/
added=addedptr;
if(gx!=NULL) {
for(;;)
{if(addedptr==NULL||added==NULL)
  { sum=(list*)malloc(sizeof(list));
   *sum=*gx;
   if(ans=='s'||ans=='S')
    
   current->next=sum;
   current=sum;
   gx=gx->next;}
 else
 {  if(gx->exp1==added->exp1&&gx->exp2==added->exp2&&gx->exp3==added->exp3)  //nageeror pa dito!!
   {gx=gx->next;
    added=added->next;}
    else
    {sum=(list*)malloc(sizeof(list));
     *sum=*gx;
      if(ans=='s'||ans=='S')
      
     current->next=sum;
     current=sum;
     gx=gx->next;}
  }
 if(gx==NULL)
 { break;}
 }
}
current->next=NULL;
/*****************************************end of addition********************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/************************PRINT THE SUM OR DIFFERENCE************************/
  printf("\nf(x,y,z)=");
  i=1;
  fx=fxptr;
if(fx!=NULL)
{  for(;;)
 {
  printf("(");
  if(fx->coef!=1)
  
  if(fx->var1!=''&&fx->exp1!=0)
  {printf("%c",fx->var1);
   if(fx->exp1!=1)
   }
  if(fx->var2!=''&&fx->exp2!=0)
 { printf("%c",fx->var2);
   if(fx->exp2!=1)
   }
  if(fx->var3!=''&&fx->exp3!=0)
  {printf("%c",fx->var3);
   if(fx->exp3!=1)
    }
  printf(")");
  fx=fx->next;i++;
  if(fx==NULL)
  
  printf(" + ");
  }

}
  printf("\ng(x,y,z)=");
   gx=gxptr;
if(gx!=NULL)
{  for(;;)
 {printf("(");
  if(gx->coef!=1)
   
  if(gx->var1!=''&&gx->exp1!=0)
  {printf("%c",gx->var1);
   if(gx->exp1!=1)
   }
  if(gx->var2!=''&&gx->exp2!=0)
 { printf("%c",gx->var2);
   if(gx->exp2!=1)
   }
  if(gx->var3!=''&gx->exp3!=0)
  {printf("%c",gx->var3);
   if(gx->exp3!=1)
    }
  printf(")");
  gx=gx->next;
  if(gx==NULL)
  
  printf(" + ");
  }
}
if(ans=='s'||ans=='S')

else

  i=1;
  sum=sumptr;
if(sum!=NULL)
{  for(;;)
 {
  printf("(");
  if(sum->coef!=1)
  {printf("%.0f",sum->coef); }
  if(sum->var1!=''&&sum->exp1!=0)
  {printf("%c",sum->var1);
   if(sum->exp1!=1)
    }
  if(sum->var2!=''&&sum->exp2!=0)
 { printf("%c",sum->var2);
   if(sum->exp2!=1)
   }
  if(sum->var3!=''&&sum->exp3!=0)
  {printf("%c",sum->var3);
   if(sum->exp3!=1)
     }
   printf(")");
  sum=sum->next;i++;
  if(sum==NULL)
  
  printf(" + ");
  }
}
/**************************************END OF PRINTING**********************/
free(gx);free(gxptr);
free(added);free(addedptr);
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/


/*********************************DIFFERENTIATE******************************/
/*****************  differentiate with respect to x *****************/
/*****************************************************************************/
if(ans==3)  {
DIFF:


dxptr=NULL;
fx=fxptr;
if(fx!=NULL)  {
  for(;;)
  { if(fx->exp1!=0)
    {dx=(list*)malloc(sizeof(list));
     *dx=*fx;
     dx->coef=fx->coef*fx->exp1;
     dx->exp1=fx->exp1-1;
     if(dxptr==NULL)
      {dxptr=dx;
       current=dx;}
      else
       {current->next=dx;
        current=dx;
       }
     }

 fx=fx->next;
 if(fx==NULL)
 

}
current->next=NULL;
}/*end of ef*/

/*********************************DIFFERENTIATE******************************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/*****************  differentiate with respect to y *****************/
/*****************************************************************************/
dyptr=NULL;
fx=fxptr;
if(fx!=NULL)  {
  for(;;)
  { if(fx->exp2!=0)
    {dy=(list*)malloc(sizeof(list));
     *dy=*fx;
     dy->coef=fx->coef*fx->exp2;
     dy->exp2=fx->exp2-1;
    if(dyptr==NULL)
      {dyptr=dy;
       current=dy; }
      else
       {current->next=dy;
        current=dy;}
     }
   else
    {}
 fx=fx->next;
 if(fx==NULL)
 
}
current->next=NULL;
}/*end of ef*/

/*********************************DIFFERENTIATE******************************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/*****************  differentiate with respect to z *****************/
/*****************************************************************************/

dzptr=NULL;
fx=fxptr;
if(fx!=NULL)  {
  for(;;)
  { if(fx->exp3!=0)
    {dz=(list*)malloc(sizeof(list));
     *dz=*fx;
     dz->coef=fx->coef*fx->exp3;
     dz->exp3=fx->exp3-1;
    if(dzptr==NULL)
      {dzptr=dz;
       current=dz; }
      else
       {current->next=dz;
        current=dz;}
     }
   else
    {}
 fx=fx->next;
 if(fx==NULL)
 
}
current->next=NULL;
}/*end of ef*/
/******************************************************************************/
/************************end of diffentiation*********************************/
/******************************************************************************/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/*****************************************************************************/
/**************print d(f(x,y,z))/dx,dy,dz*************************************/
/*****************************************************************************/
printf("\nd(f(x,y,z))/dx = ");

  dx=dxptr;
if(dx!=NULL)
{  for(;;)
 {printf("(");
  if(dx->coef!=1)
  
  else if(dx->coef==1&&dx->exp1==0)
  
  if(dx->var1!=''&&dx->exp1!=0)
  {printf("%c",dx->var1);
   if(dx->exp1!=1)
    }
  if(dx->var2!=''&&dx->exp2!=0)
 { printf("%c",dx->var2);
   if(dx->exp2!=1)
    }
  if(dx->var3!=''&&dx->exp3!=0)
  {printf("%c",dx->var3);
   if(dx->exp3!=1)
     }
  printf(")");
  dx=dx->next;i++;
  if(dx==NULL)
  
  printf(" + ");
  }
}

printf("\nd(f(x,y,z))/dy = ");

dy=dyptr;
if(dy!=NULL)
{  for(;;)
 { printf("(");
  if(dy->coef!=1)
  
  else if(dy->coef==1&&dy->exp1==0)
  
  if(dy->var1!=''&&dy->exp1!=0)
  {printf("%c",dy->var1);
   if(dy->exp1!=1)
    }
  if(dy->var2!=''&&dy->exp2!=0)
 { printf("%c",dy->var2);
   if(dy->exp2!=1)
   }
  if(dy->var3!=''&&dy->exp3!=0)
  {printf("%c",dy->var3);
   if(dy->exp3!=1)
     }
  printf(")");
  dy=dy->next;i++;
  if(dy==NULL)
  
  printf(" + ");
  }
}

printf("\nd(f(x,y,z))/dz = ");
  i=1;
  dz=dzptr;
if(dz!=NULL)
{  for(;;)
 {
  printf("(");
  if(dz->coef!=1)
  
  else if(dz->coef==1&&dz->exp1==0)
  
  if(dz->var1!=''&&dz->exp1!=0)
  {printf("%c",dz->var1);
   if(dz->exp1!=1)
    }
  if(dz->var2!=''&&dz->exp2!=0)
 { printf("%c",dz->var2);
   if(dz->exp2!=1)
    }
  if(dz->var3!=''&&dz->exp3!=0)
  {printf("%c",dz->var3);
   if(dz->exp3!=1)
     }
  printf(")");
  dz=dz->next;i++;
  if(dz==NULL)
  
  printf(" + ");
  }
}

}


free(fx);free(fxptr);


 for(;;)                                    /*wala lang*/
  {  textcolor(GREEN);
     gotoxy(10,25);
     cprintf("N-New");
     gotoxy(25,25);
     cprintf("X-Exit program");
     ans=getch();
     if(ans=='N'||ans=='n')
     
     else if(ans=='X'||ans=='x')
      
     else
     {}

  }


} /*end of the big loop*/


  }
/*---------------------------------------------------------------------------*/
/****************************************************/
/*
Full documentation and executable file available at:
www.jcmiras.net/computers_and_internet/polynomial_calculator/index.html
*/
/****************************************************/

/***************************************************************************/
/**************USER DEFINED FUNCTIONS*****************************************/
void intro(void)
{randomize();
textcolor(GREEN);
gotoxy(1,1);
cprintf("This program performs the three (3) basic polynomial calculations.");
gotoxy(1,2);
cprintf("Such 3 operations are: polynomial addition, subtraction and diffentiation. ");
gotoxy(1,3);
cprintf("Due to time constraint, the program was not able to perform multiplication");
textcolor(GREEN);
gotoxy(1,5);
cprintf("This program was implemented using single linked list.");
textcolor(GREEN);

textcolor(GREEN);
gotoxy(1,10);
cprintf("created by: Alfie    1999-27908 CS32 MHW");
gotoxy(1,11);
cprintf("Last revision: August 18, 2003,1:00pm at EPRL");

textcolor(GREEN);
gotoxy(25,25);
cprintf("C-Continue");
gotoxy(40,25);
cprintf("X-Exit");

}



