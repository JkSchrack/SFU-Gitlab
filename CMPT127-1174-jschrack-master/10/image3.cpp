#include <stdio.h>
#include <stdint.h> // for uint8_t
#include <stdlib.h>
#include <string.h>
#include "image3.hpp"
#include <iostream>
#include <fstream>

Image::Image()
{
	cols(0);
	rows(0);
	pixels(NULL);
}

Image::~Image()
{
	if (pixels != NULL)
	{
		for (unsigned int i = 0; i < rows; i++)
		{
			delete[] pixels[i];
		}
		delete pixels;
	}
	// because pixels is of **
}

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor )
{
	if (pixels != NULL)
	{
		for (unsigned int i = 0; i < rows; i++)
		{
			delete[] pixels[i];
		}
		delete pixels;
	}

  	pixels = new uint8_t*[height]; // first because height = rows
  	if (pixels == NULL)
  	{
  		return 1;
  	}
  	for (unsigned int i = 0; i < height; i++)
  	{
  		pixels[i] = new uint8_t[width]; // for each x value
  		if (pixels[i] == NULL)
  		{
  			// if failed
  			return 1;
  		}
  	}

  	for (unsigned int i = 0; i < width; i++)
  	{
  		for (unsigned k = 0; k < height; k++)
  		{
  			pixels[i][k] = fillcolor;
  		}
  	}

  	cols = width;
  	rows = height;
  	return 0;
}

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color )
{
	if (pixels != NULL)
	{
		if (x < cols && y < rows) // x & y are within range
		{
			pixels[y][x] = color;
			return 0;
		} 
	}
	return 1;
}

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp )
{
	if (pixels != NULL)
	{
		if (colorp != NULL)
		{
			if (x < cols && y < rows)
			{
				*colorp = pixels[y][x];
				return 0;
			}
		}
	}
	return 1;
}

/* Saves the image in the file filename. In a format that can be
 loaded by load().  Returns 0 on success, else a non-zero error
 code. */
int Image::save( const char* filename )
{
    ofstream output_file( filename, ios::binary);
    // ofstream create/write... outputting to file called filename in form of binary
    //output_file  18.11 summary of introducing c++ for scietists...
    if (!output_file) 
    {
        return 1;
    }
    else
    {
    	output_file.write( reinterpret_cast<char*>(&cols), sizeof(unsigned int));
    	output_file.write( reinterpret_cast<char*>(&rows), sizeof(unsigned int));
    	
    	output_file.write( reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows);
    	//reinterpret_cast converts vals to char type as file is of type char*
    	// include cols, rows and pixels
    	// ibm reinterpret_cast website
    	return 0;
    }
}

/* Load an image from the file filename, replacing the current
 image size and data. The file is in a format that was saved by
 save().  Returns 0 success, else a non-zero error code . */
int load( const char* filename )
{
	ifstream input_file( filename, ios::binary)
	// ifstream reads 
	if (!input_file)
	{	
		// input fails
		return 1;
	}
	input_file.read( reinterpret_cast<char*>(&cols), sizeof(unsigned int));
    input_file.read( reinterpret_cast<char*>(&rows), sizeof(unsigned int));
    
    input_file.read( reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows);
    return 0;

}