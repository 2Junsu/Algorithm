// dp[N]=dp[2]xdp[N-2] + 2x(dp[N-4]+dp[N-6]+...+dp[0])
#include<iostream>
using namespace std;
int main()
{
    int N;
    int dp[31];
    cin >> N;
    if(N % 2)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        dp[0] = 1;
        dp[2] = 3;
    
        for (int i = 4; i <= N; i += 2)
        {
            dp[i] = dp[2] * dp[i - 2];
            for (int j = i - 4; j >= 0; j -= 2)
            {
                dp[i] += (2 * dp[j]);
            }
        }
        cout<< dp[N] << endl;
    }
    return 0;
}
