#include<lpc21xx.h>
#include"header_uart.h"
void adc_init()
{
PINSEL1=0x5400000;
ADCR=0X00200400;

}
#define DONE ((ADDR>>31)&1)
unsigned char adc_read(unsigned int ch_num)
{
	unsigned int result=0;
ADCR|=(1<<ch_num);
ADCR|=(1<<24);	
	while(DONE==0)
ADCR^=(1<<24);
ADCR^=(1<<ch_num);
result=(ADDR>>6)&0x3ff;

return result;	
}
