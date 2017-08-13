#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define IN 1
#define OUT 0
#define SWAP(a,b) {a=a^b;b=a^b;a=a^b;}
//#define SWAP(a,b) {a=a+b;b=a-b;a=a-b;}
#define MAX_ROW 2
#define MAX_COL 3
char keywords[32][9] = {
	"auto", "break", "case", "char",
	"const", "continue", "default", "do",
	"double", "else", "enum", "extern",
	"float", "for", "goto", "if",
	"int", "long", "register", "return",
	"short", "signed", "sizeof", "static",
	"struct", "switch", "typedef", "union",
	"unsigned", "void", "volatile", "while"
};
int main01(void)
{
	int i;
	int ary[5] = {1,2,3,4,5};
	printf("size of ary=%d\n", sizeof(ary));//20
	int ary2[5];
	for (i = 0; i < 5; i++)
		printf("%d ",ary2[i]);//未初始化的数组会是随机值-858993460 -858993460 -858993460 -858993460 -858993460
	printf("\n");
	int ary3[5] = {1,2};
	for (i = 0; i < 5; i++)
		printf("%d ",ary3[i]);//1 2 0 0 0
	printf("\n");
	int ary5[] = {1,2,3};
	printf("count of ary5=%d\n",sizeof(ary5)/sizeof(ary5[0]));//获取数组元素个数 3
	printf("ary5[3]=%d\n",ary5[3]);//ary5[3]=-858993460 越界的元素是不确定的
	int ary6[] = {1,2,3};
	printf("ary5=%p\n",ary5);
	printf("ary6=%p\n",ary6);
	//比较两个数组的地址
	if (ary5 == ary6)
		printf("equal\n");
	else
		printf("not equal\n");
	return 0;
}
int main02(void)
{
	int c, i;
	int nwhite = 0;
	int nother = 0;
	int ndigit[10] = { 0 };
	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			ndigit[c - '0']++;
			break;
		case ' ':
		case '\n':
		case '\t':
			nwhite++;
			break;
		default:
			nother++;
			break;

		}
	}
	printf("digits =");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
	return 0;
}
//数组逆置
void reverse(int ary[],int cnt)
{
	//int first, last;
	/*for (first = 0, last = cnt - 1; first < last; first++,last--)
	{
		SWAP(ary[first],ary[last]);
	}*/
	int first = 0;
	int last = cnt - 1;
	while (first < last)
	{
		SWAP(ary[first],ary[last]);
		first++;
		last--;
	}
}
int main03(void)
{
	int ary[] = {1,2,3,4,5,3,9,9,7,900};
	int cnt = sizeof(ary) / sizeof(ary[0]);
	reverse(ary,cnt);
	for (int i = 0; i < cnt; i++)
	{
		printf("ary[%d]=%d\n",i,ary[i]);
	}
	return 0;
}
int main04(void)
{
	printf("size of \"hello\" = %d\n",sizeof("hello"));//6
	printf("strlen of \"hello\" = %d\n",strlen("hello"));//5
	int a[3][4];
	printf("&a[0][0] = %p\n",&a[0][0]);//0025FD80
	printf("a[0]=%p\n",a[0]);//0025FD80
	printf("a=%p\n",a);//0025FD80
	printf("&a[0][4] = %p\n", &a[0][4]);//0030FDB8
	printf("&a[1][0] = %p\n", &a[1][0]);//0030FDB8
	return 0;
}
int main05(void)
{
	int i, j;
	int a[MAX_ROW][MAX_COL] = { {1,2,3}, {4,5,6} };
	int b[MAX_ROW][MAX_COL];
	printf("Source:\n");
	for  (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
			printf("%4d",a[i][j]);
		putchar('\n');
	}
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			b[i][j] = a[i][j];
		}
	}
	printf("Array b:\n");
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
			printf("%4d", b[i][j]);
		putchar('\n');
	}
	return 0;
}
int main(void)
{
	int c;
	int i = 0;
	int state = OUT;
	int pos = 0;
	char word[32];//存储输入的字符串
	int counter[32] = {0};//统计关键字出现的次数
	while ((c = getchar()) != EOF)
	{
		if (isspace(c))
		{
			//0结尾
			state = OUT;
			word[pos] = '\0';
			pos = 0;
			for (i = 0; i < 32; i++)
			{
				if (strcmp(word, keywords[i]) == 0)
				{
					counter[i]++;
					break;
				}
			}
		}
		else if (state == OUT)
		{
			state = IN;
			word[pos++] = c;
		}
		else
			word[pos++] = c;
	}
	for (i = 0; i < 32; i++)
	{
		printf("%-8s:%d\n",keywords[i],counter[i]);
	}
	return 0;
}