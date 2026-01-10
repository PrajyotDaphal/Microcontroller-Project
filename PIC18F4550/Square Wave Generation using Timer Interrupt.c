#include <pic18f4550.h>

void timerInit(void)
{
  T0CON = 0b00000111;
  TMR0H = 0xED;
  TMR0L = 0xB0;
}

void Interrupt_Init(void)
{
  IPEN = 1;
  INTCON = 0b11100000;
  TMR0IP = 0;
}

void interrupt low_priority timerinterrupt(void)
{
  if(TMR0IF == 1)
{
TMR0ON = 0;
TMR0IF = 0;
LATB =~ LATB;
TMR0H = 0xED;
TMR0L = 0xB0;
TMR0ON = 1;
}
}

void main(void)
{
  TRISB = 0x00;
  LATB = 0xFF;

  InterruptInit();
  TMR0ON = 1;
  while(1);
}
