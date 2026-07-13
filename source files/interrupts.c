#include<lpc21xx.h>
#include "defines.h"
#include "declarations.h"
#include "types.h"

int hrs=0,minute=0,dom=0,mth=0,yr=0;
int num_meds=0;
int med_hour[3]={0,0,0}; //default medicine hours
int med_min[3]={0,0,0};  //default medicine minutes
int med_flag[3]={0,0,0};//default medicine flags
int med_count=0;//medicine count 


void INIT_INTERRUPTS() //definition for interrupt initialisation
{
    PINSEL0 &= ~((3<<2)|(3<<6)); //clear pin 2,3 and pin6,7 
    PINSEL0 |= EINT0_INPUT_PIN|EINT1_INPUT_PIN;//set the EINT0,EINT1 functions on P0.1 and P0.3
    EXTMODE = (1<<0)|(1<<1);//interrupt raise in level 
    EXTPOLAR = 0x00;
    VICIntEnable |= (1<<14)|(1<<15); //enable interrupt channels 14 and 15 in VIC
    VICVectCntl0 = (1<<5)|14;//store the irq interrupt 0 in the slots based on priority
    VICVectAddr0 = (u32)eint0_isr;//store the address in the vectaddress register corresponding to the slot 

   VICVectCntl1 = (1<<5)|15; //store the irq interrupt 1 in the slots based on priority
   VICVectAddr1 = (u32)eint1_isr;//store the address in the vectaddress register corresponding to the slot 
}

void eint0_isr(void)__irq{ //definition for interrupt 0 isr
        CONFIGURE_MENU(); //interrupt 0 occurs go to menu()
        EXTINT=1<<0;// eint0 interrupt enable
        VICVectAddr=0;//after completition of eint0 interrupt make the address is equalto zer0,if not done again goes to the same interrupt
        cmdlcd(0x01);//clear lcd screen
}

