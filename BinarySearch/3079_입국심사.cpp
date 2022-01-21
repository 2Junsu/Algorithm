#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	unsigned long long N, M;
	vector<unsigned long long> v;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		unsigned long long t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	unsigned long long  s = 1, e = 1000000000000000000;
	unsigned long long mid, ans;
	while (s <= e)
	{
		unsigned long long cnt = 0;
		mid = s + (e - s) / 2;

		//현재 시간을 심사가 걸리는 시간으로 나누면 시간 내에 심사를 받을 수 있는 사람의 수를 구할 수 있음
		for (int i = 0; i < v.size(); i++)
		{
			if (cnt >= M)
				break;
			cnt += mid / v[i];
		}

		if (cnt < M)
			s = mid + 1;
		else
		{
			ans = mid;
			e = mid - 1;
		}
	}

	cout << ans << endl;
	return 0;
}
