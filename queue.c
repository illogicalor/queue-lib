/*******************************************************************************
 * 
 *  @file:    queue.c
 *  @author:  IllogicalOR
 *  @brief:   Queue library implementation.
 * 
 *******************************************************************************
 */

/***** Includes *****/
#include <string.h>
#include "queue.h"

/***** Error checking *****/

/***** Definitions *****/
#define QUEUE_BUF_SIZE    ( MAX_QUEUE_ELEMENTS + 1 )

/***** Local Variables *****/
static int initialized = 0;
static int head_idx = 0;
static int tail_idx = 0;
static queue_data_t q_buf[QUEUE_BUF_SIZE];

/***** Function Prototypes *****/

/***** Function Definitions *****/
// ---------- Overflow Functions ----------
/**
 *  @brief  Initialize the queue
 */
void queue_init( void )
{
  // Reset head and tail pointers.
  head_idx = 0;
  tail_idx = 0;

  // Set internal flag that list is initialized.
  initialized = 1;
}

/**
 *  @brief  Deinitialize the queue
 */
void queue_deinit( void )
{
  // Reset head and tail pointers.
  head_idx = 0;
  tail_idx = 0;

  // Clear internal flag that list is initialized.
  initialized = 0;
}

/**
 *  @brief  Determined if queue was initialized or not.
 *  @return 1 if queue is initialized, 0 otherwise.
 */
int queue_initialized( void )
{
  return initialized;
}

/**
 *  @brief  See if the queue is empty.
 *  @return 1 if queue is empty. 0 otherwise.
 */
int queue_empty( void )
{
  return ( head_idx == tail_idx );
}

/**
 *  @brief  Get the size of the queue.
 *  @return Size of the queue.
 */
int queue_size( void )
{
  int size = 0;

  if ( head_idx <= tail_idx )
  {
    size = tail_idx - head_idx;
  }
  else
  {
    size = ( QUEUE_BUF_SIZE - head_idx ) + tail_idx;
  }

  return size;
}

/**
 *  @brief  Get the maximum possible list size.
 *  @return Maximum list size possible.
 */
int queue_max_size( void )
{
  return MAX_QUEUE_ELEMENTS;
}

/**
 *  @brief  Access the next element.
 *  @return Pointer to the next element in the queue.
 */
queue_data_t *queue_front( void )
{
  if ( !queue_empty() )
  {
    return &q_buf[head_idx];
  }

  return NULL;
}

/**
 *  @brief  Access the last element in the queue.
 *  @return Pointer to the last element in the queue.
 */
queue_data_t *queue_back( void )
{
  if ( !queue_empty() )
  {
    if ( tail_idx == 0 )
    {
      return &q_buf[MAX_QUEUE_ELEMENTS];
    }
    else
    {
      return &q_buf[tail_idx - 1];
    }
  }

  return NULL;
}

/**
 *  @brief  Insert element into the queue.
 *  @param  val - element to be inserted.
 *  @return 1 if push was successful. 0 otherwise.
 */
int queue_push( queue_data_t val )
{
  if ( head_idx <= tail_idx )
  {
    q_buf[tail_idx] = val;
    tail_idx = ( tail_idx + 1 ) % QUEUE_BUF_SIZE;
    return 1;
  }
  else if ( tail_idx + 1 < head_idx )
  {
    q_buf[tail_idx] = val;
    tail_idx++;
    return 1;
  }
  
  return 0;
}

/**
 *  @brief  Removes the next element in the queue.
 */
void queue_pop( void )
{
  if ( !queue_empty() )
  {
    head_idx = ( head_idx + 1 ) % QUEUE_BUF_SIZE;
  }
}

#if ( defined QUEUE_DEBUG_EN && QUEUE_DEBUG_EN > 0 )
#include <stdio.h>
/**
 *  @brief  Prints the queue contents.
 *  @param  Function pointer to printing a single queue element.
 */
void queue_print( void (*fn_print)(queue_data_t *element) )
{
  int i = head_idx;

  printf( "Queue (size %d)\n", queue_size() );
  while ( i != tail_idx )
  {
    printf( "[" );
    fn_print( &q_buf[i] );
    printf( "]" );

    // Increment index
    i = ( i + 1 ) % QUEUE_BUF_SIZE;
  }
  puts("");
}

/**
 *  @brief  Prints the queue buffer (including unused data).
 *  @param  Function pointer to printing a single queue element.
 */
void queue_print_buf( void (*fn_print)(queue_data_t *element) )
{
  int i;
  printf( "Queue buf\n" );
  for ( i = 0; i < QUEUE_BUF_SIZE; i++ )
  {
    printf( "[" );
    if ( i == head_idx )
    {
      printf( "{h}" );
    }
    if ( i == tail_idx )
    {
      printf( "{t}" );
    }

    fn_print( &q_buf[i] );
    printf( "]" );
  }
  puts("");
}
#endif /* QUEUE_DEBUG_EN */

/***** Private Functions *****/