void eint1_isr(void)__irq{//definition for interrupt 1 isr
        buzzer_off();//off the buzzer ,when interrupt raised
        cmdlcd(0x01);//clear the lcd screen
        EXTINT=1<<1;//enable the interrupt eint1 
        VICVectAddr=0;//after completition of eint1 interrupt make the address is equalto zer0,if not done again goes to the same interrupt
}
//--------------------------------------------------------------
void CONFIGURE_MENU(){ //definition for menu
        int choice;
  L1:cmdlcd(0x01);//clear lcd screen
        cmdlcd(0x80);//set cursor to line1 pos0
        strlcd("1.Edit RTC");//display on line1
        cmdlcd(0xC0);//set cursor to line2 pos0
        strlcd("2.Medicine Time");//display on line2
        choice=Read_one_Num();//read the entered choice number
        if(choice==1){//if choice 1 selected go to the this block
                cmdlcd(0x01);//clear lcd screen
                Edit_RTC();//go to the function call
                goto L1;//go to the L1 label
        }
        else if(choice==2){//if choice 2 selected go to the this block
                cmdlcd(0x01);//clear lcd screen
                CHANGE_Medicine_Time();//go to the function call
                goto L1;//go to the L1 label
        }
        else {
                return;//if other the choice 1 or 2 then exit from the menu,and display rtc time
        }
}
//..........................................................
void Edit_RTC(){//definition for edit rtc
        int choice;
        L2:cmdlcd(0x01);//clear lcd display screen
          cmdlcd(0x80);//set cursor to line 1 pos0
          strlcd("1.Time Change");//display on line1
          cmdlcd(0xC0);//set cursor to line 2 pos0
          strlcd("2.DATE & DAY");//display on line2
           choice=Read_one_Num();//read the entered choice number

          if(choice==1){//if choice 1 selected go to the this block
                cmdlcd(0x01);//clear lcd display screen
                TIME_EDIT();//go to the function call
                        goto L2;//go to l2 label
        }
                else if(choice==2){//if choice 2 selected go to the this block
                cmdlcd(0x01);//clear lcd display screen
                DATE_EDIT();//go to the function call
                        goto L2;//go to l2 label
        }
        else{
                return;//if other the choice 1 or 2 then go to the menu
        }
}
//...................................................................
void TIME_EDIT(){//definition for time edit
        int choice;
loop:cmdlcd(0x01);//clear lcd display screen
          cmdlcd(0x80);//set cursor to line 1 pos0
                strlcd("1.HOUR");//display on line1
          cmdlcd(0xC0);//set cursor to line 2 pos0
          strlcd("2.MINUTE");//display on line 2
         choice=Read_one_Num();//read the entered choice number
          if(choice==1){//if choice 1 selected go to the this block
                        H1:cmdlcd(0x01);//clear lcd display screen
                        cmdlcd(0x80);//set cursor to line 1 pos0
                        strlcd("Enter HOUR:");//display on line1
                              cmdlcd(0xC0);//set cursor to line 2 pos0
                              hrs=Read_Num();//read the number from the key pad and store in the hrs

                        if(hrs>23){ //if hour is greater than 23 then go to this block
                                cmdlcd(0x01);//clear lcd screen
                                cmdlcd(0x80);//set cursor to the line 1 pos0
                                strlcd("Invalid Hour");//display on line1
                                cmdlcd(0xC0);//set cursor to line 2 pos0
                                strlcd("HOUR(0-23)");//display on line1
                                delay_ms(200);//delay for 200 millisecond,for visibility
                                goto H1;//again go to the H1 label
                        }
                        HOUR=hrs;//if hrs is less than or equal to 23 then stored in the HOUR register
                        cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("HOUR updated");//display on line1
                        delay_ms(200);//delay for 200 millisecond,for visibility
                        goto loop;// again go to the loop label
                }
                else if(choice==2){//if choice 1 selected go to the this block
                        M1:cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("Enter Minute:");//display on line1
                        cmdlcd(0xC0);//set cursor to line 2 pos0
                        minute=Read_Num();//read the number from the key pad and store in the minute
                        if(minute>59){//if minute is greater than 59 then go to this block
                                cmdlcd(0x01);//clear the lcd screen
                                cmdlcd(0x80);//set cursor to the line 1 pos0
                                strlcd("Invalid Minute");//display on line1
                                cmdlcd(0xC0);//set cursor to line 2 pos0
                                strlcd("MIN(0-59)");//display on line1
                                delay_ms(200);//delay for 200 millisecond,for visibility
                                goto M1;//again go to the M1 label
                        }
                        MIN=minute;//if minutes is less than or equal to 59 then stored in the MIN register
                        cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("MINUTE updated");//display on line1
                        delay_ms(200);//delay for 200 millisecond,for visibility
                        goto loop;//again go to the loop label
        }
                else {
                return;//if other the choice 1 or 2 then go to the edit_rtc()
        }
}
        //....................................................................
