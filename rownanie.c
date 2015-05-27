#include <stdio.h>

#include <math.h>




float zero(float a, float b, float c, float *roz1, float *roz2, int *result)

{

  float delta;

  delta=(b*b)-(4*a*c);

  if(delta>0)

  {

    *roz1=(0-b-sqrt(delta))/(2*a);

    *roz2=(0-b+sqrt(delta))/(2*a);

    *result=2;

    return 2;

  }

  else if(delta==0)

  {

    *roz1=(0-b)/(2*a);

    *result=1;

    return 1;

  }

  else

  {

  printf("Brak rozwiazan w zbiorze liczb rzeczywistych\n");

  *result=0;

    return 0;

  }

  

}




main()

{

  float a,b,c, wynik1, wynik2;

  int result;

  printf("Podaj wspolczynnik a rownania:\n");

  scanf("%f" ,&a);

   printf("Podaj wspolczynnik b rownania:\n");

  scanf("%f" ,&b);

   printf("Podaj wspolczynnik c rownania:\n");

  scanf("%f" ,&c);

  zero(a,b,c,&wynik1,&wynik2,&result);

  if(result==2)

  {

  printf("Miejsca zerowe rownania to :\n");

  printf("%f\n i\n", wynik1);

  printf("%f\n", wynik2);

  }

  else if(result==1)

  {

  printf("Miejsce zerowe rownania to :\n");

  printf("%f", wynik1);

  }

  else

  {

  printf(" ");

  }

  

  

}
 