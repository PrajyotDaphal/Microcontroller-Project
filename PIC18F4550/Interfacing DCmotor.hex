#include<htc.h>
#include<pic18f4550.h>
#define _XTAL_FREQ   20000000 
void rundutycycle(unsigned int x );
#define s1           RD0
#define s2           RD1
#define s3           RD2
#define s4           RD3
#define s5           RD4
#define s6           RD5
#define s7           RD6
void main()
{
//ADCON1=0x06;      
TRISD=0xFF;          
TRISC2  = 0;             
CCP1CON = 0x0C;          
PR2   = 0xFF;            
rundutycycle(512);
}

void rundutycycle(unsigned int dutycyc){
T2CON = 0x01;           
T2CON |= 0x04;         

while(1){
CCPR1L   = dutycyc>>2;        	       L
CCP1CON &= 0xCF;                	
CCP1CON |= (0x30&(dutycyc<<4));        
if(s1==1){dutycyc=172; }
else if(s2==1){dutycyc=342; }
else if(s3==1){dutycyc=512; }
else if(s4==1){dutycyc=686; }
else if(s5==1){dutycyc=858; }
else if(s6==1){dutycyc=1020; }
else if(s7==1){dutycyc=0; }
dutycyc=dutycyc;
}
}
