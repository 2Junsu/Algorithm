#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int arr[10001];
	int dp[10001];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++)
	{
		// i번째 포도주 마실 경우 -> (i번째 + i-1번째) + i-3번째까지의 최댓값 vs i번째 + i-2번째까지의 최댓값
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);

		// i번째 포도주 안 마실 경우 -> i-1번째까지의 최댓값과 비교
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n] << endl;

	return 0;
}
