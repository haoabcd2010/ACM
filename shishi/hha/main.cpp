#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define  LL long long

LL dp[100][100];

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<=i;j++)
            {
                if (j>0) dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
                else dp[i][0]=dp[i-1][1];
                if (j==1) dp[i][j]+=dp[i-1][0]; // j == 1 是特殊情况 补0,1都行
            }
        }

        for (int i=0;i<=n;i++)
        {
            printf("i:%d",i);
            for (int j=0;j<=n;j++)
            {
                printf("%5lld",dp[i][j]);
            }
            printf("\n");
        }

        LL ans = 0;
        for (int i=0;i<=m;i++)
            ans+=dp[n][i];
        cout<<ans<<endl;
    }
    return 0;
}
