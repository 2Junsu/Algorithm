#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N, K;
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

		if (pos == K)
		{
			cout << time << endl;
			break;
		}

		if (0 < pos && pos <= 100000)
			if (!check[pos - 1])
			{
				check[pos - 1] = true;
				q.push({ pos - 1,time + 1 });
			}

		if (0 <= pos && pos < 100000)
			if (!check[pos + 1])
			{
				check[pos + 1] = true;
				q.push({ pos + 1,time + 1 });
			}

		if (0 < pos && pos <= 50000)
			if (!check[2 * pos])
			{
				check[2 * pos] = true;
				q.push({ 2 * pos,time + 1 });
			}
	}
	return 0;
}
