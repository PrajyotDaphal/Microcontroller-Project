
#include<pic18f4550.h>						
#include<stdio.h>					

#define RS RE0						
#define RW RE1						
#define EN RE2						
#define DATA 		PORTD			
#define DATADIR		TRISD			//LCD Data Port Direction Register
#define CNTRLDIR 	TRISE			//RS,RW,EN Direction Register

void lcdinit(void);					
void lcdclr(void);								
void lcdcomd(unsigned char);		
void lcddata(unsigned char);		
void DelayMs(unsigned int);


void main()
{
		int i;
		unsigned char First[]={" PIC DEV. BOARD "};
		unsigned char Secnd[]={"LCD DEMO PROGRAM"};
		DelayMs(500);
		lcdinit();			
		DelayMs(500);

		while(1)
		{
			lcdclr();
			lcdcomd(0x80);
			for(i=0;i<16;i++)			
			{
				lcddata(First[i]);
				DelayMs(50);
			}

			lcdcomd(0xc0);
			for(i=0;i<16;i++)			
			{
				lcddata(Secnd[i]);
				DelayMs(50);
			}
			DelayMs(500);
		}
}


void lcdinit(void)
{	
	int i;
	unsigned char command[]={0x38,0x0c,0x06,0x01};					//LCD Command set for 8 bit Interface, 2 Lines, 5x7 Dots
	ADCON1 = 0x07;													
	CNTRLDIR = 0x00;												
	DATADIR  = 0x00;	
    DelayMs(50);											
	for(i=0;i<4;i++)
	{
		lcdcomd(command[i]);										
		DelayMs(5);
	}
	DelayMs(500);
}

void lcdclr(void)													//Send LCD clear command
{
	lcdcomd(0x01);				
	DelayMs(2);
}                   
		
void lcdcomd(unsigned char cmd)
{	
	RS=0;	RW=0;												
	EN=1;														
	DATA=cmd;										
	EN=0;		
	DelayMs(5);														
}

void lcddata(unsigned char byte) 
{				
	RS=1;	RW=0;													
	EN=1;
	DATA=byte;										 
	EN=0;
	DelayMs(5);	
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
