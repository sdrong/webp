#include<stdio.h>

typedef struct element {
	int col;
	int row;
	int value;
}Ele;

typedef struct Sparse_Matrix {
	Ele data[101];
	int cols;
	int rows;
	int term;
}Sparse;

Sparse Change(int arr[][10], int r, int c)
{
	Sparse result;
	result.rows = r;
	result.cols = c;
	int t = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ((arr[i][j]) != 0)
			{
				result.data[t].col = j;
				result.data[t].row = i;
				result.data[t].value = arr[i][j];
				t++;
			}
		}
	}
	result.term = t;
	return result;
}

void Print(Sparse S)
{
	int t = 0;
	for (int i = 0; i < S.rows; i++)
	{
		for (int j = 0; j < S.cols; j++)
		{
			if (S.data[t].col == j && S.data[t].row == i)
			{
				if (S.data[t].value >= 0)
				{
					printf("%3d", S.data[t++].value);
				}
				else
				{
					printf(" %d", S.data[t++].value);
				}
			}
			else
				printf("  0");
		}
		printf("\n");
	}
}

void Print2(Sparse n)
{
	for (int i = 0; i < n.term; i++)
	{
		printf("%d, %d, %d\n", n.data[i].row, n.data[i].col, n.data[i].value);
	}
}

Sparse Add(Sparse As, Sparse Bs)
{
	Sparse sum;
	sum.cols = As.cols;
	sum.rows = As.rows;
	int t = 0;
	int At = 0;
	int Bt = 0;
	while (At < As.term && Bt < Bs.term)
	{
		if ((As.data[At].row == Bs.data[Bt].row))
		{
			if ((As.data[At].col == Bs.data[Bt].col))
			{
				if (As.data[At].value + Bs.data[Bt].value == 0)
				{
					At++;
					Bt++;
				}
				else {
					sum.data[t] = As.data[At++];
					sum.data[t++].value += Bs.data[Bt++].value;
				}
			}
			else if (As.data[At].col < Bs.data[Bt].col)
			{
				sum.data[t++] = As.data[At++];
			}
			else
			{
				sum.data[t++] = Bs.data[Bt++];
			}
		}
		else if (As.data[At].row < Bs.data[Bt].row)
		{
			sum.data[t++] = As.data[At++];
		}
		else
		{
			sum.data[t++] = Bs.data[Bt++];
		}
	}
	if (Bt >= Bs.term)
	{
		while (At < As.term)
		{  
			sum.data[t++] = As.data[At++];
		}
	}
	else
	{ 
		while (Bt < Bs.term)
		{
			sum.data[t++] = Bs.data[Bt++];
		}
	}
	sum.term = t;
	return sum;
}

int main(void)
{
	int a[8][10] = { { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0,-3, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0,-1, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };


	int b[8][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0,-1, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 } };



	int c[8][10] = { { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },

							 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0, 0, 0, 4, 0, 0, 0 } };
	
	Sparse as, bs, cs;
	Sparse sab, sac, sbc;
	as = Change(a, 8, 10);
	bs = Change(b, 8, 10);
	cs = Change(c, 8, 10);
	printf("1.a의 결과\n");
	printf("2.b의 결과\n");
	printf("3.c의 결과\n");
	printf("4.a+b의 결과\n");
	printf("5.a+c의 결과\n");
	printf("6.b+c의 결과\n");
	printf("0.종료\n");
	while (1)
	{
		int n;
		printf("입력:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("a의 결과\n");
			printf("=====================================================\n");
			Print(as);
			break;
		case 2:
			printf("b의 결과\n");
			printf("=====================================================\n");
			Print(bs);
			break;
		case 3:
			printf("c의 결과\n");
			printf("=====================================================\n");
			Print(cs);
			break;
		case 4:
			printf("a+b의 결과\n");
			printf("=====================================================\n");
			sab= Add(as, bs);
			Print(sab);
			printf("희소행렬\n");
			Print2(sab);
			break;
		case 5:
			printf("a+c의 결과\n");
			printf("=====================================================\n");
			sac = Add(as, cs);
			Print(sac);
			printf("희소행렬\n");
			Print2(sac);
			break;
		case 6:
			printf("b+c의 결과\n");
			printf("=====================================================\n");
			sbc = Add(bs, cs);
			Print(sbc);
			printf("희소행렬\n");
			Print2(sbc);
			break;
		case 0:
			printf("종료\n");
			break;
		}
		if (n == 0)
		{
			break;
		}
	}
	
	return 0;
}

