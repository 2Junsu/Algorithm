#include<iostream>
using namespace std;

//zero count는 1 0으로 시작하는 피보나치 수열이고
//one count는 1 1로 시작하는 피보나치 수열이다
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int n;
	int one[41], zero[41];
	one[0] = 0;
	one[1] = 1;
	zero[0] = 1;
	zero[1] = 0;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int i = 2; i <= n; i++)
		{
			one[i] = one[i - 1] + one[i - 2];
			zero[i] = zero[i - 1] + zero[i - 2];
		}

		cout << zero[n] << " " << one[n] << "\n";
	}
	return 0;
}
