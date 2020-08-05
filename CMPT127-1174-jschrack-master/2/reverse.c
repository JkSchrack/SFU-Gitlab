void reverse( int arr[], unsigned int len)
{
   int temp[len];
   int last = len - 1;
   for( unsigned int i=0; i<len; i++ )
   {
      temp[last] = arr[i];
      last = last - 1;
   }
   for( unsigned int i=0; i<len; i++ )
   {
   	arr[i] = temp[i];
   }
}