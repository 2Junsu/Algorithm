#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> v;
vector<int> ans; //오름차순 정렬되어 있음

void binarySearch(int vi)
{
	int l = 0, r = ans.size() - 1;
	int mid, ret;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (ans[mid] < vi)
			l = mid + 1;
		else
		{
			ret = mid;
			r = mid - 1;
		}
	}

	ans[ret] = vi;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	ans.push_back(v[0]);
	for (int i = 1; i < N; i++)
	{
		if (ans.back() < v[i]) // 현재 저장된 가장 큰 값 보다도 v[i]가 크면 정답에 추가
			ans.push_back(v[i]);

		else // 그렇지 않으면 뒤에 추가하지 않고 적절한 위치를 찾아서 사이에 끼워넣음
		{
			binarySearch(v[i]);
		}
	}

	cout << ans.size() << endl;
	return 0;
}
