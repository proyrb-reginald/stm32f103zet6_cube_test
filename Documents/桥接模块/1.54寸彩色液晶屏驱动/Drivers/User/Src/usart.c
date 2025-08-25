/***
	*************************************************************************************************
	*	@version V1.0
	*	@author  ¹С��Ƽ�	
	*	@brief   ����
   *************************************************************************************************
   *  @description
	*
	*	ʵ��ƽ̨��¹С��STM32F103ZET6���İ� ���ͺţ�LXB103ZE-P1��
	* �ͷ�΢�ţ�19949278543
	*
>>>>> �ļ�˵����
	*
	*  ��ʼ��usart���ţ����ò����ʵȲ���
	*
	************************************************************************************************
***/

#include "usart.h"



UART_HandleTypeDef huart1;  // UART_HandleTypeDef �ṹ�����


/*************************************************************************************************
*	�� �� ��:	HAL_UART_MspInit
*	��ڲ���:	huart - UART_HandleTypeDef����ı���������ʾ����Ĵ���
*	�� �� ֵ:	��
*	��������:	��ʼ����������
*	˵    ��:	��		
*************************************************************************************************/


void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	if(huart->Instance==USART1)
	{
		__HAL_RCC_USART1_CLK_ENABLE();		// ���� USART1 ʱ��

		GPIO_USART1_TX_CLK_ENABLE;				// ���� USART1 TX ���ŵ� GPIO ʱ��
		GPIO_USART1_RX_CLK_ENABLE;				// ���� USART1 RX ���ŵ� GPIO ʱ��

		GPIO_InitStruct.Pin 			= USART1_TX_PIN;					// TX����
		GPIO_InitStruct.Mode 		= GPIO_MODE_AF_PP;				// �����������
		GPIO_InitStruct.Pull 		= GPIO_PULLUP;						// ����
		GPIO_InitStruct.Speed 		= GPIO_SPEED_FREQ_HIGH;			// �ٶȵȼ� 

		HAL_GPIO_Init(USART1_TX_PORT, &GPIO_InitStruct);

		GPIO_InitStruct.Pin 			= USART1_RX_PIN;					// RX����
		HAL_GPIO_Init(USART1_RX_PORT, &GPIO_InitStruct);		
	}

}

/*************************************************************************************************
*	�� �� ��:	USART1_Init
*	��ڲ���:	��
*	�� �� ֵ:	��
*	��������:	��ʼ����������
*	˵    ��:	��		 
*************************************************************************************************/

void USART1_Init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;

  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
  }

}

/*************************************************************************************************
*	�� �� ��:	fputc
*	��ڲ���:	ch - Ҫ������ַ� ��  f - �ļ�ָ�루�����ò�����
*	�� �� ֵ:	����ʱ�����ַ�������ʱ���� EOF��-1��
*	��������:	�ض��� fputc ������Ŀ����ʹ�� printf ����
*	˵    ��:	��		
*************************************************************************************************/

int fputc(int ch, FILE *f)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 100);	// ���͵��ֽ�����
	return (ch);
}

