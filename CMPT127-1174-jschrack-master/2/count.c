#include <stdio.h>

int main()
{
	unsigned long int charcount = 0;
	unsigned long int wordcount = 0;
	unsigned long int linecount = 0;
	char item;
	int letter = 0;
	int other = 0;

	do
	{
		item = getchar();
		charcount = charcount + 1;
		
		if ( item == '\n')
		{
			linecount = linecount + 1;
		}
		//if (linecount > 0 && item == '\n')
		//{
		//	wordcount = wordcount - 1;
		//}
		if ((item >= 65 && item <= 90) || (item >= 97 && item <= 122) || (item == 39))
		{
			letter = 1;
		}
		else 
		{
			other = 1;
		}
		// Is it a letter or not?

		//if ( !((item >='A' && item <= 'Z') || (item >= 'a' && item <= 'z') || (item == 39))) //|| (item == '\n')))
		//{
		//	other = 1;
		//}
		if (letter == 0 && other == 1)
		{
			other = 0;
		}
		else if (letter == 1 && other == 1)
		{
			wordcount = wordcount + 1;
			letter = 0;
			other = 0;
		}
	}
	while( !(item == EOF));

	//wordcount = wordcount + 1;
	charcount = charcount - 1;

	printf( "%lu %lu %lu\n", charcount, wordcount, linecount );
}
