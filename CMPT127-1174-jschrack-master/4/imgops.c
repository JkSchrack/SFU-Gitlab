/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  for( int i=0; i < rows*cols; i++ )
  {
    array[i] = 0;
  }
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here
  return NULL;
}

/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  int darkest = array[0];
  for( int i=0; i < rows*cols; i++ )
  {
    if (array[i] < darkest)
    {
      darkest = array[i];
    }
  }
  return darkest;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  int lightest = array[0];
  for( int i=0; i < rows*cols; i++ )
  {
    if (array[i] > lightest)
    {
      lightest = array[i];
    }
  }
  return lightest;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  for( int i=0; i < rows*cols; i++ )
  {
    if (array[i] == pre_color)
    {
      array[i] = post_color;
    }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  unsigned int total = cols*rows;
  unsigned int col = cols - 1;
  uint8_t temp[total];

  for( int i=0; i < rows; i++ )
  {
    for( int k=0; k < cols; k++ )
    {
      temp[k + (i*cols)] = array[(col - k) + (i*cols)];
    }
  }

  for( int i=0; i < total; i++)
  {
    array[i] = temp[i];
  }
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
  unsigned int total = cols*rows;
  unsigned int row = rows - 1;
  uint8_t temp[total];

  for( int i=0; i < rows; i++ )
  {
    for( int k=0; k < cols; k++ )
    {
      temp[k + (i*cols)] = array[(k) + ((row - i)*cols)];
    }
  }

  for( int i=0; i < total; i++)
  {
    array[i] = temp[i];
  }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
  int found = 0;
  float row;
  unsigned int temp;
  unsigned int temp2;
  
  for (int i = 0; i < rows*cols; i++)
  {
    if (array[i] == color)
    {
      row = i / cols;
      temp = (unsigned int)floor(row);
      *y = temp;
      temp2 = (cols*temp);
      *x = i - temp2;
      found = 1;
      break;
    }
  }

  return found;
}



/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
  int max = 255;
  int temp;
  int reverse;

  for( int i=0; i < rows*cols; i++ )
  {
    temp = array[i];
    reverse = max - temp;

    array[i] = reverse;
  }
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  double temp;
  float new;
  int newer;
  for( int i=0; i < rows*cols; i++ )
  {
    temp = array[i];
    new = temp * scale_factor;
    newer = round(new);
    if (newer > 255)
    {
      newer = 255;
    }
    array[i] = newer;
  }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
  int darkest = min( array, cols, rows);
  int lightest = max( array, cols, rows);

  double OldMin;
  double OldMax;
  double NewMin;
  double NewMax;
  double OldValue;
  double NewValue;
  int result;

  for (int i =0; i < cols*rows; i++)
  {
    int colour = array[i];
    if (colour == darkest)
    {
      array[i] = 0;
    }
    else if (colour == lightest)
    {
      array[i] = 255;
    }
    else if ( colour > darkest && colour < lightest)
    {
      OldMin = darkest;
      OldMax = lightest;
      NewMin = 0;
      NewMax = 255;
      OldValue = array[i];
      NewValue = (((OldValue - OldMin) * (NewMax - NewMin)) / (OldMax - OldMin)) + NewMin;
      result = round(NewValue);

      if (result > 255)
      {
        result = 255;
      }
      else if (result < 0)
      {
        result = 0;
      }
    array[i] = result;
    }
  }
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
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
  // Original Image has all p/q coordinates assigned.

  unsigned OddRows = rows % 2;
  unsigned OddCols = cols % 2;
  unsigned int EvenRows;
  unsigned int EvenCols;

  if (OddRows > 0)
  {
    EvenRows = rows - 1;
  }
  else if (OddRows == 0)
  {
    EvenRows = rows;
  }
  
  if (OddCols > 0)
  {
    EvenCols = cols - 1;
  } 
  else if (OddCols == 0)
  {
    EvenCols = cols;
  } 
  unsigned int NewRows = EvenRows / 2;
  unsigned int NewCols = EvenCols / 2;
  // checks for odd Cols or Rows

  unsigned int NewSize = NewRows*NewCols;
  uint8_t *NewArray = malloc(NewSize * sizeof(uint8_t));
  // Creates new array using the new size
  unsigned int x;
  unsigned int y;
  // p/q coords of new array
  int one = 0;
  int two = 0;
  int three = 0;
  int four = 0;
  // (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1)
  double New = 0;
  int NewValue;

  for (int i = 0; i < NewRows*NewCols; i++)
  {
    row = i / NewCols;
    temp = (unsigned int)floor(row);
    y = temp;
    temp2 = (NewCols*temp);
    x = i - temp2;
    // assigns x/y coords to new array
    for (int j=0; j < rows*cols; j++)
    {
      if (p[j] == (2*x) && q[j] == (2*y))
      {
        one = array[j];
      }
      else if (p[j] == ((2*x) + 1) && q[j] == (2*y))
      {
        two = array[j];
      }
      else if (p[j] == ((2*x) + 1) && q[j] == ((2*y) + 1))
      {
        three = array[j];
      }
      else if (p[j] == (2*x) && q[j] == ((2*y) + 1))
      {
        four = array[j];
      }
      New = one + two + three + four;
      //Checks for what index matches the coords
    }
    New = New / 4;
    NewValue = (int)round(New);
    NewArray[i] = NewValue;
  }
  return NewArray;
}



/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  if ( left != right && top != bottom)
  {
    for (unsigned int i = top; i < bottom; i++)
    {
      for (unsigned int j = left; j < right; j++)
      {
        unsigned int NextRow = i * cols;
        unsigned int position = NextRow + j;
        array[position] = color;
      }
    }
  }
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  unsigned sum = 0;

  if ( left != right && top != bottom)
  {
    for (unsigned int i = top; i < bottom; i++)
    {
      for (unsigned int j = left; j < right; j++)
      {
        unsigned int NextRow = i * cols;
        unsigned int position = NextRow + j;
        sum = sum + array[position];
      }
    }
    // sum = ((right - left) * (bottom - top)); AKA area of region
  } 

  return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
 
  if ( left != right && top != bottom)
  {
    unsigned int region = ((right - left) * (bottom - top));
    int *test = malloc(region * sizeof(uint8_t));
    if (test == NULL)
    {
      return NULL;
    }
    else 
    {
      uint8_t *NewImage = malloc(region * sizeof(uint8_t));
      int next = 0;
      for (unsigned int i = top; i < bottom; i++)
      {
        for (unsigned int j = left; j < right; j++)
        {
          unsigned int NextRow = i * cols;
          unsigned int position = NextRow + j;
          NewImage[next] = array[position];
          next = next + 1;
        }
      }
      return NewImage;
    }

    // sum = ((right - left) * (bottom - top)); AKA area of region
  } 
  else 
  {
    return NULL;
  }
}


