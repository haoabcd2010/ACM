#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define MX 100005

int n;
LL dp[30][3];

void Init()
{
    dp[0][2]=1;
    for (int i=1;i<=25;i++)
    {
        dp[i][0]=dp[i-1][0]*10+dp[i-1][1];
        dp[i][1]=dp[i-1][2];
        dp[i][2]=dp[i-1][2]*10-dp[i-1][1];
    }
}

LL slove(LL x)
{
    LL a[30],len=0;
    while (x)
    {
        a[++len]=x%10;
        x/=10;
    }
    a[len+1]=0;

    LL ans =0;
    int flag=0;
    for (int i=len;i>0;i--)
    {
        ans+=dp[i-1][0]*a[i];
        if (flag)
            ans+=dp[i-1][2]*a[i];
        if (!flag&&((a[i]==1&&a[i-1]>3)||(a[i]>1)))
            ans+=dp[i-1][1];
        if (a[i]==3&&a[i+1]==1)
            flag=1;
    }
    return ans;
}

int main()
{
    Init();
    int t;
    cin>>t;
    while (t--)
    {
         cin>>n;
         LL l=1,r=1e19;
         LL ans;
         while (l<=r)
         {
             LL mid = (l+r)>>1;
             LL tp = mid-slove(mid+1);
             if (tp>=n)
             {
                 ans = mid;
                 r=mid-1;
             }
             else if (tp<n)
                 l=mid+1;
         }
         cout<<ans<<endl;
    }
    return 0;
}
