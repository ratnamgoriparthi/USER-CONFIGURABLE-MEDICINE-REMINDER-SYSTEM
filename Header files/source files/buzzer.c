#include<lpc21xx.h>
#include "defines.h"
#include "declarations.h"
void buzzer_init(){
        IODIR0|=(1<<buzzer);  //Make buzzer as output for P0.23 using IODIR0
}
void buzzer_on(){
        IOSET0=(1<<buzzer);      //set the P0.23 for buzzer on using IOSET
}
void buzzer_off(){
        IOCLR0=(1<<buzzer);     //clear the p0.23 for buzzer off using IOCLR
}
