#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
 int i,graphdriver,graphmode,size,h;
 void* buff;
 graphdriver=DETECT;
 initgraph(&graphdriver,&graphmode,"C:\\BORLANDC\\BGI");
 setbkcolor(BLUE);
 cleardevice();
 setcolor(YELLOW);
 setlinestyle(0,0,1);
 setfillstyle(1,5);
 circle(100,200,30);

 floodfill(100,200,YELLOW);
 size=imagesize(69,169,131,231);
 buff=malloc(size);
 getimage(69,169,131,231,buff);
 putimage(500,169,buff,COPY_PUT);
 h=0;
 do{
  for(i=0;i<185;i++)
  {
   putimage(70+i,170,buff,COPY_PUT);
   putimage(500-i,170,buff,COPY_PUT);

  }
  for(i=0;i<185;i++)
  {
   putimage(255-i,170,buff,COPY_PUT);
   putimage(315+i,170,buff,COPY_PUT);

  }  h++;                                }while(h<10);


  getch();
  closegraph();



 }
