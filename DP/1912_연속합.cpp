#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int arr[100001];
	int dp[100001];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	int ans = dp[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
	return 0;
}
