#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define LL long long

LL dp[55][2];

int main ()
{
    int n, p, x;
    scanf("%d%d",&n,&p);
    dp[0][0]=1;
    for (int i=1; i<=n; ++i) {
        scanf("%d",&x);
        if (x&1) dp[i][1]=dp[i-1][0]+dp[i-1][1], dp[i][0]=dp[i-1][1]+dp[i-1][0];
        else dp[i][1]=dp[i-1][1]*2, dp[i][0]=dp[i-1][0]*2;
    }
    printf("%lld\n",dp[n][p]);
    return 0;
}
