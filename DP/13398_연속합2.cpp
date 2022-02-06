#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[100001];
int dp[100001][2];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i][0] = arr[i];
	}

	int ans = dp[1][0];
	for (int i = 2; i <= n; i++)
	{
		//아무 것도 삭제 안 했을 경우, 기본 연속합 문제처럼 해결
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + arr[i]);

		//자신을 삭제했을 경우 vs 내 앞에서 뭔가가 삭제된 경우(자신은 더해야함) 중 더 큰 값
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
	}

	cout << ans << endl;
	return 0;
}
