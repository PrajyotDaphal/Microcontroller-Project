#include<pic.h>
#define FOSC 		10000										
#define BAUD_RATE	9.6											
#define BAUD_VAL	(char)(FOSC/ (16 * BAUD_RATE )) - 1;		//Calculation For 9600 Baudrate @10Mhz

void main()
	{
	unsigned char ReceiveChar;	
	TRISC=0xc0;					//RC7,RC6 set to usart mode(INPUT)
	TXSTA=0x24;					//Transmit Enable
	SPBRG=BAUD_VAL;				//9600 baud at 10Mhz
	RCSTA=0x90;					//Usart Enable, Continus receive enable
	TXREG='0';
	while(1)
	{
	    if (RCIF==1)			//char received? Send 'A' back to Terminal
	   	{
		  ReceiveChar=RCREG;
		  if(TXIF==1)
		    TXREG=ReceiveChar;
		}	
	}
}
