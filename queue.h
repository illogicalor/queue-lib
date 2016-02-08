/*******************************************************************************
 * 
 *  @file:    queue.h
 *  @author:  IllogicalOR
 *  @brief:   Header file for generic queue library.
 * 
 *******************************************************************************
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

/***** Includes *****/
#include <stdlib.h> // Needed for NULL define. Change accordingly.

/***** Definitions *****/
//
// Configure the maximum elements allowed in the queue.
//
#define MAX_QUEUE_ELEMENTS  32

//
// Enable debug functions.
//
#define QUEUE_DEBUG_EN      1

//
// Queue element data structure. This must be defined!
// Default type is an int.
//
typedef int queue_data_t;

//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !! --- Remaining code should not be modified --- !!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//

/***** Function Prototypes *****/
//
// Init/deinit functions
//
void queue_init( void );
void queue_deinit( void );
int  queue_initialized( void );

//
// Capacity
//
int queue_empty( void );
int queue_size( void );
int queue_max_size( void );

//
// Element access
//
queue_data_t *queue_front( void );
queue_data_t *queue_back( void );

//
// Modifiers
//
int queue_push( queue_data_t val );
void queue_pop( void );

#if ( defined QUEUE_DEBUG_EN && QUEUE_DEBUG_EN > 0 )
//
// Debug
//
void queue_print( void (*fn_print)(queue_data_t *element) );
void queue_print_buf( void (*fn_print)(queue_data_t *element) );
#else
#define queue_print( fnptr )
#endif /* QUEUE_DEBUG_EN */

#endif /* __QUEUE_H__ */

