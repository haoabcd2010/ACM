#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define MX 12

int mp[MX][MX];
int dp[MX][MX][(1<<10)]; // 到 (i,j) 点是 k 状态最少需要的时间

void solve()
{
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            if (i==1&&j==1) continue;
            int t = 1<<mp[i][j];
            for (int k=0;k<(1<<10);k++)
            {
                dp[i][j][k] = min (dp[i][j][k],dp[i-1][j][k]);
                dp[i][j][k] = min (dp[i][j][k],dp[i-1][j][k&~t]);
                dp[i][j][k] = min (dp[i][j][k],dp[i][j-1][k&~t]);
                dp[i][j][k] = min (dp[i][j][k],dp[i][j-1][k]);
                dp[i][j][k]+=mp[i][j];
            }
        }
}

void Init()
{
    memset(dp,0x3f,sizeof(dp));
    dp[1][1][(1<<mp[1][1])] = mp[1][1];
}

int main()
{
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        scanf("%d",&mp[i][j]);

    Init();
    solve();

    printf("%d\n",dp[10][10][1023]);
    return 0;
}
