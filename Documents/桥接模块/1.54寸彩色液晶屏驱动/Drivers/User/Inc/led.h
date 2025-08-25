#ifndef __LED_H
#define __LED_H

#include "main.h"



/*------------------------------------------ LED���ú� ----------------------------------*/

#define LED1_PIN            			 GPIO_PIN_13        				 	// LED1 ����      
#define LED1_PORT           			 GPIOC                 			 	// LED1 GPIO�˿�     
#define __HAL_RCC_LED1_CLK_ENABLE    __HAL_RCC_GPIOC_CLK_ENABLE() 	// LED1 GPIO�˿�ʱ��
 

  
/*----------------------------------------- LED���ƺ� ----------------------------------*/
						
#define LED1_ON 		LED1_PORT->BRR 	=  LED1_PIN  	// LED1������ʱIO���ǵ͵�ƽ
#define LED1_OFF		LED1_PORT->BSRR 	=  LED1_PIN		// LED1�𣬴�ʱIO���Ǹߵ�ƽ
#define LED1_Toggle	HAL_GPIO_TogglePin(LED1_PORT,LED1_PIN);							// ��תIO��״̬
			
		
/*---------------------------------------- �������� ------------------------------------*/

void LED_Init(void);

#endif //__LED_H


