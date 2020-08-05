#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <assert.h>
#include <stdio.h>
#include "intarr.h"

intarr_t* vec_create( int data[], unsigned int len )
{
    intarr_t* new_vec = (intarr_t*)malloc( sizeof(intarr_t) );
    int* new_data = (int*)malloc( len * sizeof(int) );
    if ( (new_vec == NULL) || (new_data == NULL) ) {
        perror("malloc()");
        return NULL;
    }
    new_vec->len = len;
    new_vec->data = new_data;
    for ( unsigned int i = 0; i < len; i++ )
        new_vec->data[i] = data[i];
    return new_vec;
}

void vec_destroy( intarr_t* v )
{
    if (v != NULL) {
        if (v->data != NULL)
            free( v->data );
        free( v );
    }
}

void vec_print( intarr_t* v )
{
    //assert( v );
    //assert( v->data );
    //assert( v->len > 0 );
    for ( unsigned int i = 0; i < v->len; i++ )
        printf( "%i", v->data[i] );
    printf("\n");
}

int main( int argc, char* argv[] )
{
    //int data[] = { 3, 2, 1, 4, 5};
    int data2[] = {};
    //intarr_t *v = vec_create( data, 5 );
    intarr_t *v2 = vec_create( data2, 0 );

    int result[] = {3};
    int test = intarr_pop(v2, result);

    printf("%i\n", test);
    printf("%i\n", result[0]);

    vec_print( v2 );
    vec_destroy( v2);
}
