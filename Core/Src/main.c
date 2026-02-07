#include "stm32f1xx.h"

void delay(uint32_t count); // simple delay function define

int main(void)
{
   //Clock Setting
    RCC->CR |= RCC_CR_HSEON; //bit 16 (High Speed External Clock ) ON of Clock Control Register
    while (!(RCC->CR & RCC_CR_HSERDY)); // wait till external oscillator stable

    //Flash Access
    FLASH->ACR |= FLASH_ACR_LATENCY_2; // 2 wait cycle of CPU required for 72MHZ frequency to access flash
    FLASH->ACR |= FLASH_ACR_PRFTBE; //to prefetch data from flash when cpu access other data

    // PLL Setup
    RCC->CFGR |= RCC_CFGR_PLLSRC;         // PLL source from external oscillator
    RCC->CFGR |= RCC_CFGR_PLLMULL9;       // PLL Multiply with 9 to get 72MHZ Clock

    // APB1 Setup
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; //set apb1 prescaler 2 to get max 36 MHZ

    // Enable PLL
    RCC->CR |= RCC_CR_PLLON; //start PLL
    while (!(RCC->CR & RCC_CR_PLLRDY)); //wait till PLL Frequency stable


    RCC->CFGR |= RCC_CFGR_SW_PLL; //PLL configure as system clock
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL); //wait till system clock = PLL



    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;//GPIO PORTC clock enable for LED
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // GPIO PORTA clock enable for switch


    GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13); // clear port 13 old setting
    GPIOC->CRH |=  GPIO_CRH_MODE13_1;     // Port13 2Mz Push pull output set


    GPIOA->CRL &= ~(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);   // clear port 0 old setting
    GPIOA->CRL |= GPIO_CRL_CNF0_1;                     // Input with pull-up or pull-down not sure which one
    GPIOA->ODR &= (0<<0);                           // ensure Pull-down

    while (1)
    {
        // --- 5. Read button and control LED ---
        if (GPIOA->IDR & (1 << 0))       //
        {
            GPIOC->ODR = (1 << 13);     // led off
        }
        else
        {
            GPIOC->ODR = (0 << 13);      // led on
        }

        delay(72000);
    }
}

void delay(volatile uint32_t count)
{
    while(count--);
}
