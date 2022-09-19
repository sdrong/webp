#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 101

typedef struct poly {
	double coef;
	int expon;
}Poly;

Poly arr[MAX];
int avil = 0;

void Print(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		if (i != start)
			printf(" + ");
		if (arr[i].expon == 1)
			printf("%.1lfx", arr[i].coef);
		else if (arr[i].expon == 0)
			printf("%.1lf", arr[i].coef);
		else 
			printf("%.1lfx^%d", arr[i].coef, arr[i].expon);
	}
	printf("\n");
}
void Attach(double coef, int expon)
{
	arr[avil].coef = coef;
	arr[avil].expon = expon;
	avil++;
}

void Innum(int start, int end, int n)
{
	double result = 0;
	for (int i = start; i <= end; i++)
	{
		result += arr[i].coef * pow(n, arr[i].expon);
	}
	printf("%.1lf\n", result);
}

void  Minus(int as, int ae, int bs, int be)
{
	double num;
	while (as <= ae && bs <= be)
	{
		if (arr[as].expon > arr[bs].expon)
		{
			Attach(arr[as].coef, arr[as].expon);
			as++;
		}
		else if (arr[as].expon == arr[bs].expon)
		{
			num = arr[as].coef - arr[bs].coef;
			if (num != 0)
				Attach(num, arr[as].expon);
			as++;
			bs++;
		}
		else
		{
			Attach(-1*arr[bs].coef, arr[bs].expon);
			bs++;
		}
	}
	for (; as <= ae; as++)
	{
		Attach(arr[as].coef, arr[as].expon);
		as++;
	}
	for (; bs <= be; bs++)
	{
		Attach(arr[bs].coef, arr[bs].expon);
		bs++;
	}
}

int main(void)
{
	int as = 0, ae, bs, be, cs, ce;
	int n;
	printf("1번쨰 식을 쓰시오\n");
	printf("식 입력을 종료 하실 꺼면 0 0을 입력\n");
	while (1)
	{
		printf("계수와 차수 입력:");
		scanf("%lf %d", &arr[avil].coef, &arr[avil].expon);
		if (arr[avil].coef == 0 && arr[avil].expon == 0)
			break;
		else if (arr[avil].coef == 0)
			continue;
		avil++;
	}
	ae = avil - 1;
	bs = avil;
	printf("2번째 식을 쓰시오\n");
	printf("식 입력을 종료 하실 꺼면 0 0을 입력\n");
	while (1)
	{
		printf("계수와 차수 입력:");
		scanf("%lf %d", &arr[avil].coef, &arr[avil].expon);

		if (arr[avil].coef == 0 && arr[avil].expon == 0)
			break;
		else if (arr[avil].coef == 0)
			continue;
		avil++;
		
	}
	be = avil - 1;
	cs = avil;
	Print(as, ae);
	Print(bs, be);
	Minus(as, ae, bs, be);
	ce = avil - 1;
	printf("------------------------------------------------------------\n");
	Print(cs, ce);
	while (1)
	{
		int t;
		printf("a에 대입:");
		scanf("%d", &n);
		printf("a(%d)의 값:", n);
		Innum(as, ae, n);
		printf("0을 입력하면 종료:");
		scanf("%d", &t);
		if (t == 0)
			break;
	}
	while (1)
	{
		int t;
		printf("b에 대입:");
		scanf("%d", &n);
		printf("b(%d)의 값:", n);
		Innum(bs, be, n);
		scanf("%d", &t);
		if (t == 0)
			break;
	}
	while (1)
	{
		int t;
		printf("c에 대입:");
		scanf("%d", &n);
		printf("c(%d)의 값:", n);
		Innum(cs, ce, n);
		scanf("%d", &t);
		if (t == 0)
			break;
	}
	return 0;
}

/*
* #include<stdio.h>
#include<stdlib.h>

#define MAX_NUM 100

typedef struct {
	int degree;
	int coef;
}Poly;

Poly arr[MAX_NUM];
int avil = 0;

void Put_num()
{
	printf("0 0을 입력하면 종료합니다.\n");
	while(1)
	{
		printf("차수 계수 순으로 입력:");
		scanf("%d %d", &arr[avil].degree, &arr[avil].coef);
		if (arr[avil].degree == 0 && arr[avil].coef == 0)
		{
			printf("입력종료\n");
			break;
		}
		if(arr[avil].coef!=0)
			avil++;
	}
}

void Print_num(int s, int e)
{
	for (int i = s; i <= e; i++)
	{
		if (i != s && arr[i].coef >= 0)
			printf("+");
		if (arr[i].degree == 0)
			printf("%d", arr[i].coef);
		else printf("%dx^%d", arr[i].coef, arr[i].degree);
	}
	printf("\n");
}

void Minus_num(int as, int ae, int bs, int be)
{
	while (as <= ae && bs <= be)
	{
		if (arr[as].degree > arr[bs].degree)
		{
			arr[avil++] = arr[as++];
		}
		else if (arr[as].degree == arr[bs].degree)
		{
			if (arr[as].coef == arr[bs].coef)
			{
				as++;
				bs++;
			}
			else
			{
				arr[avil] = arr[as++];
				arr[avil++].coef -= arr[bs++].coef;
			}
		}
		else
		{
			arr[avil] = arr[bs++];
			arr[avil++].coef *= -1;
		}
	}
	if (as > ae)
	{
		while (bs <= be)
		{
			arr[avil] = arr[bs++];
			arr[avil++].coef *= -1;
		}
	}
	else
		while (as <= ae)
		{
			arr[avil++] = arr[as++];
		}
}

int power(int x, int y)
{
	int result = 1;
	for (int i = 0; i < y; i++)
	{
		result *= x;
	}
	return result;
}

void Put_x(int s, int e, int n)
{
	int result = 0;
	for (int i = s; i <= e; i++)
	{
		result += arr[i].coef * power(n, arr[i].degree);
	}
	printf("%d\n", result);
}

int main(void)
{
	int as = 0, ae, bs, be, cs, ce;
	Put_num();
	ae = avil-1;
	bs = avil;
	Put_num();
	be = avil - 1;
	cs = avil;
	Minus_num(as, ae, bs, be);
	ce = avil - 1;
	Print_num(as, ae);
	Print_num(bs, be);
	Print_num(cs, ce);
	Put_x(as, ae, 2);
	Put_x(bs, be, 2);
	Put_x(cs, ce, 2);
	return 0;
}
*/
