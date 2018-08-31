#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char*f(char*p);
void main()
{
 char a[100];
 char *l;
 printf("please inpuut your words\n");
 gets(a);
 l=f(a);
 printf("%s\n",l);
}
char*f(char*p)
{
 char*back;
 int i,j,m,n,sum,k[100];
 j=0;
 for(i=0;p[i]!='\0';i++)
 {
  if((p[i]>=65&&p[i]<90)||(p[i]>=97&&p[i]<=122))
  {
   k[j]++;
  }
  else
  {
   j++;
   k[j]=0;
  }
 }
  for(n=0,m=0;n<j;n++)
  {
   if(k[n]>k[m])
    {
     m=n;
    }
   else if(k[n]==k[m])
    {
     m=m<n?m:n;
    }
   }
 for(i=0,sum=0;i<m;i++)
 {
  sum+=k[i];
 }
 sum=sum+m;
 back=p+sum;
 p[sum+k[m]+1]='\0';
 return (back);
}




