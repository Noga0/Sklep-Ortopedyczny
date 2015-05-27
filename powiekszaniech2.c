#include <stdio.h>

#include <stdlib.h>

#define ROZMIAR 100

char * deleteLastChar(char* s)

{

int i;

for(i=0; (i<ROZMIAR) && (s[i]!='\0');i++)

{}

if(s[i-1]=='\n')

{

i--;

}

char *nowynapis;

nowynapis = malloc(i*sizeof(char));

if(nowynapis==NULL)

{

return s;

}

nowynapis[i-1]='\0';

for(i; i>1; i--)

{

nowynapis[i-2]=s[i-2];

}

free(s);

return nowynapis;

}

int main()

{

char *napis;

napis = malloc(ROZMIAR * sizeof(char));

fgets(napis, ROZMIAR, stdin);

napis = deleteLastChar(napis);

puts(napis);

}
 
 printf("change1");
  
 printf("change2");