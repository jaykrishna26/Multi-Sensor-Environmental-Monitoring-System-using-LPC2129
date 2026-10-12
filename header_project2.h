void uart0_tx(unsigned char data);
void delay_ms(unsigned int ms);
unsigned char uart0_rx(void);
void uart0_init(unsigned int baud);
void uart0_tx_string(char *ptr);
void delay_ms(unsigned int ms);
unsigned char uart0_rx(void);
void uart0_integer(int num);
void lcd_data(unsigned char data);
void lcd_cmd(unsigned char cmd);
void lcd_integer(int num);
void lcd_string(char *ptr);
void adc_init(void);
unsigned char adc_read(unsigned int ch_num);







