#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3fll
#define MX 100005
struct Flo
{
    int a,b,t;
    bool operator < (const Flo& b)const
    {
        return t<b.t;
    }
}flw[MX];

int n,m,d;
LL dp[MX][2]; //gun dong buf
int sta[MX];

int main()
{
    while (scanf("%d%d%d",&n,&m,&d)!=EOF)
    {
        for (int i=1;i<=m;i++)
            scanf("%d%d%d",&flw[i].a,&flw[i].b,&flw[i].t);
        sort(flw+1,flw+1+m);

        for (int i=1;i<=n;i++)
            dp[i][1]=flw[1].b-abs(i-flw[1].a);

        for (int j=2;j<=m;j++)
        {
            LL limit =(flw[j].t-flw[j-1].t)*d;
            int l=1,r=1;
            for (int k=1;k<=limit;k++)    //对于 i=1 直接先准备好单调栈
            {
                if (k>n) break;     //这个地方搞得我 debug 很久
                while (l<r&&dp[k][(j+1)&1]>=dp[sta[r-1]][(j+1)&1]) r--;
                sta[r]=k; r++;
            }
            for (int i=1;i<=n;i++)
            {
                while (l<r&&i+limit<=n&&dp[i+limit][(j+1)&1]>=dp[sta[r-1]][(j+1)&1]) r--; //尾部小的出栈
                if (i+limit<=n) //进栈
                {
                    sta[r]=i+limit;
                    r++;
                }
                while (l<r&&abs(i-sta[l])>limit) l++; //取合适的栈底元素
                dp[i][j&1] = dp[sta[l]][(j+1)&1]+flw[j].b-abs(i-flw[j].a);
            }
        }
        LL ans = -INF;
        for (int i=1;i<=n;i++)
            ans = max (ans,dp[i][m&1]);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
30 3 2
27 3 1
11 4 1
11 4 1
*/
