/**
* @file circbuf.c
* @brief An file for functions containing circular buffer manipulation
* operations
*
* This file includes functions for manipulating data via circular
* buffers
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/

//***********************************************************************************
// Include files and definitions
//***********************************************************************************
#include"circbuf.h"
#define BUFFER_LENGTH 40
uint8_t temp_buffer[BUFFER_LENGTH];

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

CB_status CB_buffer_add_item (CB_t *buffer, uint8_t num){
	CB_status stat; /* Creating enum object */
	if ((buffer!=NULL)||(buffer->buffer_pointer)!=NULL){ /* Checking NULL conditions */
	if((buffer->size)==(buffer->count)){ /* Checking if buffer size is equal to count*/
        /* Initializing enum object and returning status that buffer is full */
		stat=Full;
        return stat;
	}
	else if((buffer->head)<((buffer->buffer_pointer)+ ((buffer->size)-1))){
		*(buffer->head)=num;  /* Adding data to the circular buffer */
		buffer->head++; /* Incrementing buffer head */
		buffer->count++; /* Incrementing buffer count */
		/* Initializing enum object and returning status that there is no error */
        	stat=Success;
		return stat;
	}
	else if((buffer->head)==((buffer->buffer_pointer)+ ((buffer->size)-1))){
		*(buffer->head)=num;  /* Adding data to the circular buffer */
		buffer->head=buffer->buffer_pointer;
		/* Incrementing buffer count */
		buffer->count++;
		/* Initializing enum object and returning status that there is no error */
		stat=Success;
		return stat;
	}
	else{
	/* Initializing enum object and returning status that buffer is outside */
		stat=Buffer_out;
		return stat;
		}
	}
	else{
	/* Initializing enum object and returning status that there is null pointer */
		stat=Null_Pointer;
		return stat;
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

CB_status CB_buffer_remove_item (CB_t *buffer, uint8_t *num){
	CB_status stat; /* Creating enum object */
	if ((buffer!=NULL)||(buffer->buffer_pointer)!=NULL) /* Checking NULL conditions */{
	if(buffer->count==0){ /* Checking if buffer count is 0 */
	    /* Initializing enum object and returning status that buffer is empty */
		stat=Empty;
		return stat;
	}
	else if((buffer->tail)<((buffer->buffer_pointer)+ ((buffer->size)-1))){
		*num=*(buffer->tail);/* Removing item */
		buffer->tail++; /* Incrementing buffer tail */
		buffer->count--; /* Decrementing buffer count */
	/* Initializing enum object and returning status that there is no error */
		stat=Success;
		return stat;
	}
	else if((buffer->tail)==((buffer->buffer_pointer)+ ((buffer->size)-1))){
		*num=*(buffer->tail); /* Reading and removing data from the circular buffer */
		buffer->tail=buffer->buffer_pointer; 
		buffer->count--; /* Decrementing buffer count */
		/* Initializing enum object and returning status that there is no error */
		stat=Success;
		return stat;
	}
	else
	{
	/* Initializing enum object and returning status that buffer is outside */
			stat=Buffer_out;
			return stat;
		}
	}
	else
	{
	/* Initializing enum object and returning status that there is null pointer */
		stat=Null_Pointer;
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

CB_status CB_is_full (CB_t *buffer){
	if((buffer!=NULL)||((buffer->buffer_pointer)!=NULL)){ /* Checking NULL conditions */
	if((buffer->count)== (buffer->size) ){ /* Checking if count and size are same */
	    /* Returning status that buffer is full */
		return Full;
	}
	else{
	/* Returning status that buffer is not full */
		return Buffer_not_full;
		}
	}
	else{
	/* Returning status that it is Null pointer */
		return Null_Pointer;
	}

}

/******************************************************************//****
* @brief CB_is_empty()
* This function checks if a circular buffer is empty
* @buffer Pointer to the circular buffer which is to be checked if it
* is full
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_is_empty (CB_t *buffer){
	if((buffer!=NULL)||((buffer->buffer_pointer)!=NULL)){ /* Checking NULL conditions */
	if((buffer->count)==0){ /* Checking if count is 0 */
	    /* Returning status that buffer is empty */
		return Empty;
	}
	else{
	 /* Returning status that buffer is not empty */
		return Buffer_not_empty;
		}
	}
	else
	{
	 /* Returning status that it is Null pointer */
		return Null_Pointer;
	}
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

CB_status CB_peek (CB_t *buffer, uint8_t pos, uint8_t *pointer){
	CB_status stat; /* Creating enum object */
	if(buffer->head==buffer->tail){ /* Checking if buffer head and tail are same */
	   /*Initializing enum object and returning status that buffer is empty */
		stat=Empty;
		return stat;
	}
	else{
	   	uint8_t *next=buffer->head - pos; /* Moving to the position specified */
	  	*pointer=*(buffer->head); /* Reading data from the position */
		buffer->head=next; /* Moving to the next position after completing reading process */
		/*Initializing enum object and returning status that there is no error */
		stat=Success;
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

CB_status CB_init (CB_t *buffer,size_t length){
	CB_status stat; /* Creating enum object */
	if(buffer!=NULL){ /* Checking if bufferis not NULL */
	buffer->buffer_pointer=(uint8_t*)malloc(length); /* Allocating size for the circular buffer */
	if((buffer->buffer_pointer)!=NULL){ /* Checking if buffer pointer is not NULL */
	/* Initializing buffer head,tail to buffer_pointer */
	buffer->head= buffer->buffer_pointer;
	buffer->tail= buffer->buffer_pointer;
	buffer->size=length;
	buffer->count=0; /* Initializing buffer count as zero */
	/* Initializing enum object and returning status that there is no error */
	stat=Success;
	return stat;
	}
	else{
	/* Initializing enum object and returning status that there is failure */
		stat=Buffer_failure;
		return stat;
		}
	}	
	else{
	/* Initializing enum object and returning status that there is null pointer */
		stat=Null_Pointer;
		return stat;
	}
}

/******************************************************************//****
* @brief CB_destroy()
* This function destroys a circular buffer/frees a circular buffer of its
* space
* @buffer Pointer to the circular buffer to be destroyed
* @return Status of the circular buffer or an error code
***********************************************************************/

CB_status CB_destroy (CB_t *buffer){
	CB_status stat; /* Creating enum object */
	free(buffer->buffer_pointer); /* Freeing buffer pointer of its space */
	/* Initializing enum object and returning status that there is no error */
	stat=Success;
	return stat;
}



