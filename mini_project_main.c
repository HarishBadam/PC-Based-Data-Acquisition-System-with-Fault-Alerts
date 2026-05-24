#include "kpm.h"
#include "lcd.h"
#include "int_defines.h"
#include "types.h"
#include "extrn_int.h"
#include "rtc.h"
#include "adc.h"
#include "lcd_defines.h"
#include "uart_defines.h"
#include "uart.h"
#include "delay.h"
#include <lpc21xx.h>
u32 i,temp,setPoint=45;
s32 hour,min,sec,date,month,year,day;
f32 eAR;
u32 adcVal;
main(){
	Init_UART0();
	Init_adc();
	ext_int();
	RTC_Init();
	InitLCD();
	Init_kpd();
	
	SetRTCTimeInfo(23,59,50);
	SetRTCDateInfo(10,5,2025);

	SetRTCDay(6);
	//U0_TxU32(year);
//	 strLCD("vector");
	while(1)
	{
		//U0_TxByte(48);
		Read_adc(1,&eAR,&adcVal);
		GetRTCTimeInfo(&hour,&min,&sec);

		DisplayRTCTime(hour,min,sec);

		GetRTCDateInfo(&date,&month,&year);
		
		DisplayRTCDate(date,month,year);

		GetRTCDay(&day);

		DisplayRTCDay(day);
		cmdLCD(GOTO_LINE2_POS0+12);
		//f32LCD(eAR*100,2);
		  temp=(int)(eAR*100);
		  u32LCD(temp);
		uart_dispaly_fun(hour,min,sec,date,month,year,day,adcVal,temp,setPoint);
		if(temp>45){
		IOSET0=1<<15;
	}
	else{
		IOCLR0=1<<15;
	}
	delay_s(2);
	//1;
	}
	//while(1);
	//strLCD("hello display");
	//delay_s(1);
//	cmdLCD(0x01);
	
}
