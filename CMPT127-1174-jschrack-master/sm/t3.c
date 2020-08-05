#include <stdio.h> // for perror, fopen, etc.
#include <stdlib.h> // for exit
#include <string.h> // recommended in a note when compiled :/
#include <math.h>

int main( int argc, char* argv[])
{
	double number = atof(argv[1]);
	int count = atof(argv[2]);

	unsigned int n = round(number);


	for(int i = 0; i < count; i++)
	{

		if ( i == 0)
		{
			for(int j = 0; j <= n; j++)
			{
				if (j < n)
				{
					printf("#");
				}
				else if (j == n)
				{
					printf("\n");
				}
			}
		}
		// first line

		if ( i > 0)
		{
			int check = n % 2;

			if (check == 0)
			{
				n = n/2;
			}
			else 
			{
				n = 3*n+1;
			}
			{
				for(int j = 0; j <= n; j++)
				{
					if (j < n)
					{
						printf("#");
					}
					else if (j == n)
					{
						printf("\n");
					}
				}
			}
		}
	}

}
