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
	setuser u;//�洢�û���Ϣ
	int mx,my,buttons,judge,temp,hx,jcode=2;
	int i,j,k;//�ֱ�������������Ĳ���
	registFace();
	mouseInit(&mx,&my,&buttons);
	setcolor(0);
	settextjustify(0,2);
	settextstyle(0,0,3);
	for(i=0;i<11;i++)
	{
		u.r[i]='\0';
	}
    i=0;//��ʼ��ע��
	for(j=0;j<11;j++)
	{
		u.c[j]='\0';
	}
	j=0;//��ʼ������
	for(k=0;k<11;k++)
	{
		s[k]='\0';
	}
	k=0;//��ʼ��ȷ������
     while(1)
   {
	  if(kbhit()!=0)
	   {
	     temp=bioskey(0);
	   }		//��ռ��̻�����//			 
	  newxy(&mx,&my,&buttons);
      if (mx >= 200 && mx <= 600 && my >= 120 && my <= 165 && buttons)judge = 1;         //if(��������˺���������)
	  if (mx >= 200 && mx <= 600 && my >= 200 && my <= 245 && buttons)judge = 2;         //if���������������������
	  if (mx >= 200 && mx <= 600 && my >= 280 && my <= 325 && buttons)judge = 3;         //if(�����������һ����������
	  if (mx >= 230 && mx <= 460 && my >= 360 && my <= 415 && buttons)judge = 4;         //if(�����ע���������
	  if (mx >= 300 && mx <= 455 && my >= 437 && my <= 455 && buttons)judge = 5;         //if(����������˻�ȥ��½����)
     switch(judge)
	 {
		
		case 1://******�����˺�******//
		        while(1)
				{    
			       newxy(&mx,&my,&buttons);
				   /*if (mx >= 200 && mx <= 600 && my >= 200 && my <= 245 && buttons)
				   {
					judge = 2;
			        break;
				   }         //if���������������������
	               else if (mx >= 200 && mx <= 600 && my >= 280 && my <= 325 && buttons)
				   {
					judge = 3;
			        break;
				   }         //if(�����������һ����������
				   else if (mx >= 230 && mx <= 460 && my >= 360 && my <= 415 && buttons)
				   {
					 judge = 4;
					 break;
				   }         //if(�����ע���������
	               else if (mx >= 300 && mx <= 455 && my >= 437 && my <= 455 && buttons)
				   {
					 judge = 5;
					 break;
				   } */
				   if (((mx <= 200 || mx >= 600 || my <= 120 || my >= 165) && buttons)==1)
				   {
					   judge=0;
					   break;
				   }
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
			    }
				
				break;
		 
		 
		case 2://******��������*****//
		        while(1)
				{    
			       newxy(&mx,&my,&buttons);
				    /*if (mx >= 200 && mx <= 600 && my >= 120 && my <= 165 && buttons)
				   {
					judge = 1;
			        break;
				   }         //if���������������������
	               else if (mx >= 200 && mx <= 600 && my >= 280 && my <= 325 && buttons)
				   {
					judge = 3;
			        break;
				   }         //if(�����������һ����������
				   else if (mx >= 230 && mx <= 460 && my >= 360 && my <= 415 && buttons)
				   {
					 judge = 4;
					 break;
				   }         //if(�����ע���������
	               else if (mx >= 300 && mx <= 455 && my >= 437 && my <= 455 && buttons)
				   {
					 judge = 5;
					 break;
				   } */
				   if (((mx <= 200 || mx >= 600 || my <= 120 || my >= 165) && buttons)==1)
				   {
					   break;
				   }
				   
				   if(kbhit()!=0)
	               {
					 
		             temp=bioskey(0);
					 u.c[j]=searchKeyValue(temp);
					 outtextxy(199+j*24,199,&u.c[j]);
					 j++;
				   }
				   if(j>=10)
				   {
					     break;
				   }
			    }
		        break;
		 
		 
		case 3://*********ȷ������*******//
		        for(i=0;i<10;i++)
		        {
			      s[i]=searchKeyValue(temp);
		        }
		        if(strcmp(s,u.c)==0)
		        {
			      jcode=1;
				  hx=haxi(u.c);
				  hxz = &hx;
		        } 
		        else jcode=0;
			    break;
		 
		 
		case 4://***ע��ɹ�***//
		        switch(jcode)
		       {
			    case 0: //���벻һ��
			    break;
			    case 1: //ע��ɹ�
			       if ((fp = fopen("FILES\\user\\usercode.txt", "r+")) == NULL)
                   {
	                  closegraph();
	                  printf("Can't open usercode.txt");
	                  getchar();
	                  exit(1);
                   }
				   fwrite(u.c,10,1,fp);
				   fwrite(hxz,2,1,fp);
				   fclose(fp);
				break;
			    case 3: //ֱ�ӵ�ע��
			 
			    break;
		        }
		 
	    break;
		
		
		case 5://***����***//
		 
		 
		break;
		case 0:
		
		break;
		 
		 
	 }
    }
 
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
 //����½����//
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


	showString( 60, 127,"�û���" ,WHITE,2);
	showString( 60,  207, "����",WHITE,2);
	showString( 60,  287, "ȷ������",WHITE,2);
	showString( 285, 370, "ע��", WHITE,2);
	showString(312, 436, "����",  WHITE,1);
	setcolor(YELLOW);
	line(300, 455, 365, 455);
	showString(240, 215, "\xa3\xb1��\xa3\xb1\xa3\xb0λ��ĸ���������",BLACK,1);
	showString(210, 20, "���û�ע��",LIGHTCYAN,3);
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 