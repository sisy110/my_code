#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "test.h"
//int g_test = 200;
//extern int g_test;//表示变量在其它地方定义过，这里只是声明
//extern void fun(void);
#define DEBUG
#define QUEEN_NUM 8
int queen[QUEEN_NUM];//存储皇后的位置
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
		int unknown = rand() % 100 + 1;   //100以内的数字
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
//n的阶乘
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
//递归判断回文数
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
//显示皇后的位置
void show()
{
	int i,j;
	//局部静态变量 作用域在当前函数 生命周期却在函数之外
	static int count = 0;
	printf("第%d个解\n",++count);
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
//检测在第y行第x列能否放置皇后
int check(int y, int x)
{
	int i;
	for (i = 0; i < y; i++)
	{
		//之前行的列和当前在同一列 || 当前行数 - 之前的行数 = abs(当前列 - 之前行数的列) [处在一个斜线之上]
		if (queen[i] == x || y - i == abs(x - queen[i]))
			return 0;
	}
	return 1;
}
//在y行来放置皇后
void place(int y)
{
	if (y == 8)
	{
		show();
		return;
	}
	int i;
	for (i = 0; i < QUEEN_NUM; i++) //在y行的每一列上进行试探
	{
		if (check(y, i))
		{
			queen[y] = i;
			place(y+1);//递归下一行的位置
		}
	}
}
int main04(void)
{
	//八皇后问题
	place(0);//从第一行开始放置皇后
	return 0;
}
/*
静态变量只分配一次内存,离开作用域的时候,生存期没有结束。静态变量的生存期是整个程序的执行期
已初始化(初始值不为0)的静态变量存储于数据段中
未初始化(初始值为0)的静态变量存储于BSS段中 零初始化段
*/
void Add(void)
{
	static int i = 10;//静态局部变量 只分配一次内存
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
	//条件编译
	printf("entering main...\n");
#ifdef DEBUG
	printf("debug..\n");
#endif
	printf("exting main...\n");
	return 0;
}
