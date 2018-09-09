#include <stdio.h>
#include<string.h>
#include "struct.h"
#include "keyboard.h"
#include "userin.h"
#include "hanzi.h"
#include "mouse.h"


void inPutAccount(int*mx,int*my,int* ju,char ss[],int abr[],int a)
{
	int buttons,temp,jjudge;
	setcolor(0);
	settextjustify(0,2);
	settextstyle(3,0,2);
	

	while(1)
	{    
		newxy(mx,my,&buttons);
        if(kbhit()!=0)
	    {
					 
		   temp=bioskey(0);
	       ss[a]=searchKeyValue(temp);
		   outtextxy(abr[0]+a*24,abr[2],&ss[a]);
		   a++;
		}
	    if(a>=10)
		{
			*ju=0;
			break;
		}
		if(*ju!=jjudge2(*mx,*my,buttons,*ju))
	    {
		    *ju=jjudge2(*mx,*my,buttons,*ju);
		    break;
		}
	    if (((*mx <= abr[0] || *mx >= abr[1]|| *my <= abr[2] || *my >= abr[3]) && buttons)==1)
		{
		    *ju=0;
			break;
	    }
	}
	
}
 int jjudge2(int mx,int my,int buttons,int judge)
 { 
        if (mx >= 265 && mx <= 445 && my >= 150 && my <= 185 && buttons)
		{
			return 1;
		}
        else if (mx >= 265 && mx <= 445 && my >= 200 && my <= 235 && buttons)
	    {
		    return 2;
		}         
	    else if (mx >= 165 && mx <= 277 && my >= 270 && my <= 306 && buttons)
	    {
		    return 3;
		}         
	    else if (mx >= 333 && mx <= 445 && my >= 270 && my <= 360 && buttons)
		{
	        return 4;
		}         
	    else if (mx >= 260 && mx <= 395 && my >= 350 && my <= 386 && buttons)
		{
		    return 5;
	    } 
		else
		{
		    return judge;
	    }
	 
 }
 
 
 
 
 