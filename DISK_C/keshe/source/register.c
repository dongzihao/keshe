#include <stdio.h>
#include<string.h>
#include "struct.h"
#include "mouse.h"
#include "keyboard.h"
#include "userin.h"
#include "hanzi.h"


void userRegist()
{
	FILE *fp=NULL;
	char s[10];
	int *hxz;
	setuser u;//存储用户信息
	int mx,my,buttons,judge,temp,hx,jcode=2;//jcode用来判断确认密码和密码是否一致
	int i,j,k;//分别用来帮助输出的参数
    int size;
	void far* buffer;
	registFace();
	size=imagesize(465,360,625,392);
	buffer=malloc(size);
    getimage(465,360,625,392,buffer);//先保存一定区域的图形
	mouseInit(&mx,&my,&buttons);
	setcolor(0);
	settextjustify(0,2);
	settextstyle(3,0,2);
	for(i=0;i<11;i++)
	{
		u.r[i]='\0';
	}
    i=0;//初始化注册
	for(j=0;j<11;j++)
	{
		u.c[j]='\0';
	}
	j=0;//初始化密码
	for(k=0;k<11;k++)
	{
		s[k]='\0';
	}
	k=0;//初始化确认密码
     while(1)
   {
	  if(kbhit()!=0)
	   {
	     temp=bioskey(0);
	   }		//清空键盘缓冲区//			 
	  newxy(&mx,&my,&buttons);
      if (mx >= 200 && mx <= 600 && my >= 120 && my <= 165 && buttons)judge = 1;         //if(鼠标点击新账号输入区域)
	  if (mx >= 200 && mx <= 600 && my >= 200 && my <= 245 && buttons)judge = 2;         //if（鼠标点击新密码输入区域）
	  if (mx >= 200 && mx <= 600 && my >= 280 && my <= 325 && buttons)judge = 3;         //if(鼠标点击再输入一次密码区域
	  if (mx >= 230 && mx <= 460 && my >= 360 && my <= 415 && buttons)judge = 4;         //if(鼠标点击注册完成区域
	  if (mx >= 300 && mx <= 455 && my >= 437 && my <= 455 && buttons)judge = 5;         //if(鼠标点击已有账户去登陆区域)
     switch(judge)
	 {
		
		case 1://******输入账号******//
		        while(1)
				{    
			       newxy(&mx,&my,&buttons);
                   if(kbhit()!=0)
	               {
					 
		             temp=bioskey(0);
					 u.r[i]=searchKeyValue(temp);
					 outtextxy(199+i*24,119,&u.r[i]);
					 i++;
				   }
				   if(i>=10)
				   {
					    judge=0;
					     break;
				   }
				   if(judge!=jjudge1(mx,my,buttons,judge))
				   {
					   judge=jjudge1(mx,my,buttons,judge);
					   break;
				   }
				   if (((mx <= 200 || mx >= 600 || my <= 120 || my >= 165) && buttons)==1)
				   {
					   judge=0;
					   break;
				   }
			    }
				
				break;
		 
		 
		case 2://******输入密码*****//
		        
		        while(1)
				{   
			       newxy(&mx,&my,&buttons);
				   if(kbhit()!=0)
	               {
					 
		             temp=bioskey(0);
					 u.c[j]=searchKeyValue(temp);
					 outtextxy(199+j*24,199,&u.c[j]);
					 j++;
				   }
				   if(j>=10)
				   {
					     judge=0;
					     break;
				   }
				   if(judge!=jjudge1(mx,my,buttons,judge))
				   {
					   judge=jjudge1(mx,my,buttons,judge);
					   break;
				   }
				   if (((mx <= 200 || mx >= 600 || my <= 200 || my >= 245) && buttons)==1)
				   {
					   judge=0;
					   break;
				   }
				
				   
			    }
				
		        break;
		 
		 
		case 3://*********确认密码*******//
		          while(1)
				{    
			       newxy(&mx,&my,&buttons);
				   if(kbhit()!=0)
	               {
					 
		             temp=bioskey(0);
					 s[k]=searchKeyValue(temp);
					 outtextxy(199+k*24,279,&s[k]);
					 k++;
				   }
				   if(k>=10)
				   {
					     judge=0;
					     break;
				   }
				   if(judge!=jjudge1(mx,my,buttons,judge))
				   {
					   judge=jjudge1(mx,my,buttons,judge);
					   break;
				   }
				   if (((mx <= 200 || mx >= 600 || my <= 280 || my >= 325) && buttons)==1)
				   {
					   judge=0;
					   break;
				   }
				   
			    }
		        
		       
			    break;
		 
		 
		case 4://***注册成功***//
		       
		       if(strcmp(s,u.c)==0&&s[0]!='\0')
		        {
			      jcode=1;
				  hx=haxi(u.c);
				  hxz = &hx;
		        } 
		        else if (strcmp(s,u.c)!=0)
				{
					jcode=0;
				}
				else if(s[0]=='\0')
				{
					jcode=3;
				}
		        switch(jcode)
		       {
			    case 0: //密码不一致
				putimage(465,360,buffer,0);
				showString( 465, 360,"密码不一致" ,WHITE,2);
			 
			    break;
			    case 1: //注册成功
			       if ((fp = fopen("FILES\\user\\usercode.txt", "ab+")) == NULL)
                   {
	                  closegraph();
	                  printf("Can't open usercode.txt");
	                  getchar();
	                  exit(1);
                   }
				   fwrite(u.r,10,1,fp);
				   fwrite(hxz,2,1,fp);
				   fclose(fp);
				   putimage(465,360,buffer,0);
				   showString( 465, 360,"注册成功" ,WHITE,2);
				 
				break;
			    case 3: //直接点注册
				putimage(465,360,buffer,0);
			    showString( 465, 360,"注册失败" ,WHITE,2);
			
			    break;
		        }
		        judge=0;
	            break;
		
		
		case 5://***返回***//
		 
		 
		break;
		case 0:
		
		break;
		 
		 
	 }
    }
 free(buffer);
 }
 
 
 int haxi(char*p)
 {
	 int i;
	 int hash=0x0626;
	for(i=0;i<strlen(p);i++){
		hash^=(unsigned)p[i];
		hash*=(unsigned)0x0222;
	}
	return hash;
 }
 //画登陆界面//
 void registFace()
 {
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);
	setfillstyle(1, WHITE);
	bar(199, 119, 551, 166);
	bar(199, 199, 551, 246);
	bar(199, 279, 551, 326);
	setfillstyle(1, LIGHTGREEN);
	bar(230, 360, 403, 415);


	showString( 60, 127,"用户名" ,WHITE,2);
	showString( 60,  207, "密码",WHITE,2);
	showString( 60,  287, "确认密码",WHITE,2);
	showString( 285, 370, "注册", WHITE,2);
	showString(312, 436, "返回",  WHITE,1);
	setcolor(YELLOW);
	line(300, 455, 365, 455);
	showString(210, 20, "新用户注册",LIGHTCYAN,3);
 }
 int jjudge1(int mx,int my,int buttons,int judge)    //点击其他区域时改变位置
 { 
        if (mx >= 200 && mx <= 600 && my >= 120 && my <= 165 && buttons)
		{
			return 1;
		}
        else if (mx >= 200 && mx <= 600 && my >= 200 && my <= 245 && buttons)
	    {
		    return 2;
		}         //if（鼠标点击新密码输入区域）
	    else if (mx >= 200 && mx <= 600 && my >= 280 && my <= 325 && buttons)
	    {
		    return 3;
		}         //if(鼠标点击再输入一次密码区域
	    else if (mx >= 230 && mx <= 460 && my >= 360 && my <= 415 && buttons)
		{
	        return 4;
		}         //if(鼠标点击注册完成区域
	    else if (mx >= 300 && mx <= 455 && my >= 437 && my <= 455 && buttons)
		{
		    return 5;
	    } 
		else
		{
		    return judge;
	    }
	 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 