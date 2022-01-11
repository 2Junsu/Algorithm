#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int arr[100][100];
int ans[101] = { 0, }; //비의 양에 따른 안전 영역의 수 저장(0~100)
int check[100][100] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y)
{
	check[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (0 <= newX && newX < N && 0 <= newY && newY < N && check[newX][newY] == 0)
		{
			check[newX][newY] = 1;
			dfs(newX, newY);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int height = 0; height <= 100; height++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] <= height) //물에 잠긴 지점 표시
				{
					check[i][j] = -1;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (check[i][j] == 0) //1번의 dfs가 끝날 때마다 해당 강수량에서의 안전 영역의 개수 1 증가
				{
					dfs(i, j);
					ans[height]++;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				check[i][j] = 0;
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= 100; i++) //각 강수량에서의 안전 영역의 최댓값
	{
		res = max(res, ans[i]);
	}
	cout << res << endl;
	return 0;
}
