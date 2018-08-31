#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <graphics.h>
#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_A 30
#define KEY_B 48
#define KEY_C 46
#define KEY_E 18
#define KEY_ENTER 28
int key();
void main()
{
 int ky,y;
 char ch;
 textbackground(0);
 clrscr();
 do{
   textmode(C80);
   textbackground(13);
   textcolor(RED);
   window(7,8,19,15);
   clrscr();
   textground(1);
   textcolor(RED);
   window(8,9,18,14);
   clrscr();
   gotoxy(3,3);cprintf("E:exit\r\n");
   gotoxy(3,4);cprintf("A:dir\r\n");
   gotoxy(3,5);cprintf("B:dir/p\r\n");
   gotoxy(3,6);cprintf("C:dir/w\r\n");
   y=10;
   upbar(y-1);
   do
   {
    ky=key();
    switch (ky)
    {
     case KEY_A:
      y=12,ky=KEY_ENTER;
      break;
     case KEY_B:
      y=13,ky=KEY_ENTER;
      break;
     case KEY_C:
      y=14,ky=KEY_ENTER;
      break;
     case KEY_E:
      y=11,ke=KEY_ENTER;
      break;
     case kEY_DOWN:
      if(y<13){upbar(y);y++;};
      break;
     case KB_S_N_UP:
      if(y>10){downbar(y);y--;};
      break;
    }
    }while(ky!=KEY_ENTER);
    textcolor(WHITE) ;
    switch(y)
    {
     case 11:
      ch='%';
      break;
     case 12:
      system("dir");
      getch();
      break;



    }

   }
 }
}


