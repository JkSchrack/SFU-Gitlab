int identical(int a[], int b[], unsigned int len)
{
   int same = 1;
   for( unsigned int i=0; i<len; i++ )
   {
      if( !(a[i] == b[i] ) )
      {
      	same = 0;
      }
   }
   return same;
}
