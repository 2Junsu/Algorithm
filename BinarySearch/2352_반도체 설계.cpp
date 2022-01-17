#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> v;
vector<int> ans;

void binarySearch(int n)
{
	int s = 0, e = ans.size() - 1;
	int mid, idx;
	while (s <= e)
	{
		mid = s + (e - s) / 2;
		if (ans[mid] > n)
		{
			idx = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}

	ans[idx] = n;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	ans.push_back(v[0]);
	for (int i = 1; i < n; i++)
	{
		if (v[i] > ans.back())
			ans.push_back(v[i]);
		else
		{
			binarySearch(v[i]);
		}
	}

	cout << ans.size() << endl;
	return 0;
}
