#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 100010

int far[MAXN];
double dp[MAXN];

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)&&(n||m))
    {
        memset(far,-1,sizeof(far));
        while (m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            far[x]=y;
        }
        memset(dp,0,sizeof(dp));

        for (int i=n;i>=0;i--)
        {
            if (far[i]==-1)
            {
                for (int j=1;j<=6;j++)
                    dp[i]+=dp[i+j]/6.0;
                dp[i]+=1.0;
                if (i==n) dp[i]=0.0;
            }
            else dp[i]=dp[far[i]];
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
