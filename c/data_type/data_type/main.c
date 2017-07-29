#include <stdio.h>
//全局变量
int global_data; //未初始化的全局变量 bss段  初始值为0
int global_data2 = 100;//已初始化的全局变量 data段
int main(void)
{
	printf("%d\n", sizeof(int));//4
	printf("%d\n", sizeof(long));//4
	printf("%d\n", sizeof(char));//1
	printf("%d\n", -1);//-1
	printf("%u\n", -1);//4294967295 补码形式存储的  

	printf("%d\n", 128);//128
	printf("%hhd\n", 128);// 128 输出8位 1个字节
	printf("%hd\n", 128);//  128 输出16位 2个字节
	printf("%hu\n", 128);//128

	printf("\n");
	char ch = 128;
	printf("%d\n", ch);//-128
	printf("%hhd\n", ch);//-128 输出8位 1个字节
	printf("%hd\n", ch);//-128  输出16位 2个字节
	printf("%hu\n", ch);//65408

	printf("%d\n",sizeof(float));//4
	printf("%d\n",sizeof(double));//8
	printf("%d\n",sizeof(long double));//8
	return 0;
}
int main02(void)
{
	//变量
	int n;
	static int bss_data;//未初始化的静态变量1  bss段
	static int bss_data2;//未初始化的静态变量2 bss段
	printf("%p\n",&bss_data);
	printf("%p\n",&bss_data2);
	static int data = 100;//已初始化的静态变量 data段
	printf("hello world\n");
	return 0;
}