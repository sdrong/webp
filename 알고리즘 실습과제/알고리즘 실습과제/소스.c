#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int n, m;
	int cnt = 0;
	scanf("%d %d", &n, &m);
	char* data[40] = malloc(sizeof(char)* n);
	char data2[40];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", data[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s", data2);
		for (int j = 0; j < n; j++)
		{
			if (strcmp(data[i], data2) == 0)
				cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}