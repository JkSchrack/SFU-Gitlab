#include <stdio.h>
#include <math.h>

 
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
  int decrease;
  int spaces;
  int tip;
  int difference;
  int middle;
  int brate;
  int rate;
  float size;
  int irate;
  int interior;

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
  
  if (width == 1 )
  {
    width = 1;
  }
  else
  {
    decrease = height - 1;
    spaces = floor( decrease * (width/(2.0*height)) );
    // calculates spaces
    tip = width - (spaces*2);

    difference = width - tip;
    middle = height - 1;

    brate = difference / middle;
    rate = brate / 2;
    irate = rate * 2;

    size = width / height;
    // if width / height is less than 2, then rate = rate; else rate = brate
  } 

  if (size < 2)
  {
    rate = brate;
    irate = rate * 2;
  }

  if (width == 1)
  {
    printf("#\n");
  }
  else
  {
    for (row = 1; row <= height; row++)
    {
      if ( row == 1)
      {
        for (i = 0; i < spaces; i++)
        {   
          printf(" ");
        }
        for (i = 1; i < tip; i++)
        {
          printf("#");
        }
        printf("#\n");
      spaces = spaces - rate;
      interior = ((width - (spaces * 2)) - 2);
      // first row 
      }
      else if (row < height )
      {
        for (i = 0; i < spaces; i++)
        {   
          printf(" ");
        }
        spaces = spaces - rate;
        printf("#");
        
        for (i = 0; i < interior; i++)
        {
          printf(".");
        }
        interior = interior + irate;
        printf("#\n");
        // middle portion
      }
    else if ( row = height)
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
} 
