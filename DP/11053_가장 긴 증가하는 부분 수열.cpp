#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int arr[1001];
	int dp[1001];
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
