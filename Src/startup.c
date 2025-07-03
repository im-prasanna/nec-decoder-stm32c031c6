#include<stdint.h>
#define SRAM_start 0x20000000U
#define SRAM_size (128U*1024U)
#define SRAM_end ( SRAM_start + SRAM_size )
#define STACK_start SRAM_end

extern uint32_t _etext;

extern uint32_t _edata;
extern uint32_t _sdata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _sidata;

int main(void);

void Reset_Handler(void);
void NMI_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler   				(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler  				(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PVM_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void RTC_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));                               
void RCC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));    

void EXTI0_1_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));  

void EXTI2_3_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_15_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));           
          
void DMA1_Channel1_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_3_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void DMAMUX_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void ADC_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_UP_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void TIM14_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void TIM16_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void TIM17_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void I2C_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void SPI_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".isr_vector")))   = {
	STACK_start,
	(uint32_t)Reset_Handler,
	(uint32_t)NMI_Handler,
	(uint32_t)HardFault_Handler,
    0,
    0,
    0,
	0,
	0,
	0,
	0,
	(uint32_t)SVC_Handler,
    0,
	0,
	(uint32_t)PendSV_Handler,
	(uint32_t)SysTick_Handler,
	(uint32_t)WWDG_IRQHandler,
	(uint32_t)PVM_IRQHandler,         
	(uint32_t)RTC_IRQHandler,    
	0,                      
	(uint32_t)RCC_IRQHandler,         
	(uint32_t)EXTI0_1_IRQHandler,       
	(uint32_t)EXTI2_3_IRQHandler,       
	(uint32_t)EXTI4_15_IRQHandler,  
    0,
    (uint32_t)DMA1_Channel1_IRQHandler,        // IRQ9
    (uint32_t)DMA1_Channel2_3_IRQHandler,      // IRQ10
    (uint32_t)DMAMUX_IRQHandler,               // IRQ11
    (uint32_t)ADC_IRQHandler,                  // IRQ12
    (uint32_t)TIM1_BRK_UP_TRG_COM_IRQHandler,  // IRQ13
    (uint32_t)TIM1_CC_IRQHandler,              // IRQ14
    0,                                          // IRQ15: Reserved
    (uint32_t)TIM3_IRQHandler,                 // IRQ16
    0, 
    0,                                       // IRQ17–18: Reserved
    (uint32_t)TIM14_IRQHandler,                // IRQ19
    0,                                          // IRQ20: Reserved
    (uint32_t)TIM16_IRQHandler,                // IRQ21
    (uint32_t)TIM17_IRQHandler,                // IRQ22
    (uint32_t)I2C_IRQHandler,                  // IRQ23
    0,                                          // IRQ24: Reserved
    (uint32_t)SPI_IRQHandler,                  // IRQ25
    0,                                          // IRQ26: Reserved
    (uint32_t)USART1_IRQHandler,               // IRQ27
    (uint32_t)USART2_IRQHandler                // IRQ28
};

void Reset_Continue(void){
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    main();

    while(1);
}
void Default_Handler(void) {
    while(1);
}
