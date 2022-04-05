#include<iostream>
using namespace std;
int N, M;
bool check[9] = { false, };
int arr[9];

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

	else {
		for (int i = 1; i <= N; i++)
		{
			if (depth == 0 || depth > 0 && arr[depth - 1] < i) {
				if (!check[i]) {
					check[i] = true;
					arr[depth] = i;
					dfs(depth + 1);
					check[i] = false;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	dfs(0);

	return 0;
}
