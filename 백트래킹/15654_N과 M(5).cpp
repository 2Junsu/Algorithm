#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, M;
int arr[8];
bool check[10001];
vector<int> v;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < v.size(); i++)
		{
			if (!check[v[i]]) {
				check[v[i]] = true;
				arr[depth] = v[i];
				dfs(depth + 1);
				check[v[i]] = false;
			}
		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	dfs(0);
	return 0;
}
