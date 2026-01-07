
#include<pic.h>								
#include<stdio.h>							

#define Buz    RB0								
#define Relay1 RB1									
#define Relay2 RB2									
#define FOSC 		10000										
#define BAUD_RATE	9.6											
#define BAUD_VAL	(char)(FOSC/ (16 * BAUD_RATE )) - 1;	

void Serial_init(void);											
void DelayMs(unsigned int);

void main()
{
	unsigned char ReceivChar;
	TRISB = 0x00;	
	PORTB = 0x04;												
	Serial_init();			
	printf("\033[2J");						
	DelayMs(20);
	printf("Press 1: Buzzer ON  \n\r\t2: Buzzer OFF");
	printf("\n\r\t3: Relay1 ON  \n\r\t4: Relay1 OFF");
	printf("\n\r\t5: Relay2 ON  \n\r\t6: Relay2 OFF\n\r\n");
	while(1)
	{
		while(RCIF==0);								//Wait until the reception is over
		RCIF=0;										//Clear the flag for next reception
		ReceivChar=RCREG;							//Store the received character to a variable
		printf(" %c",ReceivChar);					//Dislpay the character received
		switch(ReceivChar)
		{	
			case '1':							
			Buz=1;
			break;

			case '2':								
			Buz=0;
			break;
	
			case '3':								
			Relay1=1;
			break;

			case '4':								
			Relay1=0;
			break;

			case '5':								
			Relay2=1;
			break;

			case '6':								
			break;
		}
	}
}

void Serial_init()
{
	TRISC=0xc0;										
	TXSTA=0x24;										//Enable (Serial Transmission, Asynchronous mode, High Speed mode)
	SPBRG=BAUD_VAL;								
	RCSTA=0x90;										//Usart Enable, Continuous receive enable
	TXIF=1;											
}

void putch(unsigned char data)
{
	while(TXIF==0);
	TXREG=data;										
}

void DelayMs(unsigned int Ms)
{
	int delay_cnst;
	while(Ms>0)
	{
		Ms--;
		for(delay_cnst = 0;delay_cnst <220;delay_cnst++);
	}
}
