#include <stdio.h> // for perror, fopen, etc.
#include <stdlib.h> // for exit
#include <string.h> // recommended in a note when compiled :/

int bar (const char* str)
{
	int size = strlen(str); // # of bytes in s
	int length = size / sizeof(char); // bytes/ bytes per char = length
	length = length;
	if (length != 14)
	{
		//printf("Failed\n");
		return 0;
	}
	//printf("%i\n", length);
	char correct[14] = {'G', 'o', 'o', 'd', 'b', 'y', 'e', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
	//printf("%s\n", str);
	//printf("%s\n", correct);

	for (int i = 0; i < length; i++)
	{
		if(str[i] != correct[i])
		{
			//printf("Failed\n");
			return 0;
		}
	}
	//printf("Pass\n");
	return 1;
	;

}	