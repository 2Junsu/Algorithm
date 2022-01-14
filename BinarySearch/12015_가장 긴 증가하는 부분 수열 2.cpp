#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int arr[1000001];
vector<int> v;

void binarySearch(int i)
{
	int start = 1, end = v.size() - 1;
	int mid, ret = 1000002;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (v[mid] < i)
		{
			start = mid + 1;
		}
		else
		{
			ret = min(ret, mid); //위치 후보 저장(최대한 작은 인덱스에 넣어야함)
			end = mid - 1;
		}
	}

	v[ret] = i;
}

int main()
{
	v.push_back(-1);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	v.push_back(arr[1]);
	for (int i = 2; i <= N; i++)
	{
		if (v.back() < arr[i]) //탐색하는 수가 오름차순을 만족하면 dp에 넣고 저장하다가
		{
			v.push_back(arr[i]);
		}

		else //아니게 되면 이분탐색으로 오름차순이 되는 적절한 위치를 찾아 해당 수를 넣어줌
		{
			binarySearch(arr[i]);
		}
	}

	cout << v.size() - 1 << endl;
	return 0;
}
