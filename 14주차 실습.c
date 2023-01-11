#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

int dx1[2] = { -1,0 };
int dy1[2] = { 0, -1 };

int dp1[5][5];
int arr1[5][5] = { {2, 3, 4, 1, 2},
{1 , 5, -2 , 4 ,1},
{7,-21, 3 ,11, 6},
{2, 12, 1, 33, 17},
{3, 13, 27, 26, 2} };

int get_max1(int x, int y, int n)
{
	if (x == 0 && y == 0)
		return 0;
	else if (x == 0 && y!= 0)
		return dp1[y - 1][x];
	else if (x != 0 && y == 0)
		return dp1[y][x-1];
	else
		return max(dp1[y][x - 1], dp1[y - 1][x]);
}

void get_dp1(int n)
{
	int x, y;
	x = 0;
	y = 0;
	for (y = 0; y < n; y++)
	{
		for (x = 0; x < n; x++)
		{
			dp1[y][x] = arr1[y][x] + get_max1(x, y, n);
		}
	}
}

void print1_1(int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			printf("%2d ", arr1[y][x]);
		}
		printf("\n");
	}
}

void print1_2(int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			printf("%2d ", dp1[y][x]);
		}
		printf("\n");
	}
}

void s1(void)
{
	get_dp1(5);
	print1_1(5);
	printf("\n");
	print1_2(5);
	return 0;
}

// 2번

int dp2[5][5];
int cnt;
int get_max2(int x, int y)
{
	cnt += 1;
	if (x < 0 || y < 0)
	{
		return 0;
	}
	else
	{
		dp2[y][x] = arr1[y][x] + max(get_max2(x - 1, y), get_max2(x, y - 1));
		return dp2[y][x];
	}
}

void get_dp2(int n)
{
	cnt = 0;

	dp2[n-1][n-1] = arr1[n-1][n-1]+ max(get_max2(n - 2, n-1), get_max2(n-1, n - 2));
	printf("호출 횟수 %d\n", cnt);
}

void print1_2_1(int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			printf("%2d ", dp2[y][x]);
		}
		printf("\n");
	}
}

void s2(void)
{
	get_dp2(5);
	print1_1(5);
	printf("\n");
	print1_2_1(5);
}

//3번

int dx3[3] = { -1, -1,0 };
int dy3[3] = { 0, -1, -1 };

int dp3[5][5];

int get_max3(int x, int y, int n)
{
	int big = 0;
	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx3[i];
		int ny = y + dy3[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			if (big < dp3[ny][nx])
				big = dp3[ny][nx];
		}
	}
	return big;
}

void get_dp3(int n)
{
	int x, y;
	x = 0;
	y = 0;
	for (y = 0; y < n; y++)
	{
		for (x = 0; x < n; x++)
		{
			dp3[y][x] = get_max3(x, y, n) + arr1[y][x];
		}
	}
}

void print3(int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			printf("%2d ", dp3[y][x]);
		}
		printf("\n");
	}
}

void s3(void)
{
	get_dp3(5);
	print1_1(5);
	printf("\n");
	print3(5);
}

//4번
int** dp4;
int** arr4;

int get_max4(int x, int y)
{
	if (x == 0)
	{
		if (y == 3)
			return arr4[0][x] + arr4[2][x];
		else
			return arr4[y][x];
	}
	else {
		if (y == 0)
			return arr4[y][x] + max(dp4[1][x - 1], dp4[2][x - 1]);
		else if (y == 1)
			return arr4[y][x] + max(max(dp4[0][x - 1], dp4[2][x - 1]), dp4[3][x - 1]);
		else if (y == 2)
			return arr4[y][x] + max(dp4[0][x - 1], dp4[1][x - 1]);
		else if (y == 3)
			return arr4[0][x] + arr4[2][x] + dp4[1][x - 1];
	}
}

void print4_1(int n)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3d ", arr4[i][j]);
		}
		printf("\n");
	}
}

void print4_2(int n)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3d ", dp4[i][j]);
		}
		printf("\n");
	}
}

void s4(void)
{
	int n;
	printf("입력:");
	scanf("%d", &n);
	srand(time(NULL));
	dp4 = malloc(sizeof(int) * 4);
	arr4 = malloc(sizeof(int) * 3);
	for (int i = 0; i < 4; i++)
	{
		dp4[i] = malloc(sizeof(int) * n);
	}
	for (int i = 0; i < 3; i++)
	{
		arr4[i] = malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr4[j][i] = rand() % 20;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			dp4[j][i] = get_max4(i, j);
		}
	}
	print4_1(n);
	printf("\n");
	print4_2(n);
	printf("패턴 1일 떄: %d\n", dp4[0][n - 1]);
	printf("패턴 2 일 떄: %d\n", dp4[1][n - 1]);
	printf("패턴 3 일 떄: %d\n", dp4[2][n - 1]);
	printf("패턴 4 일 떄: %d\n", dp4[3][n - 1]);
}

