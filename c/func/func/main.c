#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "test.h"
//int g_test = 200;
//extern int g_test;//��ʾ�����������ط������������ֻ������
//extern void fun(void);
#define DEBUG
#define QUEEN_NUM 8
int queen[QUEEN_NUM];//�洢�ʺ��λ��
int getnumber()
{
	int n;
	while (1)
	{
		printf("Your guess:");
		if (scanf("%d", &n) != 1 || n < 1 || n > 100)
		{
			printf("Wrong number,need a number 1 - 100\n");
			while (getchar() != '\n');
		}
		else
			break;
	}
	return n;
}
void guess(int number)
{
	int count = 0;
	do
	{
		int guess_number = getnumber();
		if (guess_number > number)
			printf("Too high\n");
		else if (guess_number < number)
			printf("Too low\n");
		else
		{
			printf("Congratulation: you win!\n");
			break;
		}
	} while (++count != 10);
}
int next()
{
	int c;
	printf("Next game?(y/n):");
	while (isspace(c = getchar()));
	if (c == 'y')
		return 1;
	return 0;
}
int main01(void)
{
	srand(time(NULL));
	do
	{
		int unknown = rand() % 100 + 1;   //100���ڵ�����
		printf("%d\n",unknown);
		guess(unknown);
	} while (next());
	return 0;
}
unsigned int factorial2(unsigned int n)
{
	int i;
	int result = 1;
	for (i = n; i > 0; i--)
	{
		result *= i;
	}
	return result;
}
//n�Ľ׳�
unsigned int factorial(unsigned int n)
{
	//if (n == 1) return 1;
	//return n + factorial(n -1);
	int result=0;
	if (n == 0) return 1;
	result = n*factorial(n-1);
	printf("%d\n",result);
	return result;
}
int main02(void)
{
	//printf("factorial2(5)=%u\n", factorial2(5));
	printf("factorial(5)=%u\n", factorial(5));
	return 0;
}
//�ݹ��жϻ�����
int palindrome_r(const char* str, int first, int last)
{
	if (first >= last)
		return 1;
	if (str[first] != str[last])
		return 0;
	return palindrome_r(str, first + 1, last-1);
}
int palindrome(const char* str)
{
	return palindrome_r(str, 0, strlen(str) - 1);
}
int main03(void)
{
	if (palindrome("abcdcba"))
		printf("abcdcba is palindrome\n");
	else
		printf("abcdcba is not palindrome\n");

	if (palindrome("abcd"))
		printf("abcd is palindrome\n");
	else
		printf("abcd is not palindrome\n");

	return 0;
}
//��ʾ�ʺ��λ��
void show()
{
	int i,j;
	//�ֲ���̬���� �������ڵ�ǰ���� ��������ȴ�ں���֮��
	static int count = 0;
	printf("��%d����\n",++count);
	for (i = 0; i < QUEEN_NUM; i++)
	{
		printf("(%d,%d) ",i,queen[i]);
	}
	putchar('\n');
	for (i = 0; i < QUEEN_NUM; i++)
	{
		for (j = 0; j < QUEEN_NUM; j++)
		{
			if (queen[i] == j)
				printf("Q ");
			else
				printf("X ");
		}
		putchar('\n');
	}

}
//����ڵ�y�е�x���ܷ���ûʺ�
int check(int y, int x)
{
	int i;
	for (i = 0; i < y; i++)
	{
		//֮ǰ�е��к͵�ǰ��ͬһ�� || ��ǰ���� - ֮ǰ������ = abs(��ǰ�� - ֮ǰ��������) [����һ��б��֮��]
		if (queen[i] == x || y - i == abs(x - queen[i]))
			return 0;
	}
	return 1;
}
//��y�������ûʺ�
void place(int y)
{
	if (y == 8)
	{
		show();
		return;
	}
	int i;
	for (i = 0; i < QUEEN_NUM; i++) //��y�е�ÿһ���Ͻ�����̽
	{
		if (check(y, i))
		{
			queen[y] = i;
			place(y+1);//�ݹ���һ�е�λ��
		}
	}
}
int main04(void)
{
	//�˻ʺ�����
	place(0);//�ӵ�һ�п�ʼ���ûʺ�
	return 0;
}
/*
��̬����ֻ����һ���ڴ�,�뿪�������ʱ��,������û�н�������̬�����������������������ִ����
�ѳ�ʼ��(��ʼֵ��Ϊ0)�ľ�̬�����洢�����ݶ���
δ��ʼ��(��ʼֵΪ0)�ľ�̬�����洢��BSS���� ���ʼ����
*/
void Add(void)
{
	static int i = 10;//��̬�ֲ����� ֻ����һ���ڴ�
	i++;
	printf("%d\n",i);
}
int main05(void)
{
	Add();//11
	Add();//12
	return 0;
}
/*
void fun(void)
{
printf("hello fun main...\n");
}
*/
int main06(void)
{
	printf("g_test=%d\n", g_test);
	fun();
	return 0;
}
int main(void)
{
	//��������
	printf("entering main...\n");
#ifdef DEBUG
	printf("debug..\n");
#endif
	printf("exting main...\n");
	return 0;
}
