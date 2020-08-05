#include <stdio.h>
 
int main( void ) 
{
  
  float input;
  float check;
  int end = 0;
  int i;

  do
  {
    check = scanf( "%f", &input );

    if (check == EOF )
    {
     end = 1;
    }
    else if (check == 1)
    {
      if (input == 0)
      {
        printf("\n");
      }
      else if (input == 1 )
      {
        printf("#\n");
      }
      else
      {
        for (i = 1; i < input; i++)
        {
          printf("#");
        }
        printf("#\n");
      } 
    }
  } while (! (end == 1) );
} 
