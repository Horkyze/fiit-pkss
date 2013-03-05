/* 
 *  Matej Bellus
 *	Kontrola sumy a ladenie pomocou makier
 *  30.10. 2012
 */

#include <stdlib.h>
#include <stdio.h>

#define priemer_makro(x,y) ((x+y)/2)


#define LADENIE_ZAKLADNE
#define LADENIE_PODROBNE

void uloha1()
{
	float a,b;
	scanf("%f %f", &a, &b);
	printf("Priemer pomocou makra: %.3f\n", (float)priemer_makro(a,b) );
}

int main()
{
	FILE * f;
	float suma = 0; 
	float suma1 = 0;
	float a = 0;
	bool spravna = false;
	bool zavrety = false;

		#ifdef LADENIE_PODROBNE
			#ifdef LADENIE_PODROBNE
				#define LADENIE_ZAKLADNE
			#endif
		#endif

		#ifdef LADENIE_ZAKLADNE
			printf("Otvaranie suboru\n");
		#endif

	if ((f = fopen("suma.txt", "r")) == NULL) 
	{
		//printf("Subor sa nepodarilo otvorit.\n");
		return 1;
	}

		#ifdef LADENIE_PODROBNE
			printf("Subor otvoreny\n");
		#endif

		#ifdef LADENIE_ZAKLADNE
			printf("Kontrola sumy\n");
		#endif
	
	fscanf(f, "%f\n", &suma);


	while (fscanf(f, "%f\n", &a) != EOF)
	{
		suma1 += a;
		#ifdef LADENIE_PODROBNE
			printf("Sucet: %f\n", suma1);
		#endif
	}

		#ifdef LADENIE_ZAKLADNE
			if (suma1 == suma)
				printf("Suma je spravna\n");
			else
			{
				printf("Suma je nespravna\n");
			}
		#endif

		#ifdef LADENIE_PODROBNE
			printf("Suma skontrolovana\n");
		#endif
		
		#ifdef LADENIE_ZAKLADNE
			printf("Zatvaranie suboru\n");
		#endif

	if (fclose(f) == 0)
		zavrety = true;

		#ifdef LADENIE_PODROBNE
			if (zavrety)
				printf("Subor zatvoreny\n");
		#endif

	return 0;
}