ENTRY(Reset_Handler)
_estack = ORIGIN(RAM) + LENGTH(RAM); /* end of "RAM" Ram type memory */
/*
MEMORY
{
    RAM (rwx)   :   ORIGIN  = 0x20000000, LENGTH=12K
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH=32K
}
*/
MEMORY
{
  RAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 12K
  FLASH    (rx)    : ORIGIN = 0x8000000,   LENGTH = 32K
}

SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        _etext = .;
    } >FLASH
  _sidata = LOADADDR(.data);

    .data :
    {
        _sdata = .;
        *(.data)
        _edata = .;
    } >RAM AT> FLASH

    .bss :
    {
        _sbss = .;
        *(.bss)
        _ebss = .;
    } >RAM
}