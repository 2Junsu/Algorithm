#include<iostream>
#include<queue>
using namespace std;
int S;
bool check[2001][2001] = { false, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S;

	queue<pair<pair<int, int>, int>> q; // 화면에 i개, 클립보드에 j개의 이모티콘이 있다.
	q.push({ {1,0},0 });
	check[1][0] = true;

	while (!q.empty())
	{
		pair<pair<int, int>, int> cur = q.front();
		q.pop();
		int display = cur.first.first;
		int clip = cur.first.second;
		int time = cur.second;
		if (display == S) //조건 만족 시 출력 후 탈출
		{
			cout << time << "\n";
			break;
		}
		if (!check[display + clip][clip] && clip > 0 && display + clip <= 2000) //클립보드에서 붙여넣기
		{
			check[display + clip][clip] = true;
			q.push({ { display + clip,clip }, time + 1 });
		}

		if (!check[display][display] && display <= 2000) //클립보드에 복사
		{
			check[display][display] = true;
			q.push({ {display,display }, time + 1 });
		}

		if (!check[display - 1][clip] && display > 0) //화면에서 하나 삭제
		{
			check[display - 1][clip] = true;
			q.push({ {display - 1,clip},time + 1 });
		}
	}
	return 0;
}
