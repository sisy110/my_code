#include <stdio.h>
//#define MAX(a,b) ((a) > (b) ? (a) : (b));
//ȫ�ֱ���
int global_data; //δ��ʼ����ȫ�ֱ��� bss��  ��ʼֵΪ0
int global_data2 = 100;//�ѳ�ʼ����ȫ�ֱ��� data��
int main01(void)
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
int main03(void)
{
	int a, b, sum;
	a = 123;
	b = 456;
	sum = a + b;
	printf("%d\n",sum);
	printf("global_data=%d\n",global_data);//���0

	static int s_a;
	printf("s_a=%d\n",s_a);//���0
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
	����
�߼����� ��λ��0 (���޷�����˵, >>��ָ�߼�����)
�������� �������Ų��� (��������,��λ��0�����ڸ�������λ��1)
C����û�й涨�з�������>> ���߼����ƻ�����������
ʵ���ϣ��������еı������з�������>>��ʵ��Ϊ��������
	*/
	printf("%d\n",10 << 4); //�ȼ���10 * 2^4  >>�ȼ��� 10 / 2^4
	unsigned int n = -1;
	printf("%u\n",n);
	printf("%#x\n",n);//%#��ʾ�������ʾ��ʽ�������8���ƣ���ǰ���0�������ʮ���ƣ������κ��ַ��������ʮ�����ƣ������0x
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
	//��ȡ��8ΪҲ����2B ��Ҫ��8λ&0 ��8λ&1  0x00FF <=> 0xFF
	printf("%#X\n",x & 0xFF);//0x2B
	//x >> 8 0x1A ��ֹΪ��������λ��1 ��Ҫ& 0  
	printf("%#X\n",x >> 8 & 0xFF);//0x1A
	printf("%d\n",10&15);//10
	printf("%d\n",10|15);//15
	printf("%d\n",10^15);//5
	//~(~0 << n)ʵ�����nλΪ1,����λΪ0��λ����Ϣ
	//x &= ~(1 << m) ������x�ĵ�mλ�ó�0������λ����
	//x |= m ��mΪ1��ÿ��λ����,������x��֮��Ӧ��λ����Ϊ1������λ����
	//x &= ~m ��mΪ1��ÿ��λ����,������x��֮��Ӧ��λ����Ϊ0,����λ����
	printf("%#X\n",~(~0 << 7));//0x7F
	//��ʽ��֤ ~X <=> -X -1 ���ʽ��Ϊ��
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