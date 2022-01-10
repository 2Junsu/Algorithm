#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> //abs
using namespace std;
int main()
{
	int N;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());
	
	int start = 0, end = N - 1;
	int mini = 2000000000;
	pair<int, int> ans;
	while (start < end) //가리키는 용액이 겹치면 안 되므로 <=는 쓸 수 없음
	{
		int sum = v[start] + v[end];
		if (mini >= abs(sum))
		{
			mini = abs(sum);
			ans = { v[start],v[end] };
		}

		if (sum < 0) // 최대한 0에 맞춰야하므로 
			start++;
		else if (sum > 0)
			end--;
		else // sum이 0이면 그대로 탈출
			break;
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
