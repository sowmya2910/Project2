/**
* @file circbuf.h
* @brief An abstraction for functions containing circular buffer manipulation
* operations
*
* This header file provides an abstraction of manipulating data via circular
* buffers
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/
#ifndef SOURCES_CIRCBUF_H_
#define SOURCES_CIRCBUF_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdbool.h>

//***********************************************************************************
// Struct and Enum definitions
//***********************************************************************************
typedef struct{
	uint8_t *buffer_pointer;
	uint8_t *head;
	uint8_t *tail;
	size_t size;
	size_t count;
	} CB_t;

typedef enum{

	Full,
	Empty,
	Success,
	Null_Pointer,
	Buffer_out,
	Buffer_not_full,
	Buffer_not_empty,
	Buffer_failure,
	Peek_position_error
	} CB_status;

//***********************************************************************************
// Function prototypes
//***********************************************************************************

/******************************************************************//****
* @brief CB_buffer_add_item()
* This function adds an item to the circular buffer
* @buffer Pointer​ ​to​ the​ circular​ buffer​​ to​​ which​​ the​​ data​​ item​​ is​​ to​​
* be​​ added
* @num The​ ​data​ ​to​ be​ ​added​ ​to​ ​the​ ​circular​ ​buffer
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

CB_status CB_buffer_add_item (CB_t *buffer, uint8_t num);

/******************************************************************//****
* @brief CB_buffer_remove_item()
* This function removes an item from the circular buffer
* @buffer Pointer​ ​to​ the​ circular​ buffer​​ from​​ which​​ the​​ data​​ item​​ is​​ to​​
* be​​ removed
* @num Variable​ ​to​ ​store​ ​and​ ​return​ ​the​ ​removed​ ​item​ ​from​ ​the​ ​buffer
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

CB_status CB_buffer_remove_item (CB_t* buffer, uint8_t* num);

/******************************************************************//****
* @brief CB_is_full()
* This function checks if a circular buffer is full
* @buffer Pointer to the circular buffer which is to be checked if it
* is full
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_is_full (CB_t* buffer);

/******************************************************************//****
* @brief CB_is_empty()
* This function checks if a circular buffer is empty
* @buffer Pointer to the circular buffer which is to be checked if it
* is full
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_is_empty (CB_t* buffer);

/******************************************************************//****
* @brief CB_peek()
* This function peeks into a particular position in the circular buffer
* and returns the pointer that points to that position
* @buffer Pointer to the circular buffer to peek into
* @pos The position from the head of the buffer to peek into
* @pointer Pointer to store and return a pointer that points to the
* position peeked into
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_peek (CB_t* buffer, uint8_t pos, uint8_t* pointer);

/******************************************************************//****
* @brief CB_init()
* This function initializes and allocates size to a circular buffer
* @buffer Pointer to the circular buffer
* @length Length/size to be reserved for the buffer
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_init (CB_t* buffer,size_t length);

/******************************************************************//****
* @brief CB_destroy()
* This function destroys a circular buffer/frees a circular buffer of its
* space
* @buffer Pointer to the circular buffer to be destroyed
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_destroy (CB_t* buffer);

/******************************************************************//****
* @brief test_CB_Allocate_Free()
* This function checks if the circular buffer allocates and frees properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_Allocate_Free();

/******************************************************************//****
* @brief test_CB_Buffer_Empty()
* This function checks if the circular buffer empty function works properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_Buffer_Empty();

/******************************************************************//****
* @brief test_CB_Buffer_Full()
* This function checks if the circular buffer full function works properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_Buffer_Full();

/******************************************************************//****
* @brief test_CB_overfill()
* This function checks if the circular buffer is overfilled
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_overfill();

/******************************************************************//****
* @brief test_CB_overempty()
* This function checks if the circular buffer is over-empty
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_overempty();

/******************************************************************//****
* @brief test_CB_wrap_remove()
* This function checks if the circular buffer wrap remove
* function works properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_wrap_remove();

/******************************************************************//****
* @brief test_CB_wrap_add()
* This function checks if the circular buffer wrap add
* function works properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_wrap_add();

/******************************************************************//****
* @brief test_CB_buf_alloc_valid()
* This function checks if the circular buffer allocation is valid
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_buf_alloc_valid();

/******************************************************************//****
* @brief test_CB_buf_ptr_valid()
* This function checks if the circular buffer pointer is valid
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_buf_ptr_valid();

/******************************************************************//****
* @brief test_CB_add_remove()
* This function checks if the circular buffer add and remove
* functions work properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_add_remove();

#endif /* SOURCES_CIRCBUF_H_ */
