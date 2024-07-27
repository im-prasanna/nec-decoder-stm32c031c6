typedef struct
{
  uint32_t CSR;          	/*!<Systick Control and Status Register,        Address offset:   0x00 */
  uint32_t RVR;          	/*!<Systick Reload Value Register,       		Address offset:   0x04 */
  uint32_t CVR;          	/*!<Systick Current Value Register,       		Address offset:   0x08 */
  uint32_t CALIB;           /*!<Systick Calibration Value Register,			Address offset:   0x0C */
} Systick_TypeDef;
#define SYSTICK       ((Systick_TypeDef *) SYSTICK_BASE)
#define SYSTICK_BASE  0xE000E010