//5번

int* dp5;

void print5(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", dp5[i]);
	}
	printf("\n");
}

void s5(void)
{
	int n;
	printf("n 입력:");
	scanf("%d", &n);
	dp5 = malloc(sizeof(int) * n);
	dp5[0] = 1;
	dp5[1] = 2;
	for (int i = 2; i < n; i++)
	{
		dp5[i] = dp5[i - 1] + dp5[i - 2];
	}
	print5(n);
	return 0;
}

//6번

int* dp6;

void print6(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", dp6[i]);
	}
	printf("\n");
}

void s6(void)
{
	int n;
	printf("n 입력:");
	scanf("%d", &n);
	dp6 = malloc(sizeof(int) * n);
	dp6[0] = 1;
	dp6[1] = 1;
	dp6[2] = 2;
	for (int i = 3; i < n; i++)
	{
		dp6[i] = dp6[i - 1] + dp6[i - 3];
	}
	print6(n);
	return 0;
}

//7번

int dp7[4][31] = { 0, };

void s7(void)
{
	int money[4] = { 0, 10, 50, 80 };
	int smoney[31];
	smoney[0] = 0;
	for (int i = 1; i <= 30; i++)
	{
		smoney[i] = i * 10;
		dp7[1][i] = i;
	}
	for (int s = 1; s < 31; s++)
	{
		for (int m = 2; m < 4; m++)
		{
			if (money[m] > smoney[s])
			{
				dp7[m][s] = dp7[m - 1][s];
			}
			else
			{
				dp7[m][s] = min(dp7[m - 1][s - money[m] / 10] + 1, dp7[m - 1][s]);
			}
		}
		dp7[1][s] = dp7[2][s] = dp7[3][s];
	}
	printf("가격: ");
	for (int j = 1; j <= 30; j++)
	{
		printf("%3d ", smoney[j]);
	}
	printf("\n");
	printf("개수: ");
	for (int j = 1; j <= 30; j++)
	{
		printf("%3d ", dp7[3][j]);
	}
	printf("\n");
}

// 8번

int dp8[4][31] = { 0, };

void s8(void)
{
	int money[4] = { 0,80, 50, 10 };
	int smoney[31];
	smoney[0] = 0;
	for (int i = 1; i <= 30; i++)
	{
		smoney[i] = i * 10;
	}
	for (int s = 1; s < 31; s++)
	{
		int sum = smoney[s];
		for (int i = 1; i < 4; i++)
		{
			int j = 0;
			while ((j + 1) * money[i] <= sum)
			{
				j++;
			}
			dp8[i][s] = j;
			sum -= money[i] * j;
		}
	}
	printf("가격:  ");
	for (int j = 1; j <= 30; j++)
	{
		printf("%3d ", smoney[j]);
	}
	printf("\n");
	printf("80원:  ");
	for (int j = 1; j <= 30; j++)
	{
		printf("%3d ", dp8[1][j]);
	}
	printf("\n");
	printf("50원:  ");
	for (int j = 1; j <= 30; j++)
	{
		printf("%3d ", dp8[2][j]);
	}
	printf("\n");
	printf("10원:  ");
	for (int j = 1; j <= 30; j++)
	{
		printf("%3d ", dp8[3][j]);
	}
	printf("\n");
	printf("총개수:");
	for (int j = 1; j <= 30; j++)
	{
		printf("%3d ", dp8[3][j] + dp8[2][j] + dp8[1][j]);
	}
	printf("\n");
}

int main(void)
{
	
	bool b = true;
	while (b)
	{
		printf("1.가로세로 미로 행렬 최대경로 동적\n");
		printf("2.가로세로 미로 행렬 최대경로 재귀\n");
		printf("3.가로세로대각선 미로 행렬 최대경로 동적\n");
		printf("4.돌 놓기\n");
		printf("5.도미노\n");
		printf("6.계단\n");
		printf("7.우표 동적\n");
		printf("8.우표 그리디\n");
		int n;
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			s1();
			break;
		case 2:
			s2();
			break;
		case 3:
			s3();
			break;
		case 4:
			s4();
			break;
		case 5:
			s5();
			break;
		case 6:
			s6();
			break;
		case 7:
			s7();
			break;
		case 8:
			s8();
			break;
		default:
			b = false;
			break;
		}
	}
	
	return 0;
}
