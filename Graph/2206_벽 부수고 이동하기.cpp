#include<iostream>
#include<queue>
using namespace std;
int N, M;
char arr[2][1001][1001];
bool check[2][1001][1001] = { false };
int cnt[2][1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs()
{
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{1,1} });
	check[0][1][1] = true;
	while (!q.empty())
	{
		pair<int, pair<int, int>> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.second.first + dx[i];
			int ny = cur.second.second + dy[i];
			if (0 < nx && nx <= N && 0 < ny && ny <= M)
			{
				if (cur.first == 0) //벽을 아직 안 부순 경우
				{
					if (arr[0][nx][ny] == '1') //가려는 방향에 벽이 있으면
					{
						//부수고 벽 부순 배열로 넘어감
						if (check[1][nx][ny] == false)
						{
							cnt[1][nx][ny] = cnt[0][cur.second.first][cur.second.second] + 1;
							q.push({ 1,{nx,ny} });
							check[1][nx][ny] = true;
						}
					}
					else
					{
						//벽이 없으면 그냥 갈 수 있음
						if (check[0][nx][ny] == false)
						{
							cnt[0][nx][ny] = cnt[0][cur.second.first][cur.second.second] + 1;
							q.push({ 0,{nx,ny} });
							check[0][nx][ny] = true;
						}
					}
				}
				else //벽 부순 경우
				{
					if (check[1][nx][ny] == false)
					{
						if (arr[1][nx][ny] == '0') //벽이 없는 경우에만 갈 수 있음
						{
							cnt[1][nx][ny] = cnt[1][cur.second.first][cur.second.second] + 1;
							q.push({ 1,{nx,ny} });
							check[1][nx][ny] = true;
						}
					}
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				cnt[i][j][k] = 1;
			}
		}
	}

	if (N != 1 && M != 1)
	{
		cnt[0][N][M] = -1;
		cnt[1][N][M] = -1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[0][i][j];
			arr[1][i][j] = arr[0][i][j];
		}
	}

	bfs();

	int ans;
	ans = min(cnt[1][N][M], cnt[1][N][M]);
	if (ans != -1)
		cout << ans << endl;
	else
		cout << max(cnt[0][N][M], cnt[1][N][M]) << endl;
	return 0;
}
