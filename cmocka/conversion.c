/**
 * @file conversion.c
 * @brief This file contains functions which perform basic data manipulation operations.
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date October 25, 2017
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "conversion.h"
#include "circbuf.h"

//***********************************************************************************
//Function Definitions
//***********************************************************************************

/******************************************************************//****
 * @brief little_to_big32()
 * This function converts an array of data in memory from little endian
 * representation to big endian
 * @data Memory location of data
 * @length Length of memory
 * @return Appropriate enum value
 ***********************************************************************/

uint32_t little_to_big32(uint32_t data,uint32_t length)
{
    enum test_status status=TEST_SUCCEED; /* Initialize enum value */
    	uint32_t value;
    	if (! data ){ /* If no data, print error */
    		status= TEST_ERROR_INVALID_POINTERS;
    		return status;
    	}
    	if(length!=0){ /* Check for null length */
		/* The conversion is done from little to big endian */
        	value=((data &0X000000FF)<<24)|((data &0X0000FF00)<<8)|((data &0X00FF0000)>>8)|((data &0XFF000000)>>24);
		/* Length is decremented and data is incremented */
        	length--;
        	data++;
    	}
        else{ /* Return error */
    		return TEST_ERROR;
        }
	return TEST_SUCCEED; /* Return success */
}

/******************************************************************//****
 * @brief big_to_little32()
 * This function converts an array of data in memory from big endian
 * representation to little endian
 * @data Memory location of data
 * @length Length of memory
 * @return Appropriate enum value
 ***********************************************************************/

uint32_t big_to_little32(uint32_t data,uint32_t length)
{
    enum test_status status=TEST_SUCCEED; /* Initialize enum value */
    	uint32_t value;
    	if (! data ){ /* If no data, print error */
		status= TEST_ERROR_INVALID_POINTERS;
    		return status;
    	}
    	if(length!=0){ /* Check for null length */
		/* The conversion is done from little to big endian */
        	value=((data &0X000000FF)<<24)|((data &0X0000FF00)<<8)|((data &0X00FF0000)>>8)|((data &0XFF000000)>>24);
		/* Length is decremented and data is incremented */
        	length--;
        	data++;
    	}
        else{
    		return TEST_ERROR; /* Return error */
        }
	return TEST_SUCCEED; /* Return success */
}

