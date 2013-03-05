#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	
	scanf("%i", &n);
	
	if( n > 15 || n < 1 || n % 2 == 0)
	{
		printf("Zly vstup\n");
		exit(0);
	}
	
	int r = 0, c = 0;
	int m = 6, k = 6;
	int a, b;
	
	
	for( b = 0; b < k; b++)
	 {
		for(r = 0; r < n; r++)
		{		
			for(a = 0; a < m; a++)
			{
				for(c = 0; c < n/2+1; c++)
				{
					if( (c <= r && r < n/2+1 ) || ( r > n/2 && c >= r - n/2) )
						printf("*");
					else
						printf("-");	
				}
			}
			printf("\n");	
		}
	}
	return 0;
}
