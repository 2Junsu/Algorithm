#include<iostream>
#include<vector>
using namespace std;
int N, M;
bool check[9] = { false, };
vector<int> v;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
	}

	else {
		for (int i = 1; i <= N; i++)
		{
			if (!check[i]) {
				check[i] = true;
				v.push_back(i);
				dfs(depth + 1);
				v.pop_back();
				check[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	dfs(0);
	return 0;
}
