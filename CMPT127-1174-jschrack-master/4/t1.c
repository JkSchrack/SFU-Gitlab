#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void draw_circle( uint8_t img[], 
                  unsigned int cols,
                  unsigned int rows,
                  int x,
                  int y,
                  int r,
                  uint8_t color )
{
	// Incase of any negatve x/y values or r is 0
	if (r > 0)
	{
		unsigned int size = cols*rows;
	  	unsigned int p[size];
	  	unsigned int q[size];
	  
	 	float row;
	  	unsigned int temp;
	  	unsigned int temp2;
	  
	 	for (int i = 0; i < rows*cols; i++)
	  	{
	    	row = i / cols;
	    	temp = (unsigned int)floor(row);
		    q[i] = temp;
		    temp2 = (cols*temp);
		    p[i] = i - temp2;
		}
		// Original Image has all p/q coordinates assigned.... p = x coord and q = y coord

		double CenterX = x + 0.5;
		double CenterY = y + 0.5;
		double RSquared = pow(r, 2);

		for (int i = 0; i < size; i++)
		{
			double TempP = p[i];
			double TempQ = q[i];

			if (TempP < CenterX)
			{
				TempP += 1;
			}
			else if (TempP == CenterX)
			{
				TempP += 0.5;
			}

			if (TempQ < CenterY)
			{
				TempQ += 1;
			}
			else if (TempQ == CenterY)
			{
				TempQ += 0.5;
			}
			// If any part of the pixel is within the radius.

			//If (x - center_x)^2 + (y - center_y)^2 < radius^2 then point is within radius.
			double dx = TempP - CenterX;
			double XSquared = pow(dx, 2); //(x - center_x)^2
			double dy = TempQ - CenterY; 
			double YSquared = pow(dy, 2); //(y - center_y)^2
			double total = XSquared + YSquared;

			if ( total < RSquared )
			{
				img[i] = color;
			}
		}
		// Changes Image	
	}


}
