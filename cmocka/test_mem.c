/**
* @file test_mem.c
* @brief Functions containing cmocka unit tests for memory manipulation operations
*
* This file provides functions for cmocka unit tests for manipulating memory via function calls.
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date November 3, 2017
*
*/

//***********************************************************************************
// Include files
//***********************************************************************************

#include "memory.h"

//***********************************************************************************
// function definitions
//***********************************************************************************

/******************************************************************//****
 * @brief test_memmove_invalid_pointers()
 * Unit test function for checking invalid pointers for memmove
 * @return Appropriate enum value
 ***********************************************************************/

void test_memmove_invalid_pointers(){ 
  uint8_t * set=NULL;
  uint8_t * ptra;
  uint8_t * ptrb;
  uint8_t * ptrc;
  /* Setting pointers to NULL value */
  ptra = &set[0]; 
  ptrb = &set[0];
  /* Memmove with null pointers */
  ptrc=my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  if (! ptrc ){ /* If ptrc does not exist */
     status= TEST_ERROR_INVALID_POINTERS;;
  }
  /* cmocka failure statement for invalid (NULL) pointers */
  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}

/******************************************************************//****
 * @brief test_memcpy_invalid_pointers()
 * Unit test function for checking invalid pointers for memcopy
 * @return Appropriate enum value
 ***********************************************************************/

void test_memcpy_invalid_pointers(){
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * set=NULL;
  uint8_t * ptra;
  uint8_t * ptrb;
  /* Setting pointers to NULL value */
  ptra = &set[0];
  ptrb = &set[0];
  uint8_t * ptrc;
  /* Memcopy with null pointers */
  ptrc= my_memcpy(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  if (! ptrc ){ /* If ptrc does not exist */
     status= TEST_ERROR_INVALID_POINTERS;;
  }
  /* cmocka failure statement for invalid (NULL) pointers */
  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}

/******************************************************************//****
 * @brief test_memzero_invalid_pointers()
 * Unit test function for checking invalid pointers for memzero
 * @return Appropriate enum value
 ***********************************************************************/

void test_memzero_invalid_pointers(){
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * set=NULL;
  uint8_t * ptra;
  uint8_t * ptrc;
  /* Setting pointer to NULL value */
  ptra = &set[0];
  /* Memzero with null pointer */
  ptrc=my_memzero(ptra,TEST_MEMMOVE_LENGTH);
  if (! ptrc ){ /* If ptrc does not exist */
     status= TEST_ERROR_INVALID_POINTERS;;
  }
  /* cmocka failure statement for invalid (NULL) pointers */
  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}

/******************************************************************//****
 * @brief test_reverse_invalid_pointers()
 * Unit test function for checking invalid pointers for reverse
 * @return Appropriate enum value
 ***********************************************************************/

void test_reverse_invalid_pointers(){
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * set=NULL;
  uint8_t * ptra;
  uint8_t * ptrc;
  /* Setting pointer to NULL value */
  ptra = &set[0];
  /* Mem reverse with null pointer */
  ptrc=my_reverse(ptra,TEST_MEMMOVE_LENGTH);
  if (! ptrc ){ /* If ptrc does not exist */
     status= TEST_ERROR_INVALID_POINTERS;;
  }
  /* cmocka failure statement for invalid (NULL) pointers */
  assert_int_equal(status,TEST_ERROR_INVALID_POINTERS);
}

/******************************************************************//****
 * @brief test_memmove_no_overlap()
 * Unit test function for checking overlap in memmove
 * @return Appropriate enum value
 ***********************************************************************/

void test_memmove_no_overlap(){
  uint8_t i;
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
  printf("test_memmove1() - NO OVERLAP\n");
  /* Reserving size */
  set = (uint8_t*) reserve_words( MEM_SET_SIZE_W );
  ptra = &set[0];
  ptrb = &set[16];
  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++){
    set[i] = i;
  }
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++){
    if (set[i + 16] != i){ /* Checking overlap conditions */
      status = TEST_ERROR;
    }
  }
  /* cmocka success statement for no overlap */
  assert_int_equal(status,TEST_SUCCEED);
  free_words( (int32_t*)set );
}

