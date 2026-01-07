#include<reg51.h>


#define LEDPORT P2
void delay(void)
{
	unsigned int i;
	for(i=0;i<50000;i++);
}

void main()
{
	while(1)
	{
	LEDPORT=0x00;
	delay();
	LEDPORT=0xFF;
	delay();
	}
}
