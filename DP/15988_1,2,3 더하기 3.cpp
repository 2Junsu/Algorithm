#include<iostream>
using namespace std;
#define mod 1000000009
long long dp[1000001];
int main()
{
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			dp[i] = 0;

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod + dp[i - 3] % mod) % mod;
		}
		cout << dp[n] << "\n";
	}
	return 0;
}
