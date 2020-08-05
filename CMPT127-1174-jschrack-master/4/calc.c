#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int x = -80;
	int y = -40;
	int width = 120;
	int height = 80;

	int top = y;
	int left = x;
	int bottom = y + height;
	int right = x + width;

	printf("%i\n", top);
	printf("%i\n", left);
	printf("%i\n", bottom);
	printf("%i\n", right);
}