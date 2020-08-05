#include <math.h>
#include <stdio.h>
 
int main( void )
{
  float i = 0;
  int a = 2;


  
  a = scanf( "%f", &i );

  if(a == 1) {
  	printf( "%d ", (int)floor(i) );
  	printf( "%d ", (int)round(i) );
  	printf( "%d\n", (int)ceil(i) );
  } else {
  	printf("scanf error: (%d)\n", (int)i);
  }

} 
