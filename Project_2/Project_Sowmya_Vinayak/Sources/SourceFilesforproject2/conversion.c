/**
 * @file conversion.c
 * @brief This file contains functions which perform basic data manipulation operations.
 *
 * @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
 * @date October 25, 2017
 *
 */

//***********************************************************************************
//Function Definitions
//***********************************************************************************
/******************************************************************//****
 * @brief my_itoa()
 * This function converts data from a standard integer type into an ASCII string
 * @data Data to be converted
 * @ptr Pointer which points to the resultant ASCII string
 * @base Integer value of the base to which conversion is to happen
 * @return Length of the converted data (including a negative sign)
 ***********************************************************************/
#include"conversion.h"
void my_itoa(uint8_t data,uint8_t* ptr, uint32_t base)
{
	/* Initializing variables */
	uint8_t len=0;
	uint8_t t;
	int8_t j=1;
	/* Checking and initializing pointer to appropriate sign */
	if(data>=0){
		*ptr = '+';
		len++;
	}
	else{
		*ptr = '-';
		len++;
		data = -data;
	}

	/* Checking if data is not zero (zero conditions) */
	while(data!=0){
		/* Calculating remainder */
   		uint32_t remainder=data % base;
		/* Checking remainder and changing pointer value */
   		if(remainder>9){
   			*(ptr+len)=((uint8_t)(remainder-10))+'a';
   			len++;
   		}
   		else{
   			*(ptr+len)= ((uint8_t)(remainder))+'0';
   			len++;
   		}
		/* Dividing data by base */
 		data = data/base;
	}
	while((ptr +j) <= (ptr + len - 1 - j)){
		/* Swap operation */
         t= *(ptr+j);
         *(ptr+j) = *(ptr+len -1 -j);
         *(ptr+len-1-j)=t;
		/* Increment j and decement i */
         j++;
	}
	/* Append last character to null*/
	*(ptr+len)='\0';
}





