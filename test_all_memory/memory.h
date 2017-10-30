#ifndef __memory_H__
#define __memory_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


enum test_status{
TEST_ERROR_INVALID_POINTERS,
TEST_SUCCESS,
TEST_ERROR
}status;


/*Function for memory moving*/
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/*Function for copying of data*/
uint8_t *my_memcpy(uint8_t *src,uint8_t *dst,size_t length);

/*Function to set memory values*/

int8_t *my_memset(uint8_t *src,size_t length, uint8_t value);

/*Function to set all memory locations to Zero*/

uint8_t *my_memzero(uint8_t *src, size_t length);

/*Funtion for Reversing*/

uint8_t *my_reverse(uint8_t *src,size_t length);

/*Function for reserving of memory for words*/
int32_t *reserve_words(size_t length);

/*Function to free memory locations*/
void free_words(int32_t *src);

#endif /*__memory_H__*/
