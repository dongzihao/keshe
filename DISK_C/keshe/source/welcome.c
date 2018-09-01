#include "welcFace.h"
void setwelcome()
{
 int maxx,maxy,i,j,color;
 maxx=getmaxx();
 maxy=getmaxy();
 backgroundsetting(maxx,maxy);
 showString(maxx/2-144,26,"自助旅游系统",LIGHTRED,3);
 logfield(maxx/2-175,150);
 logal(60,60,2);
 lowside(maxx,maxy);
 
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
 
 
 
 
 void logal(int x,int y,int color)
{
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
	
 }
 
 
 
 
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
 
 
 
 
 void lowside(int x0,int y0)
 {
	 setfillstyle(1,3);
	 bar(0,450,x0,y0);
	 showString(20,460,"自动化",6,1);
	 showString(68,463,"\xa3\xb1\xa3\xb7\xa3\xb0\xa3\xb2",6,1);
	 showString(250,460,"董子浩",6,1);
	 showString(400,460,"张俊佳",6,1);
	 
	 
	 
 }