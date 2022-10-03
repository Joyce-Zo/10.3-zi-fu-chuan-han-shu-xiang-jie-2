#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<assert.h>
			strcmp

		模拟实现strcmp
int my_strcmp(const char* p1, const char* p2)
{
	assert(p1 && p2); //  断言
	while(*p1 == *p2) // 比较
	{
		if (*p1 == '\0')
		{				//  相等
			return 0;
		}
		p1++;
		p2++;
	}
	  不等，代码1
	if (*p1 > *p2)		//  大于
		return 1;
	else if (*p1 < *p2)	//  小于
		return -1;

	  代码2
	return (*p1 - *p2);

}
int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "sqwer";			//   比较的不是 长度
    一对字符比较，  a < s，返回 < 0的数
	const char* p3 = "zbcdef";
	const char* p4 = "zqwer";
    一对字符比较，  z > s，返回 > 0 的数，VS下是1和-1，其他不是
	const char* p5 = "zabced";
	const char* p6 = "zqwer";
	  如果第一对字符相同，则向后比较
	int ret = strcmp(p1, p2);
	int ret1 = strcmp(p5, p6);
	int ret2 = my_strcmp(p4, p6);
  完全相等返回0
	printf("%d ", ret2);
	printf("%d ", ret1);
	if (ret2 > 0)
		printf("666");
	else if (ret2< 0)
		printf("888");
	else
		printf("688");
	return 0;
}

			strncpy 

			模拟实现
void my_strncpy(char* p1, const char* p2, int n)
{							//			   n单位字节
	int s = strlen(p2);
	int num = 0;
	while (num != n)
	{
		if (num < s || num == s)
		{
			*p1 = *p2;
			p1++;
			p2++;
			num++;
		}
		else
		{
			*p1 = '\0';
			num++;
		}
	}
}
int main()
{
	char arr1[10] = "That sky";
	char arr2[] = "Have a good day";
	strcpy(arr1, arr2);
	 用strcpy会出现越界的情况
	strncpy(arr1, arr2, 6);
	 strncpy可以指定字节数
	char arr3[10] = "That sky";
	char arr4[] = "good";
	strncpy(arr3, arr4, 6);
	 当源数组(5字节)比要传输的大小(6)小时，自动补到目标字符串'\0'，直到达到6个

	strncpy(arr3, arr4, 6);
	my_strncpy(arr3, arr4, 6);
	printf("%s ", arr3);
	return 0;
}


			strncat

int main()
{
	char arr1[30] = "hello\0xxxxxxxxxxxx";
	char arr2[] = "world";
	strncat(arr1, arr2, 3);
	 3 个字符没到\0,不过调用函数后会自动补个\0
	strncat(arr1, arr2, 8);
	 8 个字符已经大于arr2的总数，但是只会到5+1(\0)=6个，不会自动补2个\0
	printf("%s ", arr1);
	return 0; 
 }