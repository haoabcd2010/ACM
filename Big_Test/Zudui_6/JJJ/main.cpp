#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define MOD 1000000007
#define LL long long
#define MX 100005

LL dp[MX];
LL sum[MX];
LL inv2;
LL inv6;

LL quick(LL a,LL b)
{
    LL ret = 1;
    while (b)
    {
        if (b&1) ret = ret*a%MOD;
        a = a*a%MOD;
        b/=2;
    }
    return ret;
}

void Init()
{
    inv2 = quick(2,MOD-2);
    inv6 = quick(6,MOD-2);
    dp[0]=1,sum[0]=1;
    dp[1]=1,sum[1]=2;
    for (int i=2;i<MX;i++)
    {
        dp[i]=(dp[i-1]*sum[i-2])%MOD;
        dp[i]=(dp[i]+dp[i-1])%MOD;
        dp[i]=(dp[i]+(dp[i-1]*(dp[i-1]-1)%MOD)*inv2%MOD)%MOD;
        sum[i]=(sum[i-1]+dp[i])%MOD;
    }
}

int main()
{
    int n;
    Init();

    while (scanf("%d",&n)&&n)
    {
        if (n%2==0)
        {
            int i = n/2;
            int ans = (dp[i]+dp[i]*(dp[i]-1)/2)%MOD;
            printf("%d\n",ans);
        }
        else
        {
            int i = n/2;

            int ans = (((dp[i]*(dp[i]+1))%MOD*inv2%MOD)*sum[i-1])%MOD;
            ans = (ans + dp[i])%MOD;
            ans = (ans + (dp[i]*(dp[i]-1)%MOD)%MOD)%MOD;
            ans = (ans + dp[i]*(dp[i]-1)%MOD*(dp[i]-2)%MOD*inv6%MOD )%MOD;

            printf("%d\n",ans);
        }
    }
    return 0;
}
