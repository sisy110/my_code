#include <stdio.h>
int main(void)
{
	printf("%d\n", sizeof(int));//4
	printf("%d\n", sizeof(long));//4
	printf("%d\n", sizeof(char));//1
	printf("%d\n", -1);//-1
	printf("%u\n", -1);//4294967295 ������ʽ�洢��  

	printf("%d\n", 128);//128
	printf("%hhd\n", 128);// 128 2���ֽ�
	printf("%hd\n", 128);//  128 1���ֽ�
	printf("%hu\n", 128);//128

	printf("\n");
	char ch = 128;
	printf("%d\n", ch);//-128
	printf("%hhd\n", ch);//-128 2���ֽ�
	printf("%hd\n", ch);//-128  1���ֽ�
	printf("%hu\n", ch);//65408
	return 0;
}