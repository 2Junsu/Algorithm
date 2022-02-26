#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int T, n, m;
	vector<int> a, b;
	int A[1001];
	int B[1001];

	cin >> T;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> B[i];
	}

	for (int i = 1; i <= n; i++) //모든 누적합 저장 (1,2) ~ (n,n)
	{
		long long sum = A[i];
		a.push_back(A[i]);
		for (int j = i + 1; j <= n; j++)
		{
			sum += A[j];
			a.push_back(sum);
		}
	}

	for (int i = 1; i <= m; i++) //모든 누적합 저장 (1,2) ~ (n,n)
	{
		int sum = B[i];
		b.push_back(B[i]);
		for (int j = i + 1; j <= m; j++)
		{
			sum += B[j];
			b.push_back(sum);
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long ans = 0;
	// A의 모든 누적합을 보면서 합이 T가 되는 B의 누적합의 수를 계산
	for (int i = 0; i < a.size(); i++)
	{
		int upper = upper_bound(b.begin(), b.end(), T - a[i]) - b.begin();
		int lower = lower_bound(b.begin(), b.end(), T - a[i]) - b.begin();
		ans += upper - lower;
	}

	cout << ans << "\n";
	return 0;
}
