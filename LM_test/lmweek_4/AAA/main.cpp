#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF (1<<30)
#define MX 105

int x[MX];
int dp[MX][MX];
int sum[MX];

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        scanf("%d",&n);
        sum[0]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&x[i]);
            sum[i] = sum[i-1]+x[i];
        }

        for (int i=1;i<=n;i++) dp[i][i]=0;

        for (int l=2;l<=n;l++)
        {
            for (int j=1;j + l -1<=n;j++)
            {
                int e = j + l-1;
                dp[j][e]=INF;
                for (int k = j;k<e;k++)
                {
                    dp[j][e] = min(dp[j][e],((sum[k]-sum[j-1])%100)*((sum[e]-sum[k])%100) + dp[j][k]+dp[k+1][e]);
                }
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
