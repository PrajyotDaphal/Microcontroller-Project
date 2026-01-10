#include <reg51.h>

vodi delay();

void main()
{
while(1)
{
P0 = 0x08;
  delay();
P0 = 0x04;
  delay();
P0 = 0x02;
  delay();
P0 = 0x01;
  delay();
}
}
void delay()
{
TMOD = 0x01;
TL0 = 0x1A;
TH0 = 0xFF;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
