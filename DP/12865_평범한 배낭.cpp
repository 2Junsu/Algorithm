#include<iostream>
#include<algorithm>
using namespace std;
int N, K, W, V;
int dp[101][100001] = { 0, };

int main()
{
    
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin>> W >> V;
        for (int j = 1; j <= K; j++)
        {
            // 물건 3개로 무게제한 5일때
            // 1. 물건을 담는 경우, 3번째 물건의 무게가 2이므로 물건 2개로 무게제한 3일때의 가치 최댓값+3번째 물건의 가치 dp[i-1][j-W]+V
            // 2. 물건을 안 담는 경우, 물건 2개로 무게제한 5일때의 가치 최댓값 dp[i-1][j]
            if(j >= W)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V);
            
            // 무게제한보다 현재 물건의 무게가 더 크면, 못 담으므로 안 담았는 경우와 똑같이 생각
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}
