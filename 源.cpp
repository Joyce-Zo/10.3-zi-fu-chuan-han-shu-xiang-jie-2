#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<assert.h>
			strcmp

		ģ��ʵ��strcmp
int my_strcmp(const char* p1, const char* p2)
{
	assert(p1 && p2); //  ����
	while(*p1 == *p2) // �Ƚ�
	{
		if (*p1 == '\0')
		{				//  ���
			return 0;
		}
		p1++;
		p2++;
	}
	  ���ȣ�����1
	if (*p1 > *p2)		//  ����
		return 1;
	else if (*p1 < *p2)	//  С��
		return -1;

	  ����2
	return (*p1 - *p2);

}
int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "sqwer";			//   �ȽϵĲ��� ����
    һ���ַ��Ƚϣ�  a < s������ < 0����
	const char* p3 = "zbcdef";
	const char* p4 = "zqwer";
    һ���ַ��Ƚϣ�  z > s������ > 0 ������VS����1��-1����������
	const char* p5 = "zabced";
	const char* p6 = "zqwer";
	  �����һ���ַ���ͬ�������Ƚ�
	int ret = strcmp(p1, p2);
	int ret1 = strcmp(p5, p6);
	int ret2 = my_strcmp(p4, p6);
  ��ȫ��ȷ���0
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

			ģ��ʵ��
void my_strncpy(char* p1, const char* p2, int n)
{							//			   n��λ�ֽ�
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
	 ��strcpy�����Խ������
	strncpy(arr1, arr2, 6);
	 strncpy����ָ���ֽ���
	char arr3[10] = "That sky";
	char arr4[] = "good";
	strncpy(arr3, arr4, 6);
	 ��Դ����(5�ֽ�)��Ҫ����Ĵ�С(6)Сʱ���Զ�����Ŀ���ַ���'\0'��ֱ���ﵽ6��

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
	 3 ���ַ�û��\0,�������ú�������Զ�����\0
	strncat(arr1, arr2, 8);
	 8 ���ַ��Ѿ�����arr2������������ֻ�ᵽ5+1(\0)=6���������Զ���2��\0
	printf("%s ", arr1);
	return 0; 
 }