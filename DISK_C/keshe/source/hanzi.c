#include"hanzi.h"


FILE* openZiKu(int thick){
	static FILE* ziku=NULL;
	if(thick==CLOSE_ZIKU){
		ziku=NULL;
		return NULL;
	}
	if(ziku==NULL){
		if(thick==THICK){
			ziku=fopen("c:\\keshe\\hanzi\\ziku_cu.txt","rb");
		}else {
			ziku=fopen("c:\\keshe\\hanzi\\ziku.txt","rb");	
		}
		if(ziku==NULL){
			//hideMouse();
			closegraph();
			printf("the ziku file can not be opened");
			getch();
			exit(1);
		}
	}
	
	//lseek(ziku,0,SEEK_SET);
	return ziku;
}

void closeZiKu(FILE* ziku){
	if(ziku==NULL)return;
	fclose(ziku);
	openZiKu(CLOSE_ZIKU);
}

void getMat(char incode[],char bytes[],int thick){
	unsigned char qh,wh;
	unsigned long offset;
	FILE* ziku=openZiKu(thick);
	qh=incode[0]-0xa0;
	wh=incode[1]-0xa0;
	offset=(94*(qh-1)+wh-1)*32L;
	fseek(ziku,offset,SEEK_SET);
	fread(bytes,1,32,ziku);
	//close(ziku);
}

void showHanZi16(int x0,int y0,char incode[],int color,int thick){
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	int i,j,x,y,pos;
	char mat[32];
	getMat(incode,mat,thick);
	y=y0;
	for(i=0;i<16;i++){
		x=x0;
		pos=2*i;
		for(j=0;j<16;j++){
			if((mask[j%8]&mat[pos+j/8])!=NULL){
				putpixel(x,y,color);
			}
			x++;
		}
		y++;
	}
}

void showHanZiBySize(int x0,int y0,char incode[],int color,int thick,int size){
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	int i,j,x,y,pos,num=16*size;
	char mat[32];
	getMat(incode,mat,thick);
	y=y0;
	for(i=0;i<num;i++){
		x=x0;
		pos=2*(i/size);
		for(j=0;j<num;j++){
			if((mask[(j/size)%8]&mat[pos+j/(8*size)])!=NULL){
				putpixel(x,y,color);
			}
			x++;
		}
		y++;
	}
}
void showString(int x,int y,char s[],int color,int size){
	int x1=x,y1=y;
	int i=0;
	while(1){
		showHanZiBySize(x1,y1,s+i,color,THIN,size);
		x1+=size*16;
		//y1+=size*16;
		i+=2;
		if(*(s+i)=='\0')break;
	}
}
