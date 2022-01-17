#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, maxi = 0;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		maxi = max(maxi, a);
	}

	int s = maxi, e = 1000000000;
	int mid, ans;
	while (s <= e)
	{
		mid = s + (e - s) / 2;
		int sum = 0, cnt = 1;

		for (int i = 0; i < v.size() - 1; i++)
		{
			sum += v[i];
			if (sum + v[i + 1] > mid)
			{
				cnt++;
				sum = 0;
			}
		}

		if (cnt <= m)
		{
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}

	cout << ans << "\n";
	return 0;
}
