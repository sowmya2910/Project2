/**
* @file uart.c
* @brief This file contains functions which perform UART operations
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/
//***********************************************************************************
//Includes
//***********************************************************************************

#include"uart.h"
#include"circbuf.h"
#include"project2.h"
#include<stdbool.h>

//***********************************************************************************
// Macros and definitions
//***********************************************************************************
/* Global variables to store Rx/Tx Data*/
uint8_t TData=0;
uint8_t RData=0;

//***********************************************************************************
//Function Definitions
//***********************************************************************************

/******************************************************************//****
* @brief UART_configure()
* This function configures UART to the given settings
* @return Nothing
***********************************************************************/

void UART_configure(){
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;		//Clock gate enable for PORTA
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;		//Clock gate enable for UART0

	SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL(1);
    SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);  	//MCGFLLCLK as UART0


	PORTA_PCR1 |= PORT_PCR_MUX(2); 			//ALT2 mode for UART0_Rx
	PORTA_PCR2 |= PORT_PCR_MUX(2);			//ALT2 mode for UART0_Tx


	UART0_C2&= ~(UART0_C2_TE_MASK|UART0_C2_RE_MASK);


	UART0_BDH |= UART_BDH_SBNS(0);			// 1 STOP bit
	UART0_C1  |= UART_C1_M(0);				// 8 BIT mode
	UART0_C1  |= UART_C1_PE(0);				// NO PARITY

	uint16_t divisor = (SystemCoreClock/16)/baud ;
	UART0_BDH = ((divisor >> 8) & UART_BDH_SBR_MASK);
	UART0_BDL = (divisor & UART_BDL_SBR_MASK);

	NVIC_EnableIRQ(UART0_IRQn); 			//Enable at NVIC
	UART0_C2 |= UART0_C2_RIE_MASK;			//Peripheral interrupt enable (RX)

	//Enabling Transmitter and Receiver Interrupts
	UART0_C2 |= UART0_C2_TE_MASK ;
	UART0_C2 |= UART0_C2_RE_MASK ;
}

/******************************************************************//****
* @brief UART_send()
* This function sends a single byte down a specific UART device
* @ch Pointer​ ​to​ the​ data item to send
* @return Nothing
***********************************************************************/

UART_Status UART_send(uint8_t* ch){
	/* Creating enum object */
	UART_Status status;
	/* Checking for NULL pointer */
	if(ch != NULL){
		/* Sending data to UART */
		UART0->D = *ch;
	    /* Update status*/
		status= No_Error;
	}
	else{
		/* Update status*/
		status=Null_Pointer ;
	}
	/* return status*/
	return status;
}

/******************************************************************//****
* @brief UART_send_n()
* This function sends a number of bytes down a specific UART device
* @ch Pointer to a contiguous block of data that needs to be transmitted
* @length Number of items to transmit
* @return Nothing
***********************************************************************/

UART_Status UART_send_n(uint8_t* ch, uint8_t length){
	/* Declaring variable and enum */
	uint8_t i=0;
	UART_Status status;
	/* Check NULL pointer */
	if(ch != NULL){
		for(i=0; i<length; i++){
		  /* receive the data */
		  UART0->D = *(ch+i);
		}
		/* Update status*/
		status= No_Error;
	  }
	  else{
		/* Update status*/
		status= Null_Pointer;
	  }
	  /* return status*/
	  return status;
}

/******************************************************************//****
* @brief UART_receive()
* This function receives a single byte of data on a specific UART
* device
* @ch Input parameter pointer used to return a received byte on the UART
* @return Nothing
***********************************************************************/

UART_Status UART_receive(uint8_t* ch){
	/* Creating enum object */
	UART_Status status;
	/* check NULL pointer */
	if(ch != NULL){
    /* Read data from register*/
	*ch= UART0->D;
	/* Update status*/
	status= No_Error;
	}
	else{
	/* Update status*/
	status= Null_Pointer;
	}
	/* return status*/
	return status;
}

/******************************************************************//****
* @brief UART_receive_n()
* This function receives a number of bytes of data on the UART
* @ch Pointer to a memory location to place data that is being received
* @length Number of items to receive
* @return Nothing
***********************************************************************/

UART_Status UART_receive_n(uint8_t* ch, uint8_t length){
	/* Declaring variable and enum */
	uint8_t i=0;
	UART_Status status;
	/* Check NULL pointer */
	if(ch != NULL){
	for(i=0; i<length; i++){
	  /* receive the data */
	  *(ch+i) = UART0->D;
	}
	/* Update status*/
	status=No_Error;
	}
	else{
	/* Update status*/
	status=Null_Pointer;
	}
	/* return status*/
	return status;
}

/******************************************************************//****
* @brief UART0_IRQHandler()
* This function is the IRQ Handler for the UART
* @return Nothing
***********************************************************************/
void UART0_IRQHandler(){
    /* If transmit data register empty, and data in the transmit buffer,
    send it */
    if(((UART0_S1 & UART0_S1_RDRF_MASK)==UART0_S1_RDRF_MASK) && (!(CB_is_full(&RXBuff)))){
    	UART_receive(&RData);
        CB_buffer_add_item(&RXBuff,&RData);
        if(CB_is_full(&RXBuff)){
        /* Disable Receiver Interrupt */
        UART0_C2 &=~ UART0_C2_RIE_MASK;
        }
    }
   /* If there is received data, read it into the receive buffer */
    else if(((UART0_S1 & UART0_S1_TDRE_MASK)==UART0_S1_TDRE_MASK) && (!(CB_is_empty(&TXBuff)))){
    	CB_buffer_remove_item(&TXBuff,&TData);
    	UART_send(&TData);
    	if(CB_is_empty(&TXBuff)){
    	/* Disable Transmitter Interrupt */
    	UART0_C2 &= ~ UART0_C2_TIE_MASK;
    	}
    }
}


