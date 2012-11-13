/*
 * cvicenie_8
 * Autor: Matej Bellus
 * PKSS 4. roc | skupina 26
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N ('Z' - 'A' + 1)
#define LINE_MAX_LENGTH 200

// Functions for debuging purposes 
void print_r(float a[], int n) 
{ 
    for(int i = 0; i < n; i++) 
    { 
        printf("\t [%3i] = %.2f\n", i, a[i]); 
    } 
} 
void print_r(int a[], int n) 
{ 
    for(int i = 0; i < n; i++) 
    { 
        printf("\t [%3i] = %i\n", i, a[i]); 
    } 
} 
void print_r(char a[], int n) 
{ 
    for(int i = 0; i < n; i++) 
    { 
        printf("\t [%3i] = '%c'\n", i, a[i]); 
    } 
}

void hist()
{
		int i = 0;
	int hist[N] = {0};
	char slovo[100];

	scanf("%s", slovo);  

	while (i < 100 && slovo[i] != '\0') 
	{  
		hist[toupper(slovo[i]) - 'A']++;
		i++;
	}

	for(i = 0; i < N; i++)    /* vypis hist */
		if(hist[i] != 0)
			printf("%c: %d\n", i+'A', hist[i]);
	
	for(i = 0; i < N; i++)    /* vypis hist */
		printf("\t[%3i] = %i\n", i, hist[i]);

	int max = 0;
	for(i = 0; i < N; i++)
	{
		if (hist[i] > max) max = hist[i];
	}
	printf("Max: %i\n", max);

	for(int level = max; level >= 0; level--) // for each row i
	{
		printf("%3i - ", level+1);
		for(int n = 0; n < N; n++) // for each colum n
		{
			if (hist[n] > 0)
			if((hist[n] > level))
				printf("%c%c%c ",(char)219,(char)219,(char)219);
			else 
				printf("    ");
		}
		printf("\n");
	}
	printf("      ");
	for(int n = 0; n < N; n++) // for each colum n
	{
		if (hist[n] > 0)
		 printf(" %c  ", n + 'a');
	}
}

void uloha1()
{
	FILE * f;
	char file_name[20];
	scanf("%s", file_name);

	( (f = fopen(file_name,"r")) == NULL) ? exit(1) : f;

    char c = 'A';
	printf("   ");
	while (c <= 'Z')
	{
		printf("%2c ", c++);
	}
	printf("\n");

	int hist[26] = {0};
	int row = 1;
	for(int i = 0; fscanf(f, "%c", &c) != EOF; i++)
	{
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) // ak mame pismeno
		{
			c = toupper(c);
			hist[(int)c - 'A']++;
		}
		else if (c == '\n') // koniec riadku, vypisat histogram
		{
			printf("%2i ", row);
			for(int k = 0; k < 26; k++)
			{
				printf("%2i ", hist[k]);
				hist[k] = 0; // postupne vynulovat, pripravit na dalsi riadok
			}
			printf("\n");
			row++;
			
		}
	}
	printf("%2i ", row);
	for(int k = 0; k < 26; k++)
	{
		printf("%2i ", hist[k]);
		hist[k] = 0; // postupne vynulovat, pripravit na dalsi riadok
	}
	printf("\n");
}

int parne(int x[], int y[], int pocet)
{
	int i = 0, pocet_parnych = 0;
	for(; i < pocet; i++)
	{
		if(x[i] % 2 == 0)
		{
			y[pocet_parnych] = x[i];
			pocet_parnych++;
		}
	}
	return pocet_parnych;
}

void uloha2()
{
	int n, i = 0;
	int input[50] = {0};
	int output[50];

	scanf("%i", &n);

	for(i = 0; i < n; i++)
	{
		scanf("%i", &input[i]);
	}

	printf("Povodne pole:");
	for(i = 0; i < n; i++)
	{
		printf(" %i", input[i]);
	}
	printf("\n");

	printf("Pocet parnych prvkov pola: %i\n", parne(input, output ,n));

	printf("Parne cisla:");
	for(i = 0; i < parne(input, output ,n); i++)
	{
		printf(" %i", output[i]);
	}
	printf("\n");
}

int main() 
{

	uloha1();

	getchar();
	getchar();
	return 0;
}
