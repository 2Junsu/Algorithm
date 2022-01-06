#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int N, K;
	int dp[201][201] = { 0, };
	
	cin >> N >> K;
	for (int i = 0; i <= N; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k] % 1000000000;
				dp[i][j] %= 1000000000;
			}
		}
	}

	cout << dp[K][N] % 1000000000 << "\n";
	return 0;
}
