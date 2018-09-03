#ifndef  __STRUCT
#define  __STRUCT

/*用户结构类型*/
typedef struct user
{
	char r[11];  //存放输入的字符串
    char  c[11];	//存放密码
	int hx;   //存放密码哈希值
	int i;       //记录字符串个数
} setuser;

/*按钮结构类型*/
typedef struct button
{
	char *s;   //存放按钮包含内容
	int a[4];    //存放按钮边界值
	
} setbt;

/*结构体包涵：按键的键值与代表的字符*/
typedef struct    
{
  int value;
  char ch;
}setKeyValue;

#endif
