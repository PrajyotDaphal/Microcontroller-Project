#include <reg51.h>

void UART_Init();
void UART_TxChar(char);
char UART_RxChar();
void UART_SendString(char *);

void UART_Init()
{
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	TR1 = 1;
}

void UART_TxChar(char Data)
{
	SBUF = Data;
	while (TI==0);
	TI = 0;
}

char UART_RxChar()
{
	char dat;
	while (RI==0);
	RI = 0;
	dat = SBUF;
	return(dat);
}
	
void UART_SendString(char *str)
{
     int i;
     for(i=0;str[i]!=0;i++)
		{
         UART_TxChar(str[i]);
    }
}


void main()
{
	char Data_in;
	UART_Init();					/* initialize UART Tx=P3^0 and Rx=P3^1 */
	
	while(1)
	{
		Data_in = UART_RxChar();			
		UART_TxChar(Data_in);
 }
}
