#include <stdio.h>
#include<math.h>

struct zesp
{
  float re;
  float im;
};
typedef struct zesp zespolona;
zespolona dodaj_zesp(zespolona x, zespolona y);
float modul(zespolona x);
zespolona sprzezenie(zespolona x);
void wypisz_zesp(zespolona a) 
{
printf("%.2f %+.2fi \n", a.re, a.im);
} 



int main()
{
  zespolona a, b;
printf ("Podaj dwie liczby zespolone(czesc rzeczywista, enter, czesc urojona):\n a:\n");
scanf("%f", &a.re);
scanf("%f", &a.im);
printf(" b:\n");
scanf("%f", &b.re);
scanf("%f", &b.im);

printf("wynik dodawania dwoch liczb zespolonych to:\n");
wypisz_zesp(dodaj_zesp(a, b));
printf("modul liczby zespolonej a to:\n");
printf("%f\n", modul(a));
printf("sprzezenie liczby a to:\n");
wypisz_zesp(sprzezenie(a));

return 0;
}

zespolona dodaj_zesp(zespolona x,zespolona y)
{
zespolona b;
b.re=x.re+y.re;
b.im=x.im+y.im;
return b;
}

float modul(zespolona x)
{
return sqrt(x.re*x.re + x.im*x.im);
}

zespolona sprzezenie(zespolona x)
{
zespolona s;
s.re=x.re;
s.im=-1*x.im;
return s;
}