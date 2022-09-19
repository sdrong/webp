#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// 실습문제 1번
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
	printf("숫자를 입력하시오:");
	scanf("%s", str);
	printf("%d\n", Chan_num(str));
	return 0;
}

// 실습문제 2번
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
		printf("x:%d y:%d의 거리는 %g\n", arr[i].x, arr[i].y, result[i]);
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
	printf("가장 먼 좌표는 x: %d, y: %d\n", Far(arr));
	return 0;
}

// 실습문제 3번
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
		printf("%d월생의 수는: %d명 \n", i + 1, birth_num[i]);
	}
}

void S3(void)
{
	char birth[10][9];
	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 생년월일을 입력하시오:", i + 1);
		scanf("%s", birth[i]);
	}
	Month(birth);
	return 0;
}
//실습문제 4번

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
	printf("m과 n을 입력하시오:");
	scanf("%d %d", &m, &n);
	if (m > n)
	{
		printf("m이 n보다 크면 안됩니다.");
		return -1;
	}
	printf("반복문장: %d\n", Repeat(m, n));
	printf("순환문장: %d\n", Cycle(m, n));
	return 0;
}

//메인 함수
int main(void)
{
	int num;
	while (1)
	{
		printf("1. 문자열 숫자 정수 변환.\n2. 가장 먼 좌표 출력\n3. 생월별 사람 수 구하기\n4. 반복문장 순환문장으로 합 구하기\n0. 종료\n");
		printf("몇번의 실습문제를 실행하겠습니까:");
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
			printf("종료");
			break;
		}
		else
			printf("1~4까지 입력하세요.\n");
	}
	return 0;
}