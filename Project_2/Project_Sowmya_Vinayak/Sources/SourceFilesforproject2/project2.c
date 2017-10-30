/**
* @file project2.c
* @brief This file contains functions used in project2.c
*
* This header file provides the functions in
* project2.c
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/

//***********************************************************************************
// Include files
//***********************************************************************************
#include<stdio.h>
#include<stdint.h>
#include"MKL25Z4.h"
#include"uart.h"
#include"circbuf.h"
#include"project2.h"
#include"conversion.h"

//***********************************************************************************
// Macros and definitions
//***********************************************************************************
uint8_t char_count[4];

//***********************************************************************************
//Function Definitions
//***********************************************************************************
/******************************************************************//****
* @brief dump_statistics()
* This is the function to be called in project2.c
* @return Nothing
***********************************************************************/
void dump_statistics(){
	/* Declare array of macros */
	uint8_t array1[4][33]={ALPHABET,NUMERIC,PUNCTUATION,MISCELLANEOUS};
	/* Declare variables */
	uint8_t m,n;
	/* Print lines */
	for(m=0;m<4;m++){
		for(n=0;n<33;n++){
			CB_buffer_add_item(&TXBuff,&array1[m][n]);
		}
		uint8_t array2[4];
		/* ITOA to convert integer to ascii */
		my_itoa(char_count[m],array2,10);
		/* Adding ascii value in buffer */
		CB_buffer_add_item(&TXBuff,&array2[1]);
		CB_buffer_add_item(&TXBuff,&array2[2]);
		char_count[m] = 0;
		/* Initialising value to 0 */
		for(n=0;n<4;n++){
			array2[n]=0;
		}
	}
	/* Enabling Transmitter interrupt */
	UART0_C2 |=(UART0_C2_TIE_MASK);
}

/******************************************************************//****
* @brief proj2()
* This is the function to be called in project2.c
* @return Nothing
***********************************************************************/
CB_status Status;
void proj2(){
	/* Initial Configuration operations */
	SystemInit();
	UART_configure();
	/* Setting buffer lengths and initializing */
	CB_init(&RXBuff,255);
	CB_init(&TXBuff,255);
	uint8_t data;
	while(1){
		CB_status test=0;
		test=CB_buffer_remove_item(&RXBuff,&data);
		if(test==No_Error){
			/* Checking for alphabets */
			if((data>=65 && data<=90)||(data>=97 && data<=122)){
				char_count[0]++;
				data=0;
			}
			/* Checking for numeric */
			else if(data>=48 && data<=57){
				char_count[1]++;
				data=0;
			}
			/* Checking for punctuations */
			else if((data>=33 && data<=47)||(data>=58 && data<=64)||(data>=91 && data<=96)){
			char_count[2]++;
			data=0;
			}
			/* Checking for 'space' to start printing table */
			else if((data==32)){
			dump_statistics();
			data=0;
			}
			/* Checking for miscellaneous characters */
			else if((data>=123 && data<=127)){
			char_count[3]++;
			data=0;
			}
		}
	}
}
