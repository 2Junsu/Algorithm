#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	vector<int> v;
	cin >> x;

	//2부터 넣기 위함
	v.push_back(0);
	v.push_back(0);

	for (int i = 2; i <= x; i++)
	{
		//i를 1로 만들기 위해 i-1을 1로 만드는 과정에 1을 빼주는 과정 한 번 추가
		v.push_back(v[i - 1] + 1);

		//i가 3으로 나눠떨어지면 i/3을 1로 만드는 과정에 3으로 나누는 과정 한 번 추가
		if (i % 3 == 0)
			v[i] = min(v[i], v[i / 3] + 1);

		//i가 2로 나눠떨어지면 i/2를 1로 만드는 과정에 2로 나누는 과정 한 번 추가
		if (i % 2 == 0)
			v[i] = min(v[i], v[i / 2] + 1);
	}

	cout << v[x] << endl;
	return 0;
}
