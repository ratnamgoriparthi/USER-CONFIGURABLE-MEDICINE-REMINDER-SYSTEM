#include<lpc21xx.h> //for accessing the predefined registers
#include "types.h"   //types header file inclusion
//delay
void delay_ms(unsigned int dlyms); //function declaration for millisecond delay
void delay_us(unsigned int dlyus); //function declaration for microsecond delay
void delay_s(unsigned int dlys);   //function declaration for second delay

//lcd
void cmdlcd(char cmd);   //function declaration for command lcd
void datalcd(char data); //function declaration for data lcd
void initLCD(void);       //function declaration for lcd initialisation
void strlcd(char *p);     //function declaration for string lcd
void charlcd(char ch);    //function declaration for character lcd
void integerlcd(int num);  //function declaration for integer lcd

//RTC
void RTC_Init(void);    //function declaration for RTC initialisation
void GetRTCTimeInfo(s32 *,s32 *,s32 *);  //function declaration for get rtc time information
void DisplayRTCTime(u32,u32,u32);        //function declaration for display rtc time information
void GetRTCDateInfo(s32 *,s32 *,s32 *);  //function declaration for get rtc Date information
void DisplayRTCDate(u32,u32,u32);        //function declaration for display rtc Date information
void SetRTCTimeInfo(u32,u32,u32);        //function declaration for set default rtc time by the programmer
void SetRTCDateInfo(u32,u32,u32);        //function declaration for set default rtc Date by the programmer
void GetRTCDay(s32 *);                  //function declaration for get rtc Day information
void DisplayRTCDay(u32);                //function declaration for display rtc Day information
void SetRTCDay(u32);                     //function declaration for set default rtc Day by the programmer

//interrupts
void INIT_INTERRUPTS(void); //function declaration for interrupts initialistaion
void eint0_isr(void)__irq; //function declaration for interrupt 1 
void eint1_isr(void)__irq; //function declaration for interrupt 2  
void CONFIGURE_MENU(void); //function declaration for interrupt 1 isr menu
void Edit_RTC(void);//function declaration for interrupt 1 edit menu
void TIME_EDIT(void);//function declaration for interrupt 1 time edit
void DATE_EDIT(void);//function declaration for interrupt 1 date edit
void CHANGE_Medicine_Time(void);//function declaration for interrupt 1 change medicine time
void DISPLAY_Medicine_Time(void);//function declaration for interrupt 1 display medicine time
void MED_REMAINDER(void);//function declaration for interrupt 1 medicine remainder

//buzzer
void buzzer_init(void);//function declaration for buzzer initialisation
void buzzer_on(void);//function declaration for buzzer on
void buzzer_off(void);//function declaration for buzzer off
//keypad
void Init_Kpm(void);//function declaration for keypad initialisation
char Key_Scan(void);//function declaration for key scan
int Read_Num(void);//function declaration for read multiple numbers from keypad
int Read_one_Num(void);//function for read one number from keypad
