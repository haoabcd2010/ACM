#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define MAXN 100005
double dp[MAXN];

void Init()
{
    for (int i=2;i<=100000;i++)
    {
        int yue=2;  //1 ºÍ±¾Éí
        for (int j=2;j*j<=i;j++)
        {
            if (i%j==0)
            {
                if (j*j==i)
                {
                    dp[i]+=dp[j];
                    yue++;
                }
                else
                {
                    dp[i]+=dp[i/j];
                    dp[i]+=dp[j];
                    yue+=2;
                }
            }
        }
        dp[i]+=yue;
        dp[i]/=yue-1;
    }
}

int main()
{
    Init();
    int T;
    cin>>T;
    for (int i=1;i<=T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %.8lf\n",i,dp[n]);
    }
    return 0;
}
