#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = (1<<20)+10;
int n;
double p[25];
double dp[MAXN];

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%lf",&p[i]);

        int mmm = (1<<n)-1;     //二进制为 n 个 1
        dp[mmm]=0;
        for (int i=mmm-1;i>=0;i--)  //所有情况都遍历到
        {
            double all_p=0;
            dp[i]=1;
            for (int j=0;j<n;j++)
            {
                if ( (i&(1<<j))==0 )    //第 j 种卡片没有
                {
                    dp[i]+=p[j]*dp[i+(1<<j)];   //dp [i+(1<<j)] 肯定赋过值了
                    all_p+=p[j];
                }
            }
            dp[i]/=all_p;
        }
        printf("%lf\n",dp[0]);
    }
}




