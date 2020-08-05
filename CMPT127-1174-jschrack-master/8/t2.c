#include <stdlib.h>
#include "point_array.h"

/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa )
{
  if (pa != NULL)
  {
    pa->len = 0;
    pa->reserved = 0;
    pa->points = NULL;
  }
}

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa )
{
  pa->len = 0;
  pa->reserved = 0;
  free(pa->points);
  pa->points = NULL;
}

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p )
{
  (pa->len)++;
  if (pa->reserved == 0)
  {
    pa->points = realloc(pa->points, pa->len * sizeof(point_t));
    if (pa->points == NULL)
    {
      (pa->len)--;
      return 1;
    }
    (pa->reserved)++;
  }
  else if ((pa->len + 1) > pa->reserved)
  {
    pa->points = realloc(pa->points, (pa->reserved * 2) * sizeof(point_t));
    if (pa->points == NULL)
    {
      (pa->len)--;
      return 1;
    }
    pa->reserved = pa->reserved * 2;
  }

  pa->points[pa->len-1] = *p;
  return 0; 
}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
// Return 0 on success and 1 on failure.
int point_array_remove( point_array_t* pa, unsigned int i )
{
  if (pa->len > 1 && pa->len > i)
  {
    (pa->len)--;
    pa->points[i] = pa->points[pa->len];
    pa->points = realloc(pa->points, pa->len * sizeof(point_t));
    if (pa->points == NULL)
    {
      (pa->len)++;
      return 1;
    }
    return 0;
  }
  else if (pa->len == 1 && pa->len > i)
  {
    pa->len = 0;
    pa->reserved = 0;
    free(pa->points);
    pa->points = NULL;
    return 0;
  }
  return 1;
}
