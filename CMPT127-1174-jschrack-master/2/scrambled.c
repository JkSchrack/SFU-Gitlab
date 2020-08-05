#include <stdio.h>

int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
	unsigned int i;
	unsigned int k;
	int amatch = 0;
	int bmatch = 0;
	int match = 0;
	int result = 1;
	int acount = 0;
	int bcount = 0;

	for(k = 0; k < len; k++)
	{
		for(i = 0; i < len; i++)
		{
			if (a[k] == b[i])
			{
				amatch = 1;

			}		
			if (b[k] == a[i])
			{
				bmatch = 1;
			}
			if (! (amatch == bmatch))
			{
				match = 0;
			}
			//else if (amatch == 0 && bmatch == 0)
			//{
			//	match = bmatch;
			//}
			else
			{
				match = bmatch;
			}
		}	
		if (match == 0) 
		{
			result = 0;
		}
		acount = acount + a[k];
		bcount = bcount + b[k];
		amatch = 0;
		bmatch = 0;
		match = 0;
	}
	if ( !(result == 1 && acount == bcount) )		
	{
		result = 0;
	}
	printf("%i\n", acount);
	printf("%i\n", bcount);
	return result;
}