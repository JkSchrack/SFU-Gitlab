#include <math.h>
#include <stdio.h>
 
int main( void )
{
  float i = 0;


  
  scanf( "%f", &i );
  printf( "%d ", (int)floor(i) );
  printf( "%d ", (int)round(i) );
  printf( "%d\n", (int)ceil(i) );


} 
