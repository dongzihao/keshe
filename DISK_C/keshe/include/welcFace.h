#ifndef __WELFACE
#define __WELFACE

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "graphics.h"
#include "hanzi.h"








void setwelcome();
void logal(int x,int y,int coulor);
void backgroundsetting(int x0,int y0);
void logfield(int x0,int y0);
void lowside(int x0,int y0);
int click(int mx,int my,struct button * bt,int buttons);
void newbt(int maxx,int maxy,struct button*bt);
#endif