/******************************************************************//****
 * @brief test_memmove_src_in_dst()
 * Unit test function for checking src in dst in memmove
 * @return Appropriate enum value
 ***********************************************************************/

void test_memmove_src_in_dst(){
  uint8_t i;
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
  printf("test_memmove() -OVERLAP END OF SRC BEGINNING OF DST\n");
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W); /* Reserving size */
  ptra = &set[0];
  ptrb = &set[8];
  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++){
    set[i] = i;
  }
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++){
    if (set[i + 8] != i){ /* Checking overlap conditions */
       status = TEST_ERROR;
    }
  }
  /* cmocka success statement for overlap end of src beginning of dst */
  assert_int_equal(status,TEST_SUCCEED);
  /* Free operation */
  free_words( (int32_t*)set );
}

/******************************************************************//****
 * @brief test_memmove_dst_in_src()
 * Unit test function for checking dst in src in memmove
 * @return Appropriate enum value
 ***********************************************************************/

void test_memmove_dst_in_src(){
  uint8_t i;
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
  set = (uint8_t*)reserve_words( MEM_SET_SIZE_W); /* Reserving size */
  ptra = &set[8];
  ptrb = &set[0];
  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++){
    set[i] = i;
  }
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++){ /* Checking overlap conditions */
    if (set[i] != (i + 8)){
      status = TEST_ERROR;
    }
  }
  /* cmocka success statement for overlap end of dst beginning of src */
  assert_int_equal(status,TEST_SUCCEED);
  /* Free operation */
  free_words( (int32_t*)set );
}

/******************************************************************//****
 * @brief test_memcpy_check_set()
 * Unit test function for checking if memcopy works properly
 * @return Appropriate enum value
 ***********************************************************************/

void test_memcpy_check_set(){
  uint8_t i;
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
  printf("test_memcpy()\n");
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W); /* Reserving size */
  ptra = &set[0];
  ptrb = &set[16];
  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) {
    set[i] = i;
  }
  my_memcpy(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++){ /* Checking if memcopy works properly */
    if (set[i+16] != i){
      status = TEST_ERROR;
    }
  }
  /* cmocka success statement for memcopy operation */
  assert_int_equal(status,TEST_SUCCEED);
  /* Free operation */
  free_words( (int32_t*)set );
}

/******************************************************************//****
 * @brief test_memzero_check_set()
 * Unit test function for checking if memzero works properly
 * @return Appropriate enum value
 ***********************************************************************/

void test_memzero_check_set(){
  uint8_t i;
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * set;
  uint8_t * ptra;
  printf("test_memzero()\n");
  set = (uint8_t*)reserve_words(MEM_SET_SIZE_W); /* Reserving size */
  ptra = &set[0];
  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++){
    set[i] = i;
  }
  my_memzero(ptra, MEM_ZERO_LENGTH);
  /* Validate Set & Zero Functionality */
  for (i = 0; i < MEM_ZERO_LENGTH; i++){
    if (set[i] != 0){
      status = TEST_ERROR;
    }
  }
  /* cmocka success statement for memzero operation */
  assert_int_equal(status,TEST_SUCCEED);
  /* Free operation */
  free_words( (int32_t*)set );
}

/******************************************************************//****
 * @brief test_reverse_even_check_set()
 * Unit test function for checking if reverse works properly for even 
 * number of characters
 * @return Appropriate enum value
 ***********************************************************************/

