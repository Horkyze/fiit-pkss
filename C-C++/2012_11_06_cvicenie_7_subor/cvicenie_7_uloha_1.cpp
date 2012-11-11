/*
 * Subor
 * Autor: 		Matej Bellus
 * Date: 		26.11. 2012
 * PKSS 26
*/

#include <stdio.h>

FILE * file;
float cislo, nasob, suma = 0;
int i = 0;

int otvor()
{
	file = fopen("subor.txt", "r");
	if (file == NULL)
	{
		printf("Subor sa neda otvorit!\n");
		return 0;
	}
	return 1;
}

float vynasob(float a, float b)
{
	return a*b;
}


int main()
{
	scanf("%f", &nasob);
	if (!otvor())
		return 1;

	while(fscanf(file, "%f\n", &cislo) > 0)
	{
		suma += cislo;
		printf("%.2f * %.2f = %.2f\n", cislo, nasob, vynasob(cislo,nasob));
		i++;
	}
	printf("Priemer vysledkov: %.2f/%i = %.2f\n", suma, i, (float)suma/i);

	if (fclose(file) != 0)
	{
		printf("Subor sa neda zatvorit!\n");
		return 1;
	}
	return 0;
}