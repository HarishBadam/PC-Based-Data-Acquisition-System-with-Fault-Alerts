#include <LPC21xx.H>
#include "types.h"

#include "rtc_defines.h"

#include "lcd_defines.h"

#include "lcd.h"
char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

// RTC Initialization: Configures and enables the RTC^M

void RTC_Init(void) 

{

  // Disable & Reset the RTC ^M

        CCR = RTC_RESET;

       

  // Set prescaler integer part^M

        PREINT = PREINT_VAL;

       

  // Set prescaler fractional part^M

        PREFRAC = PREFRAC_VAL;

  // Enable the RTC^M

        CCR = RTC_ENABLE|(1<<4);

      

}
void GetRTCTimeInfo(s32 *hr,s32 *mi,s32 *se)

{

        *hr = HOUR;

        *mi = MIN;

        *se = SEC;

}
void DisplayRTCTime(u32 hr,u32 mi,u32 se)

{

        cmdLCD(GOTO_LINE1_POS0);

        charLCD((hr/10)+48);    //10's position value^M

        charLCD((hr%10)+48);    //1's position value^M

        charLCD(':');

        charLCD((mi/10)+48);    //10's position value^M

        charLCD((mi%10)+48);    //1's position value^M

        charLCD(':');

        charLCD((se/10)+48);    //10's position value^M

        charLCD((se%10)+48);    //1's position value^M

        

} 
void GetRTCDateInfo(s32 *dt,s32 *mo,s32 *yr)

{

        *dt = DOM;

        *mo = MONTH;

        *yr = YEAR;

}
void DisplayRTCDate(u32 dt,u32 mo,u32 yr)

{

        cmdLCD(GOTO_LINE2_POS0);

        charLCD((dt/10)+48);
                //10's position value^M

        charLCD((dt%10)+48);    //1's position value^M

        charLCD('/');

        charLCD((mo/10)+48);    //10's position value^M

        charLCD((mo%10)+48);    //1's position value^M

        charLCD('/');

        u32LCD(yr);  

}
void GetRTCDay(s32 *d)

{

        *d = DOW;       

}
void DisplayRTCDay(u32 d)

{

        cmdLCD(GOTO_LINE1_POS0+10);

        strLCD(week[d]);

} 

// RTC_SetTime: Sets the time and date on the RTC^M

void SetRTCTimeInfo(u32 hour, u32 min, u32 sec) 

{

  // Set hours

        HOUR = hour;      

  // Set minutes^M

        MIN = min;      

        // Set seconds

        SEC = sec;

}
void SetRTCDateInfo(u32 dt,u32 mo,u32 yr)

{

        // Set date

        DOM = dt;         

  // Set month

        MONTH = mo;     

        // Set year

        YEAR = yr;      

}
void SetRTCDay(u32 day)

{

        DOW = day;

}
