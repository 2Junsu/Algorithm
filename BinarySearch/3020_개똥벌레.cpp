#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, H;
vector<int> down; //석순
vector<int> up; //종유석
vector<int> ans;

int main()
{
	cin >> N >> H;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (i % 2 == 0) //석순
			down.push_back(a);
		else //종유석
			up.push_back(H - a);
	}

	sort(down.begin(), down.end());
	sort(up.begin(), up.end());

	for (int i = 1; i <= H; i++)
	{
		auto downPos = lower_bound(down.begin(), down.end(), i); 
		int downDestroySize = down.size() - (downPos - down.begin()); //개똥벌레가 파괴하는 석순의 개수
		auto upPos = lower_bound(up.begin(), up.end(), i);
		int upNotDestroySize = up.size() - (upPos - up.begin()); //개똥벌레가 파괴 안 하는 종유석의 개수
		int upDestroySize = up.size() - upNotDestroySize; //전체에서 위를 빼주면 파괴하는 종유석의 개수
		ans.push_back(downDestroySize + upDestroySize); //둘을 더한 것(파괴하는 총 개수)을 배열에 저장
	}

	sort(ans.begin(), ans.end());
	int cnt = 0;
	int mini = ans[0];
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] == mini)
			cnt++;
	}

	cout << mini << " " << cnt << endl;
	return 0;
}
