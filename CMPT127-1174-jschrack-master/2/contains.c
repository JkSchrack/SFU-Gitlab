#include <stdio.h> // for perror, fopen, etc.
#include <stdlib.h> // for exit
#include <string.h> // recommended in a note when compiled :/

int main( int argc, char* argv[] )
{
	char* first = argv[1];
	char* second = argv[2];

	int flength = strlen(first);
	int slength = strlen(second);

	if (strstr(first, second) == NULL) {
	    printf("false\n");
	}
	else
	{
		printf("true\n");
	}
	// The C library function char *strstr(const char *haystack, 
	//const char *needle) function finds the first occurrence of the 
	//substring needle in the string haystack. The terminating '\0' 
	//characters are not compared.
}