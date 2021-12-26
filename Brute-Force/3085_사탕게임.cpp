#include<iostream>
#include<algorithm>
using namespace std;

int N;
char arr[50][50];

int check()
{
	int cnt = 0;
	int tmp = 1;

	for (int i = 0; i < N; i++) //가로
	{
		char g = arr[i][0];
		for (int j = 1; j < N; j++)
		{
			if (g == arr[i][j])
				tmp++;
			else //중간에 끊긴 경우, 연속되지 않으므로 현재까지의 카운트 저장 후, 기준을 새로 정하고 다시 시작
			{
				g = arr[i][j];
				tmp = 1;
			}
			cnt = max(cnt, tmp);
		}
		tmp = 1;
	}

	for (int j = 0; j < N; j++) //세로
	{
		char g = arr[0][j];
		for (int i = 1; i < N; i++)
		{
			if (g == arr[i][j])
				tmp++;
			else
			{
				g = arr[i][j];
				tmp = 1;
			}
			cnt = max(cnt, tmp);
		}
		tmp = 1;
	}

	return cnt;
}

int main()
{
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) //가로
	{
		for (int j = 0; j < N - 1; j++)
		{
			swap(arr[i][j], arr[i][j + 1]);
			ans = max(ans, check());
			swap(arr[i][j], arr[i][j + 1]);
		}
	}

	for (int j = 0; j < N; j++) //세로
	{
		for (int i = 0; i < N - 1; i++)
		{
			swap(arr[i][j], arr[i + 1][j]);
			ans = max(ans, check());
			swap(arr[i][j], arr[i + 1][j]);
		}
	}

	cout << ans << endl;
	return 0;
}
