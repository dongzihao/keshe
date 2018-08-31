//#include <AT89X52.h>
#include "uart.h"
sbit LED1=P3^04;  // B4=B0^04=1011,0000^0000,0100;

void delay_nus(unsigned int i);
void delay_nms(unsigned int i);

void mydelay()
{
   unsigned int i,j;//65535;
	 for(j=0;j<=50;j++)
	 {
	    for(i=0;i<=1000;i++);
			
	 }
}
void main()
{ int i=10;
  bit flag1=0;
	bit flag2=1;
  uart_Init();

  while(1)
	{
	  LED1=0;
		//delay_nms(500);
		mydelay();
		T0=1;
		//delay_nms(500);
		mydelay();

    if(P3_2==0||P3_3==0)
    {		P1_7=0;
        P3_5=0;
    }
		else
    {		P1_7=1;
		    P3_5=1;
		}
    i++;
		printf("%d\n",i);
		
	}
}

/*
void delay_nus(unsigned int i)  //延时:i>=12 ,i的最小延时单12 us
{ 
  i=i/10;
  while(--i);
}   

void delay_nms(unsigned int n)  //延时n ms
{ 
  n=n+1;
  while(--n)  
  delay_nus(900);         //延时 1ms,同时进行补偿
}   
*/