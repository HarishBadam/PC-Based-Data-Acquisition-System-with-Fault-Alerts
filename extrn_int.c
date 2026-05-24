#include "pincfg.h"
#include "extrn_int.h"
#include "delay.h"
#include "int_defines.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "kpm_defines.h"
#include "kpm.h"
#include "uart.h"
#include<lpc21xx.h>
u32 val,time,flag=0;
extern u32 setPoint;
void ext_int(void){
				cfgPortPinFunc(0,16,EINT0_INPUT_PIN);
				VICIntEnable=1<<EINT0_VIC_CHNO;
				VICVectCntl0=(1<<5)|EINT0_VIC_CHNO;
				VICVectAddr0=(u32 )eint0_isr;
				
				EXTMODE=1<<0;
				//IODIR0|=1<<EINT0_STATUS_LED;
}
void eint0_isr(void) __irq
{
	//toggle EINT0 status LED for ISR activity
	//IOPIN0^=1<<EINT0_STATUS_LED;
	U0_TxStr("***TIME EDETING MODE ACTIVATED***\r\n");
	cmdLCD(0x01);
	strLCD("1.H2.M3.S4.Day");
	cmdLCD(GOTO_LINE2_POS0);
	strLCD("5.D6.M 7.Y8.E9.T");
	while(1){
		if(flag==1){
			break;
		}
		//while(colScan());
		val=keyScan();
		cmdLCD(0x01);
		//strLCD("val is ");
		//charLCD(val);
		delay_s(1);
		//cmdLCD(0X01);
		switch(val){
			case '1'://strLCD("HOUR");
								time=readNum();
								//cmdLCD(0x01);
								 if(time<25){
									HOUR=time;
								}
								delay_s(1);
								break;
			case '2'://strLCD("MINUTES");
								time=readNum();
								//cmdLCD(0x01);
								//u32LCD(time);
								if(time<60){
									MIN = time;
								}
								break;
			case '3'://strLCD("SECONDS");
								time=readNum();
								//cmdLCD(0x01);
								//u32LCD(time);
								SEC = time;
								break;
			case '4'://strLCD("DAY");
								time=readNum();
								//cmdLCD(0x01);
								//u32LCD(time);
								if(time<7){
									DOW =time;
								}
								break;
			case '5'://strLCD("DATE");
								time=readNum();
								//cmdLCD(0x01);
								//u32LCD(time);
								if((MONTH==2)&&(time<29)){
									DOM=time;
								}
								else if((MONTH!=2)&&(time<31)){
									DOM=time;
								}
								break;
			case '6'://strLCD("MONTH");
								time=readNum();
								//cmdLCD(0x01);
								//u32LCD(time);
								if((time>0)&&(time<13)){
									MONTH=time;
								}
								break;
			case '7'://strLCD("YEAR");
								time=readNum();
								//cmdLCD(0x01);
								//u32LCD(time);
								YEAR=time;
								break;
			case '9'://strLCD("TIME");
								time=readNum();
								//cmdLCD(0x01);
								//u32LCD(time);
								setPoint=time;
								break;
			case '8'://cmdLCD(0x01);
								strLCD("exit key ");
								flag=1;
								break;
		}
	}	
	delay_ms(500);
	//clear EINT0 status flag in Ext Int Peripheral
	EXTINT=1<<0;
	//clear EINT0 status in VIC Peripheral
	VICVectAddr=0;
	cmdLCD(0x01);
	flag=0;
}
