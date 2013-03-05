#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "znaky.txt"

int male_pismeno(char c);
int velke_pismeno(char c);
int cislica(char c);
int biely(char c);

void zisti(FILE * fd, int (*funcPtr)(char) );


int main()
{
	int n; 	// kolko krat vykonavat program
	char f;	// co treba vykonat? 'c' || 'b' || 'v' || 'm'
	FILE * fd; // file pointer

	// pointer na funkciu
	// funkcia typu 'int' a ma argument 'char'
	int (*funcPtr)(char);

	// otvorenie suboru
	if ( (fd = fopen(FILE_NAME, "r")) == NULL)
	{
		printf("%s\n", "Neotvoreny subor..\n");
		exit(1);
	}


	scanf("%i", &n);
	// getchar() treba, lebo inak sa '\n' posuva do dalsieho scanf, ktory je vo while
	getchar();

	while(n > 0)
	{
		scanf("%c", &f);
		// to iste ako hore...
		getchar();

		// do funcPtr sa priradi potrebna funkcia
		switch(f)
		{
			case 'c':
				funcPtr = &cislica;
				break;
			case 'b':
				funcPtr = &biely;
				break;
			case 'm':
				funcPtr = &male_pismeno;
				break;
			case 'v':
				funcPtr = &velke_pismeno;
				break;
		}
		
		n--;

		// volanie zisti, s pozadovanou funkcioum
		// da sa robit priamo vo switchi, napr: zisti(fd, &biely); ci?
		zisti(fd, funcPtr);
	}


	return 0;
}

void zisti(FILE * fd, int (*funcPtr)(char) )
{
	char c; // citany znak
	int suma = 0; // sucet znakov

	// preistotu nastavit pointer na zaciatok
	fseek ( fd , 0 , SEEK_SET );

	// pismenko po pismenku
	while( fscanf(fd, "%c", &c) != EOF)
	{
		// volanie funkcie
		if ( (*funcPtr) (c) )
			suma++;
	}

	printf("%i\n", suma);
}

int male_pismeno(char c)
{
	return (c >= 'a' && c <= 'z');
}

int velke_pismeno(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int cislica(char c)
{
	return (c >= '0' && c <= '9');
}

int biely(char c)
{
	return (c == '\t' || c == ' ' || c == '\n');
}



