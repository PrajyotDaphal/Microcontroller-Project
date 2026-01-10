#include <reg51.h>

vodi delay();

void main()
{
while(1)
{
P2 = 0x00;
delay();
P2 = 0xFF;
delay();
}
}
void delay()
{
TMOD = 0x01;
TL0 = 0x3E;
TH0 = 0xB8;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
