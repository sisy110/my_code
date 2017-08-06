#include <stdio.h>
//#define MAX(a,b) ((a) > (b) ? (a) : (b));
//全局变量
int global_data; //未初始化的全局变量 bss段  初始值为0
int global_data2 = 100;//已初始化的全局变量 data段
int main01(void)
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
int main03(void)
{
	int a, b, sum;
	a = 123;
	b = 456;
	sum = a + b;
	printf("%d\n",sum);
	printf("global_data=%d\n",global_data);//输出0

	static int s_a;
	printf("s_a=%d\n",s_a);//输出0
	return 0;
}
int main04(void)
{
	int a = 123;
	a = 456;

	{
		int a = 100;
		printf("a=%d,&a=%p\n",a,&a);//100
		static int b = 200;
		printf("b=%d\n",b);
	}

	printf("a=%d,&a=%p\n",a,&a);//456
	return 0;
}
int main05(void)
{
	/*
	右移
逻辑右移 高位补0 (对无符号来说, >>是指逻辑右移)
算术右移 保留符号不变 (对于正数,高位补0，对于负数，高位补1)
C语言没有规定有符号数的>> 是逻辑右移还是算术右移
实际上，几乎所有的编译器有符号数的>>都实现为算术右移
	*/
	printf("%d\n",10 << 4); //等价于10 * 2^4  >>等价于 10 / 2^4
	unsigned int n = -1;
	printf("%u\n",n);
	printf("%#x\n",n);//%#表示的输出提示方式，如果是8进制，在前面加0，如果是十进制，不加任何字符，如果是十六进制，会加上0x
	printf("%#x\n",n >> 8);//0xffffffff => 0xffffff
	printf("\n");
	int n2 = -1;
	printf("%#x\n",n2);  
	printf("%#x\n",n2 >> 8);
	return 0;
}
int main06(void)
{
	printf("%d\n",sizeof(short));//2
	short x = 0x1A2B;
	printf("%#X\n",x);//0x1A2B
	//获取低8为也就是2B 需要高8位&0 低8位&1  0x00FF <=> 0xFF
	printf("%#X\n",x & 0xFF);//0x2B
	//x >> 8 0x1A 防止为负数符号位补1 需要& 0  
	printf("%#X\n",x >> 8 & 0xFF);//0x1A
	printf("%d\n",10&15);//10
	printf("%d\n",10|15);//15
	printf("%d\n",10^15);//5
	//~(~0 << n)实现最低n位为1,其余位为0的位串信息
	//x &= ~(1 << m) 将变量x的第m位置成0，其余位不变
	//x |= m 在m为1的每个位置上,将变量x与之对应的位设置为1，其余位不变
	//x &= ~m 在m为1的每个位置上,将变量x与之对应的位设置为0,其余位不变
	printf("%#X\n",~(~0 << 7));//0x7F
	//公式验证 ~X <=> -X -1 表达式恒为真
	printf("%d\n",~-10); //9
	return 0;
}
int main(void)
{
	//printf("%d\n",MAX(100,200));
	int n;
	n = 1, 2, 3;
	printf("n=%d\n",n);//1
	n = (1, 2, 3);//3
	printf("n=%d\n",n);
	printf("\n");
	printf("n=%d\n",(1,2,3));//3
	return 0;
}