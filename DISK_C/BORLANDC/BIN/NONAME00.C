#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
 int cursor[16][10]={
 {1,0,0,0,0,0,0,0,0,0},
 {1,1,0,0,0,0,0,0,0,0},
 {1,1,1,0,0,0,0,0,0,0},
 {1,1,1,1,0,0,0,0,0,0},
 {1,1,1,1,1,0,0,0,0,0},
 {1,1,1,1,1,1,0,0,0,0},
 {1,1,1,1,1,1,1,0,0,0},
 {1,1,1,1,1,1,1,1,0,0},
 {1,1,1,1,1,1,1,1,1,0},
 {1,1,1,1,1,1,1,1,1,1},
 {1,1,1,1,1,0,0,0,0,0},
 {1,1,1,0,1,1,0,0,0,0},
 {1,1,0,0,1,1,0,0,0,0},
 {1,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,0,1,0,0,0}
 };
 int driver=VGA;
 int mode=VGAHI,i,j,x,y;
 initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
 cleardevice();
 setviewport(20,100,570,450,1);
 x=500;
 y=200;
 for(i=0;i<16;i++)
 {
  for(j=0;j<10;j++)
  {
   if(cursor[i][j]!=0)
   putpixel(x+j,y+i,WHITE);
  }
 }
 setfillstyle(1,WHITE);
 bar(100,100,400,120);
 setcolor(BLUE);
 circle(250,50,30);
 circle(250,10,8);
 circle(220,15,5);
 circle(280,15,5);
 setfillstyle(1,BLUE);
 floodfill(250,50,BLUE);
 floodfill(250,10,BLUE);
 floodfill(220,15,BLUE);
 floodfill(280,15,BLUE);
 settextstyle(1,0,3);
 setcolor(RED);
 outtextxy(150,35,"SEARCHING ENDING");
 setfillstyle(1,LIGHTGRAY);
 bar(420,100,460,120);
 setcolor(WHITE);
 line(419,99,461,99);
 line(419,99,419,121);
 setcolor(DARKGRAY);
 line(461,121,461,99);
 line(461,121,419,121);
 setcolor(RED);
 settextstyle(SMALL_FONT,HORIZ_DIR,4);
 outtextxy(423,102,"search");
 outtextxy(125,130,"help");
 outtextxy(225,130,"more");
 outtextxy(325,130,"about");
 setcolor(DARKGRAY);
 line(102,101,102,119);
 closegraph();
 getchar();
 }
