#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <assert.h>
#include "intarr.h"

/* LAB 6 TASK 2 */
/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.
  Examples:
  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/

int intarr_save_json( intarr_t* ia, const char* filename )
{
  if (filename == NULL)
  {
    return 1;
  }
  
  FILE* f = fopen(filename, "w" );
  if (f == NULL)
  {
    return 1;
  }
  
  if (ia == NULL)
  {
    return 1;
  }
  
  fprintf(f, "[\n"); // start
  for(int i = 0; i < ia->len; i++)
  {
    if (i == ia->len - 1)
    {
      fprintf(f, " %d\n", ia->data[i]);
    }
    
    if (i != ia->len - 1)
    {
      fprintf(f, " %d,\n", ia->data[i]);
    }
  }
  fprintf(f, "]\n"); //end 
  fclose(f);

  return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/

intarr_t* intarr_load_json( const char* filename )
{
  if (filename == NULL)
  {
    return NULL;
  }
  
  FILE* f = fopen(filename, "r" );
  if (f == NULL)
  {
    return NULL;
  }
  
  intarr_t* NewArr = intarr_create(0);
  char item;
  fscanf(f, "%c ", &item);
  
  int element;
  while(fscanf(f, "%d,", &element))
  {
    intarr_push(NewArr, element);
  }
  
  fclose(f);
  return NewArr;
}