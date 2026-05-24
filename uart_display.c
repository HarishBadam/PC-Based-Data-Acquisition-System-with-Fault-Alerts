#include "types.h"
#include "uart.h"
//u8 week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
void uart_dispaly_fun(u32 hour,u32 min,u32 sec,u32 date,u32 month,u32 year,u32 day,u32 adcVal,u32 temp,u32 setpoint){
	if((min%2==0)&&(sec==0)&&(temp<setpoint)){
		U0_TxStr("[INFO]Temp: ");
		U0_TxU32(temp);
		U0_TxByte(223);
		U0_TxByte('C');
		U0_TxByte('@');
		U0_TxByte((hour/10)+48);   

    U0_TxByte((hour%10)+48);    

    U0_TxByte(':');

    U0_TxByte((min/10)+48);    

    U0_TxByte((min%10)+48);    

    U0_TxByte(':');

    U0_TxByte((sec/10)+48);   
    U0_TxByte((sec%10)+48); 
		
		U0_TxByte((date/10)+48);    

    U0_TxByte((date%10)+48);
		U0_TxByte('/');
		U0_TxByte((month/10)+48);   
    U0_TxByte((month%10)+48);

    U0_TxByte('/');
		U0_TxU32(year);
	U0_TxStr("\r\n");
	}
	 else if((temp>setpoint)){
		U0_TxStr("[ALERT]Temp: ");
		U0_TxU32(temp);
		U0_TxByte(223);
		U0_TxByte('C');
		U0_TxByte('@');
		U0_TxByte((hour/10)+48);   

    U0_TxByte((hour%10)+48);    

    U0_TxByte(':');

    U0_TxByte((min/10)+48);    

    U0_TxByte((min%10)+48);    

    U0_TxByte(':');

    U0_TxByte((sec/10)+48);   
    U0_TxByte((sec%10)+48); 
		
		U0_TxByte((date/10)+48);    

    U0_TxByte((date%10)+48);
		U0_TxByte('/');
		U0_TxByte((month/10)+48);   
    U0_TxByte((month%10)+48);

    U0_TxByte('/');
		U0_TxU32(year);
	U0_TxStr("OVER TEMP!");
	U0_TxStr("\r\n");
	}
}

