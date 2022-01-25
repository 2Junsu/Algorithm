#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int N, K, ans = 999999, cnt = 0;
	bool check[100001] = { false, };
	cin >> N >> K;
	check[N] = true;
	queue<pair<int, int>> q; // 위치, 시간
	q.push({ N,0 });
	while (!q.empty())
	{
		int pos = q.front().first;
		int time = q.front().second;
		q.pop();
		check[pos] = true; // 큐에 넣을 때가 아닌, 나올 때 중복 처리를 해야한다.
		// 이렇게 해야 같은 거리를 가지고 있는 모든 지점에 대해 확인 가능

		if (pos == K)
		{
			ans = min(ans, time);
			if (ans == time)
				cnt++;
			else
				break;
		}

		if (0 < pos && pos <= 100000)
			if (!check[pos - 1])
			{
				q.push({ pos - 1,time + 1 });
			}

		if (0 <= pos && pos < 100000)
			if (!check[pos + 1])
			{
				q.push({ pos + 1,time + 1 });
			}

		if (0 < pos && pos <= 50000)
			if (!check[2 * pos])
			{
				q.push({ 2 * pos,time + 1 });
			}
	}
	cout << ans << endl << cnt << endl;
	return 0;
}
