#include<iostream>
using namespace std;
int N, M;
int value[100001];
int sum[100001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> value[i];
		sum[i] = sum[i - 1] + value[i];
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
	return 0;
}
