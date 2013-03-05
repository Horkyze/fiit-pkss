/*
 * cvicenie_10
 * Autor: Matej Bellus
 * PKSS 4. roc | skupina 26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 	vlozi do s[] od pozicie i s2[]
//	s[] ma MAX dlzku d

//	s: "totojeretazec", i: 6, s2: "druhy"
//	s-> "totojedruhyretazec"
void strinsert(char s[], int d, char s2[], int i)
{
	if (i + sizeof(s2)-1 > d)
	{
		printf("Moc malo miesta..\n");
		return;
	}
}

void strdelete(char s[], int n, int i)
{
}

int main()
{
	char s[] = "totojeretazeccc";
	char s2[] = "druhy";
	int i = 6;
	int d = sizeof(s2)-1;
	printf("size(d): %i\n", d);
	//strinsert(char s[], int d, char s2[], int i)

	return 0;
}
