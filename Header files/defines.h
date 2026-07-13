#include<lpc21xx.h>
//lcd
#define lcd_data_pins 8 //P0.8-P0.15
#define RS 16//P0.16
#define EN 17//P0.17
#define RW 18//P0.18

//rtc
#define FOSC 12000000
#define CCLK (5*FOSC);
#define PCLK (CCLK/4);
#define PREINT_VAL (int)((PCLK/32758)-1)
#define PREFRAC_VAL (PCLK-((preint_val+1)*32768))
#define RTC_ENABLE (1<<0)
#define RTC_RESET (1<<1)
#define RTC_RESET (1<<1)
#define RTC_CLKSRC (1<<4)

#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6

//interrupts
#define EINT0_INPUT_PIN 0x0000000C //P0.1
#define EINT0_VIC_CHNO 14//external interrupt 1 for channel no 14

#define EINT1_INPUT_PIN 0x000000C0 //P0.3
#define EINT1_VIC_CHNO 15 //external interrupt 2 for channel no 15

//switches
#define SWITCH1 1//P0.1
#define SWITCH2 3//P0.3
//kpm
#define ROW0 16//P1.16
#define ROW1 17//P1.17
#define ROW2 18//P1.18
#define ROW3 19//P1.19
#define COL0 20//P1.20
#define COL1 21//P1.21
#define COL2 22//P1.22
#define COL3 23//P1.23
//BUZZER
#define buzzer 23 //P0.23
