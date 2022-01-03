#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int M, N;
char arr[101][101];
int cnt[101][101] = { 0, };
bool check[101][101] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs()
{
	deque<pair<int, int>> dq;
	dq.push_back({ 1,1 });
	check[1][1] = true;
	while (!dq.empty())
	{
		pair<int, int> cur = dq.front();
		dq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (1 <= nx && nx <= N && 1 <= ny && ny <= M && check[nx][ny] == false)
			{
				if (arr[nx][ny] == '0')
				{
					cnt[nx][ny] = cnt[cur.first][cur.second];
					dq.push_front({ nx,ny }); // 벽이 없는 칸을 우선적으로 탐색
				}
				else
				{
					cnt[nx][ny] = cnt[cur.first][cur.second] + 1;
					dq.push_back({ nx,ny });
				}
				check[nx][ny] = true;
				if (nx == N && ny == M) // (N,M)에 도달하면 탐색 종료
					return;
			}
		}
	}
}

int main()
{
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	bfs();
	cout << cnt[N][M] << endl;
	return 0;
}
