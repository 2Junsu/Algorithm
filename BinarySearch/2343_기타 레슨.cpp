#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, maxi = 0;
	vector<int> v;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		maxi = max(maxi, a); //블루레이 크기는 아무리 작아도 강의의 최대 길이보단 커야함
	}

	int s = maxi, e = 1000000001;
	int mid, ans;
	while (s <= e)
	{
		mid = s + (e - s) / 2;
		int cumSum = v[0], cnt = 1;

		//강의를 탐색하면서 현재까지의 누적합이 mid 초과이면 그 전에서 끊음
		for (int i = 0; i < N - 1; i++)
		{
			cumSum += v[i + 1];
			if (cumSum > mid)
			{
				cnt++;
				cumSum = v[i + 1];
			}
		}

		if (cnt <= M)
		{
			e = mid - 1;
			ans = mid;
		}
		else
			s = mid + 1;
	}

	cout << ans << "\n";
	return 0;
}
