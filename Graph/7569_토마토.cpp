#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int M, N, H;
int arr[100][100][100];
int day[100][100][100] = { 0, };
int dx[6] = { 0,0,0,0,1,-1 }; //위, 아래, 동서남북
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };
vector<pair<int, pair<int, int>>> v;

void bfs()
{
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]);
	}

	while (!q.empty())
	{
		int z = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nz && nz < H && 0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (arr[nz][nx][ny] == 0)
				{
					arr[nz][nx][ny] = 1;
					day[nz][nx][ny] = day[z][x][y] + 1;
					q.push({ nz,{nx,ny} });
				}
			}
		}
	}
}

int main()
{
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
					v.push_back({ i,{j,k} });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (arr[i][j][k] == 1 || arr[i][j][k] == -1)
					cnt++;
			}
		}
	}

	if (cnt == H * N * M) //처음부터 모두 익어있는 상황
	{
		cout << 0 << endl;
		return 0;
	}

	bfs();

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (arr[i][j][k] == 0) //모두 익지는 못 하는 상황
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				ans = max(ans, day[i][j][k]);
			}
		}
	}

	cout << ans << endl;
	return 0;
}
