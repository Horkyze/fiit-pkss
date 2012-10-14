/*
 * cvicenie_3_ulohy_1_az_6.cpp 	
 * if/else/terarny operator/ praca s float
 * Autor: 			Matej Bellus
 * Date: 			2.10. 2012
*/

#include <stdio.h>
#include <stdlib.h>
void uhloha1()
{
	char c;
	scanf("%c",&c);
	
	((47 < c)  && (c < 58)) ? printf("%c\n", c) : printf("ZNAK\n");  

	if ( (47 < c)  && (c < 58))
	{
		printf("%c\n", c);
	}
	else
	{
		printf("ZNAK\n");
	}

	getchar();
}

void uhloha2()
{
	char c;
	scanf("%c",&c);
	((47 < c)  && (c < 91))  ? printf("Alfanumericky znak\n", c) : printf("Interpunkcny znak\n");
}

void uhloha3()
{
	char a,b;
	scanf("%c %c",&a, &b);
	printf("%c %i \n", a-32, a-32);
	printf("%c %i \n", b-32, b-32);
}

void uhloha4()
{
	char a,b;
	scanf("%c %c",&a, &b);
	printf("%c ", b+32);
	printf("%c/n", a+32);
}

void uhloha5()
{
	float f,c;
	scanf("%f",&f);
	c = ((f - 32)*5)/9;
	printf("%.2f\n", c);
	if (c<0) printf("Mrzne\n");
	if (c>99) printf("Vrie\n");

}

void uhloha6()
{
	float vyska, mass, bmi;
	scanf("%f %f",&vyska, &mass);
	vyska = vyska/100;
	bmi = (mass)/(vyska*vyska);
	printf("BMI:  %.3f\n",(mass)/(vyska*vyska));
	if (bmi <= 18.5)
		printf("Podvaha\n");
	if ((bmi > 18.5) && (bmi < 25))
		printf("Normalna hmotnost\n");
	if ((bmi >= 25) && (bmi < 30))
		printf("Nadvaha\n");
	if (bmi >= 30)
		printf("Obezita\n");

}

int main()
{
	uhloha6();
	system("PAUSE");
	return 0;
}
