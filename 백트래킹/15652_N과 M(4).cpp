#include<iostream>
using namespace std;
int N, M;
int arr[8];
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
			if (depth == 0 || arr[depth - 1] <= i) {
				arr[depth] = i;
				dfs(depth + 1);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(0);
	return 0;
}
