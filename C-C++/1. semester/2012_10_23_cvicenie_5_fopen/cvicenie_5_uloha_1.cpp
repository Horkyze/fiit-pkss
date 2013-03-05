/*
 * cvicenie_5_ulohy_1_az_7.cpp 	
 * Praca so suborom
 * Autor: 		Matej Bellus
 * Date: 		27.10. 2012
 * PKSS 26
*/

#include <stdio.h>

#define abs(x)  ((x < 0)? -x : x)

void uloha1()
{
	FILE * f;
	float n;

	scanf("%f", &n);
	f = fopen ("NASOBKY.TXT","w");
	if (f == NULL) return;
	for (int i = 1 ; i < 11  ; i++)
	{
		fprintf(f, "%2d * %0.2f = %.2f\n", i, n, n*i);
	}
	fclose (f);
}

void uloha2()
{
	FILE * znak;
	FILE * novy;
	char c;
	
	scanf("%c", &c);
	znak = fopen("ZNAK.TXT", "r");
	
	if (c == 's') // tak vypisuje do soboru novy
	{
		// kopirovanie diakritiky do NOVY.TXT je fajn, u mna funguje
		novy = fopen("NOVY.TXT", "w");
		while((c = fgetc(znak)) != EOF)
		{
			fprintf(novy, "%c", c);
		}	
		fclose(novy);
	}
	else
	{
		// vypisovanie diakritiky ze zle, vypisuje to vseliake hatlaniny
		while((c = fgetc(znak)) != EOF)
		{
			printf("%c", c);
		}	
	}
	fclose(znak);
}

void uloha3()
{
	char c;
	int male = 0;
	FILE * vstup;
	FILE * cisla;
	
	vstup = fopen("VSTUP.TXT", "r"); // chceme "r", pretoze iba citame
	cisla = fopen("CISLA.TXT", "a"); // nechceme "w", pretoze w zmaze cely subor -.-
	
	while((c = fgetc(vstup)) != EOF) // EOF (end of file), je znak ktory na nachaza na konci suboru
	{
		(c >= 'a' && c <= 'z') ? male++ : c; // c je tam len tak, nechcelo mi to skompilovat bez toho
		if (c == '\n')
		{
			fprintf(cisla,"\n%i", male);
			male = 0;
		}
		fprintf(cisla,"%c", c);
	}
	
	fclose(vstup);
	fclose(cisla);
}

void uloha4()
{
	char c;
	int medzery = 0;
	FILE * text;

	text = fopen("TEXT.TXT", "r");
	
	while((c = fgetc(text)) != EOF) // kym nebude EOF (v pripade, ze by sa zabudla dat '*')
	{
		// je to v "else if", aby zbytocbe neporovnaval, ked netreba
		if (c == '#'  || c =='$' || c == '&') 
			printf("Precital som riadiaci znak\n");
		else if (c == 'x' || c == 'X')
			printf("Precital som X\n");
		else if (c == 'y' || c == 'Y')
			printf("Precital som Y\n");	
		else if (c == ' ')
			medzery++;
		else if (c == '*')
		{
			printf("Koniec\n");	
			break;
		}	
	}
	printf("Pocet precitanych medzier: %i\n", medzery);	
	fclose(text);
}

/*
 * Trochu som sa pohral s vypisovanim, aby to vyzeralo lepsie :P
 * Ked su vsak '\n' v hociakom subore, tak to vyzera skaredo (lebo printf vypise '\n' tam kde nema)
 * nechcelo sa mi s tym uz viac hrat.
 * Ale funguje to tak ci tak.
 */
void uloha5()
{

	int size1, size2, p, d, i = 1, dlhsi = 0, rozne_znaky = 0;
	char c1, c2;
	
	FILE * prvy;
	FILE * druhy;
	
	prvy = fopen("PRVY.TXT", "r");
	druhy = fopen("DRUHY.TXT", "r");
	
	fseek(prvy, 0, SEEK_END);
	size1 = ftell(prvy);
	fseek(prvy, 0, SEEK_SET);
	
	fseek(druhy, 0, SEEK_END);
	size2 = ftell(druhy);
	fseek(druhy, 0, SEEK_SET);
	
	
	printf("  prvy    druhy \n");
	printf(" %4i   |%4i \n", size1, size2); // vypise dlzky oboch suborov	
	printf("________________\n");
	
    for(i = 1; true; i++ ) 
	{
		p = fread( &c1, 1, 1, prvy );
		d = fread( &c2, 1, 1, druhy);

		if ( p == 0 && d == 0) // ak sa nacitali dva *ziadne znaky* skonci sa citanie
		{
			break;
		}
		else
		{
			if (p == 0) // ak prvy subor uz nema znaky v sebe (prislo sa na jeho koniec)
			{
				printf("        | %3i (%c)        [d = %i]\n", c2, c2, d);
			}
			else if (d == 0) // ak druhy subor uz nema znaky v sebe (prislo sa na jeho koniec)
			{
				printf("%3i (%c) |         [p = %i]\n", c1, c1, p);
			}
			else // ak maju oba znaky v sebe
			{
				if (c1 != c2) // ked su rozne znaky na rovnakej pozicii
				{
					rozne_znaky++;
					if (dlhsi == 0) 
						dlhsi = i;
				}
				printf("%3i (%c) | %3i (%c) [p = %i][d = %i]\n", c1, c1, c2, c2, p, d);
			}
		}
    }
	fclose(prvy);
	fclose(druhy);
	
	if (rozne_znaky == 0 && dlhsi == 0)
		printf("Subory su identicke\n");
	else
	{
		printf("Pocet roznych znakov: %i\n", rozne_znaky);
		if (abs(size1 - size2) > 0)  // makro :)
			printf("Jeden zo suborov je dlhsi o %i znakov\n", abs(size1 - size2));
	}
}

void uloha6()
{
	FILE * prvy;
	FILE * druhy;
	FILE * treti;
	
	prvy = fopen("prvy.txt", "r");
	druhy = fopen("druhy.txt", "r");
	treti = fopen("treti.txt", "w");
}

int main()
{
	uloha6();

	return 0;
}















