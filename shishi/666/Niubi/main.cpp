
#include <bits/stdc++.h>
using namespace std;
#define LL long long

int n,m;
LL dp[105][10][10]; //��Ϊ i �����У�0��1���� j ������1��0���� k ��

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=m;j++)
            {
                for (int k=0;k<=m;k++)
                {
                    dp[i+1][j+1][max(k-1,0)]+=dp[i][j][k];  // ��һ������ 0
                    dp[i+1][max(j-1,0)][k+1]+=dp[i][j][k];  // ��һ������ 1
                }
            }
        }
        LL ans = 0;
        for (int i=0;i<=m;i++)
            for (int j=0;j<=m;j++)
                ans += dp[n][i][j];
        cout<<ans<<endl;
    }
    return 0;
}
