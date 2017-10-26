/**
* @file uart.h
* @brief An abstraction for functions containing UART operations
*
* This header file provides an abstraction of manipulating UART via function calls
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/
#ifndef __UART_H__
#define __UART_H__

//***********************************************************************************
// Include files
//***********************************************************************************
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

//***********************************************************************************
// Macros
//***********************************************************************************
#define baud_rate 115200

//***********************************************************************************
// Function prototypes
//***********************************************************************************

/******************************************************************//****
* @brief UART_configure()
* This function configures UART to the given settings
* @return Nothing
***********************************************************************/

void UART_configure();

/******************************************************************//****
* @brief UART_send()
* This function sends a single byte down a specific UART device
* @ch Pointer​ ​to​ the​ data item to send
* @return Nothing
***********************************************************************/

void UART_send(uint8_t* ch);

/******************************************************************//****
* @brief UART_send_n()
* This function sends a number of bytes down a specific UART device
* @ch Pointer to a contiguous block of data that needs to be transmitted
* @length Number of items to transmit
* @return Nothing
***********************************************************************/

void UART_send_n(uint8_t* ch,int length);

/******************************************************************//****
* @brief UART_receive()
* This function receives a single byte of data on a specific UART
* device
* @ch Input parameter pointer used to return a received byte on the UART
* @return Nothing
***********************************************************************/

void UART_receive(uint8_t* ch);

/******************************************************************//****
* @brief UART_receive_n()
* This function receives a number of bytes of data on the UART
* @ch Pointer to a memory location to place data that is being received
* @length Number of items to receive
* @return Nothing
***********************************************************************/

void UART_receive_n(uint8_t* ch,int length);

/******************************************************************//****
* @brief UART0_IRQHandler()
* This function is the IRQ Handler for the UART
* @return Nothing
***********************************************************************/

void UART0_IRQHandler();

#endif /* __UART_H__ */
