#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MX 5005
char s[MX];
char t[MX];
int dp[2][MX];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        getchar();
        for(int i=0;i<n;i++)
        {
            s[i]=getchar();
            t[n-1-i]=s[i];
        }
        getchar();
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (s[i-1]==t[j-1])
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                else
                    dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
            }
        }
        printf("%d\n",n-dp[n%2][n]);
    }
}
