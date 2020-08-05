#include <stdio.h> // for perror, fopen, etc.
#include <stdlib.h> // for exit
#include <string.h> // recommended in a note when compiled :/
#include <math.h>

int main( int argc, char* argv[])
{
	double number = atof(argv[1]);
	int count = atof(argv[2]);

	float number2 = (float)number;
	int number3 = round(number2);

	printf("n=%i ", number3);
	printf("count=%i\n", count);

}