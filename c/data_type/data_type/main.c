#include <stdio.h>
//ȫ�ֱ���
int global_data; //δ��ʼ����ȫ�ֱ��� bss��  ��ʼֵΪ0
int global_data2 = 100;//�ѳ�ʼ����ȫ�ֱ��� data��
int main(void)
{
	printf("%d\n", sizeof(int));//4
	printf("%d\n", sizeof(long));//4
	printf("%d\n", sizeof(char));//1
	printf("%d\n", -1);//-1
	printf("%u\n", -1);//4294967295 ������ʽ�洢��  

	printf("%d\n", 128);//128
	printf("%hhd\n", 128);// 128 ���8λ 1���ֽ�
	printf("%hd\n", 128);//  128 ���16λ 2���ֽ�
	printf("%hu\n", 128);//128

	printf("\n");
	char ch = 128;
	printf("%d\n", ch);//-128
	printf("%hhd\n", ch);//-128 ���8λ 1���ֽ�
	printf("%hd\n", ch);//-128  ���16λ 2���ֽ�
	printf("%hu\n", ch);//65408

	printf("%d\n",sizeof(float));//4
	printf("%d\n",sizeof(double));//8
	printf("%d\n",sizeof(long double));//8
	return 0;
}
int main02(void)
{
	//����
	int n;
	static int bss_data;//δ��ʼ���ľ�̬����1  bss��
	static int bss_data2;//δ��ʼ���ľ�̬����2 bss��
	printf("%p\n",&bss_data);
	printf("%p\n",&bss_data2);
	static int data = 100;//�ѳ�ʼ���ľ�̬���� data��
	printf("hello world\n");
	return 0;
}