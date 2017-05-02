#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int x[1005];
int dp[1005];

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&x[i]);
        for (int i=0;i<n;i++)
        {
            dp[i]=x[i];
            for (int j=i-1;j>=0;j--)
            {
                if (x[i]>x[j])
                    dp[i]=max(dp[i],dp[j]+x[i]);
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
            ans = max (ans,dp[i]);
        printf("%d\n",ans);
    }
	return 0;
}
