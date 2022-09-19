#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// �ǽ����� 1��
int Chan_num(char* str)
{
	int result = 0;
	int len = strlen(str);
	if (str[0] == '-')
	{
		for (int i = 1; i < len; i++)
		{
			result += (str[i] - '0') * pow(10, len - i - 1);
		}
		result *= -1;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			result += (str[i] - '0') * pow(10, len - i - 1);
		}
	}
	return result;
}

int S1(void)
{
	char str[50];
	printf("���ڸ� �Է��Ͻÿ�:");
	scanf("%s", str);
	printf("%d\n", Chan_num(str));
	return 0;
}

// �ǽ����� 2��
typedef struct dot {
	int x;
	int y;
}Dot;

Dot Far(Dot* arr)
{
	double result[5] = { 0, };
	double big = 0;
	int num = 0;
	for (int i = 0; i < 5; i++)
	{
		result[i] = sqrt((arr[i].x * arr[i].x) + (arr[i].y * arr[i].y));
		printf("x:%d y:%d�� �Ÿ��� %g\n", arr[i].x, arr[i].y, result[i]);
		if (big < result[i])
		{
			big = result[i];
			num = i;
		}
	}
	return arr[num];
}

void S2(void)
{
	Dot arr[5] = { {2, 3},{5, 5},{1, 2}, {3,4},{4, 5} };
	printf("���� �� ��ǥ�� x: %d, y: %d\n", Far(arr));
	return 0;
}

// �ǽ����� 3��
void Month(char birth[][9])
{
	int result[10];
	int birth_num[12] = { 0. };
	char temp[10];
	for (int i = 0; i < 10; i++)
	{
		temp[0] = birth[i][4];
		temp[1] = birth[i][5];
		result[i] = atoi(temp);
		printf("%d\n", result[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		birth_num[result[i] - 1]++;
	}
	for (int i = 0; i < 12; i++)
	{
		printf("%d������ ����: %d�� \n", i + 1, birth_num[i]);
	}
}

void S3(void)
{
	char birth[10][9];
	for (int i = 0; i < 10; i++)
	{
		printf("%d��° ��������� �Է��Ͻÿ�:", i + 1);
		scanf("%s", birth[i]);
	}
	Month(birth);
	return 0;
}
//�ǽ����� 4��

int Repeat(int n1, int n2)
{
	int sum = 0;
	for (int i = n1; i <= n2; i++)
	{
		sum += i;
	}
	return sum;
}

int Cycle(int n1, int n2)
{
	if (n1 > n2)
		return 0;
	else
		return n1 + Cycle(n1 + 1, n2);
}

void S4(void)
{
	int m, n;
	printf("m�� n�� �Է��Ͻÿ�:");
	scanf("%d %d", &m, &n);
	if (m > n)
	{
		printf("m�� n���� ũ�� �ȵ˴ϴ�.");
		return -1;
	}
	printf("�ݺ�����: %d\n", Repeat(m, n));
	printf("��ȯ����: %d\n", Cycle(m, n));
	return 0;
}

//���� �Լ�
int main(void)
{
	int num;
	while (1)
	{
		printf("1. ���ڿ� ���� ���� ��ȯ.\n2. ���� �� ��ǥ ���\n3. ������ ��� �� ���ϱ�\n4. �ݺ����� ��ȯ�������� �� ���ϱ�\n0. ����\n");
		printf("����� �ǽ������� �����ϰڽ��ϱ�:");
		scanf("%d", &num);
		if (num == 1)
			S1();
		else if (num == 2)
			S2();
		else if (num == 3)
			S3();
		else if (num == 4)
			S4();
		else if (num == 0)
		{
			printf("����");
			break;
		}
		else
			printf("1~4���� �Է��ϼ���.\n");
	}
	return 0;
}