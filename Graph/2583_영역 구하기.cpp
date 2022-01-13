#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int M, N, K;
int arr[100][100] = { 0 };
bool check[100][100] = { false };
vector<int> v; // 각 영역의 넓이 저장
int cnt = 1; // 각 영역의 넓이를 계산할 임시 변수
int dx[] = { 0,0,1,-1 }; //동서남북
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y)
{
	check[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			if (!check[nx][ny] && !arr[nx][ny]) // check==false이고 arr값이 0일때
			{
				cnt++;
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2 - 1; j++)
		{
			for (int k = y1; k <= y2 - 1; k++)
			{
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!check[i][j] && !arr[i][j])
			{
				dfs(i, j);
				v.push_back(cnt);
				cnt = 1;
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
