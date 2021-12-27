#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N;
char arr[25][25];
bool check[25][25] = { false, };
queue<pair<int, int>> q;
vector<int> v; //각 단지에 포함된 집의 수를 저장할 벡터
int dx[4] = { 0,0,1,-1 }; //행 동서남북
int dy[4] = { 1,-1,0,0 }; //열 동서남북

void bfs(int i, int j)
{
	int cnt = 1; //bfs함수에 들어갈 조건이 애초에 탐색 안 된 '1'이므로 cnt가 1부터 시작해야함
	check[i][j] = true;
	q.push({ i,j });
	while (!q.empty())
	{
		pair<int, int> cur = { q.front().first,q.front().second };
		q.pop();
		for (int idx = 0; idx < 4; idx++)
		{
			int newX = cur.first + dx[idx];
			int newY = cur.second + dy[idx];

			//집이 있지만 아직 탐색되지 않았으면 하나의 단지로 묶음
			if (0 <= newX && newX < N && 0 <= newY && newY < N &&
				arr[newX][newY] == '1' && check[newX][newY] == false)
			{
				q.push({ newX,newY });
				check[newX][newY] = true;
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];


	//전체 탐색하면서 해당 칸이 1이면 거기서 bfs 수행, 끝나면 cnt++하고 다음 칸 탐색
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] == '1' && check[i][j] == false)
				bfs(i, j);


	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;


	return 0;
}
