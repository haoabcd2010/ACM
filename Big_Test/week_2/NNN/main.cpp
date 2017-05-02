#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 1005
int n,m,x,y;
int data[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d",&n,&m);
        scanf("%d%d",&x,&y);
        for (int i=0;i<n;i++)
           for (int j=0;j<m;j++)
                scanf("%d",&data[i][j]);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                dp[i][j]=data[i][j];
                if (j-1>=0)
                    dp[i][j]+=dp[i][j-1];
                if (i-1>=0)
                    dp[i][j]+=dp[i-1][j];
                if (i-1>=0&&j-1>=0)
                    dp[i][j]-=dp[i-1][j-1];
            }
        }

        int ans = 0;
        for (int i=x-1;i<n;i++)
        {
            for (int j=y-1;j<m;j++)
            {
                int res = dp[i][j];
                if (i-x>=0)
                    res -= dp[i-x][j];
                if (j-y>=0)
                    res -= dp[i][j-y];
                if (i-x>=0&&j-y>=0)
                    res += dp[i-x][j-y];
                if (res>ans)
                    ans = res;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
