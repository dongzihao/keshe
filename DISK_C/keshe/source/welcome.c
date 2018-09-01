#include "welcFace.h"
void setwelcome()
{
 int maxx,maxy,i,j,color;
 maxx=getmaxx();
 maxy=getmaxy();
 backgroundsetting(maxx,maxy);
 logal(maxx/2-164,10,LIGHTGREEN);
 showString(maxx/2-144,26,"自助旅游系统",LIGHTRED,3);
 logfield(maxx/2-175,150);
 
 }
 void backgroundsetting(int x0,int y0)
 {
	setfillstyle(1,15);
	bar(0,0,x0,y0);
	setcolor(LIGHTCYAN);
	setfillstyle(1,11);
	rectangle(0,0,x0,100);
	floodfill(1,1,LIGHTCYAN);   
}
 void logal(int x0,int y0,int coulor)
 {
	 
 }
 void logfield(int x0,int y0)
 {
	 showString(x0,y0,"用户名",RED,2);
	 showString(x0,y0+50,"密\xa1\xa1码",RED,2);
	 setcolor(BLACK);
	 setfillstyle(1,10);
	 rectangle(x0+120,y0,x0+300,y0+35);
	 rectangle(x0+120,y0+50,x0+300,y0+85);
	 fillellipse(x0+48,y0+150,50,35);
	 showString(x0+15,y0+130,"登录",WHITE,2);
	 fillellipse(x0+300,y0+150,50,35);
	 showString(x0+267,y0+130,"注册",WHITE,2);
	 setfillstyle(1,7);
	 bar(x0+100,y0+225,x0+280,y0+275);
	 showString(x0+110,y0+230,"管理员登录",WHITE,2);
} 