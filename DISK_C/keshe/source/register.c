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
	int mx,my,buttons,judge,temp,hx,jcode=2;//jcode�����ж�ȷ������������Ƿ�һ��
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
				   if(judge!=jjudge(mx,my,buttons,judge))
				   {
					   judge=jjudge(mx,my,buttons,judge);
					   break;
				   }
				   if (((mx <= 200 || mx >= 600 || my <= 120 || my >= 165) && buttons)==1)
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
				   if(judge!=jjudge(mx,my,buttons,judge))
				   {
					   judge=jjudge(mx,my,buttons,judge);
					   break;
				   }
				   if (((mx <= 200 || mx >= 600 || my <= 200 || my >= 245) && buttons)==1)
				   {
					   judge=0;
					   break;
				   }
				   
			    }
		        break;
		 
		 
		case 3://*********ȷ������*******//
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
				   if(judge!=jjudge(mx,my,buttons,judge))
				   {
					   judge=jjudge(mx,my,buttons,judge);
					   break;
				   }
				   if (((mx <= 200 || mx >= 600 || my <= 280 || my >= 325) && buttons)==1)
				   {
					   judge=0;
					   break;
				   }
				   
			    }
		        
		       
			    break;
		 
		 
		case 4://***ע��ɹ�***//
		       if(strcmp(s,u.c)==0)
		        {
			      jcode=1;
				  hx=haxi(u.c);
				  hxz = &hx;
		        } 
		        else jcode=0;
		        switch(jcode)
		       {
			    case 0: //���벻һ��
				showString( 465, 360,"���벻һ��" ,WHITE,2);
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
				   showString( 465, 360,"ע��ɹ�" ,WHITE,2);
				break;
			    case 3: //ֱ�ӵ�ע��
			    showString( 465, 360,"ע��ʧ��" ,WHITE,2);
			    break;
		        }
		        judge=0;
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
 int jjudge(int mx,int my,int buttons,int judge)
 { 
        if (mx >= 200 && mx <= 600 && my >= 120 && my <= 165 && buttons)
		{
			return 1;
		}
        else if (mx >= 200 && mx <= 600 && my >= 200 && my <= 245 && buttons)
	    {
		    return 2;
		}         //if���������������������
	    else if (mx >= 200 && mx <= 600 && my >= 280 && my <= 325 && buttons)
	    {
		    return 3;
		}         //if(�����������һ����������
	    else if (mx >= 230 && mx <= 460 && my >= 360 && my <= 415 && buttons)
		{
	        return 4;
		}         //if(�����ע���������
	    else if (mx >= 300 && mx <= 455 && my >= 437 && my <= 455 && buttons)
		{
		    return 5;
	    } 
		else
		{
		    return judge;
	    }
	 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 