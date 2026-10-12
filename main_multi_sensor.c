#include<lpc21xx.h>
#include"header_uart.h"
#define green (1<<17)
#define yellow (1<<18)
#define red (1<<19)
#define water ((IOPIN0>>5)&1)
#define pump (1<<20)

void lcd_float(float f);
void uart0_float(float f);
void lcd_init(void);

int main()
{
	
adc_init();
	IODIR0=1<< 17 | 1<< 18 | 1<< 19 | 1<<20;
	IOSET0=1<< 17 | 1<< 18 | 1<< 19 | 1<<20;
uart0_init(9600);
lcd_init();
float vout,temperature,light_percent,soil_percent;
	int adc_value,ldr_value,soil_value;
	while(1)
{
	
	//ldr_value=lrd_read(2);
//	light_percent=(ldr_value*100)/1023;
light_percent=(1000*100)/1023;
	if(light_percent<=30)
	{
		uart0_tx_string("Light level : LOW\r\n");
		
	}
	else if(light_percent>=31 && light_percent<=70)
	{
	uart0_tx_string("Light level : NORMAL\r\n");
		
	}
	else
	{
	uart0_tx_string("Light level : HIGH\r\n");
		
	}
	
	//soil_value=adc_read(3);
//	soil_percent=(soil_value*100)/1023;
	soil_percent=(30*100)/1023;
	
	if(soil_percent<=45)
	{
		uart0_tx_string("Soil moisture :DRY\r\nSoil percentage :");
		uart0_integer(soil_percent);
		uart0_tx_string(" %\r\n");
				IOCLR0=pump;
	}
		else
		{
			uart0_tx_string("Soil moisture : WET\r\nSoil percentage :");
		uart0_integer(soil_percent);
		uart0_tx_string(" %\r\n");
		IOSET0=pump;
		}
	
		
	if(water==0)	
	{
		uart0_tx_string("Water sensor : NOT DETECTED\r\n");
	
	}
	else
	{
	uart0_tx_string("Water sensor : DETECTED\r\n");
	
	}		
		
		
		
		
		
		
		
		
		
//	adc_value=adc_read(1);
//	vout=(adc_value*3.3)/1023;
	vout=(500*3.3)/1023;
	temperature=vout*100;

	if(35>=temperature)
	{
		IOCLR0=green;
		IOSET0=yellow;
		IOSET0=red;
  	lcd_cmd(0x80);	
		lcd_string("temp :");	
		lcd_float(temperature);
		lcd_string(" c");
		lcd_cmd(0xc0);	
		lcd_string("status :SAFE ");
		uart0_tx_string("temperature :");
		uart0_float(temperature);
		uart0_tx_string(" C\r\n");
		delay_ms(100);
		uart0_tx_string("Machine Status :SAFE\r\n");
		delay_ms(100);	
		uart0_tx_string("LED Status :green LED ON\r\n");
		uart0_tx_string("\r\n");
		delay_ms(200);
	}

		else if(36<=temperature && 40>=temperature)
	{
		IOCLR0=yellow;
		IOSET0=green;
		IOSET0=red;
	lcd_cmd(0x80);	
		lcd_string("temp :");	
		lcd_float(temperature);
		lcd_string(" C");
		lcd_cmd(0xc0);	
		lcd_string("status :Modurate ");
		uart0_tx_string("temperature :");
		uart0_float(temperature);
		uart0_tx_string(" C\r\n");
		delay_ms(100);	
		uart0_tx_string("Machine Status :Modurate\r\n");
		delay_ms(100);	
			uart0_tx_string("LED Status :yellow LED ON\r\n");
	uart0_tx_string("\r\n");
		delay_ms(200);	
	}

//(40<=temperature)
	else
	{
		IOCLR0=red;
		IOSET0=green;
		IOSET0=yellow;
	lcd_cmd(0x80);	
		lcd_string("temp :");	
		lcd_float(temperature);
		lcd_string(" C");
		lcd_cmd(0xc0);	
		lcd_string("status :NOT SAFE");
		uart0_tx_string("temperature :");
		uart0_float(temperature);
		uart0_tx_string(" C\r\n");
		delay_ms(250);	
		
		uart0_tx_string("Machine Status :NOT SAFE\r\n");
		delay_ms(250);	
			uart0_tx_string("LED Status :red LED ON\r\n");
		uart0_tx_string("\r\n");	
		delay_ms(300);	
	}
		

}
}

