#include <stdint.h>
#include "config.h"

void  LED_On(uint16_t ledPin);
void  LED_Off(uint16_t ledPin);

void delay(int cnt)
{
	for(;cnt!=0;cnt--);
}


void GPIOA_Output_Init(uint16_t  pinNum, GPIOSpeed_TypeDef speedValE, GPIOMode_Output_TypeDef modeE)
{
    uint32_t  tmpVal=modeE << 2 | speedValE;
    uint32_t  pinpos=0x00;

    //pin #0 ~ #7
    if((pinNum & 0xFF) !=0) {
            for(pinpos = 0x00; pinpos <0x08; pinpos++) {
                    if(pinNum &((uint32_t)0x01 << pinpos)){
                            GPIOA->CRL &= ~(0xF << (pinpos*4));
                            GPIOA->CRL |= tmpVal << (pinpos*4);
                    }
            }
    }else {
            pinNum=pinNum >>8;
            for(pinpos = 0x00; pinpos <0x08; pinpos++) {
                             if(pinNum==((uint32_t)0x01 <<pinpos)){
                            GPIOA->CRH &= ~(0xF << (pinpos*4));
                            GPIOA->CRH |= tmpVal << (pinpos*4);
                    }
            }
    }
}






int main(void)
{
 // unsigned char led_status=0xFF;
  int i=0;
  
  RCC_APB2ENR |= RCC_APB2Periph_GPIOA;
  GPIOA_Output_Init(GPIO_LED0_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED1_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED2_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED3_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED4_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED5_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
  GPIOA_Output_Init(GPIO_LED6_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);  
  GPIOA_Output_Init(GPIO_LED7_PIN,GPIO_Speed_50MHz,GPIO_Mode_Out_PP);
 
  while (1)  {

    i=0;
    while(i<7){
      LED_On(0x01<<i);
      delay(0xAFFF);
      LED_Off(0x01<<i); 
      i++;
    }
     while(i>=0){
      LED_On(0x01<<i);
      delay(0xAFFF);
      LED_Off(0x01<<i); 
      i--;
    }   
    
    
  }
  
}//end main
void  LED_On(uint16_t ledPin) {
		GPIO_LED->BSRR |= ledPin;
}

void  LED_Off(uint16_t ledPin) {
		 GPIO_LED->BRR |= ledPin;
}