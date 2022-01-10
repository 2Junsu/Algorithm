#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, x;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	cin >> x;

	sort(v.begin(), v.end());

	int l = 0, r = n - 1; // 양 끝점에서 시작
	int cnt = 0;

	while (l < r)
	{
		int sum = v[l] + v[r];
		if (sum == x) //부분합==x이면 cnt 증가 양쪽의 포인터 당김
		{
			cnt++;
			l++;
			r--;
		}
		else if (sum > x) //부분합이 더 크면 줄여야하므로 r 감소
			r--;
		else //부분합이 더 작으면 늘려야하므로 l 증가
			l++;
	}
	cout << cnt << endl;
	return 0;
}
