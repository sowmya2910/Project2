/**
 * @file test_conv.c
 * @brief This file contains functions which perform unit tests for conversion operations.
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date November 3,2017
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************

#include "conversion.h"

//***********************************************************************************
// function definitions
//***********************************************************************************

/******************************************************************//****
 * @brief test_little_to_big32_invalid_pointers()
 * This function checks if little to big works for invalid pointers
 * @return Appropriate enum value
 ***********************************************************************/

void test_little_to_big32_invalid_pointers(){
  enum test_status status = TEST_SUCCEED; /* Initializing enum value to SUCCESS */
  uint32_t * set=NULL; /* Initializing variable value to NULL */
  uint32_t * ptra;
  ptra = &set[0]; /* Setting value of set to ptra */
  /* Carrying out little to big conversion for NULL pointer */
  status=little_to_big32(ptra, TEST_MEMMOVE_LENGTH);
  /* Cmocka for Null pointer */
  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}

/******************************************************************//****
 * @brief test_big_to_little32_invalid_pointers()
 * This function checks if big to little works for invalid pointers
 * @return Appropriate enum value
 ***********************************************************************/

void test_big_to_little32_invalid_pointers(){ 
  enum test_status status = TEST_SUCCEED; /* Initializing enum value to SUCCESS */
  uint32_t * set=NULL; /* Initializing variable value to NULL */
  uint32_t * ptra;
  ptra = &set[0]; /* Setting value of set to ptra */
  /* Carrying out little to big conversion for NULL pointer */
  status=big_to_little32(ptra, TEST_MEMMOVE_LENGTH);
  /* Cmocka for Null pointer */
  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}

/******************************************************************//****
 * @brief test_big_to_little32_check_set()
 * This function checks if big to little works properly
 * @return Appropriate enum value
 ***********************************************************************/

void test_big_to_little32_check_set(){
  enum test_status status = TEST_SUCCEED; /* Initializing enum value to SUCCESS */
  uint32_t set=0x12345678; /* Setting 32 bit value to variable */
  uint32_t ptra=0x78563412; /* Setting its little endian value to another variable */
  ptra=big_to_little32(&ptra,32); /* Big to little operation for ptra */
  if(set==ptra){ /* Checking if set and ptra are equal */
     status=TEST_SUCCEED; /* Enum value is success */
  }
  /* Cmocka for operation successful */
  assert_int_equal(status,TEST_SUCCEED); 
}

/******************************************************************//****
 * @brief test_little_to_big32_check_set()
 * This function checks if little to big works properly
 * @return Appropriate enum value
 ***********************************************************************/

void test_little_to_big32_check_set(){
  enum test_status status = TEST_SUCCEED; /* Initializing enum value to SUCCESS */
  uint32_t set=0x12345678; /* Setting 32 bit value to variable */
  uint32_t ptra=0x78563412; /* Setting its big endian value to another variable */
  ptra=little_to_big32(&ptra,32); /* Little to big operation for ptra */
  if(set==ptra){ /* Checking if set and ptra are equal */
     status=TEST_SUCCEED; /* Enum value is success */
  }
  /* Cmocka for operation successful */
  assert_int_equal(status,TEST_SUCCEED);
}
