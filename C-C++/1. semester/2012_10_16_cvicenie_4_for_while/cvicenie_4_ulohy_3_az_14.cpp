/*
 * V niektorych prikladoch je pouzity string, to sme zatial nebrali, ale myslim ze inak sa to ani neda spravit.
 * Ak sa to da aj bez stringu alebo pola, tak budem prekvapeni.
 * Horkyze (Matej Bellus) - 16.10.2012
 */

/*
 * cvicenie_4_ulohy_3_az_14.cpp 	
 * Cykly, String, Pole
 * Autor: 		Matej Bellus
 * Date: 		16.10. 2012
 * PKSS 26
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int uloha3()
{
	int n, c;
	scanf("%i", &n);
	
	if ((n < 1) || (n > 15))
	{
		printf("Cislo nie je z daneho intervalu");
		return 0;
	}
	c = n;
	for (int i = 0; i < n; i++)
	{
		printf("%i:", i+1);

		for (int k = c; k > 0; k--)
		{
			printf(" %2i", k);
		}
		c--;
		printf("\n");
	}
}

// vypise riadok s hviezdickami a pomlckami
// p je pocet hviezdiciek, n je pocet znakov v riadku
// priklad riadok(2,5) vypise "**---"
void riadok(int p, int n) 
{
		for(int i = 0; i < p; i++)
			printf("*");
		for(int i = p; i < n; i++)
			printf("-");
}

int uloha4()
{
	int n;
	scanf("%i", &n);

	if ( !((n < 1) || (n > 150)) && ((n%2) == 0 ))
	{
		printf("Cislo nie je z daneho intervalu");
		return 0;
	}
	for(int r = 1; r <= n; r++)
	{
		riadok(r,n);
		printf("\n");
	}
	
	for(int r = n-1; r > 0; r--)
	{
		riadok(r,n);
		printf("\n");
	}
	return 0;
}

void riadok2(int r, int n)
{
     if (r == n/2)
     {
         for (int i = 0; i < n; i++)
         {   
             printf("*");
         }   
     }
     else
     {
         for (int i = 0; i < n; i++)
         {   
             (i == r || i == n/2 || i == n-r-1) ? printf("*") : printf("-");
         }
     }
}

void uloha5()
{
	int n;
	scanf("%i", &n);
	if ( !((n < 1) || (n > 150)) && ((n%2) == 0 ))
	{
		printf("Zly vstup");
		return;
	}
	for (int r = 0; r < n; r++)
	{
        riadok2(r,n);      
        printf("\n");
    }
	
}

void uloha6()
{
     int i = 0;
     while(i < 10)    
     {
          printf("%d. \n", i+1);	
          i++;
     }
}

void uloha7()
{
     char c;
     string s = "";
     while(true) // nacitavanie, skonci ked c == *
     {
          scanf("%c",&c);
          if(c == '*') break;
          s += c;	     
     }
     
     for (int i = 0; i < s.length(); i++)
     {
        c = s[i];
        if (c >= 'a' && c <= 'z')
           printf("%c",c-32);
        else if (c >= 'A' && c <= 'Z')
           printf("%c",c);
        else if (c == '\t' || c == '\n')
           printf(" ");
        else 
           printf("-");
     }
     printf("*\n");
}

void uloha8()
{
     int velke = 0;
     int male = 0;
     char c;
     string s;
     getline(cin,s);
     for (int i = 0; i < s.length(); i++)
     {
         c = s[i];
         if (c >= 'A' && c <= 'Z')
            velke++;
         if (c >= 'a' && c <= 'z')
            male++;
     }

     printf("%i %i\n", male, velke);
}

void uloha9()
{
     int n,c;
     char buffer [33];
     scanf("%i", &n);
     
     string s = ""; 
     
     for(int i = 0; i < n; i++)
     {
             scanf("%i",&c);
             if ((c > 0) && (c <= 100))
             {
                itoa(c,buffer,10);
				s += buffer;
				s += " "; 
             }
     }
     cout << s << endl;
}

void uloha10()
{
	int a, b;
	scanf("%i %i", &a, &b);

	for(int i = a; i <= b; i++)
	{
		if (i % 3 == 0)
			printf("%i ", i);
	}
}

void uloha11()
{
	int a, b, d;
	scanf("%i %i %d", &a, &b, &d);

	for(int i = a; i <= b; i++)
	{
		if (i % d == 0)
			printf("%i ", i);
	}
}

void uloha12()
{
	float vyska, mass, bmi;
	int n, podvaha = 0, normal = 0, nadvaha = 0, tucko = 0;
	scanf("%i", &n);
	float bmis[100] = {NULL}; // bmis[n] mi nechce zobrat. Takto sa to nema robit, 
	// ale nebudem tu dynamicky alokovat pamet. Keby ich na vtupe bolo viac
	// ako 100, tak program ma pruser == spadne.
	for(int i = 0; i < n; i++)
	{
		scanf("%f %f",&vyska, &mass);
		vyska = vyska/100;
		bmi = (mass)/(vyska*vyska);
		bmis[i] = (mass)/(vyska*vyska);
		if (bmi <= 18.5)
			podvaha++;
		if ((bmi > 18.5) && (bmi < 25))
			normal++;
		if ((bmi >= 25) && (bmi < 30))
			nadvaha++;
		if (bmi >= 30)
			tucko++;
	}
	for(int i = 0; i < 100; i++)
	{
		if (bmis[i] != NULL)
		{
			printf("%.3f\n", bmis[i]);
		}
		else // ked narazi na prvu NULL, tak vsetky ostatne su uz NULL
		{    // tak netreba robit cely cyklus
			break;
		}
	}
	printf("Podvaha: %i\n", podvaha);
	printf("Normalna hmotnost: %i\n", normal);
	printf("Nadvaha: %i\n", nadvaha);
	printf("Obezita: %i\n", tucko);
}

// funguje iba do urciteho rozsahu, pretoze faktorial je velmi velke cislo
void uloha13()
{
	long sum;
	int n;
	scanf("%i", &n);
	sum = 1;

	for(int i = 2; i <= n; i++)
		sum = sum * i;
	printf("%i", sum);
}

void uloha14()
{
	int n, i, pred;
	bool ok = false;
	scanf("%i", &n);

	for(int k = 1; k <= n; k++)
	{
		if ( k > 1)
		{
			pred = i;
		}
		scanf("%i", &i);
		if ( (k == 1) && (i < 11) && (i > -1) ) // if podmiakna a je OK		
		{
			ok =  true;
		}

		if ( ! ((k > 1) && (i <= pred*2) && (i >= pred/2)) )
		{
			ok = false;
		}
	}
	(ok) ? printf("Postupnost je spravna\n") : printf("Postupnost nie je spravna\n");
	
}

int main()
{
	uloha14();	

	system("PAUSE");
	return 0;
}
