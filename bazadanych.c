#include <stdio.h>

#include <stdlib.h>




typedef struct{

int index;

char imie[40];

char nazwisko[40];

long numer;

}baza;







void dodaj(baza **ptab, int *dlug)

{

baza *tab=malloc((*dlug+1)*sizeof(baza));

if(tab==NULL)

{

free(*ptab);

return;

}

int przepisz;

for(przepisz=0;przepisz<(*dlug);przepisz++)

{

tab[przepisz]=(*ptab)[przepisz];

}

tab[(*dlug)].index=(*dlug+1);

printf("Podaj imie:\n");

fgets((tab[(*dlug)].imie),40,stdin);

printf("Podaj nazwisko:\n");

fgets(tab[(*dlug)].nazwisko,40,stdin);

printf("Podaj numer telefonu:\n");

scanf("%ld",&tab[(*dlug)].numer);

free(*ptab);

*dlug=przepisz+1;

*ptab=tab;

}




void print(baza *wsk)

{

printf("%d\n", wsk->index);

puts(wsk->imie);

puts(wsk->nazwisko);

printf("%ld\n", wsk->numer);

}




int search(baza *tab, int dlug)

{

long numer;

printf("Podaj numer do wyszukania:\n");

scanf("%ld", &numer);

int i;

for(i=0;tab[i].numer!=numer;i++);

if(i>dlug)

{

printf("-1");

}

else

{

print(&tab[i]);

}

return i;

}







int main()

{

int dlugosc=0;

int wybor;

char enter;

baza *tablica=NULL;

int run=1;

while(run==1)

{

printf("Co chcesz zrobic?\n 1)Dodaj rekord\n 2)Wyszukaj i Wypisz\n 3)Zakoncz\n");

scanf("%d", &wybor);

while(scanf("%c", &enter)=="\n");

{

switch(wybor)

{

case 1:

{

dodaj(&tablica,&dlugosc);

break;

}

case 2:

{

if(dlugosc<1)

{

printf("Baza jest pusta\n");

break;

}

else

{

search(tablica,dlugosc);

break;

}

}

case 3:

{

run=0;

free(tablica);

break;


}

}

}

}

printf("Koniec programu\n");
