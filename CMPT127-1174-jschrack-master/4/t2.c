#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void draw_rectangle( uint8_t array[], 
                          unsigned int cols, 
                          unsigned int rows, 
                          int x,
                          int y,
                          int rect_width,
                          int rect_height,
                          uint8_t color )
{
	if ( rect_width != 0 && rect_height != 0)
	{
		int top = 0;
		int bottom = 0;
		int left = 0;
		int right = 0;

		//top = y;
		//left = x;
		//bottom = y + rect_height + 1;
		//right = x + rect_width + 1;

		if (rect_width < 0)
		{
			left = x + rect_width + 1;
			right = x;
		}
		else 
		{
			left = x;
			right = x + rect_width -1;
		}
		
		if (rect_height < 0)
		{
			top = y + rect_height + 1;
			bottom = y;
		}
		else
		{
			top = y;
			bottom = y + rect_height -1;
		}

		for ( int i = 0; i<cols*rows;i++)
		{
			int a = i/cols;
			int b = i%cols;

			if ( (a == top || a == bottom ) && (b >= left && b <= right ))
			{
				array[i] = color;
			}
			if ( (b == left || b == right ) && (a >= top && a <= bottom ))
			{
				array[i] = color;
			}
		}
	}
}