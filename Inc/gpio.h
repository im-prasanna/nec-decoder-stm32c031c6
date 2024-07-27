typedef struct
{
  uint32_t MODER;       /*!< GPIO port mode register,               Address offset: 0x00      */
  uint32_t OTYPER;      /*!< GPIO port output type register,        Address offset: 0x04      */
  uint32_t OSPEEDR;     /*!< GPIO port output speed register,       Address offset: 0x08      */
  uint32_t PUPDR;       /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  uint32_t IDR;         /*!< GPIO port input data register,         Address offset: 0x10      */
  uint32_t ODR;         /*!< GPIO port output data register,        Address offset: 0x14      */
  uint32_t BSRR;        /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
  uint32_t LCKR;        /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  uint32_t AFR[2];      /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
  uint32_t BRR;         /*!< GPIO Bit Reset register,               Address offset: 0x28      */
} GPIO_TypeDef;
#define GPIOA_BASE	0x50000000
#define GPIOB_BASE  0x50000400
#define GPIOA       ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB       ((GPIO_TypeDef *) GPIOB_BASE)
