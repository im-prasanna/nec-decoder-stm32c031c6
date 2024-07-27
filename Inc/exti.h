typedef struct
{
  uint32_t RTSR1;          /*!< EXTI Rising Trigger Selection Register 1,        Address offset:   0x00 */
  uint32_t FTSR1;          /*!< EXTI Falling Trigger Selection Register 1,       Address offset:   0x04 */
  uint32_t SWIER1;         /*!< EXTI Software Interrupt event Register 1,        Address offset:   0x08 */
  uint32_t RPR1;           /*!< EXTI Rising Pending Register 1,                  Address offset:   0x0C */
  uint32_t FPR1;           /*!< EXTI Falling Pending Register 1,                 Address offset:   0x10 */
  uint32_t RESERVED1[3];   /*!< Reserved 1,                                                0x14 -- 0x1C */
  uint32_t RESERVED2[5];   /*!< Reserved 2,                                                0x20 -- 0x30 */
  uint32_t RESERVED3[11];  /*!< Reserved 3,                                                0x3C -- 0x5F */
  uint32_t EXTICR[4];      /*!< EXTI External Interrupt Configuration Register,            0x60 -- 0x6C */
  uint32_t RESERVED4[4];   /*!< Reserved 4,                                                0x70 -- 0x7C */
  uint32_t IMR1;           /*!< EXTI Interrupt Mask Register 1,                  Address offset:   0x80 */
  uint32_t EMR1;           /*!< EXTI Event Mask Register 1,                      Address offset:   0x84 */
} EXTI_TypeDef;
#define EXTI       ((EXTI_TypeDef *) EXTI_BASE)
#define EXTI_BASE  0x40021800
