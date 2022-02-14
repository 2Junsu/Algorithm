#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<int> v1;
	vector<int> v2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v1.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v2.push_back(a);
	}

	sort(v1.begin(), v1.end(),greater<>());
	sort(v2.begin(), v2.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int data = v1[i] * v2[i];
		ans += data;
	}
	cout << ans << endl;
	return 0;
}
