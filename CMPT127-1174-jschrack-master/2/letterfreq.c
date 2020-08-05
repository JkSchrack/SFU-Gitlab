#include <stdio.h>

int main()
{
	char item;
	char lower[27];
	char upper[27];
	char letter[27];
	float freq[26];
	int total = 0;

	for (int i = 0; i < 26; i++)
	{
		lower[i] = 97 + i; // a = 97, z = 122
		upper[i] = 65 + i; // A = 65, Z = 90
		letter[i] = 97 + i;
		freq[i] = 0;
	}
	
	lower[26] = '\0';
	upper[26] = '\0';
	letter[26] = '\0';

	//printf("%s\n", lower);
	//printf("%s\n", upper);

	do
	{
		item = getchar();

		if ((item >= 65 && item <= 90) || (item >= 97 && item <= 122))
		{
			total = total + 1;

			for (int i = 0; i < 26; i++)
			{
				if (item == lower[i] || item == upper[i])
				{
					freq[i] = freq[i] + 1;
				}
			}


		}
	}
	while( !(item == EOF));

	for (int i = 0; i < 26; i++)
	{
		freq[i] = (freq[i] / total);

		if (freq[i] > 0)
		{
			printf( "%c %.4f\n", letter[i], freq[i]);
		}
	}
}
