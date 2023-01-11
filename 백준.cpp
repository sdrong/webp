#include <iostream>
#include <string.h>
#include<algorithm>
#include<sstream>
#include<math.h>
#include<cctype>
#include<stdbool.h>
#include<vector>
#include<map>
#include<queue>
#include<stdbool.h>

using namespace std;

int arr[1025][1025];
int dp[100001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int cnt;
	cin >> n >> cnt;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < cnt; i++)
	{
		int sum = 0;
		int g1, g2, s1, s2;
		cin >> g1 >> s1 >> g2 >> s2;
		for (int s = s1; s <= s2; s++)
		{
			for (int g = g1; g <= g2; g++)
			{
				sum += arr[s][g];
			}
		}
		cout << sum << "\n";
	}
	
	return 0;
}