#include <math.h>
#include <stdio.h>
 
int main( void ) 
{
  
  float i;
  int check;
  int end = 0;

  do
  {
    check = scanf( "%f", &i );

    if (check == EOF )
    {
      printf("Done.\n");
      end = 1;
    }
    else if (check == 1)
    {
     printf( "%d ", (int)floor(i) );
     printf( "%d ", (int)round(i) );
     printf( "%d\n", (int)ceil(i) );
    }
  } while (! (end == 1) );
} 
