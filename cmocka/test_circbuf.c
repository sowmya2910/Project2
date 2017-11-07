/**
* @file test_circbuf.c
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

#include "circbuf.h"

//***********************************************************************************
// function definitions
//***********************************************************************************

/******************************************************************//****
* @brief test_CB_Allocate_Free()
* This function checks if the circular buffer allocates and frees properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_Allocate_Free(){
  uint8_t length;
  length=5; /* Length to be initialized to buffer*/
  CB_status status; /* Enum object */
  CB_t circ_buf; 
  CB_t * ptr = &circ_buf; /* Buffer pointer */
  status=CB_init(ptr, length); /* Calling init function with length as 5 */
  assert_int_equal(status,Success); /* cmocka statement for successful operation */
}

/******************************************************************//****
* @brief test_CB_Buffer_Empty()
* This function checks if the circular buffer empty function works properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_Buffer_Empty(){
  uint8_t length;
  length=5; /* Length to be initialized to buffer*/
  CB_status status; /* Enum object */
  CB_t circ_buf;
  CB_t * ptr = &circ_buf; /* Buffer pointer */
  CB_init(ptr, length); /* Calling init function with length as 5 */
  status=CB_is_empty(ptr); /* Checking is buffer empty */
  assert_int_equal(status,Empty); /* cmocka statement for buffer empty */
}

/******************************************************************//****
* @brief test_CB_Buffer_Full()
* This function checks if the circular buffer full function works properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_Buffer_Full(){
  uint8_t length,i;
  length=5; /* Length to be initialized to buffer*/
  i=0;
  CB_status status; /* Enum object */
  CB_t circ_buf;
  CB_t * ptr = &circ_buf; /* Buffer pointer */
  CB_init(ptr, length); /* Calling init function with length as 5 */
  uint8_t a[5]={1,2,3,4,5};
  while(i<length){
	/* Adding items to buffer */
  	CB_buffer_add_item(ptr, a[i]);
  	i++;
  }
  status=CB_is_full(ptr); /* Checking if buffer is full */
  assert_int_equal(status,Full); /* cmocka statement for buffer full */
}

/******************************************************************//****
* @brief test_CB_overfill()
* This function checks if the circular buffer is overfilled
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_overfill(){
  uint8_t length,i;
  length=5; /* Length to be initialized to buffer*/
  i=0;
  CB_status status; /* Enum object */
  CB_t circ_buf;
  CB_t * ptr = &circ_buf; /* Buffer pointer */
  CB_init(ptr, length); /* Calling init function with length as 5 */
  uint8_t a[6]={1,2,3,4,5,6};
  while(i<length){
	/* Adding items to buffer */
  	CB_buffer_add_item(ptr,a[i]);
  	i++;
  }
  /* Calling buffer add function with 6 elements */
  status=CB_buffer_add_item(ptr,a[5]); 
  if(status!=Success){
  	status=Buffer_failure; /* Enum object as failure */
  }
  assert_int_equal(status,Buffer_failure); /* cmocka failure statement for buffer overfull */
}

/******************************************************************//****
* @brief test_CB_overempty()
* This function checks if the circular buffer is over-empty
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_overempty(){
  uint8_t length,a;
  length=5; /* Length to be initialized to buffer*/
  uint8_t * ptr1 = &a; /* Pointer object */
  CB_status status; /* Enum object */
  CB_t circ_buf;
  CB_t * ptr = &circ_buf; /* Buffer pointer */
  CB_init(ptr, length); /* Calling init function with length as 5 */
  status=CB_buffer_remove_item(ptr,ptr1); /* Reading items from buffer */
  if(status!=Success){
  	status=Buffer_failure; /* Enum object as failure */
  }
  /* cmocka failure statement for buffer overempty */
  assert_int_equal(status,Buffer_failure);
}

