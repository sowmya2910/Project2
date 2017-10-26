/**
* @file uart.c
* @brief This file contains functions which perform UART operations
*
* @author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan
* @date October 25, 2017
*
*/

#include"uart.h"
#include"circbuf.h"

//***********************************************************************************
// Macros
//***********************************************************************************
/* Declaring Receive and Transmit buffers as circular buffer objects */
CB_t RXBuff;
CB_t TXBuff;

//***********************************************************************************
//Function Definitions
//***********************************************************************************

/******************************************************************//****
* @brief UART_configure()
* This function configures UART to the given settings
* @return Nothing
***********************************************************************/

void UART_configure(){
    SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
    UART0_C2 &= ~(ARTLP_C2_RE_MASK | UARTLP_C2_TE_MASK) /* Disable the transmitter and receiver */
    /* Turn on clock to UART0 module and select 48Mhz clock (FLL/PLL source) */
    SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
    SIM_SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
    SIM_SOPT2 |= SIM_SOPT2_FLLPLLSEL(1);
    SIM_SOPT2 |= SIM_SOPT2_FLLPLLSEL(1);
    /* Select "Alt 2" usage to enable UART0 on pins */
    PORTA_PCR1 = PORT_PCR_MUX(2);
    PORTA_PCR2 = PORT_PCR_MUX(2);
    UART0_S2 = 0; /* Initialize LSB */
    /* Clear C1, C2, C3 to disable UART transmitter and receiver */
    UART0_C2 = 0;
    UART0_C1 = 0;
    UART0_C3 = 0;
    uint16_t divisor = CORE_CLOCK / (baud_rate * 16); /* Calculate baud rate value */
    UART0_C4 = UARTLP_C4_OSR(16-1); /* Set oversampling rate to 16 */
    /* Set the baud rate */
    UART0_BDH = (divisor >> 8) & UARTLP_BDH_SBR_MASK;
    UART0_BDL = (divisor & UARTLP_BDL_SBR_MASK);
    /* Enable the transmitter, receiver, and receiver interrupts */
    UART0_C2 = (uint32_t)UARTLP_C2_RE_MASK | UARTLP_C2_TE_MASK | UARTLP_C2_RIE_MASK;
    /*Enable UART0 interrupts */
	NVIC_ISER |= (uint32_t)(1<<(INT_UART0-16));
}

/******************************************************************//****
* @brief UART_send()
* This function sends a single byte down a specific UART device
* @ch Pointer​ ​to​ the​ data item to send
* @return Nothing
***********************************************************************/

void UART_send(uint8_t* ch){
    while((UART0_S1 & UART_S1_TDRE_MASK)==0) /* Waiting until transmit data buffer is empty */
        ;
    UART0_D=*ch; /* Sending data down the UART */
}

/******************************************************************//****
* @brief UART_send_n()
* This function sends a number of bytes down a specific UART device
* @ch Pointer to a contiguous block of data that needs to be transmitted
* @length Number of items to transmit
* @return Nothing
***********************************************************************/

void UART_send_n(uint8_t* ch,int length){
    int i;
    for(i=0;i<length;i++){ /* For loop for sending length number of data */
    while((UART0_S1 & UART_S1_TDRE_MASK)==0) /* Waiting until transmit data buffer is empty */
        ;
    UART0_D=*ch++; /* Sending data down the UART */
    }
}

/******************************************************************//****
* @brief UART_receive()
* This function receives a single byte of data on a specific UART
* device
* @ch Input parameter pointer used to return a received byte on the UART
* @return Nothing
***********************************************************************/

void UART_receive(uint8_t* ch){
    while((UART0_S1 & UART_S1_RDRF_MASK)==0) /* Waiting until receive data buffer is empty */
        ;
    *ch=UART0_D; /* Receiving data on the UART */
}

/******************************************************************//****
* @brief UART_receive_n()
* This function receives a number of bytes of data on the UART
* @ch Pointer to a memory location to place data that is being received
* @length Number of items to receive
* @return Nothing
***********************************************************************/

void UART_receive_n(uint8_t* ch,int length){
    int i;
    for(i=0;i<length;i++){ /* For loop for receiving length number of data */
    while((UART0_S1 & UART_S1_RDRF_MASK)==0) /* Waiting until receive data buffer is empty */
        ;
    *ch++=UART0_D; /* Receiving data on the UART */
    }
}

/******************************************************************//****
* @brief UART0_IRQHandler()
* This function is the IRQ Handler for the UART
* @return Nothing
***********************************************************************/

void UART0_IRQHandler(){
    /* If transmit data register empty, and data in the transmit buffer,
    send it */
    if((UART0_S1 & UART_S1_RDRF_MASK)==UART_S1_RDRF_MASK){
        UART_receive(ch);
        CB_buffer_add_item(RXBuff,(uint8_t)ch);
    }
    /* If there is received data, read it into the receive buffer */
    else if((UART0_S1 & UART_S1_TDRE_MASK)==UART_S1_TDRE_MASK){
        CB_buffer_remove_item(TXBuff,(uint8_t)ch);
        UART_send(ch);
    }
}
