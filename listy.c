#include <stdio.h>

#include <stdlib.h>




typedef struct element{

struct element *next;

char imie[30];

char nazwisko[30];

long data_ur;

}elem_listy;




void RemoveEndingEnter(char* s, int max_size)

{

int i;

for(i = max_size-1; i >= 0; i--)

if(s[i] == '\n')

{

s[i] = 0;

return;

}

return;

}




void wypisz(elem_listy *lista)

{

  elem_listy *wsk=lista;

  while(wsk!=NULL)

  {

    puts(wsk->imie);

    puts(wsk->nazwisko);

    printf("%ld \n", wsk->data_ur);

    wsk=wsk->next;

  }

}




void dodajpocz(elem_listy **head)

{

  elem_listy *ptr;

  ptr=malloc(sizeof(elem_listy));

  if(ptr==NULL)

  {

    printf("Nie udalo sie przydzielic pamieci.\n");

    return;

  }

  printf("Podaj imie:\n");

  fgets(ptr->imie,30,stdin);

  RemoveEndingEnter(ptr->imie,30);

  printf("Podaj nazwisko:\n");

  fgets(ptr->nazwisko,30,stdin);

  RemoveEndingEnter(ptr->nazwisko,30);

  printf("Podaj date urodzenia:\n");

  scanf("%ld", &(ptr->data_ur));

  ptr->next=*head;

  *head=ptr;

  return;

}




void usunkoniec(elem_listy **head)

{

if((*head)->next==NULL)

{

free(*head);

*head=NULL;

}

elem_listy *ptr=*head;

  while(ptr->next->next!=NULL)

  {

  ptr=ptr->next;

  }

  free(ptr->next);

  ptr->next=NULL;

}




void szukaj(elem_listy *lista)

  {

    elem_listy *ptr=lista;

    long rok_ur;

    printf("Podaj szukany rok urodzenia:\n");

    scanf("%ld", &rok_ur);

    while(ptr!=NULL)

    {

      if(ptr->data_ur==rok_ur)

      {

    puts(ptr->imie);

    puts(ptr->nazwisko);

    printf("%ld", ptr->data_ur);

    return;

      }

    ptr=ptr->next;

    }

  }

  

void zwolnij(elem_listy **head)

{

elem_listy *ptr=(*head)->next;

while(ptr!=NULL)

{

free(*head);

ptr=ptr->next;

}

}




int main()

{

  elem_listy *head=NULL;

  dodajpocz(&head);

  int run=1;

  while(run==1)

  {

  printf("Co chcesz zrobic?\n 1)Dodaj elementy\n 2)Wypisz liste\n 3)Usun element z konca listy\n 4)Usun cala liste\n 5)Koniec programu\n");

  int x;

  scanf("%d", &x);

  switch (x){

    case 1:

    printf("Ile elementow chcesz dodac?\n");

    int ilosc;

    scanf("%d", &ilosc);

    int i;

    for(i=0;i<ilosc;i++)

    {

    dodajpocz(&head);

    }

    break;

    case 2:

    wypisz(head);

    break;

    case 3:

    usunkoniec(&head);

    break;

    case 4:

    zwolnij(&head);

    break;

    case 5:

    run=0;

    break;

  }

  }

  free(head);

  return 0;

}