void DATE_EDIT(){//definition for time edit
        int choice;
        loop1:cmdlcd(0x01);//clear lcd screen
          cmdlcd(0x80);//set cursor to the line 1 pos0
                strlcd("1.DATE");//display on line1
          cmdlcd(0x80+8);//shift the cusor to the right by 8 positions on line1
          strlcd("2.MONTH");//display on line1
          cmdlcd(0xC0);//set cursor to line 2 pos0
          strlcd("3.YEAR");//display on line2
          cmdlcd(0xC0+8);//shift the cusor to the right by 8 positions on line2
          strlcd("4.DAY");//display on line2
        choice=Read_one_Num();//read the number from the key pad and go to particular choice 
	
          if(choice==1){//if choice 1 selected go to the this block
                     label:cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("Enter DATE:");//display on line1
                        cmdlcd(0xC0);//set cursor to line 2 pos0
                        dom=Read_Num();//read the number from the key pad and store in the dom
                        if(dom>31){//if date of month is greater than 31 then go to this block
                                cmdlcd(0x01);//clear lcd screen
                                cmdlcd(0x80);//set cursor to the line 1 pos0
                                strlcd("Invalid DATE");//display on line1
                                cmdlcd(0xC0);//set cursor to line 2 pos0
                                strlcd("DATE(1-31)");//display on line2
                                delay_ms(200);//delay for 200 millisecond,for visibility
                                goto label;//again go to the label
                        }
                        DOM=dom;//if dom is less than or equal to 31 then stored in the DOM register
                        cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0xC0);//set cursor to line 2 pos0
                        strlcd("DATE UPDATED");//display on line2
                        delay_ms(200);//delay for 200 millisecond,for visibility
                        goto loop1;//again to the loop1
                }

                        else if(choice==2){//if choice 2 selected go to the this block
                        label1:cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("Enter MONTH:");//display on line1
                                cmdlcd(0xC0);//set cursor to line 2 pos0
                        mth=Read_Num();//read the number from the key pad and store in the mth
                        if(mth>12){//if month is greater than 12 ,then go to the loop
                                cmdlcd(0x01);//clear lcd screen
                                cmdlcd(0x80);//set cursor to the line 1 pos0
                                strlcd("Invalid ");//display on line1
                                cmdlcd(0xC0);//set cursor to line 2 pos0
                                strlcd("MONTH(1-12)");//display on line2
                                delay_ms(200);//delay for 200 millisecond,for visibility
                                goto label1;//again go to the label1
                        }
                        MONTH=mth;//if mth is less than or equal to 12 then stored in the MONTH register
                        cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0xC0);//set cursor to line 2 pos0
                        strlcd("MONTH UPDATED");//display on line2
                        delay_ms(200);//delay for 200 millisecond,for visibility
                        goto loop1;//again go to the loop1
        }
                else if(choice==3){//if choice 3 selected go to the this block
                        label2:cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("Enter YEAR:");//display on line1
                        cmdlcd(0xC0);//set cursor to line 2 pos0
                        yr=Read_Num();//read the number from the key pad and store in the yr
									
                        if(yr<2026){//if year is less than 2026 
                                cmdlcd(0x01);//clear lcd screen
                                cmdlcd(0x80);//set cursor to the line 1 pos0
                                strlcd("Invalid ");//display on line1
                                cmdlcd(0xC0);//set cursor to line 2 pos0
                                strlcd("YEAR(2026,2027,...)");//display on line2
                                delay_ms(200);//delay for 200 millisecond,for visibility
                                goto label2;//again go to the label2
                        }
                        YEAR=yr;//store the yr value in YEAR register
                        cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("YEAR UPDATED");//display on line1
                        delay_ms(200);//delay for 200 millisecond,for visibility
                        goto loop1;//again go to the loop
        }

                else if(choice==4){//if choice 4 selected go to the this block
                        cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("Enter DAY(0-6):");//display on line1
                        cmdlcd(0xC0);//set cursor to line 2 pos0
                        DOW=Read_one_Num();//read the number from the key pad and store in the DOW
                        cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("DAY UPDATED");//display on line1
                        goto loop1;//GO TO loop1
        }

                else {
                return;//if other the choice 1,2,3 or 4 then go to the edit_rtc()
        }
}
//*********************************************************************************************************************************
/*int med_hour[3]={0,0,0};
int med_min[3]={0,0,0};
int med_flag[3]={0,0,0};
int med_count=0;*/

