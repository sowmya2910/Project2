/**
* @file circbuf.c
* @brief This file contains functions which perform the circular buffer operations
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/

#include"circbuf.h"

//***********************************************************************************
//Function Definitions
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

CB_status CB_buffer_add_item (CB_t *buffer, uint8_t num)
{
	CB_status stat;
	uint8_t next=buffer->head + 1;
	if(next==buffer->tail)
	{
		stat=Full;
	    	return stat;
	}
	else 
{
}
}

/******************************************************************//****
* @brief CB_buffer_remove_item()
* This function removes an item from the circular buffer
* @buffer Pointer​ ​to​ the​ circular​ buffer​​ from​​ which​​ the​​ data​​ item​​ is​​ to​​ 
* be​​ removed
* @num Variable​ ​to​ ​store​ ​and​ ​return​ ​the​ ​removed​ ​item​ ​from​ ​the​ ​buffer
* @return Enumeration that specifies the success, failure etc.of the  
* function call
***********************************************************************/

CB_status CB_buffer_remove_item (CB_t* buffer, uint8_t* num)
{
	CB_status stat;
	if(buffer->head==buffer->tail)
	{
		stat=Empty;
		return stat;
	} 
	else
	{
		uint8_t next=buffer->tail+1;
		*num=buffer->buffer_pointer[buffer->tail];
		buffer->tail=next;
		buffer->count--;
		stat=No_Error;
		return stat;
	}
}

/******************************************************************//****
* @brief CB_is_full()
* This function checks if a circular buffer is full
* @buffer Pointer to the circular buffer which is to be checked if it
* is full
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_is_full (CB_t* buffer)
{
	CB_status stat;
	int next=buffer->head + 1;
	if(next==buffer->tail)
	{
		stat=Full;
		return stat;
	}
	stat=No_Error;
	return stat;
}

/******************************************************************//****
* @brief CB_is_empty()
* This function checks if a circular buffer is empty
* @buffer Pointer to the circular buffer which is to be checked if it
* is full
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_is_empty (CB_t* buffer)
{
	CB_status stat;
	if(buffer->head==buffer->tail)
	{
		stat=Empty;
		return stat;
	}
	stat=No_Error;
	return stat;
}

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

CB_status CB_peek (CB_t* buffer, uint8_t pos, uint8_t* pointer)
{
	CB_status stat;
	if(buffer->head==buffer->tail)
	{
		stat=Empty;
		return stat;
	}
	else
	{
	   	uint8_t next=buffer->head + pos;
	   	*pointer=&buffer->buffer_pointer[buffer->head];
		buffer->head=next;
		stat=No_Error;
		return stat;
	}
}

/******************************************************************//****
* @brief CB_init()
* This function initializes and allocates size to a circular buffer
* @buffer Pointer to the circular buffer
* @length Length/size to be reserved for the buffer
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_init (CB_t* buffer,size_t length)
{
	CB_status stat;
	buffer->buffer_pointer=malloc(length);
	buffer->size=length;
	buffer->count=0;
	stat=No_Error;
	return stat;
}

/******************************************************************//****
* @brief CB_destroy()
* This function destroys a circular buffer/frees a circular buffer of its 
* space
* @buffer Pointer to the circular buffer to be destroyed
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_destroy (CB_t* buffer)
{
	CB_status stat;
	free(buffer->buffer_pointer);
	stat=No_Error;
	return stat;
}


