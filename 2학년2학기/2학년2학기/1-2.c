#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void change(int num1, int num2)
{
	char arr[100];
	int i = 0;
	char result[100];
	char temp[2];
	while (num1 > num2)
	{
		if (num1 % num2 >= 10)
		{
			arr[i++] = 'A' + (num1 % num2 - 10);
			num1 /= num2;
		}
		else {
			sprintf(temp, "%d", num1 % num2);
			num1 /= num2;
			arr[i++] = temp[0];
		}
	}
	if (num1 >= 10)
		arr[i] = 'A' + (num1 % num2 - 10);
	else
	{
		sprintf(temp, "%d", num1);
		arr[i] = temp[0];
	}
	int s = 0;
	while (i>=0)
	{
		result[s++] =  arr[i--];
	}
	result[s] = NULL;
	printf("%s", result);
}

void change2(int num1, int num2)
{
	char num;
	if (num1 < num2)
	{
		if (num1 % num2 >= 10)
		{
			printf("%c", 'A' + (num1 % num2 - 10));
		}
		else
			printf("%d", num1 % num2);
	}
	else
	{
		change2(num1 / num2, num2);
		if (num1 % num2 >= 10)
		{
			printf("%c", 'A' + (num1 % num2 - 10));
		}
		else
			printf("%d", num1 % num2);
	}
}

int main(void)
{
	int num1, num2;
	printf("���������Է�: ");
	scanf("%d", &num1);
	printf("�ٲ� ����(2~16) �Է�: ");
	scanf("%d", &num2);
	change2(num1, num2);

	return 0;
}