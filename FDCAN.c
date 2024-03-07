/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : FDCAN.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE BEGIN Includes */
#include "main.h"
#include "FDCAN.h"
#include <stdio.h>
#include "stm32g4xx_hal.h"

extern FDCAN_HandleTypeDef hfdcan1;
extern UART_HandleTypeDef huart1;


/*FDCAN filter structure definition*/
FDCAN_FilterTypeDef sFilterConfig;

/*brief  FDCAN Tx header structure definition */
FDCAN_TxHeaderTypeDef TxHeader;

/*brief  FDCAN Rx header structure definition */
FDCAN_RxHeaderTypeDef RxHeader;


uint8_t Node1_Rx[64];
uint32_t Rx_FIFO_Level;
char Rx_FIFO_Lev[50];
/* USER CODE END Includes */

/*************************************************************************
*@brief Using filter_config() function inside wrapper to SET Acceptance filters .
*@retval void
*
**************************************************************************/

void filter_config(void)
{
	/* Configure Rx filter */
 	  sFilterConfig.IdType = FDCAN_STANDARD_ID;
 	  sFilterConfig.FilterIndex = 0;
 	  sFilterConfig.FilterType = FDCAN_FILTER_DUAL;
 	  sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO1;
 	  sFilterConfig.FilterID1 = 0x10;
 	  sFilterConfig.FilterID2 = 0x10;

 	 HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig);
}
/*************************************************************************
*@brief Using FDCAN_TX_Header() function inside wrapper to Set TX Header FD CAN.
*@retval void
*
**************************************************************************/
void Tx_header(void)
{
	/* Prepare Tx Header */
 		TxHeader.Identifier = 0x12;
 	  TxHeader.IdType = FDCAN_STANDARD_ID;
 	  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
 	  TxHeader.DataLength = FDCAN_DLC_BYTES_64;
 	  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
 	  TxHeader.BitRateSwitch = FDCAN_BRS_ON;
 	  TxHeader.FDFormat = FDCAN_FD_CAN;
 	  TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
 		//TxHeader.TxEventFifoControl =FDCAN_STORE_TX_EVENTS;
 	  TxHeader.MessageMarker = 0x0;
}
/*************************************************************************
*@brief Using FDCAN_Start() function inside wrapper to Start FD CAN.
*@retval void
*
**************************************************************************/
void FDCAN_Start(void)
{
	// Start the FDCAN module //
	 	  if (HAL_FDCAN_Start(&hfdcan1) != HAL_OK)
	 	  {
	 			HAL_UART_Transmit(&huart1,(uint8_t *)"CAN_Node_2_Error in FDCAN_Start\n\r", sizeof("Error in FDCAN_ConfigFilter\n\r"),100);
	 	    Error_Handler();
	 	  }

}
/*************************************************************************
 *@brief Function FDCAN_GetRxMessage() Receive RX message to  FIFO
 *@retval void
 *
 **************************************************************************/
void FDCAN_GetRxMessage(void)
{
	 //Get Rx Message //
	  	if(HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO1,&RxHeader, Node1_Rx)==HAL_OK)
	  	{

	  		printf("Received Data:");
	  		HAL_UART_Transmit(&huart1,(uint8_t *)Node1_Rx, 64,100);
	  		printf("\n\r ");
	  	}
}
/*************************************************************************
*@brief Function FIFO_Level() to get FIFO Level
*@retval void
*
**************************************************************************/
void FIFO_Level(void)
{
	Rx_FIFO_Level=HAL_FDCAN_GetRxFifoFillLevel(&hfdcan1, FDCAN_RX_FIFO1);

		  //	sprintf(Rx_FIFO_Lev,"Rx_FIFO_Fill:%u\n\r",Rx_FIFO_Level);
		  //
		  //	HAL_UART_Transmit(&huart1,(uint8_t *)Rx_FIFO_Lev, sizeof(Rx_FIFO_Lev),100);

}
