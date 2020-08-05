#include <stdio.h> // for perror, fopen, etc.
#include <stdlib.h> // for exit
#include <string.h> // recommended in a note when compiled :/

int main()
{
	int check;
	int number;
	int input[80];
	int NumberOfRows = 0;
	int k = 0;
	//printf("%s", input);

	do
	{
		check = scanf( "%i", &number );

		input[k] = number;
		k = k + 1;

	}
	while (! (check == EOF));

	int columns = k - 1;

	for (int i = 0; i < columns; i++)
	{
		if ( input[i] > NumberOfRows)
		{
			NumberOfRows = input[i];
		}
	}
	// determines # of rows
	
	//printf("%i\n", NumberOfRows);

	for (int i = NumberOfRows; i >= 1; i-- )
	{
		for (int j = 0; j < columns; j++)
		{
			if ( input[j] >= i )
			{
				printf("#");
			}
			else if ( input[j] < i )
			{
				printf(" ");
			}

			if (j == columns - 1)
			{
				printf("\n");
			}
		}
	}



}