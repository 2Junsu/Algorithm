#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	int N;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int start = 0, end = v.size() - 1;
	pair<int, int> ans;
	int mini = 2000000001;

	while (start < end)
	{
		if (mini > abs(v[start] + v[end]))
		{
			mini = abs(v[start] + v[end]);
			ans = { v[start],v[end] };
		}

		if (v[start] + v[end] == 0)
			break;
		else if (v[start] + v[end] < 0)
			start++;
		else
			end--;
	}

	cout << ans.first << " " << ans.second << endl;
	return 0;
}