void CHANGE_Medicine_Time(){//definition for change medicine time
        int i=0;
        if(med_count>0){//if medicine count is greater than zero then display the medicine time
                        DISPLAY_Medicine_Time();
					return;
                }
        else {
                  cmdlcd(0x01);//clear lcd screen
                  cmdlcd(0x80);//set cursor to the line 1 pos0
                  strlcd("NO data found");//display on line1
                  cmdlcd(0x01);//clear lcd screen
                  cmdlcd(0x80);//set cursor to the line 1 pos0
                  strlcd("no.of med's:");//display on line1
                  cmdlcd(0xC0);//set cursor to the line 2 pos0
                  num_meds=Read_one_Num();//read the number from the key pad and store in the num_meds
                for(i=0;i<num_meds;i++){//iterate loop for num of medicine remainder times
                        label3:cmdlcd(0x01);//clear lcd screen
                  cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("enter med hour:");//display on line1
                  cmdlcd(0xC0);//set cursor to the line 2 pos0
                        med_hour[i]=Read_Num();//read number from keypad and stored in med_hour[i]
                        if(med_hour[i]>23){//if medicine hour is greater than 23 go to this block
                                cmdlcd(0x01);//clear lcd screen
                                cmdlcd(0x80);//set cursor to the line 1 pos0
                                strlcd("Invalid Hour");//display on line1
                                cmdlcd(0xC0);//set cursor to the line 2 pos0
                                strlcd("HOUR(0-23)");//display on line2
                                delay_ms(200);//delay for 200 millisecond,for visibility
                                goto label3;//GO TO label3
                        }
                  label4:cmdlcd(0x01);//clear lcd screen
                  cmdlcd(0x80);//set cursor to the line 1 pos0
                strlcd("enter med min:");//display on line1
                  cmdlcd(0xC0);//set cursor to the line 2 pos0
                        med_min[i]=Read_Num();//read number from keypad and stored in med_min[i]
                        if(med_min[i]>59){//if medicine minute is greater than 59 go to this block
                                cmdlcd(0x01);//clear lcd screen
                                cmdlcd(0x80);//set cursor to the line 1 pos0
                                strlcd("Invalid Minute");//display on line1
                                cmdlcd(0xC0);//set cursor to the line 2 pos0
                                strlcd("MIN(0-59)");//display on line2
                                delay_ms(200);//delay for 200 millisecond,for visibility
                                goto label4;//GO TO label4
                        }
                med_count++;//medicine count increment
                cmdlcd(0x01);//clear lcd screen
                cmdlcd(0x80);//set cursor to the line 1 pos0
                strlcd("med");//display on line1
                integerlcd(i+1);//display the count of medicine
                strlcd(":");
                cmdlcd(0x80+6);//
                strlcd(" updated");
                        delay_s(1);//delay of 1 second for visibility
        }
        cmdlcd(0x01);//clear lcd screen
        cmdlcd(0x80);//set cursor to the line 1 pos0
        strlcd("MED time UPDATED");//display on line1
        delay_s(1);//delay of 1 second for visibility
}
        }
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
void DISPLAY_Medicine_Time(){//definition for display medicine time 
        int i=0;
                        for(i=0;i<num_meds;i++){//iterate loop for num of medicines
                                cmdlcd(0x01);//clear lcd screen
                                cmdlcd(0x80);//set cursor to the line 1 pos0
                                strlcd("med");//display on line1
                                integerlcd(i+1);//display the count of medicine
                                strlcd(":");
                                integerlcd(med_hour[i]);//display medicine hour
                                strlcd(":");
                                integerlcd(med_min[i]);//display medicine minute
                                delay_s(2);//delay of 2 second for visibility
                        }
                }
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
void MED_REMAINDER(){//definition for medicine remainder
        int i=0;
        for(i=0;i<num_meds;i++){//iterate loop for num of medicines
                if(HOUR==med_hour[i] && MIN==med_min[i]&& med_flag[i]==0&& SEC==00){//if rtc time is equal to med hour and rtc minute is equal to med min
                        med_flag[i]=1;//make flag is 1;itshows it is already completed
                        cmdlcd(0x01);//clear lcd screen
                        cmdlcd(0x80);//set cursor to the line 1 pos0
                        strlcd("Take Medicine!");//display on line1
                        buzzer_on();//on the buzzer
                        while((((IOPIN0>>SWITCH2)&1)==1) && SEC!=59);//wait until the switch2 or eint1 is raised /up to 1 minute 
                                buzzer_off();//off the buzzer
                                cmdlcd(0x01);//clear the lcd screen
        }
}
        }
