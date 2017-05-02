#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int dp[10000];

int n1,n2,n3;
int main()
{
    while (scanf("%d%d%d",&n1,&n2,&n3)&&(n1||n2||n3))
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for (int i=1;i<=n1;i++)
            dp[i]=1;

        int res =1;
        int t = n2;
        int k=0;
        int bi[40];
        while (t>=res)
        {
            bi[k++]=res;
            t-=res;
            res*=2;
        }
        if (t)
            bi[k++]=t;
        for(int i=0;i<k;i++)
        {
            for (int j=10000;j>=bi[i]*2;j--)
                if (dp[j-bi[i]*2]) dp[j]=1;
        }

        res =1;
        t = n3;
        k=0;
        while (t>=res)
        {
            bi[k++]=res;
            t-=res;
            res*=2;
        }
        if (t)
            bi[k++]=t;
        for(int i=0;i<k;i++)
        {
            for (int j=10000;j>=bi[i]*5;j--)
                if (dp[j-bi[i]*5]) dp[j]=1;
        }

        for (int i=1;i<=10000;i++)
        {
            if (!dp[i])
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
