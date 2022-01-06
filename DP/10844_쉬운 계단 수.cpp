#include<iostream>
using namespace std;
#define MOD 1000000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	unsigned long long dp[101][10];
	unsigned long long res = 0;
	cin >> N;

	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			if (j == 1) {
				dp[i][j] = (dp[i - 1][7] + dp[i - 1][9]) % MOD;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}

	for (int i = 1; i < 10; i++)
	{
		res += dp[N][i];
	}

	cout << res % MOD << "\n";
	return 0;
}
