
#include<reg52.h>
#include<stdio.h>

sbit ADC_CS 	=  P2^4;
sbit ADC_CLK 	=  P2^5;
sbit ADC_DO 	=  P2^6;
sbit ADC_DI 	=  P2^7;


void InitSerial(void);
void write_adc_byte(char data_byte);
unsigned int ReadADC(unsigned char channel);
void DelayMs(unsigned int count);

void InitSerial(void)
{
  	SCON = 0x52;     
  	TMOD = 0x20;    
  	TH1  = 0xFD;    
	  TR1	 = 1;  		
}

unsigned int ReadADC(unsigned char channel)
{
	   unsigned char i,k;
	   unsigned int AdcResult;  /
	
	   ADC_CS=0;  						
     k++;								    
		 ADC_CLK=0; 						
	   k++;k++;	
	   channel = channel? 0xA0 : 0xD0;	
	   k++;k++;  						

	   for(i=0; i< 4;i++) 
	   {
	      ADC_DI = (channel & 0x80) != 0;
			 //ADC_DI = (channel & 0x80);
	      channel<<=1;
	      ADC_CLK=1;
	      k++;k++;					
	      ADC_CLK=0;
	   }
	
	   k++;k++;  					
	   ADC_CLK=1;
	   k++;k++;  				
	   ADC_CLK=0;
	   k++;k++;  					

	   AdcResult=0;
	   for(i=0;i<12;i++) 
	   {
		      ADC_CLK=1;
		      k++;k++;  			
		      AdcResult<<=1;
			  AdcResult=AdcResult | (ADC_DO & 0x01);	       
		   ADC_CLK=0;
		      k++;k++;  			
	   }
	   ADC_CS=1;
	   return(AdcResult);	
}

void main(void)
{
	unsigned int CH0, CH1;
	InitSerial();  		
	putchar(0x0C);  
	while(1)
	{									   	    
		CH0	=	ReadADC (0);
		printf("Ch 0 : %4d  \n\r", CH0);
	}
}