void test_reverse_even_check_set(){
  uint8_t i;
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * copy;
  /* Even set of characters */
  uint8_t set[MEM_SET_SIZE_B] = {0x3F, 0x73, 0x72, 0x33, 0x54, 0x43, 0x72, 0x26,
                                 0x48, 0x63, 0x20, 0x66, 0x6F, 0x00, 0x20, 0x33,
                                 0x72, 0x75, 0x74, 0x78, 0x21, 0x4D, 0x20, 0x40,
                                 0x20, 0x24, 0x7C, 0x20, 0x24, 0x69, 0x68, 0x54
                               };
  printf("test_reverse()\n");
  copy = (uint8_t*)reserve_words(MEM_SET_SIZE_W); /* Reserving size */
  if (! copy ){ /* If copy is empty, null pointer error */
    status=TEST_ERROR_INVALID_POINTERS;
  }
  my_memcpy(set, copy, MEM_SET_SIZE_B);
  my_reverse(set, MEM_SET_SIZE_B); /* Reverse operation */
  for (i = 0; i < MEM_SET_SIZE_B; i++){
    if (set[i] != copy[MEM_SET_SIZE_B - i - 1]){ /* Checking if reverse works correctly */
      status = TEST_ERROR;
    }
  }
  /* cmocka success statement for memreverse operation with even characters */
  assert_int_equal(status,TEST_SUCCEED);
  /* Free operation */
  free_words( (int32_t*)copy );
}

/******************************************************************//****
 * @brief test_reverse_odd_check_set()
 * Unit test function for checking if reverse works properly for odd
 * number of characters
 * @return Appropriate enum value
 ***********************************************************************/

void test_reverse_odd_check_set(){
  uint8_t i;
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * copy;
  /* Odd set of characters */
  uint8_t set[31] = {0x3F, 0x73, 0x72, 0x33, 0x54, 0x43, 0x72, 0x26,
                                 0x48, 0x63, 0x20, 0x66, 0x6F, 0x00, 0x20, 0x33,
                                 0x72, 0x75, 0x74, 0x78, 0x21, 0x4D, 0x20, 0x40,
                                 0x20, 0x24, 0x7C, 0x20, 0x24, 0x69, 0x68
                               };
  printf("test_reverse()\n");
  copy = (uint8_t*)reserve_words(31); /* Reserving size */
  if (! copy ){ /* If copy is empty, null pointer error */
    status=TEST_ERROR_INVALID_POINTERS;
  }
  my_memcpy(set, copy, 31);
  my_reverse(set, 31); /* Reverse operation */
  for (i = 0; i < 31; i++){
    if (set[i] != copy[31 - i - 1]){ /* Checking if reverse works correctly */
      status = TEST_ERROR;
    }
  }
  /* cmocka success statement for memreverse operation with odd characters */
  assert_int_equal(status,TEST_SUCCEED);
  /* Free operation */
  free_words( (int32_t*)copy );
}

/******************************************************************//****
 * @brief test_reverse_character_check_set()
 * Unit test function for checking if reverse works properly for any
 * number of characters
 * @return Appropriate enum value
 ***********************************************************************/

void test_reverse_character_check_set(){
  uint8_t i;
  enum test_status status = TEST_SUCCEED; /* Enum status as success */
  uint8_t * copy;
  /* Set of characters */
  uint8_t set[32] = {'a', 'b', 'c', 'd', 'e','f', 'g','h',
                                 'i','j','k','l','m','n','o','p',
                                'q','r','s','t','u','v','w','x',
                                'y','z','a','b','c','d','e','f'
                               };
  printf("test_reverse()\n");
  copy = (uint8_t*)reserve_words(32); /* Reserving size */
  if (! copy ){ /* If copy is empty, null pointer error */
    status=TEST_ERROR_INVALID_POINTERS;
  }
  my_memcpy(set, copy, MEM_SET_SIZE_B);
  my_reverse(set, MEM_SET_SIZE_B); /* Reverse operation */
  for (i = 0; i < MEM_SET_SIZE_B; i++){
    if (set[i] != copy[MEM_SET_SIZE_B - i - 1]){ /* Checking if reverse works correctly */
      status = TEST_ERROR;
    }
  }
  /* cmocka success statement for memreverse operation with character check set */
  assert_int_equal(status,TEST_SUCCEED);
  /* Fre operation */
  free_words( (int32_t*)copy );
}




