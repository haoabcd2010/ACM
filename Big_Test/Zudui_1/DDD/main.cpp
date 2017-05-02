#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define INF 0x3fffffff
#define MX  205

int n;
int d[MX];
int e[MX];
int dp[MX][MX];

int main()
{
    int T;
    cin>>T;
    for (int cnt=1;cnt<=T;cnt++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&e[i]);
        e[0]=0;e[n+1]=0;
        for (int i=1;i<=n;i++)
            dp[i][i]=d[i]+e[i-1]+e[i+1];
        for (int l=2;l<=n;l++)  //长度
        {
            for (int i=1;i+l-1<=n;i++)
            {
                int r = i+l-1;
                dp[i][r]=INF;
                for (int k=i;k<=r;k++)   //枚举最后要杀的狼
                    dp[i][r]=min(dp[i][r],dp[i][k-1]+dp[k+1][r]+d[k]+e[i-1]+e[r+1]);
                //对于例如访问到 dp [i][i-1] 时，必定是 0 ，所以不必处理越界情况
            }
        }
        printf("Case #%d: %d\n",cnt,dp[1][n]);
    }
    return 0;
}
