/**
* @file conversion.h
* @brief An abstraction for functions containing basic data manipulation operations
*
* This header file provides an abstraction of manipulating data via function calls.
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/
#ifndef __conversion_H__
#define __conversion_H__

//***********************************************************************************
// Include files and macros
//***********************************************************************************
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "memory.h"
#define TEST_MEMMOVE_LENGTH (16)
#define TESTCOUNT           (8)

//***********************************************************************************
// function prototypes
//***********************************************************************************

/******************************************************************//****
 * @brief test_little_to_big32_invalid_pointers()
 * This function checks if little to big works for invalid pointers
 * @return Appropriate enum value
 ***********************************************************************/

void test_little_to_big32_invalid_pointers();

/******************************************************************//****
 * @brief test_big_to_little32_invalid_pointers()
 * This function checks if big to little works for invalid pointers
 * @return Appropriate enum value
 ***********************************************************************/

void test_big_to_little32_invalid_pointers();

/******************************************************************//****
 * @brief test_big_to_little32_check_set()
 * This function checks if big to little works properly
 * @return Appropriate enum value
 ***********************************************************************/

void test_big_to_little32_check_set();

/******************************************************************//****
 * @brief test_little_to_big32_check_set()
 * This function checks if little to big works properly
 * @return Appropriate enum value
 ***********************************************************************/

void test_little_to_big32_check_set();

/******************************************************************//****
 * @brief big_to_little32()
 * This function converts an array of data in memory from big endian
 * representation to little endian
 * @data Memory location of data
 * @length Length of memory
 * @return Appropriate enum value
 ***********************************************************************/

uint32_t big_to_little32(uint32_t data,uint32_t length);

/******************************************************************//****
 * @brief little_to_big32()
 * This function converts an array of data in memory from little endian
 * representation to big endian
 * @data Memory location of data
 * @length Length of memory
 * @return Appropriate enum value
 ***********************************************************************/

uint32_t little_to_big32(uint32_t data,uint32_t length);

#endif
