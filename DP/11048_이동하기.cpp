#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001][1001];
int dp[1001][1001] = { 0 };
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (i < N)
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1][j]);
			if (j < M)
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + arr[i][j + 1]);
			if (i < N && j < M)
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
		}
	}

	cout << dp[N][M] << endl;
	return 0;
}
