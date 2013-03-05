/*
 * cvicenie_2_uloha_2_az_5.cpp 	
 * V main si treba vybrat ktoru ulohu spustit.
 * Autor: 			Matej Bellus
 * Date: 			2.10. 2012
*/

#include <stdio.h>
#include <stdlib.h>

void ulaha2()
{
	int a, b, c = 0;
	scanf("%i %i %i",&a, &b, &c);
	printf("%i\n", a*b*c);
}

void uloha3()
{
	float a, b, c;
	scanf("%f %f %f",&a, &b, &c);
	printf("Priemer cisel %f %f %f je: %f\n", a,b,c,((a+b+c)/3));
}

void uloha4()
{
	float a;
	scanf("%f",&a);
	printf("Cena bez dane:  %f\n",a);
	printf("Predajna cena s danou 20%%: %f\n",a*1.2);
}

void uloha5()
{
	float vyska, mass;
	scanf("%f %f",&vyska, &mass);
	vyska = vyska/100;
	printf("BMI:  %.3f\n",(mass)/(vyska*vyska));
}

int main(void)
{
	uloha5();
	system("PAUSE");
	return 0;
}