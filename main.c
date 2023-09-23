#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//#pragma pack(4)
//struct A
//{
//	int i1;
//	short s;
//	int i2;
//	char c;
//};
//struct B
//{
//	int i1;
//	short s;
//	char c;
//	int i2;
//};
//#pragma pack()
//int main()
//{
//	struct A a = { 0 };
//	struct B b = { 0 };
//	printf("%zd\n", sizeof(a));
//	printf("%zd\n", sizeof(b));
//	return 0;
//}

//#pragma pack(4)
//struct s1
//{
//	short a;
//	char b;
//	long c;
//	long d;
//};
//struct s2
//{
//	long a;
//	short b;
//	char c;
//	long d;
//};
//struct s3
//{
//	short a;
//	long b;
//	char c;
//	long d;
//};
//#pragma pack()
//
//int main()
//{
//	struct s1 ss1 = { 0 };
//	struct s2 ss2 = { 0 };
//	struct s3 ss3 = { 0 };
//	printf("%zd\n", sizeof(ss1));
//	printf("%zd\n", sizeof(ss2));
//	printf("%zd\n", sizeof(ss3));
//	return 0;
//}

//#include<stdlib.h>
//#define A 2
//#define B 3
//#define MAX_SIZE A+B
//struct MyStruct
//{
//	unsigned char id : 4;
//	unsigned char pra : 2;
//	unsigned char sta;
//	unsigned char ava : 1;
//}*p;
//int main()
//{
//	//struct MyStruct* p = (struct MyStruct*)malloc(sizeof(struct MyStruct) * MAX_SIZE);
//	int size = sizeof(struct MyStruct) * MAX_SIZE;
//	printf("%d\n", size);
//	return 0;
//}

//int main()
//{
//	union MyUnion
//	{
//		short s;
//		char b[2];
//	}*p,a;
//	p = &a;
//	p->b[0] = 0x38;
//	p->b[1] = 0x39;
//	printf("%x", a.s);
//	return 0;
//}

//char* getmemery()
//{
//	char p[] = "hello world";
//	return p;
//}
//int main()
//{
//	char* str = NULL;
//	str = getmemery();
//	printf("%s",str);
//	return 0;
//}

//int main()
//{
//	int n = 20;
//	int* const p = &n;
//	//p = &n;
//	*p = 79;
//	printf("%d\n", n);
//	printf("%p\n", &n);
//	return 0;
//}

//模拟实现atoi函数
//#include<ctype.h>
//#include<limits.h>
////#include<stdlib.h>
//enum State
//{
//	INVALUE, //0
//	VALUE    //1
//};
//State = INVALUE;//默认均为非法转换
//int my_atoi(const char* c)
//{
//	int flag = 1;//判断正负号的转换标志
//	// 1.NULL
//	if (NULL == c)
//	{
//		return 0;
//	}
//	// 2.空白字符
//	while (isspace(*c))
//	{
//		c++;
//	}
//	// 3."+/-"符号存在
//	if (*c == '+')
//	{
//		flag = 1;
//		c++;//往后移动
//	}
//	else if (*c == '-')//单引号才行，否则进不去循环
//	{
//		flag = -1;
//		c++;
//	}
//	// 4.纯数字的字符转换
//	long long n = 0;//以防初始值太小
//	while (isdigit(*c))
//	{
//		n = n * 10 + (*c - '0') * flag;
//		//（n * 10 + *c - '0') * flag会报错，由于括号的存在，会先计算n * 10 + *c，然后再减去'0'
//		if (n <= INT_MIN || n >=INT_MAX)
//		{
//			return 0;
//		}
//		c++;
//	}
//	if (*c == '\0')
//	{
//		State = VALUE;
//		return (int)n;
//	}
//	if (isalnum(*c))
//	{
//		State = INVALUE;
//		return (int)n;
//	}
//}
//int main()
//{
//	const char* c = "   +1234";//const在*左边：不改动内容
//	int ret = my_atoi(c);
//	if (ret == 0)
//	{
//		printf("非法转换：%d\n", ret);
//	}
//	else
//	{
//		printf("合法转换：%d\n", ret);
//	}
//	return 0;
//}

//找单身狗
//一个数组中只有两个数字出现一次，其他数字出现了两次。编写一个函数找出这两个只出现一次的数字
//例：在{1 2 3 4 5 6 1 2 3 4}找出5和6
void find_dog(int arr[], int length)
{
	int i = 0;
	int xor_result = 0;
	int tmp = 0;
	int num1 = 0;
	int num2 = 0;
	for ( i = 0; i < length; i++)
	{
		xor_result ^= arr[i];
	}
	for ( i = 0; i < 32; i++)
	{
		if (((xor_result >> i) & 1) == 1)
		{
			tmp = i;
			break;
		}
	}
	for ( i = 0; i < length; i++)
	{
		if (((arr[i] >> tmp) & 1) == 1)
		{
			num1 ^= arr[i];
		}
		else
		{
			num2 ^= arr[i];
		}
	}
	printf("%d %d", num1, num2);

	////方法一
	//int i = 0;
	//int j = 0;
	//int flag = 0;//判断是否存在只出现一次的情况，0不存在，1存在
	//for ( i = 0; i < length ; i++)
	//{
	//	for ( j = 0; j < length; j++)
	//	{
	//		
	//		if (i != j && arr[i] == arr[j])
	//			break;
	//	}
	//	if (j == length)
	//	{
	//		flag = 1;
	//		printf("%d\n", arr[i]);
	//	}
	//}
	//if (0 == flag)
	//{
	//	printf("不存在只出现一次的数字！\n");
	//}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
	int length = sizeof(arr) / sizeof(arr[0]);
	find_dog(arr, length);
	return 0;
}