#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <assert.h>
#include <stdio.h>

/* DO NOT CHANGE THIS FILE - YOUR CODE WILL BE COMPILED AGAINST THE
   ORIGINAL. NON-COMPILING CODE WILL FAIL ALL THE TASKS!
*/

/* Structure type that encapsulates the vector data. */
typedef struct {
  double* data; // data for the vector of dimension size dim
  unsigned int dim; // dimension of the vector
} vec_t;

/* THE FOLLOWING THREE FUNCTIONS ARE PROVIDED FOR YOU. DO NOT DEFINE A FUNCTION WITH THE SAME NAME! */

/* WRITE CODE FOR THE FOLLOWING TASKS */

/* Always check all pointers if they are NULL before you use them */

/* TASK 1 */

// Find the first element of the vector v and set the deferenced
// pointer result to the first element of v. Return 0 on success.
// If v is NULL or v->dim is zero or v->data is NULL then return -1. 
// Do not modify *result on failure.
int vec_first( vec_t *v, double* result )
{
	if (v == NULL || v->dim == 0 || v->data == NULL)
	{
		return -1;
	}
	else
	{
		double first = v->data[0];
		if (result != NULL)
		{
			*result = first;
			return 0;
		}
		else
		{
			return -1;
		}
	}
}

/* TASK 2 */

// Find the last element of the vector v and set the deferenced
// pointer result to the last element of v. Return 0 on success.
// If v is NULL or v->dim is zero or v->data is NULL then return -1. 
// Do not modify *result on failure.
int vec_last( vec_t *v, double* result )
{
	if (v == NULL || v->dim == 0 || v->data == NULL)
	{
		return -1;
	}
	else
	{
		unsigned int len = v->dim;
		double last = v->data[len - 1];
		if (result != NULL)
		{
			*result = last;
			return 0;
		}
		else
		{
			return -1;
		}

	}
}

/* TASK 3 */

// Return the maximum value in the vector.
// If finding the maximum was successful, dereference the pointer
// result and place the max value in that location. Return 0 on success.
// If finding the maximum failed, because the vector v was
// NULL or v->dim is zero or v->data was NULL then return -1 on failure. 
// Do not modify *result in this case.
int vec_max( vec_t *v, double* result )
{
	if (v == NULL || v->dim == 0 || v->data == NULL)
	{
		return -1;
	}
	else
	{
		unsigned int len = v->dim;
		double max = v->data[0];
		for (int i = 1; i < len; i++ )
		{
			if (v->data[i] > max)
			{
				max = v->data[i];
			}
		}
		if (result != NULL)
		{
			*result = max;
			return 0;
		}
		else
		{
			return -1;
		}
	}
}

/* TASK 4 */

// Return the minimum value in the vector.
// If finding the minimum was successful, dereference the pointer
// result and place the min value in that location. Return 0 on success.
// If finding the minimum failed, because the vector v was
// NULL or v->dim is zero or v->data was NULL then return -1 on failure. 
// Do not modify *result in this case.
int vec_min( vec_t *v, double* result )
{
	if (v == NULL || v->dim == 0 || v->data == NULL)
	{
		return -1;
	}
	else
	{
		unsigned int len = v->dim;
		double min = v->data[0];
		for (int i = 1; i < len; i++ )
		{
			if (v->data[i] < min)
			{
				min = v->data[i];
			}
		}
		if (result != NULL)
		{
			*result = min;
			return 0;
		}
		else
		{
			return -1;
		}
	}	
}

/* TASK 5 */

// Return the sum of all elements in vector v.
// If sum was successful, dereference the pointer result and
// place the sum value in that location. Return 0 on success.
// If calculating the sum was unsuccessful, because vector v 
// was NULL or v->dim was zero or v->data was NULL then return
// -1 on failure. Do not modify *result in this case.
int vec_sum( vec_t *v, double* result )
{
	if (v == NULL || v->dim == 0 || v->data == NULL)
	{
		return -1;
	}
	else
	{
		unsigned int len = v->dim;
		double sum = 0;
		for (int i = 0; i < len; i++ )
		{
			sum = sum + v->data[i];
		}

		if (result != NULL)
		{
			*result = sum;
			return 0;
		}
		else
		{
			return -1;
		}
	}	
}

/* TASK 6 */

// Return the dot product of two vectors which is defined as the
// sum of the product of the corresponding elements of each vector.
// For example, if v1 = [0.3,0.2] and v2 = [0.5,0.4] then vec_dotprod
// will return 0.23 = (.3*.5) + (.2*.4)
// If the dot product was successful, dereference the pointer
// result and place the result in that location. Return 0 on success.
// If the dot product was unsuccessful return -1.
// The two vectors must have the same dimension. If they do not
// then the dot product will be unsuccessful. If either vector
// is NULL or the data location for either vector is NULL then 
// the dot product will be unsuccessful.
int vec_dotprod( vec_t *v1, vec_t *v2, double *result )
{
	if (v1->dim != v2->dim || v1 == NULL || v2 == NULL || v1->data == NULL || v2->data == NULL)
	{
		return -1;
	}
	else 
	{
		unsigned int len = v1->dim;
		double sum = 0;
		for (int i = 0; i < len; i++ )
		{
			double product = v1->data[i] * v2->data[i];
			sum = sum + product;
		}

		if (result != NULL)
		{
			*result = sum;
			return 0;
		}
		else
		{
			return -1;
		}
	}
}
