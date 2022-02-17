#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char arr[20][20];
int cnt[20][20] = { 1, };
int ans = 1;
bool check[20][20] = { false, };
vector<char> apb; // 지나온 칸에 적혀있던 알파벳 집합
int r, c;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y)
{
	check[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < r && 0 <= ny && ny < c && check[nx][ny] == false)
		{
			bool flag = false;
			for (int j = 0; j < apb.size(); j++)
			{
				if (apb[j] == arr[nx][ny])
				{
					flag = true;
					break;
				}
			}
			if (!flag) // 겹치는 알파벳이 없는 경우
			{
				apb.push_back(arr[nx][ny]); // 지나온 알파벳 목록에 새로 추가
				cnt[nx][ny] = cnt[x][y] + 1; // 전 칸에서 길이 1 증가
				ans = max(ans, cnt[nx][ny]);
				dfs(nx, ny);
				apb.pop_back(); // dfs가 끝나면 1칸 후퇴하므로 알파벳 목록에서 빼주고
				check[nx][ny] = false; // check도 false로 변경
			}
		}
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
		}
	}

	apb.push_back(arr[0][0]);
	dfs(0, 0);
	
	cout << ans << endl;
	return 0;
}
