#include<iostream>
using namespace std;
unsigned long long dp[100001] = { 1, };
int main()
{
	int N;
	cin >> N;

	dp[1] = 3;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 2] % 9901 + (dp[i - 1] * 2) % 9901) % 9901;
	}
	cout << dp[N] % 9901 << endl;
	return 0;
}
