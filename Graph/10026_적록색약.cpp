#include<iostream>
using namespace std;

int N;
char arr[100][100]; //적록색약 x의 시야
char arr2[100][100]; //적록색약의 시야
bool check[100][100] = { false, };
bool check2[100][100] = { false, };
int cnt = 0, cnt2 = 0; // 적록색약 아닌 사람, 적록색약인 사람
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int i, int j, char color, int flag)
{
	if (flag == 1)
	{
		check[i][j] = true;
		for (int idx = 0; idx < 4; idx++)
		{
			int newX = i + dx[idx];
			int newY = j + dy[idx];
			if (0 <= newX && newX < N && 0 <= newY && newY < N
				&& check[newX][newY] == false && arr[newX][newY] == color)
			{
				dfs(newX, newY, arr[newX][newY], 1);
			}
		}
	}
	else
	{
		check2[i][j] = true;
		for (int idx = 0; idx < 4; idx++)
		{
			int newX = i + dx[idx];
			int newY = j + dy[idx];
			if (0 <= newX && newX < N && 0 <= newY && newY < N
				&& check2[newX][newY] == false && arr2[newX][newY] == color)
			{
				dfs(newX, newY, arr2[newX][newY], 2);
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			//적록색약의 시야는 초록이 빨강과 같게 보이게 설정
			if (arr[i][j] == 'G')
				arr2[i][j] = 'R';
			else
				arr2[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j])
			{
				//적록색약 x의 경우
				dfs(i, j, arr[i][j], 1);
				cnt++;
			}
			if (!check2[i][j])
			{
				//적록색약의 경우
				dfs(i, j, arr2[i][j], 2);
				cnt2++;
			}
		}
	}

	cout << cnt << " " << cnt2 << endl;
	return 0;
}
