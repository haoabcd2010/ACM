#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 50
struct Block
{
    int x,y;
    int h;
}data[MX*6];

int dp[MX*6];

int main()
{
    int n;
    int cnt = 1;
    while (scanf("%d",&n)&&n)
    {
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            data[i*6]=(Block){x,y,z};
            data[i*6-1]=(Block){y,x,z};
            data[i*6-2]=(Block){y,z,x};
            data[i*6-3]=(Block){z,y,x};
            data[i*6-4]=(Block){z,x,y};
            data[i*6-5]=(Block){x,z,y};
        }
        int ok;
        for (int i=1;i<=n*6;i++)
            dp[i]=data[i].h;
        while (1)
        {
            ok=0;
            for (int i=1;i<=n*6;i++)
            {
                for (int j=1;j<=n*6;j++)
                {
                    if ((data[i].x<data[j].x&&data[i].y<data[j].y))
                    {
                        if (dp[i]<dp[j]+data[i].h)
                        {
                            ok=1;
                            dp[i]=dp[j]+data[i].h;
                        }
                    }
                }
            }
            if (ok==0)
                break;
        }
        int ans = 0;
        for (int i=1;i<=n*6;i++)
            ans = max(ans,dp[i]);
        printf("Case %d: maximum height = %d\n",cnt++,ans);
    }
    return 0;
}

