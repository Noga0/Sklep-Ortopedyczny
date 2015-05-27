#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int** tab, int n)
{
  int a=1;
  int i,k;
for(i=0;i<n;i++)
  {
    for(k=0;k<n;k++)
    {
      tab[i][k]=a;
      a++;
    }
  }
}



void deleteMatrix(int*** ptab, int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    free((*ptab)[i]);
    (*ptab)[i]=NULL;
  }
  free((*ptab));
  (*ptab)=NULL;
}


int** createMatrix(int n)
{
int i;
int **tab;
  tab=malloc(n*sizeof(int*));
  for(i=0;i<n;i++)
    {
      tab[i]=malloc(n*sizeof(int));
      if(tab[i]==NULL) 
      {
    deleteMatrix(&tab,n);
    return NULL;
      }
    }
return tab;
}


void copyMatrix(int*** dest, int** src, int n)
{
  int i,k;
  *dest=createMatrix(n);
  for(i=0;i<n;i++)
    {
      for(k=0;k<n;k++)
    {
      (*dest)[i][k]=src[i][k];
    }
    } 
}

int main()
{
  int i,k,n;
int **tablica;
printf("Podaj rozmiar tablicy X na X:\n");
scanf("%d", &n);
int **ret=createMatrix(n);

fillMatrix(ret,n);

copyMatrix(&tablica,ret,n);
for(i=0;i<n;i++)
{
  for(k=0;k<n;k++)
      {
    printf("%3d", tablica[i][k]);
      }
      printf("\n");
}      


return 0;
}

