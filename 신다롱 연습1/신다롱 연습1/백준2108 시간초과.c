#include<stdio.h>
#include<math.h>

int temp[500001];

int Mod(int arr[], int n)
{
	int list[8002] = { 0, };
	int num, cnt = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		num = arr[i] + 4000;
		list[num]++;
		if (max < list[num])
		{
			max = list[num];
		}
	}
	num = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (list[i] == 0)
			continue;
		else
		{
			if (max == list[i] && cnt == 0)
			{
				num == i - 4000;
				cnt++;
			}
			else if (max == list[i] && cnt == 1)
				return i - 4000;
		}
	}
	return num;
}

void Merge(int* arr, int s, int m, int e)
{
	int l = s;
	int r = m + 1;
	int t = s;
	while (l <= m && r <= e)
	{
		if (arr[l] > arr[r])
			temp[t++] = arr[r++];
		else
			temp[t++] = arr[l++];
	}
	if (l > m)
	{
		while (r <= e)
			temp[t++] = arr[r++];
	}
	else
	{
		while (l <= m)
			temp[t++] = arr[l++];
	}
	for (int i = s; i <= e; i++)
		arr[i] = temp[i];
}

void Merge_Sort(int* arr, int s, int e)
{
	int mid;
	if (s < e)
	{
		mid = (s + e) / 2;
		Merge_Sort(arr, s, mid);
		Merge_Sort(arr, mid + 1, e);
		Merge(arr, s, mid, e);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	int r = 0;
	Merge_Sort(arr, 0, n - 1);
	double sumf = fmod(((double)sum / (double)n), 1);
	if (sumf > 0)
	{
		if (sumf >= 0.5)
			printf("%d\n", sum / n + 1);
		else
			printf("%d\n", sum / n);
	}
	else
	{
		if (sumf >= -0.5)
			printf("%d\n", sum / n);
		else
			printf("%d\n", sum / n - 1);
	}
	int mid = n / 2;
	printf("%d\n", arr[mid]);
	printf("%d\n", Mod(arr, n));
	printf("%d\n", arr[n - 1] - arr[0]);
	free(arr);
	return 0;
}