#include<lpc21xx.h>
#include "types.h"
#include "defines.h"
#include "declarations.h"

char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
int hour,min,sec,date,month,year,day;
#define _LPC2148

void RTC_Init(void){
	CCR=RTC_RESET;
	#ifndef _LPC2148
	PREINT = PREINT_VAL;
  PREFRAC = PREFRAC_VAL;
	CCR = RTC_ENABLE; 
	#else
	CCR = RTC_ENABLE | RTC_CLKSRC;
	#endif
}
void GetRTCTimeInfo(s32 *hour, s32 *minute, s32 *second)
{
	*hour = HOUR;
	*minute = MIN;
	*second = SEC;
	delay_us(50);
	SEC++;
	if(SEC==60){
		SEC=0;
		MIN++;
	}
	if(MIN==60){
		MIN=0;
		HOUR++;
	}
	if(HOUR==23){
		HOUR=0;
	}
}
void DisplayRTCTime(u32 hour, u32 minute, u32 second)
{
	cmdlcd(0X80);
	charlcd(hour/10+48);
	charlcd(hour%10+48);
	charlcd(':');
	charlcd(minute/10+48);
	charlcd(minute%10+48);
	charlcd(':');
	charlcd(second/10+48);		
	charlcd(second%10+48);	
}
void GetRTCDateInfo(s32 *date, s32 *month, s32 *year)
{
	*date = DOM;
	*month = MONTH;
	*year = YEAR;
	/*if(DOM>31 && MONTH>12){
		cmdlcd(0x01);
		cmdlcd(0x80);
		strlcd("invalid DOM");
		cmdlcd(0xC0);
		strlcd("DD:1-31,MM:1-12");
}*/
	}
void DisplayRTCDate(u32 date, u32 month, u32 year)
{
	cmdlcd(0XC0);
	charlcd(date/10+48);
	charlcd(date%10+48);
	charlcd('/');
	charlcd(month/10+48);
	charlcd(month%10+48);
	charlcd('/');
	integerlcd(year);
}
void SetRTCTimeInfo(u32 hour, u32 minute, u32 second)
{
	HOUR = hour;
	MIN = minute;
	SEC = second;
}
void SetRTCDateInfo(u32 date, u32 month, u32 year)
{
	DOM = date;
	MONTH = month;
	YEAR = year;
}
void GetRTCDay(s32 *dow)
{
	*dow = DOW; 
}
void DisplayRTCDay(u32 dow)
{
	cmdlcd(0X80+10);
	strlcd(week[dow]);
}
void SetRTCDay(u32 dow)
{
	DOW = dow;
}

