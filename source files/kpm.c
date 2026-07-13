#include<lpc21xx.h>
#include "defines.h"
#include "declarations.h"
#include "types.h"

//Key values in keypad matrix
char KPMLUT[][4]={{'1','2','3','4'},{'5','6','7','8'},{'9','0','+','-'},{'*','/','C','='}};

//initialise KPM
void Init_Kpm(void)
	{
	//Clear P1.16 -P1.23 and set row pins as output,columns as input
	IODIR1=((IODIR1&(~(255<<ROW0)))|(15<<ROW0));
}
	
//check if key is pressed or not
int Key_Detect(void)
	{
	//if column values are less than 15 ,then return 0,else return 1
	return((((IOPIN1>>COL0)&15)<15)?0:1);
}
	
//if key detected then check in which row the key is pressed
int Row_Check(void)
{
	int rno;
	//loop for checking four rows
	for(rno=0;rno<4;rno++){
		//mask the rows and columns and make the rno as zero which row is checking 
		IOPIN1=((IOPIN1&(~(255<<ROW0)))|(~(1<<rno)<<ROW0));
		//if key detect then stop,no need to check further
		if(Key_Detect()==0)
			break;
	}
	//make the rows as zeros
	IOPIN1=((IOPIN1&(~(255<<ROW0)))|(0x0<<ROW0));
	//return the rno,in which row key is detected
	return rno;
}
//if key detected then check in which column the key is pressed
int Col_Check(void){
	int cno;
	//loop for checking four columns
	for(cno=0;cno<4;cno++){
		//if column value is detected then stop
		if(((IOPIN1>>(COL0+cno))&1)==0)
			break;
	}
	return cno;
}

//scan the value from the keypad
int Key_Scan(void){
	int rno,cno,keyvalue;
	//wait for the switch press
	while(Col_Check());
	//find the rno
	rno=Row_Check();
	//find the cno
	cno=Col_Check();
	//get the keyvalue from the keypad look up table
  keyvalue=KPMLUT[rno][cno];
  //wait for switch release
  while(!(Col_Check()));
	//return the keyvalue
  return keyvalue;
}

//used for multiple digit functions
int Read_Num(void){
	char key;
	int sum=0;
	while(1){
		//store the keyvalue 
		key=Key_Scan();
		if(key>='0' && key<='9'){
			sum=(sum*10)+(key-'0');
		}
		//if entering the '='then break
		else if(key=='='){
			break;
		}
	}
	//return the sum value
	return sum;
}



