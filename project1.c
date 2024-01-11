#include<reg51.h>
sbit a = P0^1;
sbit b = P0^2;
unsigned int i;


void main()
{
	a = 1;
while(1)
{
	if(a== 0)
		{
			P1 = 0XFB;
			
	}
		else
		{
			P3 = 0X44;
		}
		
}

		
	}
