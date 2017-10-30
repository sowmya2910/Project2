/*@file conversion.h
* @brief An abstraction for functions containing basic data manipulation operations
*
* This header file provides an abstraction of manipulating data via function calls.
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/

#ifndef __CONVERSION_H__
#define __CONVERSION_H__
//***********************************************************************************
// Include files
//***********************************************************************************
#include<stdint.h>

//***********************************************************************************
// Function Prototype
//***********************************************************************************
/******************************************************************//****
 * @brief my_itoa()
 * This function converts data from a standard integer type into an ASCII string
 * @data Data to be converted
 * @ptr Pointer which points to the resultant ASCII string
 * @base Integer value of the base to which conversion is to happen
 * @return Length of the converted data (including a negative sign)
 ***********************************************************************/
void my_itoa(uint8_t data, uint8_t* ptr, uint32_t base);

#endif /* SOURCES_CONVERSION_H_ */
