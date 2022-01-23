#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M;
int f1, f2;
vector<int> v;
vector<pair<int, int>> graph[10001];

bool bfs(int mid)
{
	bool check[10001] = { false, };
	queue<int> q;
	q.push(f1);
	check[f1] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			//방문하지 않은 섬이면서 해당 다리의 최대 중량이 mid 이상이면 그 섬으로 진행 가능
			if (graph[cur][i].second >= mid && !check[graph[cur][i].first])
			{
				q.push(graph[cur][i].first);
				check[graph[cur][i].first] = true;
			}
		}
	}

	return check[f2]; //최종 목적지에 도달했다면 check값이 true이므로 bfs 가능 여부 판별
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
		v.push_back(c);
	}

	cin >> f1 >> f2;

	sort(v.begin(), v.end());
	int s = v[0], e = v[v.size() - 1]; //중량의 최댓값을 구하는 것이므로 s, e 값을 중량으로 설정
	int mid, ans;
	while (s <= e)
	{
		mid = s + (e - s) / 2;
		if (bfs(mid)) //bfs가 가능하다면 해당 무게로 목적지 도달이 가능한 것이므로 무게를 더 늘려봄
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}

	cout << ans << endl;
	return 0;
}
