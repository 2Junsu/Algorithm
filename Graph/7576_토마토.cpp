#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int M, N;
int arr[1000][1000];
bool check[1000][1000] = { false, };
int day[1000][1000];
vector<pair<int, int>> v; //처음 상태에서 토마토가 존재하는 칸의 좌표 저장
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs()
{
	for (int i = 0; i < v.size(); i++) //v에 있던 좌표들을 처음부터 큐에 넣고 시작(bfs)
	{
		q.push({ v[i].first,v[i].second });
		check[v[i].first][v[i].second] = true;
	}

	while (!q.empty())
	{
		pair<int, int> cur = { q.front().first,q.front().second };
		q.pop();
		for (int idx = 0; idx < 4; idx++) //현재 탐색 중인 좌표의 동서남북 탐색
		{
			int newX = cur.first + dx[idx];
			int newY = cur.second + dy[idx];
			if (0 <= newX && newX < N && 0 <= newY && newY < M
				&& arr[newX][newY] == 0 && check[newX][newY] == false)
			{
				q.push({ newX,newY });
				check[newX][newY] = true;
				arr[newX][newY] = 1;
				day[newX][newY] = day[cur.first][cur.second] + 1; //이전 칸에 의해 익혀졌으므로 1일 추가
			}
		}
	}
}

int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];

			//토마토가 동시다발적으로 익으므로 처음 상태에서 토마토가 존재하는 칸을 확인함
			if (arr[i][j] == 1)
			{
				day[i][j] = 0; //토마토가 존재하는 각 칸에서 0일부터 시작함
				v.push_back({ i,j });
			}
		}
	}

	// 모든 토마토가 익어있는 경우 0 출력
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
				cnt++;
		}
	}
	if (cnt == N * M)
	{
		cout << 0 << endl;
		return 0;
	}

	bfs();

	// 토마토가 모두 익지는 못하는 상황이면 -1 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}

	//모든 토마토가 익었을 때 날짜 출력
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ans = max(ans, day[i][j]);
		}
	}

	cout << ans << endl;
	return 0;
}