/******************************************************************//****
* @brief test_CB_wrap_remove()
* This function checks if the circular buffer wrap remove
* function works properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_wrap_remove(){
    uint8_t length = 2; /* Length to be initialized to buffer*/
    uint8_t i=2; 
    uint8_t a ;
    uint8_t *st = &a; /* Pointer object */
    CB_status status =Buffer_failure; /* Enum object as failure */
    CB_t circ_buf;
    CB_t * ptr = &circ_buf; /* Buffer pointer */
    CB_init(ptr , length);  /* Calling init function with length as 2 */
    for( a=0 ;a<length;a++){
    	CB_buffer_add_item(ptr,i); /* Adding 2 items to buffer */
    }
    /* Removing 2 items from buffer */
    CB_buffer_remove_item(ptr,st);
    CB_buffer_remove_item(ptr,st);
    /* Checking if wrap condition worked correctly */
    if((ptr->tail) == (ptr->buffer_pointer)){
         status=Success; 
    }
    /* cmocka success statement for buffer wrap remove */
    assert_int_equal(status,Success);
}

/******************************************************************//****
* @brief test_CB_add_remove()
* This function checks if the circular buffer add and remove
* functions work properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_add_remove(){
    uint8_t length = 4; /* Length to be initialized to buffer*/
    uint8_t i, j=5;
    uint8_t a, count =0;
    uint8_t *st = &a;
    CB_status status; /* Enum object */
    CB_t circ_buf;
    CB_t * ptr = &circ_buf; /* Buffer pointer */
    CB_init(ptr , length); /* Calling init function with length as 4 */
    for(i=0 ; i<length ; i++){
        j = j+i;
	/* Adding and removing items from buffer successively */
        CB_buffer_add_item(ptr,j);
        CB_buffer_remove_item(ptr,st);
        if(*st == j){
            count ++;
        }
    }
    if(count == length){ /* Checking if count is same as length of buffer */
        status = Success;
	/* cmocka success statement for buffer add remove */
        assert_int_equal(status,Success);
    }
}

/******************************************************************//****
* @brief test_CB_buf_ptr_valid()
* This function checks if the circular buffer pointer is valid
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_buf_ptr_valid(){
    uint8_t length = 6; /* Length to be initialized to buffer*/
    CB_status status; /* Enum object */
    CB_t circ_buf;
    CB_t * ptr = &circ_buf; /* Buffer pointer */
    status  = CB_init(ptr , length); /* Calling init function with length as 6 */
    if(ptr->buffer_pointer != NULL) /* Checking if buffer pointer has been initialized */
    status = Success;
    /* cmocka success statement for valid buffer pointer */
    assert_int_equal(status,Success);
}

/******************************************************************//****
* @brief test_CB_buf_alloc_valid()
* This function checks if the circular buffer allocation is valid
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_buf_alloc_valid(){
    uint8_t length = 6; /* Length to be initialized to buffer*/
    CB_status status; /* Enum object */
    CB_t circ_buf;
    CB_t * ptr = &circ_buf; /* Buffer pointer */
    status  = CB_init(ptr , length); /* Calling init function with length as 6 */
    /* cmocka success statement for valid buffer allocation */
    assert_int_equal(status,Success);
}

/******************************************************************//****
* @brief test_CB_wrap_add()
* This function checks if the circular buffer wrap add
* function works properly
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

void test_CB_wrap_add(){
    uint8_t length = 2; /* Length to be initialized to buffer*/
    uint8_t i=2;
    uint8_t a ;
    uint8_t *st = &a; /* Pointer object */
    CB_status status; /* Enum object */
    CB_t circ_buf;
    CB_t * ptr = &circ_buf; /* Buffer pointer */
    CB_init(ptr , length); /* Calling init function with length as 2 */
    /* Adding 2 items and removing 1 item from buffer */
    CB_buffer_add_item(ptr,i++);
    CB_buffer_add_item(ptr,i++);
    CB_buffer_remove_item(ptr,st);
    if((ptr->buffer_pointer) == (ptr->head)){ /* Checking if wrap condition worked correctly */
        status = Success;
    }
    else{
        status = Buffer_failure; /* If wrap add failed */
    }
    /* cmocka success statement for buffer wrap add */
    assert_int_equal(status,Success);
}

