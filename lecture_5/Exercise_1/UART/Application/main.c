#include "stm32f30x.h"

/** 
  * @brief This devenition specefies the pin which connected to the board LED
	*/
#define LED_PORT   (GPIOE)
/*
#define LED_PINS   (GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 )
*/
#define LED_PINS   (GPIO_Pin_8) /*LLZ: Changed for support only one led*/
#define TIM_PERIOD (8000)
/**
  * @brief This is runtime counter
  */
static volatile uint32_t runtime = 0;

/**
  * @brief  This function inits the GPIO pin which connected to board led
	*
	* @retval None
	*/
void gpio_init(void)
{
	GPIO_InitTypeDef        gpio = {0};
	
	 /* GPIOE Periph clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
  
  /* Configure PE14 and PE15 in output pushpull mode */
  gpio.GPIO_Pin = LED_PINS;
  gpio.GPIO_Mode = GPIO_Mode_OUT;
  gpio.GPIO_OType = GPIO_OType_PP;
  gpio.GPIO_Speed = GPIO_Speed_50MHz;
  gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(LED_PORT, &gpio);
}

/**
  * @brief  This function init timer to updates each 1 millisecond
  *         and set up interrupt to handle it
  * 
  * @retbal None
  */
void timer_init(void)
{
  TIM_TimeBaseInitTypeDef tim = {0};
  NVIC_InitTypeDef nvic = {0};
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  
  /* Period 1ms */
  tim.TIM_Prescaler = 0;
  tim.TIM_CounterMode = TIM_CounterMode_Up;
  tim.TIM_Period = TIM_PERIOD;
  tim.TIM_ClockDivision = TIM_CKD_DIV1;
  tim.TIM_RepetitionCounter = 0;

  TIM_TimeBaseInit(TIM4, &tim);

  /* Enable the TIM4 global Interrupt */
  nvic.NVIC_IRQChannel = TIM4_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 0;
  nvic.NVIC_IRQChannelSubPriority = 1;
  nvic.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&nvic);
  
  TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

  TIM_Cmd(TIM4, ENABLE);
}

/**
  * @brief This function set up system clock source as High Speed Internal (HSI) source
  * 
  * @retval
  */
void clk_init(void)
{
  RCC_HSICmd(ENABLE);

  while(RCC_GetFlagStatus(RCC_FLAG_HSIRDY) != SET)    
    {
      /* Wait while HSI source is not ready */
    }
    
  RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);
}

/**
  * @brief This function perform a delay in miliseconds
  * 
  * @retval None
  */
void delay_ms(uint32_t delay)
{
  uint32_t target_runtime = runtime + delay;

  while(target_runtime != runtime)
    {
      /* Wait while runtime variable reach target_runtime value */
    }
}


void UART1_open(void)
{
	RCC->APB2ENR	|= RCC_APB2ENR_USART1EN;	//USART1 Clock ON
	RCC->CFGR3	|= RCC_CFGR3_USART1SW; 			// set 11 - HSI -8MHz
}

void UART1_init(uint32_t brate)
{

	// BBR example: 8000000/11520 = 0x45
	USART1->BRR = (uint32_t) 8000000/brate;

	USART1->CR1 &= ~USART_CR1_OVER8; // Oversampling mode = 16
	USART1->CR1 &= ~USART_CR1_M; // Word length = 8 bits
	USART1->CR1 &= ~USART_CR1_PCE; // No parity

	USART1->CR1  |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE; // USART1 ON, TX ON, RX ON

	// GPIO for TX/RX
	RCC->AHBENR  |= RCC_AHBENR_GPIOCEN;			// GPIOC Clock ON. 

	// config TX pin
	GPIOC->MODER &= ~GPIO_MODER_MODER4_0; // mode = alternate function, output
	GPIOC->MODER |= GPIO_MODER_MODER4_1; // mode = alternate function, output
	GPIOC->AFR[0] &= ~GPIO_AFRL_AFRL4; // prepare field for following OR
	GPIOC->AFR[0] |= GPIO_AFRL_AFRL4 & (0x7 << 4*4); // set alternate function 7

	// config RX pin
	GPIOC->MODER &= ~GPIO_MODER_MODER5_0;
	GPIOC->MODER |= GPIO_MODER_MODER5_1;
	GPIOC->AFR[0] &= ~GPIO_AFRL_AFRL5;
	GPIOC->AFR[0] |= GPIO_AFRL_AFRL5 & (0x7 << 5*4);	

}
uint8_t UART1_read(void)
{
	while(!(USART1->ISR & USART_ISR_RXNE))
	{
	} // Wait for Char. ToDo timeout
  
	return USART1->RDR; // Collect Char
}
void UART1_write(uint8_t val)
{
	while (!(USART1->ISR & USART_ISR_TXE))
	{
	} // wait for sending previous data. ToDo Timeout
	
	USART1->TDR = val;
}
void UART1_deinit(void)
{
	USART1->CR1  &= ~(USART_CR1_UE | USART_CR1_TE | USART_CR1_RE); // USART1 OFF, TX OFF, RX OFF
}

void UART1_close(void)
{
	RCC->APB2ENR	&= ~RCC_APB2ENR_USART1EN;	//USART1 Clock OFF
}

/**
  * @brief  This is Main routine. 
  *         It is init all necessary perephery and then just toggle LED with 1 sec period.
  * 
  * @retval If main routine return you something, then you get in trouble :)
  */
int main(void)
{
	uint8_t ch;
  clk_init();
  timer_init();
  gpio_init();

	UART1_open();
	
//	UART1_init(115200);
	UART1_init(9600);
  ch = 0x00;
  while(ch != 27)
  {
		ch = UART1_read();			
		UART1_write(ch);
  }

	UART1_deinit();
	UART1_close();
	
  while(1) /*Indication that received escape and echo application stopped*/
  {
    GPIO_SetBits(LED_PORT, LED_PINS);
    delay_ms(50);
    GPIO_ResetBits(LED_PORT, LED_PINS);
    delay_ms(1000);
  }

	
  return 0;
}

/**
	* @brief  This is an interrupt handler routine for TIM4.
  *         It just check if source of interrupt is Timer Update event.
  *         If yes, then it updates runtime counter and clear pending bit.
  *
  * @retval None
  */
void TIM4_IRQHandler(void)
{
  if(TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
    {
      runtime++;
      TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    }
}

