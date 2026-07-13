#include<lpc21xx.h>
#include "defines.h"
#include "declarations.h"
#include "types.h"
int h,m,s,dd,mm,y,dow;
int num;
int main(){
        buzzer_init();  //Iinitialise buzzer
        Init_Kpm();      //Iinitialise keypad
        initLCD();       //Iinitialise LCD
        RTC_Init();       //Iinitialise RTC
        INIT_INTERRUPTS();  //Iinitialise  interrupts
        SetRTCTimeInfo(8,04,07); //set default rtc hour,minute,seconds
        SetRTCDateInfo(25,03,2026);//set default rtc date,month,year
        SetRTCDay(0);//set rtc default day
        cmdlcd(0x80);//set cursor to the line 1 pos0
        strlcd("Medicine");//display on line1
        cmdlcd(0XC0);//set cursor to the line 2 pos0
        strlcd("Remainder");//display on line2
        delay_s(1);//delay of 1 second for visibility
        cmdlcd(0x01);//clear lcd display
        while(1){
                cmdlcd(0x80);//set cursor to the line 1 pos0
                GetRTCTimeInfo(&h,&m,&s);//get rtc time from the user
                DisplayRTCTime(h,m,s);//display rtc time
                strlcd(" ");
                GetRTCDay(&dow);//get rtc day from the user
                cmdlcd(0x80+11);//shift cursor right to 11 positions   
                DisplayRTCDay(dow);//display rtc day
                cmdlcd(0XC0);//set cursor to the line 2 pos0
                GetRTCDateInfo(&dd,&mm,&y);//get rtc date,month,year from the user
                DisplayRTCDate(dd,mm,y);//display rtc date,month,year 
                MED_REMAINDER();//check the medicine remainder
}
        }
