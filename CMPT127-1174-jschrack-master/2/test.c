#include <stdio.h> // for perror, fopen, etc.
#include <stdlib.h> // for exit
#include <string.h> // recommended in a note when compiled :/	

int main( int argc, char* argv[] )
{
	int i = 0;
	//int k;
	int charcount = 0;
	char item;
	char input[128];
	//char* temp;

	do
	{
		item = getchar();
		// If i print each char after this it works
		input[i] = item;
		charcount = charcount + 1;
		i = i + 1;
	}
	while((!(item == EOF)) || charcount == 128);
	i = i - 2;
	input[i] = '\0';

	printf("%s\n", input);
	//puts (input);

}