/*
* #include<stdio.h>
#include<stdlib.h>
#include<String.h>

#define MAX_SIZE 101

typedef struct {
	int row;
	int col;
	int value;
}element;

typedef struct {
	element data[MAX_SIZE];
	int rows;
	int cols;
	int terms;
}Sparse;

Sparse Change(int arr[][10], int r, int c)
{
	Sparse s;
	int t = 0;
	s.cols = c;
	s.rows = r;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j <10; j++)
		{
			if (arr[i][j] != 0)
			{
				s.data[t].col = j;
				s.data[t].row = i;
				s.data[t++].value = arr[i][j];
			}
		}
	}
	s.terms = t;
	return s;
}

void Print_S(Sparse s)
{
	for (int i = 0; i < s.terms; i++)
	{
		printf("(%d %d %d)\n", s.data[i].row, s.data[i].col, s.data[i].value);
	}
	printf("\n");
}

void Print(Sparse s)
{
	int t=0;
	for (int i = 0; i < s.rows; i++)
	{
		for (int j = 0; j < s.cols; j++)
		{
			if (s.data[t].row == i && s.data[t].col == j)
			{
				printf("%2d", s.data[t++].value);
			}
			else printf("%2d", 0);
		}
		printf("\n");
	}
}

void Add_sparse(Sparse n1, Sparse n2)
{
	Sparse result;
	int rt = 0;
	int nt1 = 0;
	int nt2 = 0;
	result.cols = n1.cols;
	result.rows = n1.rows;
	while (nt1 < n1.terms && nt2 < n2.terms)
	{
		if (n1.data[nt1].row > n2.data[nt2].row)
		{
			result.data[rt++] = n2.data[nt2++];
		}
		else if (n1.data[nt1].row == n2.data[nt2].row)
		{
			if (n1.data[nt1].col == n2.data[nt2].col)
			{
				if ((n1.data[nt1].value + n2.data[nt2].value) == 0)
				{
					nt1++;
					nt2++;
					continue;
				}
				else
				{
					result.data[rt] = n1.data[nt1++];
					result.data[rt++].value += n2.data[nt2++].value;
				}
			}
			else if (n1.data[nt1].col < n2.data[nt2].col)
			{
				result.data[rt++] = n1.data[nt1++];
			}
			else
			{
				result.data[rt++] = n2.data[nt2++];
			}
		}
		else
		{
			result.data[rt++] = n1.data[nt1++];
		}
	}
	if (nt1 >= n1.terms)
	{
		while (nt2 < n2.terms)
			result.data[rt++] = n2.data[nt2++];
	}
	else
		while (nt1 < n1.terms)
			result.data[rt++] = n1.data[nt1++];
	result.terms = rt;
	Print_S(result);
	Print(result);
}

int main(void)
{
	int a[8][10] = { { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0,-3, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						 { 0,-1, 0, 0, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	
	int b[8][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0,-1, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

						 { 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 } };

	int c[8][10] = { { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },

							 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

							 { 0, 0, 0, 0, 0, 0, 4, 0, 0, 0 } };
	Sparse Sa = Change(a,8,10);
	Sparse Sb = Change(b,8,10);
	Sparse Sc = Change(c,8,10);
	Print_S(Sa);
	Print_S(Sb);
	Print_S(Sc);
	Add_sparse(Sa, Sb);
	return 0;
}
*/