#include <pic18f4550.h>
#include <stdio.h>

void InitUART()
{
  TRISCbits.RC6 = 0;
  TRISCbits.RC7 = 1;

  SPBRG = 77;

  TXSTA = 0b00100000;
  RCSTA = 0b10010000;
}

void SendChar(unsigned char data)
{
  while(TXIF == 0);
  TXREG = data;
}

unsigned char GetChar(void)
{
  while(!RCIF)
  return RCREG;
}

void main(void)
{
  key = GetChar();
  SendChar(kay);
}
