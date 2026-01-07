#include<reg51.h>
#include<stdio.h>

#define Data P0

sbit RS =P0^0;
sbit RW =P0^1;
sbit LCD_ENABLE =P0^2;

unsigned char message1[]=("Hello World");
unsigned char message2[]=("ESD -IOT");

void lcd_init(void);
void delay(int);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);


void delay(int k)
{
	unsigned int a;
	for(a=0;a<k;a++);
}

void lcd_data(unsigned char dat)
{
	Data= 0xf0 &  dat;
	RS=1;RW=0;
	LCD_ENABLE=1;
	delay(35);
	LCD_ENABLE=0;
	Data=dat <<4;
	RS=1;RW=0;
	LCD_ENABLE=1;
	delay(35);
	LCD_ENABLE=0;
	
}

void lcd_cmd(unsigned char command)
{
	Data= 0xf0 &  command;// upper nibble 1111 0000
	RS=0;RW=0;
	LCD_ENABLE=1;
	delay(35);
	LCD_ENABLE=0;
	
	Data=command <<4;
	RS=0;RW=0;
	LCD_ENABLE=1;
	delay(35);
	LCD_ENABLE=0;
	
}


void lcd_init(void)
{
	unsigned char i;
	lcd_cmd(0x28);  
	delay(15);
	lcd_cmd(0x0C);  
		delay(15);
lcd_cmd(0x06);  
		delay(15);
	lcd_cmd(0x01);  
		delay(15);
		delay(5000);

		lcd_cmd(0x80);  
		delay(15);
	i=0;
	while(message1[i]!='\0')
	{
		lcd_data(message1[i]);
		i++;
	}
				delay(50);
	/////
	lcd_cmd(0xc0);  
		delay(15);
	i=0;
	while(message2[i]!='\0')
	{
		lcd_data(message2[i]);
		i++;
	}
				delay(50);
}

void main(void)
{
	P0=0;
	lcd_init();
	delay(10);
	while(1);
	
}


















