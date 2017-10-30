/**
* @file uart.h
* @brief An abstraction for functions containing UART manipulation operations
*
* This header file provides an abstraction of manipulating data in UART
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/
#ifndef SOURCES_UART_H_
#define SOURCES_UART_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include"MKL25Z4.h"
#include"system_MKL25Z4.h"
#include"circbuf.h"

//***********************************************************************************
// Macros
//***********************************************************************************
#define baud 38400
CB_t RXBuff;
CB_t TXBuff;
extern	uint8_t TData;
extern	uint8_t RData;

//***********************************************************************************
// Function prototypes
//***********************************************************************************

/******************************************************************//****
* @brief UART_configure()
* This function configures UART to the given settings
* @return Nothing
***********************************************************************/

void UART_configure(void);

/******************************************************************//****
* @brief UART_send()
* This function sends a single byte down a specific UART device
* @ch Pointer​ ​to​ the​ data item to send
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

UART_Status UART_send(uint8_t* ch);

/******************************************************************//****
* @brief UART_send_n()
* This function sends a number of bytes down a specific UART device
* @ch Pointer to a contiguous block of data that needs to be transmitted
* @length Number of items to transmit
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

UART_Status UART_send_n(uint8_t* ch,uint8_t length);

/******************************************************************//****
* @brief UART_receive()
* This function receives a single byte of data on a specific UART
* device
* @ch Input parameter pointer used to return a received byte on the UART
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

UART_Status UART_receive(uint8_t* ch);

/******************************************************************//****
* @brief UART_receive_n()
* This function receives a number of bytes of data on the UART
* @ch Pointer to a memory location to place data that is being received
* @length Number of items to receive
* @return Enumeration that specifies the success, failure etc.of the
* function call
***********************************************************************/

UART_Status UART_receive_n(uint8_t* ch,uint8_t length);

/******************************************************************//****
* @brief UART0_IRQHandler()
* This function is the IRQ Handler for the UART
* @return Nothing
***********************************************************************/

void UART0_IRQHandler(void);


#endif /* SOURCES_UART_H_ */
