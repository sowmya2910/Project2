/**
 * @file test_main.c
 * @brief This file consists of the functions to be used for unit testing with cmocka
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date November 3, 2017
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "conversion.h"
#include "circbuf.h"

//***********************************************************************************
//Function Definitions
//***********************************************************************************

/******************************************************************//****
 * @brief function to call cmocka functions
 * This function calls cmocka functions
 * @return void
 ***********************************************************************/

int main(void)
{
  const struct CMUnitTest tests[] = {
    /* Memory functions */
    cmocka_unit_test(test_memmove_invalid_pointers),
    cmocka_unit_test(test_memcpy_invalid_pointers),
    cmocka_unit_test(test_memzero_invalid_pointers),
    cmocka_unit_test(test_reverse_invalid_pointers),
    cmocka_unit_test(test_memmove_no_overlap),
    cmocka_unit_test(test_memmove_src_in_dst),
    cmocka_unit_test(test_memmove_dst_in_src),
    cmocka_unit_test(test_memcpy_check_set),
    cmocka_unit_test(test_memzero_check_set),
    cmocka_unit_test(test_reverse_even_check_set),
    cmocka_unit_test(test_reverse_odd_check_set),
    cmocka_unit_test(test_reverse_character_check_set),
    /* Conversion functions */
    cmocka_unit_test(test_big_to_little32_invalid_pointers),
    cmocka_unit_test(test_little_to_big32_invalid_pointers),
    cmocka_unit_test(test_big_to_little32_check_set),
    cmocka_unit_test(test_little_to_big32_check_set),
    /* Circular buffer functions */
    cmocka_unit_test(test_CB_Allocate_Free),
    cmocka_unit_test(test_CB_Buffer_Empty),
    cmocka_unit_test(test_CB_Buffer_Full),
    cmocka_unit_test(test_CB_overfill),
    cmocka_unit_test(test_CB_overempty),
    cmocka_unit_test(test_CB_wrap_remove),
    cmocka_unit_test(test_CB_wrap_add),
    cmocka_unit_test(test_CB_buf_alloc_valid),
    cmocka_unit_test(test_CB_buf_ptr_valid),
    cmocka_unit_test(test_CB_add_remove),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
