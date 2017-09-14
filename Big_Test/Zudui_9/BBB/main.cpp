#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define LL long long
#define MX 200005

int n;
LL dp[MX];
LL die[MX];
LL a[MX];
LL b[MX];

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        memset(die,0,sizeof(die));
        for (int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i],&b[i]);
            die[i]+=die[i-1]+b[i];
        }
        dp[1]=a[1];
        for (int i=2;i<=n;i++)
        {
            LL xxx = dp[i-1];
            if (dp[i-1]-die[i-1]<a[i])
                xxx+=a[i]-(dp[i-1]-die[i-1]);
            LL yyy = a[i];
            if (a[i]-b[i]<dp[i-1])
                yyy+=dp[i-1]-(a[i]-b[i]);
            dp[i]=min(xxx,yyy);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
