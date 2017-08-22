#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
结构体内存对齐
一.第一个数据成员对齐至结构体变量地址偏移值为0的地方
二.接下来的数据成员对齐至对齐模数的整数倍。每个数据成员都有自己的对齐模数
三.对齐模数取数据成员的大小与pragma pack(n) (对齐值,gcc默认为4,vc默认为8)的较小值
四.整个结构体的大小对齐至最大对齐模数的整数倍

gcc pack(n) n为1 2 4
vc  pack(n) n为1 2 4 8
*/
struct point
{
	int x;
	int y;
};
typedef struct point point_t;
typedef struct circle
{
	point_t center;
	int radius;
}circle_t;
typedef struct test
{
int a[3];
int b;
char c[10];
}test_t;
//使用伪指令#pragma pack (n)，C编译器将按照n个字节对齐
#pragma pack(2)
typedef struct test2
{
	char a;
	double b;
	char c;
}test2_t;
#pragma pack()
//结构体位字段 可以节省占用空间
typedef struct pack
{
	char a : 1; //1位
	char b : 2; //2位
	char c : 3; //3位
} pack_t;
typedef union data
{
	int n;
	char c;
	double d;
} data_t;
typedef union data2
{
	char c[2];
	unsigned short s;
}data_t2;
int main01(void)
{
	point_t p1 = {1,2};
	circle_t c1 = { {1,2},3};
	circle_t c2 = {1,2,3};
	//circle_t c3 = {p1,3};//error
	circle_t c3 = { p1.x,p1.y,3 };

	printf("(%d,%d) %d\n",c1.center.x,c1.center.y,c1.radius);
	return 0;
}
int main02(void)
{
	int a[3] = {1,2,3};
	int b[3];
	int i;
	for (i = 0; i < 3; i++)
		b[i] = a[i];
	
	test_t t = { {4,5,6},100,"hello"};
	test_t t2;
	t2 = t;//结构体赋值
	printf("%d %d %d %d %s\n",t2.a[0],t2.a[1],t2.a[2],t2.b,t2.c);

	char x[6] = "hello";
	char y[6];
	strcpy(y,x);//字符串拷贝
	printf("%s\n",y);
	return 0;
}
int main03(void)
{
	printf("%d\n",sizeof(test2_t));//24默认对齐模数(8)
	return 0;
}
int main04(void)
{
	//结构体位字段
	printf("%d\n", sizeof(pack_t));//1
	return 0;
}
int main05(void)
{
	printf("%d\n",sizeof(data_t));//8三个成员占用同一段内存空间
	return 0;
}
int main(void)
{
	data_t2 x;
	x.s = 0x0102;
	if (x.c[0] == 2 && x.c[1] == 1)
		printf("little endian\n");
	else
		printf("big endian\n");
	return 0;
}