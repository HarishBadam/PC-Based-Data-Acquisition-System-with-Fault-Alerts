#include<lpc21xx.h>
#include "lcd.h"
#include "delay.h"
#include "types.h"
#include "lcd_defines.h"

void InitLCD(){
	IODIR1|=((u32)0XFF<<LCD_DATA);
	IODIR0|=(1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_RW);
	
	delay_ms(15);
	cmdLCD(0X30);
  cmdLCD(0X30);
  cmdLCD(0X30);
  cmdLCD(MODE_8BIT_2LINE);
  cmdLCD(DSP_ON_CUR_ON);
  cmdLCD(CLEAR_LCD);
  cmdLCD(SHIFT_CUR_RIGHT);
}

void writeLCD(u8 byte){
	IOCLR0=1<<LCD_RW;
	IOPIN1=((IOPIN1&~((u32)0XFF<<LCD_DATA))|((u32)byte<<LCD_DATA));
	IOSET0=1<<LCD_EN;
	delay_us(1);
	IOCLR0=1<<LCD_EN;
	delay_ms(2);
}

void cmdLCD(u8 cmd){
	IOCLR0=1<<LCD_RS;
	writeLCD(cmd);
}

void charLCD(u8 byte){
	IOSET0=1<<LCD_RS;
	writeLCD(byte);
}

void strLCD(u8* ptr){
	while(*ptr){
		charLCD(*ptr++);
	}
}

void u32LCD(u32 num){
	s32 i=0;
	u8 arr[10];
	if(num==0){
		charLCD('0');
	}
	else{
		while(num){
			arr[i++]=num%10+48;
			num/=10;
		}
		for(--i;i>=0;i--){
			charLCD(arr[i]);
		}
	}
	
}
void f32LCD(f32 fnum,u32 ndp){
	u32 num;
	u32 i;
	num=fnum;
	u32LCD(num);
	charLCD('.');
	for(i=0;i<ndp;i++){
		fnum=(fnum-num)*10;
		num=fnum;
		charLCD(num+48);
	}
}
