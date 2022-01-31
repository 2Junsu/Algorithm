#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s;
	vector<int> v;
	cin >> s;
	//각 자리의 합이 3의 배수이고, 0이 있어야함

	for (int i = 0; i < s.size(); i++)
	{
		int n = s[i] - '0';
		v.push_back(n);
	}

	int sum = 0;
	bool check = false;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		if (v[i] == 0)
			check = true;
	}

	if (sum % 3 == 0 && check == true)
	{
		sort(v.begin(), v.end(), greater<>());
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}
	}
	else
		cout << -1 << endl;
	return 0;
}
