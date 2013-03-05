/* 
 *  Matej Bellus
 *	cvic 2. u. 4
 *  30.10. 2012
 */

#include <stdlib.h>
#include <stdio.h>

double tyzdenna_mzda(double h_mzda, double hod)
{
	int i = 0;
	double love = 0;
	
	printf("h_mzda =  %f \t hod =  %f \n", h_mzda, hod);
	for(i = 0; i < hod; i++ )
	{
		if(i < 40)
			love += h_mzda;
		else if(i < 60)
			love += 1.5*h_mzda;
		else
			love += 2*h_mzda;
	}
	return love;
}

int main()
{
	double h_mzda, hod, suma = 0, m;
	int n;
	scanf("%i", &n);
	
	while(n--)
	{
		scanf("%lf %lf", &h_mzda, &hod);
		m = tyzdenna_mzda(h_mzda, hod);
		suma += m;
		printf("Hod. mzda: %.2f SKK/hod, hodin: %.2f, spolu: %.2f SKK\n", h_mzda, hod, m);		
	}
	printf("Celkova mzda: %.2f SKK\n", suma);
	return 0;
	
}
