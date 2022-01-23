#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;

	int zcnt = 0, ocnt = 0;
	char g = s[0];
	if (g == '1')
		ocnt++;
	else
		zcnt++;

	for (int i = 1; i < s.size(); i++)
	{
		if (g == s[i])
			continue;
		else
		{
			if (s[i] == '1')
				ocnt++;
			else
				zcnt++;
			g = s[i];
		}
	}

	cout << min(ocnt, zcnt) << endl;
	return 0;
}
