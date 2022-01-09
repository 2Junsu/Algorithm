#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		auto l = lower_bound(v.begin(), v.end(), a); // a보다 크거나 같은 수 중 처음 숫자의 위치
		auto r = upper_bound(v.begin(), v.end(), a); // a보다 큰 수 중 처음 숫자의 위치
		cout << r - l << " ";
	}

	return 0;
}
