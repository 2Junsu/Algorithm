#include<iostream>
using namespace std;
int main() {
	int N;
	unsigned long long arr[1001][10];

	for (int i = 0; i < 10; i++) //한 자리수는 0~9까지 각 경우가 1가지씩이다.
		arr[0][i] = 1;

	cin >> N;

	for (int n = 1; n <= N; n++)
		for (int i = 0; i < 10; i++)
			if (i == 0)
				arr[n][i] = 1;
			else
				arr[n][i] = (arr[n][i - 1] + arr[n - 1][i]) % 10007;

	cout << arr[N][9] % 10007 << "\n";
	return 0;
}
