#include<lpc21xx.h>
#include "defines.h"
#include "declarations.h"

void cmdlcd(char cmd){//definition for command lcd
	IOCLR0=(1<<RS);//make rs=0,then it acts as command register
	IOCLR0=(1<<RW);//make rw=0,then it writes the data
	IOCLR0=(255<<lcd_data_pins);//clear the 8 data pins
	IOSET0=(cmd<<lcd_data_pins);//set the cmd value of the data pins
	IOSET0=(1<<EN);//make enable pin high
	delay_us(1);
	IOCLR0=(1<<EN);//make enable low,then data will be write to lcd
	delay_ms(2);
}
void datalcd(char data){
	IOSET0=(1<<RS);//make rs=1,then it acts as data register
	IOCLR0=(1<<RW);//make rw=0,then it writes the data
	IOCLR0=(255<<lcd_data_pins);//clear the 8 data pins
	IOSET0=(data<<lcd_data_pins);//set the data value of the data pins
	IOSET0=(1<<EN);//make enable pin high
	delay_us(1);
	IOCLR0=(1<<EN);//make enable low,then data will be write to lcd
	delay_ms(2);
}
void initLCD(void){
	IODIR0|=(255<<lcd_data_pins);//make 8 data pins as output
	IODIR0|=(1<<EN);//EN pin as output
	IODIR0|=(1<<RS);//RS pin as output
	IODIR0|=(1<<RW);//RW pin as output
	delay_ms(15);//delay for 15 ms for on the lcd
	cmdlcd(0X30);//set 8 bit mode 3 times
	delay_ms(5);//delay for 5ms
	cmdlcd(0X30);
	delay_us(100);//delay of 100 micro seconds
	cmdlcd(0X30);
	cmdlcd(0X38);//we use 8 bit mode 2 lines
	cmdlcd(0X0C);//set cursor to the line2 pos0
	cmdlcd(0X06);//shift cursor to the right
	cmdlcd(0X01);//clear lcd
}
void strlcd(char *p){//definition for string lcd
	while(*p){//untill p value become NULL it continues
		datalcd(*p);//display each character
		delay_us(50);//delay of 50 micro seconds for visibility  
		p++;//increment p 
	}
}
void charlcd(char ch){//definition  for char lcd
	datalcd(ch);//display the character
}
void integerlcd(int num){//definition for integer lcd
	int arr[10];//store the numbers in array
	int i;
	if(num==0){//if num==0 then it displays '0'
		datalcd('0');
	}
	if(num<0){//if num<0 ,then it's first character will be negative sign
		datalcd('-');
	}
	while(num){
		arr[i++]=(num%10)+48;//convert the character into ascii value
		num=num/10;
	}
	for(i--;i>=0;i--){
		datalcd(arr[i]);//display integer value
	}
}
