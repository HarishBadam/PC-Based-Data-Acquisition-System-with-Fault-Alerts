#include "types.h"
#include "kpm_defines.h"
#include "kpm.h"
#include "lcd.h"
#include "delay.h"
#include "lcd_defines.h"
#include<lpc21xx.h>
u32 kpm_lut[4][4]={{'1','2','3','A'},{'4','5','6'},{'7','8','9'},{'0','0','0','*'}};

void Init_kpd(){
	IOPIN1&=~(15<<ROW0);
	IODIR1|=(15<<ROW0);
	//IOCLR1 = 15<<ROW0;
}
u32 colScan(){
	u32 val;
	val= (((IOPIN1>>COL0)&15)<15)?0:1;
	return val;
}

u32 rowCheck(void){
	u32 rNo;
	for(rNo=0;rNo<4;rNo++){
		IOPIN1=(IOPIN1&~(15<<ROW0))|((~(1<<rNo))<<ROW0);
		if(colScan()==0){
			break;
		}
	}
	IOCLR1=(15<<ROW0);
	return rNo;
}

u32 colCheck(){
	u32 cNo;
	for(cNo=0;cNo<4;cNo++){
		if(((IOPIN1>>(COL0+cNo))&1)==0){
			break;
		}
	}
	return cNo;
}

u32 keyScan(){
	u32 rNo,cNo, keyV;
	while(colScan());
	rNo=rowCheck();
	cNo=colCheck();
	keyV=kpm_lut[rNo][cNo];
	while(!colScan());
	return keyV;
	
}
u32 readNum(){
	u32 sum;
	u32 key;
	sum=0;
	while(1){
		//cmdLCD(0x01);
    //cmdLCD(GOTO_LINE2_POS0);
		//strLCD("Any key pressed");
		key=keyScan();
		if((key>='0')&&(key<='9')){
			cmdLCD(0x01);
			sum=(sum*10)+(key-'0');
			//cmdLCD(0x01);
			//while(colScan());
			//strLCD("time mode");
			//delay_s(2);
			u32LCD(sum);
		}
		else if(key=='*'){
			sum=sum/10;

			cmdLCD(0x01);
			u32LCD(sum);
		}
    else if(key=='A'){
      //cmdLCD(0x01);
      //strLCD("Exit key pressed");
      break;
      }
		
	}
	return sum;
}
