/**
* @file project2.h
* @brief An abstraction for functions to be used in project2.c
*
* This header file provides an abstraction of functions in
* project2.c
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/
#ifndef SOURCES_PROJECT2_H_
#define SOURCES_PROJECT2_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"MKL25Z4.h"
#include"uart.h"
#include"circbuf.h"

//***********************************************************************************
// Macros
//***********************************************************************************
#define ALPHABET "Number of alphabets            :"
#define NUMERIC "Number of numerical values     :"
#define PUNCTUATION "Number of punctuation values   :"
#define MISCELLANEOUS "Number of miscellaneous values :"

//***********************************************************************************
// Extern Variables
//***********************************************************************************
extern uint8_t char_count[4];
extern	CB_t RXBuff;
extern	CB_t TXBuff;
extern	uint8_t TData;
extern	uint8_t RData;

//***********************************************************************************
// Function declarations
//***********************************************************************************

/******************************************************************//****
* @brief proj2()
* This is the function to be called in project2.c
* @return Nothing
***********************************************************************/
void proj2();

/******************************************************************//****
* @brief dump_statistics()
* This is the function to be called in project2.c
* @return Nothing
***********************************************************************/
void dump_statistics();


#endif /* SOURCES_PROJECT2_H_ */
