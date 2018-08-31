#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<hanzi.h>




void main(){
	int driver=VGA;
	int mode=VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\BGI");
	cleardevice();
		
	showString(100,100,"´ºÃß²»¾õÏþ",RED,3);
	
	getch();
	closegraph();
	closeZiKu(openZiKu(THIN));
}

