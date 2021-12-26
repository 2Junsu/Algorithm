#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool button[10] = { false }; //true이면 고장난 버튼

bool check(int n)
{
	string s = to_string(n);
	for (int i = 0; i < s.size(); i++)
	{
		if (button[s[i] - 48]) //탐색하는 숫자에 대해 하나라도 고장난 버튼의 숫자이면 false 리턴
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		button[n] = true;
	}

	int ans = abs(N - 100); // +,-버튼만 이용하여 도달하는 경우를 기준으로 잡음
	for (int i = 0; i < 1000000; i++)
	{
		string s = to_string(i);
		if (check(i)) //해당 수에 대해 고장난 버튼이 없으면, 즉 버튼을 눌러서 i에 도달할 수 있으면
			//-> 그 i에서 +,-버튼을 이용하여 N까지 도달하는 경우
		{
			if (ans > (s.size() + abs(N - i)))
				ans = s.size() + abs(N - i);
		}
	}
	cout << ans << endl;
	return 0;
}
