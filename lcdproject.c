#include <reg51.h>
//8 data lines D0 -D7
// 3 command lines RW , RS , AND ENABLE
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;

void cmdf(unsigned char);
void dataf(unsigned char);
void delay();
char message[]="Well come to CSE ES lab clas";
unsigned int i;
void main(void)
{
	P2 =0X00;
	while(1)
	{
		cmdf(0X38); // SCREEN LINES
	  delay();
		cmdf(); // clear screen
		delay();
		cmdf(0X10); // CURSUR BLINKING
		delay();
		cmdf(0X0C); // screen on
		delay();
	  cmdf(0X81); // FRIST LINE AT THE BEIGNING
		
		for(i=0;i<sizeof(message)+1;i++)
		{
			dataf(message[i]);
			delay();
		}
		
	}
}
void cmdf(unsigned char val)
{
	P2=val;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void dataf(unsigned char val)
{
	P2=val;
	rs=0; // 1 fro data 0 for command
	rw=0;// o to write and 1 to read
	en=1;
	delay();
	en=0;
}
void delay()
{
	unsigned int j;
	for(j=0;j<15000;j++);
	
}

