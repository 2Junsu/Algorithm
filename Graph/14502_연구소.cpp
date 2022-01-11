#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int arr[8][8];
int tmp[8][8];
int N, M;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;

void bfs()
{
	queue<pair<int, int>> q;
	int tmp2[8][8]; //바이러스가 퍼진 후의 상황을 저장할 임시 배열
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmp2[i][j] = tmp[i][j]; //임시 배열을 만들기 위해 tmp 복사
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tmp2[i][j] == 2) //바이러스가 존재하는 좌표 큐에 추가
				q.push({ i,j });
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newX = cur.first + dx[i];
			int newY = cur.second + dy[i];
			if (0 <= newX && newX < N && 0 <= newY && newY < M)
			{
				if (tmp2[newX][newY] == 0) //바이러스가 퍼진 후의 상황을 만들기 위해 바이러스 주변에 벽이 없으면 확산
				{
					q.push({ newX,newY });
					tmp2[newX][newY] = 2;
				}
			}
		}
	}

	//바이러스가 퍼진 후의 상황에서 안전 영역의 최대 크기 갱신
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tmp2[i][j] == 0)
				cnt++;
		}
	}

	ans = max(ans, cnt);
}

void makeWall(int cnt)
{
	if (cnt == 3) //벽이 3개가 만들어지면 그때 bfs 진행
	{
		bfs();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tmp[i][j] == 0) //벽이 없는 곳에 벽을 세움
			{
				tmp[i][j] = 1;
				makeWall(cnt + 1);
				tmp[i][j] = 0; //재귀가 끝나면 다시 벽을 없앰
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				for (int a = 0; a < N; a++)
				{
					for (int b = 0; b < M; b++)
					{
						tmp[a][b] = arr[a][b]; //원래 배열을 건들지 않기 위해 임시 배열에 복사
					}
				}
				tmp[i][j] = 1; // 비어있는 곳에 벽 세움
				makeWall(1); //벽의 수
				tmp[i][j] = 0; //재귀가 끝나면 다시 벽을 없앰
			}
		}
	}

	cout << ans << endl;
	return 0;
}
