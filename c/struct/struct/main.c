#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/*
�ṹ���ڴ����
һ.��һ�����ݳ�Ա�������ṹ�������ַƫ��ֵΪ0�ĵط�
��.�����������ݳ�Ա����������ģ������������ÿ�����ݳ�Ա�����Լ��Ķ���ģ��
��.����ģ��ȡ���ݳ�Ա�Ĵ�С��pragma pack(n) (����ֵ,gccĬ��Ϊ4,vcĬ��Ϊ8)�Ľ�Сֵ
��.�����ṹ��Ĵ�С������������ģ����������

gcc pack(n) nΪ1 2 4
vc  pack(n) nΪ1 2 4 8
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
//ʹ��αָ��#pragma pack (n)��C������������n���ֽڶ���
#pragma pack(2)
typedef struct test2
{
	char a;
	double b;
	char c;
}test2_t;
#pragma pack()
//�ṹ��λ�ֶ� ���Խ�ʡռ�ÿռ�
typedef struct pack
{
	char a : 1; //1λ
	char b : 2; //2λ
	char c : 3; //3λ
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
	t2 = t;//�ṹ�帳ֵ
	printf("%d %d %d %d %s\n",t2.a[0],t2.a[1],t2.a[2],t2.b,t2.c);

	char x[6] = "hello";
	char y[6];
	strcpy(y,x);//�ַ�������
	printf("%s\n",y);
	return 0;
}
int main03(void)
{
	printf("%d\n",sizeof(test2_t));//24Ĭ�϶���ģ��(8)
	return 0;
}
int main04(void)
{
	//�ṹ��λ�ֶ�
	printf("%d\n", sizeof(pack_t));//1
	return 0;
}
int main05(void)
{
	printf("%d\n",sizeof(data_t));//8������Առ��ͬһ���ڴ�ռ�
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