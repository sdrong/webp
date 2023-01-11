#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_DEG 101
#define MAX(a,b) a>b ? a:b

typedef struct poly {
	int expon;
	double coef[MAX_DEG];
}Poly;

void Put_num(Poly* num)
{
	int n;
	printf("최대 차수를 입력하시오:");
	scanf("%d", &n);
	num->expon = n;
	for (int i = n; i >= 0; i--)
	{
		printf("차수%d의 계수를 입력하시오:", i);
		scanf("%lf", &num->coef[n - i]);
	}
}
void Print(Poly num)
{
	for (int i = num.expon; i > 1; i--)
	{
		printf("%.1lfx^%d + ", num.coef[num.expon - i], i);
	}
	printf("%.1fx + ", num.coef[num.expon - 1]);
	printf("%.1lf\n", num.coef[num.expon]);
}

void Put_X(Poly num, int x)
{
	double result = 0;
	for (int i = 0; i <= num.expon; i++)
	{
		result += num.coef[i] * pow(x, (num.expon - i));
	}
	printf("%lf\n", result);
}

Poly Minus(Poly a, Poly b)
{
	Poly c;
	int apos = 0, bpos = 0, cpos = 0;
	int degree_a = a.expon;
	int degree_b = b.expon;
	c.expon = MAX(a.expon, b.expon);
	for (int i = 0; i < c.expon; i++)
	{
		if (a.coef[i] - b.coef[i] == 0 && a.expon == b.expon)
		{
			apos++;
			bpos++;
			degree_a--;
			degree_b--;
			c.expon--;
		}
		else
			break;
	}
	while (apos <= a.expon && bpos <= b.expon)
	{
		if (degree_a > degree_b)
		{
			c.coef[cpos++] = a.coef[apos++];
			degree_a--;
		}
		else if (degree_a == degree_b)
		{
			c.coef[cpos++] = a.coef[apos++] - b.coef[bpos++];
			degree_a--;
			degree_b--;
		}
		else
		{
			c.coef[cpos++] = -1 * b.coef[bpos++];
			degree_b--;
		}
	}
	return c;
}

int main(void)
{
	Poly a;
	Poly b;
	Poly c;
	Put_num(&a);
	Put_num(&b);
	c = Minus(a, b);
	Print(a);
	Print(b);
	printf("-----------------------------------------\n");
	Print(c);
	while (1)
	{
		printf("x를 입력하시오:");
		int x;
		scanf("%d", &x);
		printf("A(%d)의 결과:", x);
		Put_X(a, x);
		printf("0을 입력하면 종료:");
		scanf("%d", &x);
		if (x == 0)
			break;
	}
	while (1)
	{
		printf("x를 입력하시오:");
		int x;
		scanf("%d", &x);
		printf("B(%d)의 결과:", x);
		Put_X(b, x);
		printf("0을 입력하면 종료:");
		scanf("%d", &x);
		if (x == 0)
			break;
	}
	while (1)
	{
		printf("x를 입력하시오:");
		int x;
		scanf("%d", &x);
		printf("C(%d)의 결과:", x);
		Put_X(c, x);
		printf("0을 입력하면 종료:");
		scanf("%d", &x);
		if (x == 0)
			break;
	}
	return 0;
}

/*
* #include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 101
#define MAX(a,b) a>b ? a:b
typedef struct {
	int degree;
	int coef[MAX_STACK_SIZE];
}Poly;

void Print_p(Poly p)
{
	for (int i = 0; i < p.degree; i++)
	{
		printf("%dx^%d+", p.coef[i], p.degree - i);
	}
	printf("%d", p.coef[p.degree]);
	printf("\n");
}

Poly MINUS(Poly a, Poly b)
{
	Poly c;
	int apos = 0, bpos = 0, cpos = 0;
	int degree_a = a.degree;
	int degree_b = b.degree;
	c.degree = MAX(a.degree, b.degree);
	for (int i = 0; i <= c.degree; i++)
	{
		if (degree_a == degree_b && a.coef[i] == b.coef[i])
		{
			degree_a--;
			degree_b--;
			apos++;
			bpos++;
			c.degree--;
		}
	}
	while (apos <= a.degree && bpos <= b.degree)
	{
		if (degree_a > degree_b)
		{
			c.coef[cpos++] = a.coef[apos++];
			degree_a--;
		}
		else if (degree_a == degree_b)
		{
			c.coef[cpos] = a.coef[apos++];
			c.coef[cpos++] -= b.coef[bpos++];
			degree_a--;
			degree_b--;
		}
		else
		{
			c.coef[cpos++] = b.coef[bpos++];
			degree_b--;
		}
	}
	return c;
}

int getlen(int x, int y)
{
	int result = 1;
	for (int i = 0; i < y; i++)
	{
		result *= x;
	}
	return result;
}
void Put_x(Poly p, int n)
{
	int result = 0;
	for (int i = 0; i <= p.degree; i++)
	{
		result += p.coef[i]*getlen(n, p.degree - i);
	}
	printf("%d\n", result);
}

int main(void)
{
	Poly p1;
	printf("p1의 최대 차수를 입력하시오:");
	scanf("%d", &p1.degree);
	for (int i = 0; i <= p1.degree; i++)
	{
		printf("%d차수의 계수 입력:", p1.degree - i);
		scanf("%d", &p1.coef[i]);
	}
	Poly p2;
	printf("p2의 최대 차수를 입력하시오:");
	scanf("%d", &p2.degree);
	for (int i = 0; i <= p2.degree; i++)
	{
		printf("%d차수의 계수 입력:", p2.degree - i);
		scanf("%d", &p2.coef[i]);
	}
	Print_p(p1);
	Print_p(p2);
	Poly p3 = MINUS(p1, p2);
	Print_p(p3);
	Put_x(p1, 2);
	Put_x(p2, 2);
	Put_x(p3, 2);
	return 0;
}
*/