#include "defines.h" //declarations are in defines.h file
void delay_ms(unsigned int dlyms){ //definition for function of delay in milli second
	for(dlyms*=12;dlyms>0;dlyms--);
}

void delay_us(unsigned int dlyus){ //definition for function of delay in micro seconds
	for(dlyus*=12000;dlyus>0;dlyus--);
}
void delay_s(unsigned int dlys){ //definition for function of delay in seconds
	for(dlys*=12000000;dlys>0;dlys--);
}
