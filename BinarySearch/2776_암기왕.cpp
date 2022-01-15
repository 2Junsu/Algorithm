#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T, N, M;
vector<int> v1, v2;

int binarySearch(int n)
{
	int l = 0, r = v1.size() - 1;
	int mid;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (v1[mid] < n)
			l = mid + 1;
		else if (v1[mid] > n)
			r = mid - 1;
		else
			return 1;
	}
	return 0;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			v1.push_back(a);
		}

		cin >> M;
		for (int i = 0; i < M; i++)
		{
			int a;
			cin >> a;
			v2.push_back(a);
		}

		sort(v1.begin(), v1.end());
		for (int i = 0; i < M; i++)
		{
			cout << binarySearch(v2[i]) << "\n";
		}

		v1.clear();
		v2.clear();
	}
	return 0;
}
