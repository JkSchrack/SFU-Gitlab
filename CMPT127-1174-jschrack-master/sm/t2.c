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