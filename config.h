#define RCC_APB2ENR (*(volatile unsigned *)0x40021018)
#define GPIOA_BASE   (0x40010800)
#define GPIOA_CRL   (*(volatile unsigned *)0x40010800)
#define GPIOA_BSRR   (*(volatile unsigned *)0x40010810)
#define GPIOA_BRR   (*(volatile unsigned *)0x40010814)



#define GPIO_Pin_0		((uint16_t)0x0001) 		// Pin 0 Selected
#define GPIO_Pin_1		((uint16_t)0x0002) 		// Pin 1 Selected
#define GPIO_Pin_2		((uint16_t)0x0004) 		// Pin 2 Selected
#define GPIO_Pin_3		((uint16_t)0x0008) 		// Pin 3 Selected
#define GPIO_Pin_4		((uint16_t)0x0010) 		// Pin 4 Selected
#define GPIO_Pin_5		((uint16_t)0x0020) 		// Pin 5 Selected
#define GPIO_Pin_6		((uint16_t)0x0040) 		// Pin 6 Selected
#define GPIO_Pin_7		((uint16_t)0x0080) 		// Pin 7 Selected
#define GPIO_Pin_8		((uint16_t)0x0100) 		// Pin 8 Selected
#define GPIO_Pin_9		((uint16_t)0x0200) 		// Pin 9 Selected
#define GPIO_Pin_10		((uint16_t)0x0400) 		// Pin 10 Selected
#define GPIO_Pin_11		((uint16_t)0x0800) 		// Pin 11 Selected
#define GPIO_Pin_12		((uint16_t)0x1000) 		// Pin 12 Selected
#define GPIO_Pin_13		((uint16_t)0x2000) 		// Pin 13 Selected
#define GPIO_Pin_14		((uint16_t)0x4000) 		// Pin 14 Selected
#define GPIO_Pin_15		((uint16_t)0x8000) 		// Pin 15 Selected
#define GPIO_Pin_All		((uint16_t)0xFFFF) 		// All Pins Selected


#define 	GPIO_LED0_PIN 		GPIO_Pin_0
#define 	GPIO_LED1_PIN 		GPIO_Pin_1
#define 	GPIO_LED2_PIN 		GPIO_Pin_2
#define 	GPIO_LED3_PIN 		GPIO_Pin_3
#define 	GPIO_LED4_PIN           GPIO_Pin_4
#define 	GPIO_LED5_PIN 		GPIO_Pin_5
#define 	GPIO_LED6_PIN 		GPIO_Pin_6
#define 	GPIO_LED7_PIN 		GPIO_Pin_7

#define 		RCC_APB2Periph_AFIO		((uint32_t)0x00000001)
#define 		RCC_APB2Periph_GPIOA		((uint32_t)0x00000004)
#define 		RCC_APB2Periph_GPIOB		((uint32_t)0x00000008)
#define 		RCC_APB2Periph_GPIOC		((uint32_t)0x00000010)
#define 		RCC_APB2Periph_GPIOD		((uint32_t)0x00000020)
#define 		RCC_APB2Periph_GPIOE		((uint32_t)0x00000040)
#define 		RCC_APB2Periph_GPIOF		((uint32_t)0x00000080)
#define 		RCC_APB2Periph_GPIOG		((uint32_t)0x00000100)
#define 		RCC_APB2Periph_ADC1		((uint32_t)0x00000200)
#define 		RCC_APB2Periph_ADC2		((uint32_t)0x00000400)
#define 		RCC_APB2Periph_TIM1		((uint32_t)0x00000800)
#define 		RCC_APB2Periph_SPI1		((uint32_t)0x00001000)
#define 		RCC_APB2Periph_TIM8		((uint32_t)0x00002000)
#define 		RCC_APB2Periph_USART1		((uint32_t)0x00004000)
#define 		RCC_APB2Periph_ADC3		((uint32_t)0x00008000)


typedef enum
{
        GPIO_Speed_10MHz =1,
        GPIO_Speed_2MHz,
        GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;

typedef  enum
{
      GPIO_Mode_Out_PP, 
      GPIO_Mode_Out_OD,
      GPIO_Mode_AF_PP,
      GPIO_Mode_AF_OD
}GPIOMode_Output_TypeDef;


#define 	__IO 	volatile

typedef  struct
{
      __IO 	uint32_t 	CRL;
      __IO 	uint32_t 	CRH;
      __IO 	uint32_t 	IDR;
      __IO 	uint32_t 	ODR;
      __IO 	uint32_t 	BSRR;
      __IO 	uint32_t 	BRR;
      __IO 	uint32_t 	LCKR;
} GPIO_TypeDef;

#define 	GPIOA 	((GPIO_TypeDef *) GPIOA_BASE)
#define 	GPIO_LED	GPIOA