#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "imgops.h"

void life( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
	/*
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
	*/
  	uint8_t* original = copy( array, cols, rows ); // keeps track of original version
  
	for( unsigned int x = 0; x < cols; x++ )  // for all cols
	{
		for( unsigned int y = 0; y < rows; y++ ) // for all rows
		{		
			////////// for keeping track of whats alive and needs to die
			unsigned int alive = 0;
			int NewX;
			int NewY;


			for( unsigned int j = x - 1; j<=1; j++ ) // j = x -1
			{
				for( unsigned int k = y - 1; k<=1; k++ ) // k = y -1
				{
			      	if( ! (j == 0 && k == 0 ) ) 
			      	{
			    		NewX = (x+j+cols) % cols; 
			    		// wrap x = j left-right
				  		NewY = (y+k+rows) % rows; 
				  		// wrap y = ktop-bottom
				  		alive += get_pixel( original, cols, rows, NewX, NewY ) > 0; //update
			      	}
			    }
			}
			//////////////////

			if( alive < 2 )
			{
				set_pixel( array, cols, rows, x, y, 0 );
			}
			if( alive > 3 )
			{
				set_pixel( array, cols, rows, x, y, 0 );
			}
			if( alive == 3 ) // needs to become alive
			{
	  			set_pixel( array, cols, rows, x, y, 255 );
	  		}
	  	}
  	}
  	free(original);
}