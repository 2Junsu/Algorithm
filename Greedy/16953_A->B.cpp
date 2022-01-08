#include<iostream>
using namespace std;
int a, b;
int cnt = 1;
int main()
{
	cin >> a >> b;

	while (b > a)
	{
		int tmp = b / 10;
		if (b - tmp * 10 == 1) //끝자리가 1인 경우
			b /= 10;
		else
		{
			if (b % 2 == 1) //A->B로 갈 때 2를 곱하거나 1을 추가하므로 짝수이거나 일의 자리가 1인 수만 가능
				break;
			b /= 2;
		}
		cnt++;
	}
	if (a == b)
		cout << cnt << endl;
	else
		cout << -1 << endl;
	return 0;
}
