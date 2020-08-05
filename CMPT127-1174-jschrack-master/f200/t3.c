#include <stdio.h> // for perror, fopen, etc.
#include <stdlib.h> // for exit
#include <string.h> // recommended in a note when compiled :/


void reverse_string( char s[])
{
	int size = strlen(s); // # of bytes in s
	int length = size / sizeof(char); // bytes/ bytes per char = length
	length = length - 1;

	char current;
	int opposite = length - 1;
	char temp;
	for (int i = 0; i < length; i++)
	{
		if (opposite != i && opposite > i)
		{
			current = s[i];
			s[i] = s[opposite];
			s[opposite] = current;
			opposite--;
		}

	}
	/*
	for (int i = 0; i < length; i++)
	{
		printf("%c\n", s[i]);
	}
	*/
	//printf("%i\n", length);
}