#include<stdio.h>
#define ROW1 2
#define COL1 3
#define ROW2 3
#define COL2 4

int main()
{
  int i, j, k;
float macierz[ROW1][COL1]={
{2,4,5},
{1,3,5},
};
float macierz1[ROW2][COL2]={
{3,8,0,5},
{9,4.4,7,6},
{5,2,1,4},
};
float macierziloczyn[ROW1][COL2];
  for(i=0;i<ROW1;i++)
  {
     for(j=0;j<COL2;j++)
     {       
       macierziloczyn[i][j]=0;
    for(k=0;k<COL1;k++)
    {
      macierziloczyn[i][j]=macierziloczyn[i][j]+macierz[i][k]*macierz1[k][j];
    }
       
     }
  }
   for(i=0;i<ROW1;i++)
  {
     for(j=0;j<COL2;j++)
     {
    printf("%.1f ", macierziloczyn[i][j]);
     }
     printf("\n");
  }

}