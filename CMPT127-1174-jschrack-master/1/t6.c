#include <stdio.h>
 
int main( void ) 
{
  
  float number;
  float check;
  int end = 0;
  float smallest = 100000;
  float largest = -100000;
  float count = 0;
  float total = 0;
  float mean = 0;

  do
  {
    check = scanf( "%f", &number );

    if (check == EOF )
    {
      printf("%.2f ", smallest);
      printf("%.2f ", largest);
      printf("%.2f\n", mean);
      end = 1;
    }
    else if (check == 1)
    {
      if (number < smallest)
      {
        smallest = number;
      }
      if (number > largest)
      {
        largest = number;
      }
      count = count + 1;
      total = total + number;
      mean = (total / count);
    }
  } while (! (end == 1) );
} 
