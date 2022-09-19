#include<stdio.h>
#include<string.h>
//1번

void Check(char* str, int n, int* c)
{
	printf("%c\n", *str);
	if (*str == NULL)
	{
		if (n >= 10)
		{
			for (int i = 0; i < 4; i++)
			{
				if (c[i] == 0)
				{
					printf("조건이 맞지 않습니다\n");
					return 0;
				}
			}
			printf("조건이 맞습니다.\n");
			return 0;
		}
		else
		{
			printf("글자의 개수가 조건에 맞지 않습니다.\n");
			return 0;
		}
	}
	else if (*str >= 'A' && *str <= 'Z')
		c[0]++;
	else if (*str >= 'a' && *str <= 'z')
		c[1]++;
	else if (*str >= '0' && *str <= '9')
		c[2]++;
	else if (*str == '!'|| *str == '?' || *str == '*' || *str == '#' || *str == '$')
		c[3]++;
	else
	{
		printf("적합하지 않은 수가 들어갔습니다.\n");
		return 0;
	}
	n++;
	*str++;
	Check(str, n, c);
}

int S1(void)
{
	char str[101];
	printf("문자열을 입력하시오 대문자,소문자,숫자,특수문자(!,?,*,#,$)를 포함 : ");
	scanf("%s", str);
	printf("%s\n", str);
	int c[4] = { 0, };
	int n = 0;
	Check(str, n, c);
	return 0;
}

//2번
typedef struct complex_number {
	double x;
	double y;
}Cnum;

double Addx(Cnum* arr, int n)
{
	if (n < 0)
		return 0;
	else
	{
		return  arr[n].x + Addx(arr, n - 1);
	}
}
double Addy(Cnum* arr, int n)
{
	if (n < 0)
		return 0;
	else
	{
		return  arr[n].y + Addy(arr, n - 1);
	}
}
int S2(void)
{
	int n;
	printf("몇개할것인가:");
	scanf("%d", &n);
	Cnum* arr = malloc(sizeof(Cnum) * n);
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 실수부와 허수부 입력하시오:", i + 1);
		scanf("%lf %lf", &arr[i].x, &arr[i].y);
	}
	double x;
	double y;
	x = Addx(arr, n - 1);
	y = Addy(arr, n - 1);
	printf("%.1lf + %.1lfi\n", x, y);
	free(arr);
	return 0;
}

//3번
int Slen(char* str)
{
	if (*str == NULL)
	{
		return 0;
	}
	else
	{
		*str++;
		return 1 + Slen(str);
	}
}

int S3(void)
{
	char str[101];
	printf("문자열을 입력하시오:");
	scanf("%s", str);
	int len = Slen(str);
	printf("%d\n", len);
	return 0;
}
//4번
void Cycle(int* arr, int choice, int start, int end, int try)
{
	int mid = (start + end) / 2;
	printf("arr[%d]~arr[%d] 탐색 arr[%d]: %d 시도 %d\n", start, end, mid, arr[mid], try);
	if (start > end)
		return printf("못찾았습니다.\n");
	else if (arr[mid] == choice)
	{
		return printf("arr[%d]에 있습니다. 시도횠수 %d\n", mid, try);
	}
	else if (arr[mid] < choice)
		start = mid + 1;
	else if (arr[mid] > choice)
		end = mid - 1;
	Cycle(arr, choice, start, end, try + 1);
}

int S4(void)
{
	int n;
	printf("몇개의 숫자를 입력할 것인가");
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 숫자를 입력:", i + 1);
		scanf("%d", &arr[i]);
	}
	for (int base = 0; base < n - 1; base++)
	{
		for (int i = base + 1; i < n; i++)
		{
			if (arr[base] > arr[i])
			{
				int temp = arr[base];
				arr[base] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	int start = 0;
	int end = n - 1;
	int try = 1;
	int choice;
	printf("찾을 숫자를 입력하시오:");
	scanf("%d", &choice);
	Cycle(arr, choice, start, end, try);
	free(arr);
	return 0;
}

int main(void)
{
	while (1)
	{
		int u_choice;
		printf("1.실습문제 1번\n");
		printf("2.실습문제 2번\n");
		printf("3.실습문제 3번\n");
		printf("4.실습문제 4번\n");
		printf("0. 종료\n");
		printf("선택하시오:");
		scanf("%d", &u_choice);
		if (u_choice == 1)
			S1();
		else if (u_choice == 2)
			S2();
		else if (u_choice == 3)
			S3();
		else if (u_choice == 4)
			S4();
		else if (u_choice == 0)
			break;
	}
	printf("종료\n");
	return 0;
}