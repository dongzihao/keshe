#include "welcFace.h"
#include "struct.h"
#include "userin.h"
#include "mouse.h"
#include "userin.h"

//***欢迎界面****//
void setwelcome()
{
 int maxx,maxy,color;
 int buttons,mx,my,i,j;
 int temp,judge;
 char acc[11],code[11];
 setbt bt[5];
 static int inAcc=0,inCod=0;
 for(i=0;i<11;i++)
    {
		acc[i]='\0';
	}
 for(j=0;j<11;j++)
{
	code[j]='\0';
}
 
 
 maxx=getmaxx();
 maxy=getmaxy();
 newbt(maxx,maxy,bt);
 backgroundsetting(maxx,maxy);
 showString(maxx/2-144,26,"自助旅游系统",LIGHTRED,3);
 logfield(maxx/2-175,150);
 logal(60,60,2);
 lowside(maxx,maxy);
 
 mouseInit(&mx,&my,&buttons);
 while(1)
 {
	 newxy(&mx,&my,&buttons);
	 judge=click(mx,my,bt,buttons);
	 if(kbhit()!=0)
	 {
	    temp=bioskey(0);
	 }		//清空键盘缓冲区//
     switch(judge)
	 {
		 case 1://******输入账号******
		 inPutAccount(&mx,&my,&judge,acc,bt->a,inAcc);
		 
		 
		 break;
		 
		 case 2://******输入密码*****
		 inPutAccount(&mx,&my,&judge,code,(bt+1)->a,inCod);
		 break;
		 
		 case 3://*********登录******
		 
		 break;
		 
		 case 4://***注册***//
		 userRegist();
		 
		 
		 break;
		 case 5://***管理员登录***//
		 
		 
		 break;
		 case 0:
		 break;
		 
	 }
 }
 
 }
 
 
 
 //***背景设计********//
 void backgroundsetting(int x0,int y0)
 {
	setfillstyle(1,15);
	bar(0,0,x0,y0);
	setcolor(LIGHTCYAN);
	setfillstyle(1,11);
	rectangle(0,0,x0,100);
	floodfill(1,1,LIGHTCYAN);   
 }
 
 
 
 //*****设计logal******//
 void logal(int x,int y,int color)
{
	//************画飞机****************//
	setcolor(color);
	setlinestyle(0, 0, 2);
	ellipse(x, y, 90, 250, 40, 16);
	line(x, y - 15, x + 27, y - 17);
	line(x + 43, y - 17, x + 55, y - 17);
	line(x - 16, y + 15, x + 30, y + 15);
	line(x + 55, y - 17, x + 62, y - 40);
	line(x + 62, y - 40, x + 70, y - 40);
	line(x + 70, y - 40, x + 70, y - 30);
	line(x + 70, y - 15, x + 70, y);
	ellipse(x + 30, y - 1, 270, 360, 40, 16);
	line(x + 15, y, x + 45, y - 40);
	line(x + 45, y - 40, x + 51, y - 40);
	line(x + 51, y - 40, x + 35, y);
	line(x + 53, y - 10, x + 77, y - 35);
	line(x + 77, y - 35, x + 83, y - 35);
	line(x + 83, y - 35, x + 66, y - 11);
	line(x - 38, y, x + 69, y);

	setlinestyle(0, 0, 1);
	setcolor(LIGHTBLUE);
	line(x - 37, y - 4, x - 22, y - 4);
	line(x - 22, y - 4, x - 22, y - 7);
	line(x - 22, y - 7, x - 33, y - 7);
	rectangle(x - 7, y - 7, x - 4, y - 4);
	rectangle(x + 8, y - 7, x + 11, y - 4);
	rectangle(x + 40, y - 7, x + 43, y - 4);
	
	setlinestyle(0,0,3);
	setcolor(12);
	arc(530,55,0,70,20);
	arc(530,55,110,360,20);
	line(530,20,530,55);
	
	
	//************画火车************//
	
	setlinestyle(0,0,2);
	setcolor(12);
	circle(50,435,15);
	circle(100,435,15);
	circle(180,435,15);
	circle(230,435,15);
	rectangle(20,380,260,420);
	rectangle(40,340,45,380);
	setlinestyle(0,0,2);
	setcolor(BLACK);
	rectangle(50,385,75,400);
	rectangle(100,385,125,400);
    rectangle(150,385,175,400);
    rectangle(200,385,225,400);
    setlinestyle(0,0,2);
    setcolor(12);
	ellipse(60,330,0,360,9,6);
	ellipse(90,315,0,360,10,7);
	line(192,430,218,430);
	line(192,440,218,440);
	line(62,430,88,430);
    line(62,440,88,440);

	
	
	
	
 }
 
 
 
 //***登陆区域***//
 void logfield(int x0,int y0)
 {
	 showString(x0+20,y0+10,"用户名",RED,1);
	 showString(x0+20,y0+60,"密\xa1\xa1码",RED,1);
	 
	 
	 setcolor(BLACK);
	 rectangle(x0+120,y0,x0+300,y0+35);
	 rectangle(x0+120,y0+50,x0+300,y0+85);
	 
	 setfillstyle(1,9);
	 bar(x0+20,y0+120,x0+132,y0+156);
	 showString(x0+60,y0+130,"登录",WHITE,1);
     bar(x0+188,y0+120,x0+300,y0+156);
	 showString(x0+228,y0+130,"注册",WHITE,1);
	 bar(x0+90,y0+200,x0+250,y0+236);
	 showString(x0+130,y0+210,"管理员登录",WHITE,1);
	 
	 
} 
 
 
 
 //***底部设计***//
 void lowside(int x0,int y0)
 {
	 setfillstyle(1,3);
	 bar(0,450,x0,y0);
	 showString(20,460,"自动化",6,1);
	 showString(68,463,"\xa3\xb1\xa3\xb7\xa3\xb0\xa3\xb2",6,1);
	 showString(250,460,"董子浩",6,1);
	 showString(400,460,"张俊佳",6,1);
	 
	 
	 
 }
 //*******初始化按钮区域*******//
   void newbt(int maxx,int maxy,setbt*bt)
 {
	 bt->s="账号输入";
	 bt->a[0]=maxx/2-55;
	 bt->a[1]=maxx/2+125;
	 bt->a[2]=150;
	 bt->a[3]=185;
	 (bt+1)->s="密码输入";
	 (bt+1)->a[0]=maxx/2-55;
	 (bt+1)->a[1]=maxx/2+125;
	 (bt+1)->a[2]=200;
	 (bt+1)->a[3]=235;
	 (bt+2)->s="登录";
	 (bt+2)->a[0]=maxx/2-155;
	 (bt+2)->a[1]=maxx/2-43;
	 (bt+2)->a[2]=270;
	 (bt+2)->a[3]=306;
	 (bt+3)->s="注册";
	 (bt+3)->a[0]=maxx/2+13;
	 (bt+3)->a[1]=maxx/2+125;
	 (bt+3)->a[2]=270;
	 (bt+3)->a[3]=306;
	 (bt+4)->s="管理员登录";
	 (bt+4)->a[0]=maxx/2-60;
	 (bt+4)->a[1]=maxx/2+75;
	 (bt+4)->a[2]=350;
	 (bt+4)->a[3]=386;
 }
 
 /**判定鼠标点击区域**/
 int click(int mx,int my,struct button *bt,int buttons)
 {
	 if (mx >=bt->a[0]  && mx <= bt->a[1]&& my >=bt->a[2] && my <=bt->a[3] && buttons)return 1;   //if(鼠标点击【账号输入】区域)
	 if (mx >=(bt+1)->a[0] && mx <=(bt+1)->a[1]&& my >=(bt+1)->a[2] && my <= (bt+1)->a[3] && buttons)return 2;   //if(鼠标点击【密码输入】区域)
	 if (mx >= (bt+2)->a[0] && mx <=(bt+2)->a[1] && my >=(bt+2)->a[2] && my <=(bt+2)->a[3]&& buttons)return 3;   //if(鼠标点击【登陆】区域)
	 if (mx >= (bt+3)->a[0] && mx <=(bt+3)->a[1] && my >=(bt+3)->a[2] && my <=(bt+3)->a[3] && buttons)return 4;    //if(鼠标点击【注册】区域)
	 if (mx >= (bt+4)->a[0]&& mx <= (bt+4)->a[1] && my >= (bt+4)->a[2] && my <=(bt+4)->a[3] && buttons)return 5;  //if(鼠标点击【管理员登录】区域)
     else return 0;
 }