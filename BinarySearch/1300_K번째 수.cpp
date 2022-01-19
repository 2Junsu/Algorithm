#include<iostream>
#include<algorithm>
using namespace std;
long long N;
int K;

long long check(long long mid)
{
	long long cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		cnt += min(N, mid / i); //i번째 행에서 mid보다 작거나 같은 것의 수는 mid/i (i번째 행은 i의 배수로 이루어짐)

		if (i > mid)
			break;
	}
	return cnt;
}

int main()
{
	cin >> N >> K;
	
	long long l = 1, r = N * N;
	long long ans;
	while (l <= r)
	{
		long long mid = l + (r - l) / 2;
		long long cnt = check(mid); // mid 보다 작거나 같은 것의 수

		if (cnt < K) //K보다 작으면 수가 더 커야함
		{
			l = mid + 1;
		}
		else //K 이상이면 수가 더 작아야 하지만, 존재하지 않을 수도 있으므로 임시 저장
		{
			ans = mid;
			r = mid - 1;
		}
	}

	cout << ans << "\n";
	return 0;
}
