#define _CRT_SECURE_NO_WARNINGS
#define IN 1
#define OUT 0
#include <stdio.h>
#include <math.h>
int main01(void)
{
	int grade;
	scanf("%d", &grade);
	if (grade >= 60){
		printf("passed\n");
	}
	return 0;
}
int main02(void)
{
	int year;
	printf("please input year:");
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		printf("%d is a leap year\n", year);
	}
	else
	{
		printf("%d not a leap year\n", year);
	}
	return 0;
}
int main03(void)
{
	int x = 0;
	printf("Enter Choice(1-3):");
	scanf("%d", &x);
	if (x == 1)
		printf("Choice is 1\n");
	else if (x == 2)
		printf("Choice is 2\n");
	else if (x == 3)
		printf("Choice is 3\n");
	else
		printf("Invalid Choice\n");
	return 0;
}
int main04(void)
{
	int x = 0;
	printf("Enter Choice(1-3):");
	scanf("%d", &x);
	switch (x)
	{
	case 1:
		printf("Choice 1\n");
		break;
	case 2:
		printf("Choice 2\n");
		break;
	case 3:
		printf("Choice 3\n");
		break;
	default:
		printf("Invalid Choice\n");
	}
	return 0;
}
int is_prime(int n)
{
	if (n <= 1)
		return 0;
	int i;
	//for (i = 2; i < (int)sqrt(n); ++i)
	for (i = 2; i*i < n; ++i)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
//获取下一个素数
int next_prime(int n)
{
	if (is_prime(n))
		n++;

	if (n % 2 == 0)
	{
		n++;
	}

	for (; !is_prime(n); n += 2);
	return n;
}
int main05(void)
{
	printf("please input a integer:");
	int n;
	scanf("%d", &n);
	if (is_prime(n)){
		printf("%d是一个素数\n", n);
	}
	else{
		printf("%d不是一个素数\n", n);
	}
	printf("%d的下一个素数是%d\n", n, next_prime(n));
	return 0;
}
int main06(void)
{
	//99乘法表
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%d*%d=%d\t", i, j, i*j);
		printf("\n");
	}
	return 0;
}
int main07(void)
{
	int m, n;
	for (n = 6; n <= 20; n += 2)
	{
		for (m = 3; m <= n / 2; m += 2)
		{
			if (is_prime(m) && is_prime(n - m))
				printf("%d=%d+%d\n", n, m, n - m);
		}
	}
	return 0;
}
int main08(void)
{
	int m, n;
	int found;
	for (n = 6; n <= 20; n += 2)
	{
		for (found = 0, m = 3; m < n / 2 && !found; m += 2)
		{
			if (is_prime(m) && is_prime(n - m))
			{
				printf("%d=%d+%d\n", n, m, n - m);
				found = 1;
			}
		}
	}
	return 0;
}
int main09(void)
{
	int counter = 0;
LOOP:
	counter++;
	printf("counter=%d\n", counter);
	if (counter <= 10)
		goto LOOP;
	return 0;
}
int main10(void)
{
	double d1 = 123.45;
	double d2 = 0.00000163;
	printf("d1=%f\n", d1);//d1=123.450000
	printf("d1=%e\n", d1);//d1=1.234500e+002
	printf("d1=%g\n", d1);//d1=123.45    去掉浮点数小数中多余的0
	printf("d2=%f\n", d2);//d2=0.000002
	printf("d2=%e\n", d2);//d2=1.630000e-006
	printf("d2=%g\n", d2);//d2=1.63e-006
	//printf("%p\n",main);
	printf("%p\n", &d1);
	printf("%%\t%p\n", &d1);//%       0017FC20
	printf("###############################\n");
	int n = 10;
	printf("%4d\n", n);//  10
	printf("%04d\n", n);//0010
	printf("[%-4d]\n", n);//[10  ]
	printf("%.2f\n", 123.456);//123.46
	printf("%s\n", "hello world");//hello world
	printf("%.5s\n", "hello world");//hello
	printf("%.*s\n", 5, "hello world");//hello
	printf("%.*s\n", n, "hello world");//hello worl
	int nn;
	char c;
	scanf("%d%c", &nn, &c);
	printf("nn=%d c=%c\n", nn, c);
	scanf("%d#%c", &nn, &c);
	printf("nn=%d c=%c\n", nn, c);
	return 0;
}
int main11(void)
{
	int ch;
	/*ch = getchar();
	printf("ch=%d\n",ch);
	printf("ch=%c\n",ch);*/
	while ((ch = getchar()) != EOF)
		putchar(ch);
	return 0;
}
int main(void)
{
	int c;//存储字符
	int nc = 0;//字符的个数
	int nl = 0;//行数
	int nw = 0;//单词的个数
	int state = OUT;//当前是否在单词内部
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}

	}
	printf("nc=%d,nl=%d,nw=%d\n", nc, nl, nw);
	return 0;
}