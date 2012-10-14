/*
 * cvicenie_3_uloha_1.cpp 	
 * Terarny operator a if/else
 * Autor: 			Matej Bellus
 * Date: 			9.10. 2012
*/

#include <stdio.h>

int main()
{
	char c;
	scanf("%c", &c);

	((47 < c)  && (c < 58)) ? printf("%c\n", c) : printf("ZNAK\n");

	if ( (47 < c)  && (c < 58))
	{
		printf("%c\n", c);
	}
	else
	{
		printf("ZNAK\n");
	}

	return 0;
}
