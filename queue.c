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

/***** Local Variables *****/
static int initialized = 0;
static int head_idx = 0;
static int tail_idx = 0;
static queue_data_t queue[MAX_QUEUE_SIZE + 1];

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
    size = ( MAX_QUEUE_SIZE - head_idx ) + tail_idx;
  }

  return size;
}

/**
 *  @brief  Get the maximum possible list size.
 *  @return Maximum list size possible.
 */
int queue_max_size( void )
{
  return MAX_QUEUE_SIZE;
}

/**
 *  @brief  Access the next element.
 *  @return The next element in the queue.
 */
queue_data_t queue_front( void )
{

}

/**
 *  @brief  Access the last element in the queue.
 *  @return The last element in the queue.
 */
queue_data_t queue_back( void )
{

}

/**
 *  @brief  Insert element into the queue.
 *  @param  val - element to be inserted.
 */
void queue_push( queue_data_t val )
{

}

/**
 *  @brief  Removes the next element in the queue.
 */
void queue_pop( void )
{

}

/***** Private Functions *****/

