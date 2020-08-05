#include <stdio.h> // for perror, fopen, etc.
#include <stdlib.h> // for exit
#include <string.h> // recommended in a note when compiled :/

int main( int argc, char* argv[] )
{
	char * censored = "CENSORED";
	int amount = argc - 1;
	char* words[amount];

	for (int i = 1; i <= argc; i++)
	{
		if (i == argc)
		{
			words[i] = argv[1];
		}
		// gives space for sort
		words[i] = argv[i];
		//printf("%s\n", words[i]);

	}
	// takes target words in argument

	int i = 0;
	//int k;
	int charcount = 0;
	char item;
	char input[128];
	char* temp;
	char* tempp;

	do
	{
		item = getchar();
		input[i] = item;
		charcount = charcount + 1;
		i = i + 1;
	}
	while((!(item == EOF)) || charcount == 128);
	i = i - 2;
	input[i] = '\0';
	// takes file input into a a string as an array

	for(int j = 1; j < argc - 1; j++)
	{
		temp = strstr(input, words[j]);

		long unsigned int part = strlen(temp);		
		int total = (int)part;

		tempp = strstr(input, words[j + 1]);

		long unsigned int ppart = strlen(tempp);		
		int ttotal = (int)ppart;

		//printf("%i", total);
	
		if (ttotal > total)
		{
			words[argc] = words[j];
			words[j] = words[j + 1];
			words[j + 1] = words[argc]; 
		}
	}
	for(int j = 1; j < argc - 1; j++)
	{
		temp = strstr(input, words[j]);

		long unsigned int part = strlen(temp);		
		int total = (int)part;

		tempp = strstr(input, words[j + 1]);

		long unsigned int ppart = strlen(tempp);		
		int ttotal = (int)ppart;

		//printf("%i", total);
	
		if (ttotal > total)
		{
			words[argc] = words[j];
			words[j] = words[j + 1];
			words[j + 1] = words[argc]; 
		}
	}
	words[argc] = words[argc - 1];

	//printf("%s\n", words[1]);
	//printf("%s\n", words[2]);
	//printf("%s\n", words[3]);
	//printf("%s\n", words[4]);

	int begin = 0;

	for (int k = 1; k <= argc; k++)
	{
		if (strstr(input + begin, words[k]) != NULL) //target word is inside text
		{
			temp = strstr(input + begin, words[k]);

			long unsigned int size = strlen(input);
			long unsigned int part = strlen(temp);
			
			int total = (int)part;
			int tsize = (int)size;
			int start = tsize - total;
			int travel = start - begin;
			//printf("%i", total);

			//printf("%i", start);

			long unsigned int word = strlen(words[k]);
			int length = (int)word;	
			//printf(" %i", length);	

			if ((length < 8) && (k == 1))
			{	
				printf("%.*s", start, input + 0);
				printf("CENSORED");
				begin = length + start;
			}
			else if ((length < 8) && (k > 1))
			{
				printf("%.*s", travel, input + begin);
				printf("CENSORED");
				begin = length + start;
			}
			else
			{
				strncpy(temp, censored,8);
				printf("%s\n", input);
			}

			if (k == argc)
			{
				printf("%.*s\n", total, input + begin);
			}
			//printf("%s\n", words[k]);
			//puts (input);
			// temp is destination of target and words[k] is the replacement 
			//and 7 is # of char in CENSORED
		}
		else
		{

			temp = strstr(input, words[k]);

			long unsigned int part = strlen(temp);
			
			int total = (int)part;
		
			printf("%.*s\n", total, input + begin);
		}
	}

	//puts (input);
	//printf("%i\n", input);
	//printf("%i\n", argc);
}