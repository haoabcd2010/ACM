#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 1000005
#define LL long long
const int INF = 1e8;
int m,n;
LL pre[MX];
LL dp[MX];
int num[MX];

int main()
{
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        dp[0]=0;
        memset(pre,0,sizeof(pre));
        LL big = 0;
        for (int i=1;i<=m;i++)
        {
            big = -INF;
            for (int j=i;j<=n;j++)
            {
                dp[j] = max(dp[j-1],pre[j-1])+num[j];
                pre[j-1] = big;
                big = max(big,dp[j]);
            }
        }
        printf("%lld\n",big);
    }
    return 0;
}
