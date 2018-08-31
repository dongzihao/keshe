#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define N 10
struct students{
char name[20];
char number[20];
int grade1;
int grade2;
int grade3;
};
void input(struct students *dp);
void average(struct students *dp);
void order(struct students *dp);
void find(struct students *dp);
void main()
{
 struct students d[N];
 int i;
 for(i=0;i<N;i++)
 {
  input(&d[i]);
 }
 for(i=0;i<N;i++)
 {
  average(d);
 }
 order(d);
 find(d);
}
void input(struct students *dp)
{
 printf("name\n");
 gets(dp->name);
 printf("number\n");
 gets(dp->number);
 printf("grade1 grade2 grade3\n");
 scanf("%d     %d     %d",&dp->grade1,&dp->grade2,&dp->grade3);
}
void average(struct students *dp)
{
}
void order(struct students *dp)
{
}
void find(struct students *dp)
{
}