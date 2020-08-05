#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <assert.h>
#include "intarr.h"

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename )
{
	FILE* f = fopen( filename, "w");
	if (f == NULL)
	{
		return 1;
	}

	if (ia == NULL)
	{
		return 1;
	}

	if(fwrite( ia->data, sizeof(int), ia->len, f) != ia->len)
	{
		return 1;
	}

	fclose(f);
	return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename )
{
	intarr_t* NewArr = intarr_create(0);
	FILE* f = fopen(filename, "r");
	if (f == NULL)
	{
		return NULL;
	}

	int item = 0;

	while (fread(&item, sizeof(int), 1, f) == 1 ) 
	//increments at 1 element, if == 1 it works
	{
		intarr_push(NewArr, item); // appends element to arr
	}
	return NewArr;
}