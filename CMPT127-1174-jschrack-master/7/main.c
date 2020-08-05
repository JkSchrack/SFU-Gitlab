#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char* argv[] )
{
  list_t* list = list_create();

  for( int i=0; i<5; i++ )
    list_append( list, i );
  
  for( int i=-1; i>-5; i-- )
    list_prepend( list, i );
  
  list_print( list );

  
  int index = 2;
  element_t* el = list_index( list, index );
  
  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1; // fail
    }
  
  printf( "value at index %d is %d\n", index, el->val );
  
  if( el->val != -2 ) 
    return 1;
  
  list_destroy( list );

///task 1 list index is wrong///task 1 list index is wrong
  list_t* list1 = list_create();
  list_index(list1, 3);
  list_destroy(list1);


///task 2 element create is wrong
  list_t* list2 = list_create();
  list_append(list2, 1);
  list_prepend(list2, 1);
  element_t* el2 = list_index(list2, 1);
  el2 = element_create(1);
  if (el2->next != NULL)
  {
    printf("el2->next should be null but is not assigned\n");
    return 1;
  }
  list_destroy(list2);

  ///t3 list index is wrong
  list_t* list3 = list_create();
  list_append(list3, 7);
  element_t* el3 = list_index(list3, 0);
  if (el3 == NULL)
  {
    printf("el3 shouldnt be NULL because list->head->next is not a thing\n");
    return 1;
  }
  list_destroy(list3);
  
  
  ///t4 prepend is wrong
  list_t* list4 = list_create();
  list_prepend(list4, 7);
  if (list4->tail == NULL)
  {
    printf("tail should never be NULL\n"); // list->tail is not assigned
    return 1;
  }
  list_destroy(list4);
  

  
  ///t5 create is wrong
  list_t* list5 = list_create();
  if(list5->head != NULL || list5->tail != NULL)
  {
    printf("head and tail were not assigned\n");
    return 1;
  }
  list_destroy(list5);


  
  //task 6 list index/print is wrong
  list_t* list6 = list_create();
  list_append(list6, 7);
  list_index(list6, 3);
  list_destroy(list6);

  
  ///////////////////////
  return 0; // tests pass
}
