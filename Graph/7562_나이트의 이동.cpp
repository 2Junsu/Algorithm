#include<iostream>
#include<queue>
using namespace std;
int T, l;
int arr[300][300];
bool check[300][300];
pair<int, int> now, want;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 }; //시계 방향
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ now.first,now.second });
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int newX = cur.first + dx[i];
			int newY = cur.second + dy[i];
			if (0 <= newX && newX < l && 0 <= newY && newY < l)
			{
				if (check[newX][newY] == false)
				{
					check[newX][newY] = true;
					arr[newX][newY] = arr[cur.first][cur.second] + 1;
					q.push({ newX,newY });
					if (newX == want.first && newY == want.second)
						return;
				}
			}
		}
	}
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> l;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				arr[i][j] = 0;
				check[i][j] = false;
			}
		}

		cin >> now.first >> now.second;
		cin >> want.first >> want.second;
		check[now.first][now.second] = true;
		bfs();
		cout << arr[want.first][want.second] << "\n";
	}
	return 0;
}
