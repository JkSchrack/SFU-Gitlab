#include <stdio.h>
#include <stdint.h> // for uint8_t
#include <stdlib.h>
#include <string.h>
#include "image.hpp"

Image::Image()
{
	cols = 0;
	rows = 0;
	pixels = NULL;
}

Image::~Image()
{
	if (pixels != NULL)
	{
		delete[] pixels;
	}
}

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor )
{
	delete[] pixels; // reset
  	pixels = new uint8_t[width * height]; // allocate
  	if (pixels == NULL)
  	{
  		return 1;
  	}
  	for (unsigned int i = 0; i < width*height; i++)
  	{
  		pixels[i] = fillcolor;
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
			pixels[(cols*y) + x] = color;
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
				*colorp = pixels[(cols*y) + x];
				return 0;
			}
		}
	}
	return 1;
}