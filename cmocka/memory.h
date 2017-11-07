/**
* @file memory.h
* @brief An abstraction for functions containing memory manipulation operations
*
* This header file provides an abstraction of manipulating memory via function calls.
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/

#ifndef __memory_H__
#define __memory_H__

//***********************************************************************************
// Include files, macro and enum definitions
//***********************************************************************************

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define DATA_SET_SIZE_W (10)
#define MEM_SET_SIZE_B  (32)
#define MEM_SET_SIZE_W  (8)
#define MEM_ZERO_LENGTH (16)
#define TEST_MEMMOVE_LENGTH (16)
#define TESTCOUNT           (8)

enum test_status{
TEST_ERROR_INVALID_POINTERS,
TEST_SUCCEED,
TEST_ERROR
}status;

//***********************************************************************************
// function prototypes
//***********************************************************************************

/******************************************************************//****
 * @brief test_memmove_invalid_pointers()
 * Unit test function for checking invalid pointers for memmove
 * @return Appropriate enum value
 ***********************************************************************/

void test_memmove_invalid_pointers();

/******************************************************************//****
 * @brief test_memcpy_invalid_pointers()
 * Unit test function for checking invalid pointers for memcopy
 * @return Appropriate enum value
 ***********************************************************************/

void test_memcpy_invalid_pointers();

/******************************************************************//****
 * @brief test_memzero_invalid_pointers()
 * Unit test function for checking invalid pointers for memzero
 * @return Appropriate enum value
 ***********************************************************************/

void test_memzero_invalid_pointers();

/******************************************************************//****
 * @brief test_reverse_invalid_pointers()
 * Unit test function for checking invalid pointers for reverse
 * @return Appropriate enum value
 ***********************************************************************/

void test_reverse_invalid_pointers();

/******************************************************************//****
 * @brief test_memmove_no_overlap()
 * Unit test function for checking overlap in memmove
 * @return Appropriate enum value
 ***********************************************************************/

void test_memmove_no_overlap();

/******************************************************************//****
 * @brief test_memmove_src_in_dst()
 * Unit test function for checking src in dst in memmove
 * @return Appropriate enum value
 ***********************************************************************/

void test_memmove_src_in_dst();

/******************************************************************//****
 * @brief test_memmove_dst_in_src()
 * Unit test function for checking dst in src in memmove
 * @return Appropriate enum value
 ***********************************************************************/

void test_memmove_dst_in_src();

/******************************************************************//****
 * @brief test_memcpy_check_set()
 * Unit test function for checking if memcopy works properly
 * @return Appropriate enum value
 ***********************************************************************/

void test_memcpy_check_set();

/******************************************************************//****
 * @brief test_memzero_check_set()
 * Unit test function for checking if memzero works properly
 * @return Appropriate enum value
 ***********************************************************************/

void test_memzero_check_set();

/******************************************************************//****
 * @brief test_reverse_even_check_set()
 * Unit test function for checking if reverse works properly for even 
 * number of characters
 * @return Appropriate enum value
 ***********************************************************************/

void test_reverse_even_check_set();

/******************************************************************//****
 * @brief test_reverse_odd_check_set()
 * Unit test function for checking if reverse works properly for odd
 * number of characters
 * @return Appropriate enum value
 ***********************************************************************/

void test_reverse_odd_check_set();

/******************************************************************//****
 * @brief test_reverse_character_check_set()
 * Unit test function for checking if reverse works properly for any
 * number of characters
 * @return Appropriate enum value
 ***********************************************************************/

void test_reverse_character_check_set();

/******************************************************************//****
 * @brief my_memmove()
 * This function copies bytes of data from source to destination and
 * handles overlap of source and destination
 * @src Memory location of source data
 * @dst Memory location of destination data
 * @length Number of bytes to be moved
 * @return Pointer to the destination
 ***********************************************************************/

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/******************************************************************//****
 * @brief my_memcpy()
 * This function copies bytes of data from source to destination and
 * does not handle overlap of source and destination
 * @src Memory location of source data
 * @dst Memory location of destination data
 * @length Number of bytes to be moved
 * @return Pointer to the destination
 ***********************************************************************/

uint8_t *my_memcpy(uint8_t *src,uint8_t *dst,size_t length);

/******************************************************************//****
 * @brief my_memset()
 * This function sets all locations of a memory to a given value
 * @src Memory location of source data
 * @length Number of bytes to be set
 * @value Value to be set
 * @return Pointer to the source
 ***********************************************************************/

int8_t *my_memset(uint8_t *src,size_t length, uint8_t value);

/******************************************************************//****
 * @brief my_memzero()
 * This function zeros out all the memory
 * @src Memory location of source data
 * @length Number of bytes to be zero-d
 * @return Pointer to the source
 ***********************************************************************/

uint8_t *my_memzero(uint8_t *src, size_t length);

/******************************************************************//****
 * @brief my_reverse()
 * This function reverses the order of all the bytes
 * @src Memory location of source data
 * @length Number of bytes to be reversed
 * @return Pointer to the source
 ***********************************************************************/

uint8_t *my_reverse(uint8_t *src,size_t length);

/******************************************************************//****
 * @brief reserve_words()
 * This function allocates words in dynamic memory
 * @length Number of words to be allocated
 * @return If operation is successful, pointer to the allocation is returned
 * If operation is not successful, NULL pointer is returned
 ***********************************************************************/

int32_t *reserve_words(size_t length);

/******************************************************************//****
 * @brief free_words()
 * This function frees an allocated dynamic memory
 * @src Pointer pointing to memory allocation
 * @return void
 ***********************************************************************/

void free_words(int32_t *src);

#endif /*__memory_H__*/
