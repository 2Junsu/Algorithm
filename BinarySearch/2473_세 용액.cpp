#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int N;
	vector<long long> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int s, e;
	long long sum, mini = 3000000001;
	vector<long long> ans;

	//용액 하나를 정해놓고 나머지 두 용액은 투 포인터를 이용하여 탐색
	for (int i = 0; i < v.size(); i++)
	{
		s = 0, e = v.size() - 1;
		while (s < e)
		{
			if (s == i)
			{
				s++;
				continue;
			}
			if (e == i)
			{
				e--;
				continue;
			}

			sum = v[s] + v[e] + v[i];
			if (sum == 0)
			{
				ans.clear();
				ans.push_back(v[s]);
				ans.push_back(v[e]);
				ans.push_back(v[i]);
				sort(ans.begin(), ans.end());
				for (int j = 0; j < ans.size(); j++)
					cout << ans[j] << " ";
				return 0;
			}
			else
			{
				if (abs(sum) < mini)
				{
					mini = abs(sum);
					ans.clear();
					ans.push_back(v[s]);
					ans.push_back(v[e]);
					ans.push_back(v[i]);
				}

				if (sum > 0)
					e--;
				else
					s++;
			}
		}
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
