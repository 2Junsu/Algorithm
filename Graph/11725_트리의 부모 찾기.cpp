#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> v[100001];
int par[100001];
bool check[100001] = { false, };

void dfs(int start)
{
	check[start] = true;
	for (int i = 0; i < v[start].size(); i++)
	{
		int next = v[start][i];
		if (check[next] == false)
		{
			par[next] = start;
			dfs(next);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++)
	{
		cout << par[i] << "\n";
	}
	return 0;
}
