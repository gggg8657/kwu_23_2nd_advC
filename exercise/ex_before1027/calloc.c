#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   long *buffer;

   buffer = (long *)calloc( 40, sizeof( long ) );
   if( buffer != NULL )
      printf( "Allocated 40 long integers\n" );
   else
      printf( "Can't allocate memory\n" );
    for (int i=0; i<5; i++){
        printf("%d", *(buffer+i));
    }
   free( buffer );
   return 0;
}


