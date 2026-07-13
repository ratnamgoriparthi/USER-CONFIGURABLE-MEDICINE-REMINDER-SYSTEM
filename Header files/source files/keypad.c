#include<lpc21xx.h>
#include "defines.h"
#include "declarations.h"
#include "types.h"
//4x4 keypad matrix
char keypad[4][4] = {
 {'7','8','9','/'},
 {'4','5','6','*'},
 {'1','2','3','-'},
 {'C','0','=','#'}
};
void Init_Kpm()
{
    // Rows (P1.16 to P1.19)  OUTPUT
    // Columns (P1.20 to P1.23)  INPUT

    IODIR1 |= (0x0F << 16);   // rows output
    IODIR1 &= ~(0x0F << 20);  // columns input
}
char Key_Scan()
{
    int row, col;
    while(1)
    {
        for(row=0; row<4; row++)
        {
            // Make all rows HIGH
            IOSET1 = (0x0F << 16);
            // Make one row LOW
            IOCLR1 = (1 << (16 + row));
            // Check columns
            for(col=0; col<4; col++)
            {
                if(((IOPIN1 >> (20 + col)) & 1) == 0)
                {
                    // Wait until key release
                    while(((IOPIN1 >> (20 + col)) & 1) == 0);
                    delay_ms(200);
                    return keypad[row][col];//return  the rowno and cno
                }
            }
        }
    }
}
int Read_one_Num(void)
{
    char key;
    int sum = 0;
        key = Key_Scan();
                  // read one key from keypad
        if(key >= '0' && key <= '9')
        {
           datalcd(key);
            sum = (sum * 10) + (key - '0');
        }
                 else if(key=='#'){//if key =='#' then it works as backspace
                  sum=sum/10;//sum last value will be removed
                  cmdlcd(0x10);//shift cursor to the left
                  strlcd(" ");
                  cmdlcd(0x10);
                  }
                  else if(key=='C'){//if key =='C' then it clears the screen
                  cmdlcd(0x01);
                  }
                        return sum;
    }

int Read_Num(void)
{
    char key;
    int sum = 0;

    while(1)
    {
        key = Key_Scan();
                  // read one key from keypad
        if(key >= '0' && key <= '9')
        {
            datalcd(key);
            sum = (sum * 10) + (key - '0');
        }
                 else if(key=='#')
                 {
                        if(sum>0)
                        {
                                sum=sum/10;
                                cmdlcd(0x10);
                                strlcd(" ");
                                cmdlcd(0x10);
                        }
                  }
                        else if(key=='C'){
                  cmdlcd(0x01);
                        break;
                  }
        else if(key == '=')
        {
           cmdlcd(0x01);
            break;

        }
    }
    return sum;
}

