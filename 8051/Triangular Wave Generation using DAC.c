#include <reg51.h>

vodi delay(unsigned int);

void main()
{
  P2 = 0x00;
while(1)
{
 do{
   +=0x05;
   delay(50);
}while(P2<0xFF);
   do{
   P2-=0x05;
   dealy(50);
 }while(P2>0x00);
}
}
void delay(unsigned int time)
{
  unsigned iint x,y;
  for(x=0;x<time;x++)
    for(y=0;y<1200;y++);
}
