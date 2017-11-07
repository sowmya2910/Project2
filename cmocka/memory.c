/**
 * @file memory.c
 * @brief This file contains functions which perform memory manipulation operations.
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date October 25, 2017
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************

//***********************************************************************************
//Function Definitions
//***********************************************************************************

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

/******************************************************************//****
 * @brief my_memmove()
 * This function copies bytes of data from source to destination and
 * handles overlap of source and destination
 * @src Memory location of source data
 * @dst Memory location of destination data
 * @length Number of bytes to be moved
 * @return Pointer to the destination
 ***********************************************************************/

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length){
	size_t i;
	uint8_t *temp;
	if (! src ){ /* Check for NULL condition */
    		return NULL;
    	}
	/* Allocate memory to temporary variable */
	temp = (uint8_t*) malloc(length * sizeof(uint8_t)); 
    	for(i=0;i<length;i++){ /* Run for loop */
        *(temp+i)=*(src+i); /* Temporary  variable copy operation */
    	}
	for(i=0;i<length;i++){ /* Run for loop */
        *(dst+i)=*(temp+i); /* Destination copy operation */
    	}
   	free(temp); /* Free temporary variable */
	/* Return pointer to destination */
	return dst;
}

/******************************************************************//****
 * @brief my_memcpy()
 * This function copies bytes of data from source to destination and
 * does not handle overlap of source and destination
 * @src Memory location of source data
 * @dst Memory location of destination data
 * @length Number of bytes to be moved
 * @return Pointer to the destination
 ***********************************************************************/

uint8_t *my_memcpy(uint8_t *src,uint8_t *dst,size_t length){
	int i;
	if (! src ){ /* Check for NULL condition */
    		return NULL;
    	}
	for(i=0;i<length;i++){ /* Run for loop */
      		*(dst+i)= *(src+i); /* Data copy operation */
    	}
	return dst; /* Return pointer to the destination */
}

/******************************************************************//****
 * @brief my_memset()
 * This function sets all locations of a memory to a given value
 * @src Memory location of source data
 * @length Number of bytes to be set
 * @value Value to be set
 * @return Pointer to the source
 ***********************************************************************/

int8_t *my_memset(uint8_t *src,size_t length, uint8_t value){
	uint8_t i;
	/* Run for loop */
	for(i=0;i<length;i++){
     		*(src+i)=value; /* Replace memory with the value */
   	}
	/* Return pointer to the source */
	return(int8_t*)src;
}

/******************************************************************//****
 * @brief my_memzero()
 * This function zeros out all the memory
 * @src Memory location of source data
 * @length Number of bytes to be zero-d
 * @return Pointer to the source
 ***********************************************************************/

uint8_t *my_memzero(uint8_t *src, size_t length){
	uint8_t i;
	if (! src ){ /* Check for NULL condition */
    		return NULL;
    	}
	/* Zero out the memory by replacing 0 in source data */
	for(i=0;i<length;i++){
     		*(src+i)=0;
   	}
	/* Return pointer to the source */
	return src;
}

/******************************************************************//****
 * @brief my_reverse()
 * This function reverses the order of all the bytes
 * @src Memory location of source data
 * @length Number of bytes to be reversed
 * @return Pointer to the source
 ***********************************************************************/

uint8_t *my_reverse(uint8_t *src,size_t length){
	int i=0;
	int j=0;			       
  	uint8_t temp;
  	j=length-1;
  	if (! src ){ /* Check NULL condition */
    		return NULL;
    	}			
        while(i <j){ /* Check if i is less than j */
		/* Swapping operation */				
        	temp= *(src+i);
        	*(src+i) = *(src+j);
        	*(src+j)=temp;
		/* Increment i and decrement j */
        	i++;
        	j--;
       }
       /* Return pointer to the source */
       return src;
}

/******************************************************************//****
 * @brief reserve_words()
 * This function allocates words in dynamic memory
 * @length Number of words to be allocated
 * @return If operation is successful, pointer to the allocation is returned
 * If operation is not successful, NULL pointer is returned
 ***********************************************************************/

int32_t *reserve_words(size_t length){
	int32_t *ptr;
	/* Allocate dynamic memory */
	ptr = (int32_t*) malloc(length * sizeof(int32_t));
	/* Return pointer to the allocation */
	return ptr;
}

/******************************************************************//****
 * @brief free_words()
 * This function frees an allocated dynamic memory
 * @src Pointer pointing to memory allocation
 * @return void
 ***********************************************************************/

void free_words(int32_t *src){
	if(src!=NULL){ /* Check NULL condition */
	/* Free the allocated dynamic memory */
		free(src);
	}
}

