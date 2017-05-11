#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define LL long long
#define MX 3005
struct Shop
{
    LL p,v;
    bool operator < (const Shop& b)const
    {
        return p<b.p;
    }
}shop[MX];
LL dp[MX];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
            scanf("%I64d%I64d",&shop[i].p,&shop[i].v);
        sort(shop+1,shop+1+n);
        LL total = 0;
        for (int i=1;i<=n;i++)
            total += shop[i].p - shop[1].p;

        dp[1]=shop[1].v+total;
        for (int i=2;i<=n;i++)
        {
            for (int j=1;j<i;j++)
            {
                if (j==1) dp[i] = dp[j] + shop[i].v - (n-i+1)*(shop[i].p-shop[j].p);
                else dp[i] = min(dp[i],dp[j]+shop[i].v-(n-i+1)*(shop[i].p-shop[j].p));
            }
        }
        LL ans = dp[1];
        for (int i=2;i<=n;i++)
            ans = min(dp[i],ans);
        printf("%I64d\n",ans);
    }
    return 0;
}
