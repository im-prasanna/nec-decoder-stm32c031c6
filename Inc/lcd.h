void lcd_init();
void enablepulse();
void lcd_command(uint8_t);
void lcd_data(uint8_t);
void lcd_clear();
void lcd_returnHome();
void lcd_entryModeSet(uint8_t, uint8_t);
void lcd_displayControl(uint8_t, uint8_t, uint8_t);
void lcd_cursor_display_shift(uint8_t, uint8_t);
void lcd_print(char*);
void lcd_init(){
	RCC->IOPENR |= (1<<1);								//Enable Port B
	GPIOB->MODER &= ~((0b11<<0) | (0b11<<2) | (0b11<<4) | (0b11<<6) | (0b11<<8) | (0b11<<10) | (0b11<<12));
	GPIOB->MODER |= ((1<<0) | (1<<2) | (1<<4) | (1<<6) | (1<<8) | (1<<10) | (1<<12));
	GPIOB->PUPDR &= ~((0b11<<0) | (0b11<<2) | (0b11<<4) | (0b11<<6) | (0b11<<8) | (0b11<<10) | (0b11<<12));
	GPIOB->ODR &= ~((1<<5) | (1<<6));

	GPIOB->ODR &= ~(1<<6);
	GPIOB->ODR &= ~(1<<5);
	GPIOB->ODR &= ~(0xF);
	GPIOB->ODR |= (0b0010); // set 4bit mode
	enablepulse();
}
void lcd_clear(){ // Clears Display
  lcd_command(1);
}
void lcd_returnHome(){  //Returns cursor to address 0
  lcd_command(2);
}
void lcd_entryModeSet(uint8_t ID, uint8_t S){  //ID=1 increment ID=0 decrement (cursor), S=1 with display shift S=0 no display shift
  lcd_command(4|((ID<<1)+ S));
}
void lcd_displayControl(uint8_t D, uint8_t C, uint8_t B){  //D=1 Display On, C=1 Cursor on, B=1 cursor position blinking on
  lcd_command(8|((D<<2)+((C<<1)+B)));
}
void lcd_cursor_display_shift(uint8_t SC, uint8_t RL){  //SC=1 Display shift SC=0 cursor shift, RL=1 right RL=0 left
  lcd_command(16|((SC<<3)+ (RL<<2)));
}
void lcd_print(char *s){
  for(int i=0;s[i]!=0;i++) lcd_data((uint8_t)s[i]);
}
void lcd_command(uint8_t command){
	GPIOB->ODR &= ~(1<<6);
	GPIOB->ODR &= ~(1<<5);
	GPIOB->ODR &= ~(0x0F);
	GPIOB->ODR |= (command>>4 & 0x0F);
	enablepulse();
	GPIOB->ODR &= ~(0xF);
	GPIOB->ODR |= ((command) & 0x0F);
	enablepulse();
}
void lcd_data(uint8_t data){
	GPIOB->ODR |= (1<<6);
	GPIOB->ODR &= ~(1<<5);
	GPIOB->ODR &= ~(0x0F);
	GPIOB->ODR |= (data>>4 & 0x0F);
	enablepulse();
	GPIOB->ODR &= ~(0xF);
	GPIOB->ODR |= ((data) & 0x0F);
	enablepulse();
}
void enablepulse(){
	GPIOB->ODR |= (1<<4);
	GPIOB->ODR &= ~(1<<4);
}
