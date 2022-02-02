#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	int arr[10001]; // 각 카드팩 Pi 가격
	int dp[10001]; // i개의 카드를 사기 위한 최대 비용

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0] = 0;
	dp[1] = arr[1];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			//ex) dp[4] = max(dp[3]+arr[1], dp[2]+arr[2], dp[1]+arr[3], dp[0]+arr[4]);
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
