/***** Includes *****/
#include <stdio.h>
#include "queue.h"

/***** Definitions *****/

/***** Function Prototypes *****/
void print_element( queue_data_t *e );

/***** Start of main *****/
int main( int argc, char *argv[] )
{
  //
  // Variables
  //
  int curr_size = 0;
  queue_data_t i = 0;
  
  //
  // Initialize queue
  //
  queue_init();

  //
  // Fill up queue halfway.
  //
  printf( "Filling up queue halfway...\n" );
  for ( i = 0; i < queue_max_size() / 2; i++ )
  {
    queue_push( i );
    queue_print( &print_element );
    queue_print_buf( &print_element );
  }

  //
  // Empty out queue
  //
  printf( "Emptying queue...\n" );
  while ( !queue_empty() )
  {
    queue_pop();
    queue_print( &print_element );
    queue_print_buf( &print_element );
  }

  //
  // Fill up queue to the max.
  //
  printf( "Filling up queue all the way...\n" );
  i = 1;
  while ( queue_size() < queue_max_size() )
  {
    queue_push( i );
    queue_print( &print_element );
    queue_print_buf( &print_element );
    i = i + 2;
  }

  //
  // Empty out half of the queue
  //
  printf( "Emptying queue to half full...\n" );
  curr_size = queue_size();
  while ( queue_size() > curr_size / 2 )
  {
    queue_pop();
    queue_print( &print_element );
    queue_print_buf( &print_element );
  }

  //
  // Demo done!
  //
  return 0;
}

/***** Function Definitions *****/
void print_element( queue_data_t *e )
{
  printf( "%d", *e );
}

