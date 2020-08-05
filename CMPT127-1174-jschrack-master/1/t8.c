#include <stdio.h>
 
int main( void ) 
{
  
  float input;
  float check;
  int end = 0;
  int i;
  float width;
  float breadth;
  float height;
  float dotscolumn;
  int row;
  int column;
  int value = 0;

  do
  {
    check = scanf( "%f", &input );

    if (check == 1)
    {
      value = value + 1;

      if ( value == 1 )
      {
        width = input;
      }
      else if ( value == 2 )
      {
        breadth = input;
      }
      else if ( value == 3 )
      {
        height = input;
        end = 1;
      }
    }
  } while (! (end == 1) );
  // assigns width, breadth and height

  dotscolumn = width - 2;

  for (row = 1; row <= breadth; row++)
  {
    if ( row == 1)
    {
      if (width == 0)
      {
        printf("\n");
      }
      else if (width == 1 )
      {
        printf("#\n");
      }
      else
      {
        for (i = 1; i < width; i++)
        {   
          printf("#");
        }
        printf("#\n");
      }
      // first row 
    }
    else if (row < breadth )
    {
      for (column = 1; column <= width; column++)
      {   
        if ( column == 1)
        {
          printf("#");
        }
        else if ( column < width )
        {
          printf(".");
        }
        else if ( column == width )
        {
          printf("#\n");
        }
      }
      // middle portion
    }
  else if ( row = breadth)
  {
    if (width == 0)
      {
        printf("\n");
      }
      else if (width == 1 )
      {
        printf("#\n");
      }
      else
      {
        for (i = 1; i < width; i++)
        {   
          printf("#");
        }
        printf("#\n");
      }
    }
    // assigns last row
  }
} 
