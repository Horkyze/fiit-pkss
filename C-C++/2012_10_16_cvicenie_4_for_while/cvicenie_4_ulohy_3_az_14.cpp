/*
 * bellus_cvicenie_4_uloha_2.cpp 	
 * Cykly
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

int main()
{
	uloha8();	


	system("PAUSE");
	return 0;
}
