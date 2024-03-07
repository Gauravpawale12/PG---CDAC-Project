/*
 **************************************************************************
 * @file 		FDCAN.c
 * @brief 		FDCAN and its operations
 **************************************************************************
 *
 */
#include <FDCAN.h>
extern int l;
char b2[50];
extern FDCAN_HandleTypeDef hfdcan1;
extern UART_HandleTypeDef huart1;
/*brief  FDCAN Tx header structure definition */
extern FDCAN_TxHeaderTypeDef TxHeader;
uint8_t count;
uint8_t Node1_Node2_Tx[64];
int j=0,d=0;
char Tx_FIFO_Buffer[40];
uint32_t Ret,Ret1;
char a;
/*************************************************************************
 *@brief Using printf() function inside wrapper to transmit data over UART.
 *@param UART Handler
 *@retval void
 *
 **************************************************************************/
void Printf_Function(UART_HandleTypeDef *UART){
#ifdef __GNUC__
  /* With GCC, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

	HAL_Delay(500);
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
 *@brief Using FDCAN_TX_Header() function inside wrapper to Set TX Header FD CAN.
 *@retval void
 *
 **************************************************************************/
void FDCAN_TX_Header(void)
{
	/* Prepare Tx Header */
  TxHeader.Identifier = 0x10;
  TxHeader.IdType = FDCAN_STANDARD_ID;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;

		/* FDCAN_data_length_code */

	HAL_UART_Transmit(&huart1,(uint8_t *)"Enter the Size of Data \n\r:",sizeof("Enter the Size of Data \n\r"),200);
	HAL_Delay(2000);


			if(HAL_OK==HAL_UART_Receive(&huart1, (uint8_t *) &a, 1, 2000))

				{

			HAL_UART_Transmit(&huart1,(uint8_t *)&a,2,200);
			HAL_Delay(1000);
			switch(a)
			{
				case 'A': {TxHeader.DataLength =FDCAN_DLC_BYTES_0;l=0;}break;
				case 'B': {TxHeader.DataLength =FDCAN_DLC_BYTES_1;l=1;}break;
				case 'C': {TxHeader.DataLength =FDCAN_DLC_BYTES_2;l=2;}break;
				case 'D': {TxHeader.DataLength =FDCAN_DLC_BYTES_3;l=3;}break;
				case 'E': {TxHeader.DataLength =FDCAN_DLC_BYTES_4;l=4;}break;
				case 'F': {TxHeader.DataLength =FDCAN_DLC_BYTES_5;l=5;}break;
				case 'G': {TxHeader.DataLength =FDCAN_DLC_BYTES_6;l=6;}break;
				case 'H': {TxHeader.DataLength =FDCAN_DLC_BYTES_7;l=7;}break;
				case 'I': {TxHeader.DataLength =FDCAN_DLC_BYTES_8;l=8;}break;
				case 'J': {TxHeader.DataLength =FDCAN_DLC_BYTES_12;l=12;}break;
				case 'K': {TxHeader.DataLength =FDCAN_DLC_BYTES_16;l=16;}break;
				case 'L': {TxHeader.DataLength =FDCAN_DLC_BYTES_20;l=20;}break;
				case 'M': {TxHeader.DataLength =FDCAN_DLC_BYTES_24;l=24;}break;
				case 'N': {TxHeader.DataLength =FDCAN_DLC_BYTES_32;l=32;}break;
				case 'O': {TxHeader.DataLength =FDCAN_DLC_BYTES_48;l=48;}break;
				case 'P': {TxHeader.DataLength =FDCAN_DLC_BYTES_64;l=64;}break;
			}


		}

  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_ON;
  TxHeader.FDFormat = FDCAN_FD_CAN;
  TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
  TxHeader.MessageMarker = 0x0;
}
/*************************************************************************
 *@brief Function Prototype for Printf Functionality
 *@param UART Handler
 *@retval void
 *
 **************************************************************************/
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}

/*************************************************************************
 *@brief Function Read_Data() for Read user data
 *@param UART Handler
 *@retval void
 *
 **************************************************************************/
void Read_Data(void)
{
	HAL_UART_Transmit(&huart1,(uint8_t *)b2,sprintf(b2,"\n\rEnter the Data ( %d ) =  ",d),1000);
			HAL_Delay(2000);
	if (HAL_OK==HAL_UART_Receive(&huart1, (uint8_t *) &count, 1, 2000))
				{
				HAL_UART_Transmit(&huart1,(uint8_t *)&count,1,200);
				Node1_Node2_Tx[d]=count;

				d++;
				}
}
/*************************************************************************
 *@brief Function Delay() for providing delay
 *@retval void
 *
 **************************************************************************/
void Delay(uint32_t Delay)
{
		HAL_Delay(Delay);
}
/*************************************************************************
 *@brief Function FDCAN_Transmit_FIFO() add TX message to Transmit FIFO
 *@retval void
 *
 **************************************************************************/
 void FDCAN_Transmit_FIFO(void)
 {
	 if(HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader,Node1_Node2_Tx) != HAL_OK)
	 			{
	 				HAL_UART_Transmit(&huart1,(uint8_t *)"\n\rCAN_Node_1_Error in FDCAN_AddMessageToTxFifoQ", sizeof("\n\rError in FDCAN_ConfigFilter\n\r"),2000);

	 			}
	 /*Return Tx FIFO free level*/
				Ret=HAL_FDCAN_GetTxFifoFreeLevel(&hfdcan1);
	//			sprintf(Tx_FIFO_free_level,"GetTxFifoFreeLevel:%u\n\r",Ret);
	//
	//			HAL_UART_Transmit(&huart1,(uint8_t *)Tx_FIFO_free_level, sizeof(Tx_FIFO_free_level),100);

				/*Get Tx buffer index of latest Tx FIFO/Queue request*/
				Ret1=HAL_FDCAN_GetLatestTxFifoQRequestBuffer(&hfdcan1);

				if(HAL_FDCAN_GetLatestTxFifoQRequestBuffer(&hfdcan1)!= 0)
				{
	//				sprintf(Tx_FIFO_Buffer,"GetLatestTxFifoQRequest_status:%u\n\r", Ret1);
	//				HAL_UART_Transmit(&huart1,(uint8_t *)Tx_FIFO_Buffer, sizeof(Tx_FIFO_Buffer),100);
					HAL_UART_Transmit(&huart1,(uint8_t *)"\n\r Tx request has been submitted ", sizeof("\n\r Tx request has been submitted "),100);

				}

 }


