#include<iostream>
using namespace std;
int main()
{
	long long x, y, tmp;
	int ans = -1;
	int win;

	cin >> x >> y;

	tmp = x - y;
	win = 100 * y / x;

	int start = x, end = 2000000000; //게임 횟수
	while (start <= end)
	{
		long long mid = start + (end - start) / 2;
		long long tmp_win = 100 * (mid - tmp) / mid;
		if (tmp_win != win) //확률이 변했으면 더 작은 값이 있나 왼쪽을 살펴봄
		{
			ans = mid - x; //진행한 게임 횟수 - 최초의 게임 횟수 = 추가로 진행한 게임 횟수
			end = mid - 1;
		}
		else //확률이 안 변했으면 아직 게임을 덜 한 것이므로 오른쪽을 살펴봄
			start = mid + 1;
	}

	cout << ans << "\n";
	return 0;
}
