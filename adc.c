#include "adc_defines.h"
#include "pincfg.h"
#include<lpc21xx.h>
#include "delay.h"
void Init_adc(){
	cfgPortPinFunc(0,28,1);
	IODIR0|=(1<<15);
	ADCR|=(1<<PDN_BIT)|(DIVISOR<<CLK_DIV_BITS);
}
void Read_adc(u32 chNo,f32* eAR,u32* adcVal){
	ADCR&=0XFFFFFF00;
	ADCR|=(1<<chNo);
	ADCR|=(1<<START_CONV_BITS);
	delay_ms(3);
	while(((ADDR>>DONE_BIT)&1)==0);
	ADCR&=~(1<<START_CONV_BITS);
	*adcVal=((ADDR>>ADCVAL_BITS)&1023);
	*eAR=(3.3/1023)*(*adcVal);
	
}
