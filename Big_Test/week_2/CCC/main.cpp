#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

double dp[20][100]; // i 次到 j 的概率
double p[10];
double a[10];

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        for (int i=1;i<=6;i++)
            scanf("%lf",&p[i]);
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for (int i=1;i<=6;i++) dp[1][i]=p[i];
        for (int i=2;i<=10;i++)
        {
            for (int j=0;j<=60;j++)
            {
                for (int k=1;k<=6;k++)
                    if (j-k>=0)
                        dp[i][j]+=dp[i-1][j-k]*p[k];
            }
        }
        for(int i=10;i>0;i--)    a[0]+=dp[i][5];  printf("5: %.1lf%%\n",a[0]*100);
        for(int i=10;i>0;i--)    a[1]+=dp[i][12]; printf("12: %.1lf%%\n",a[1]*100);
        for(int i=10;i>0;i--)    a[2]+=dp[i][22]; printf("22: %.1lf%%\n",a[2]*100);
        for(int i=10;i>0;i--)    a[3]+=dp[i][29]; printf("29: %.1lf%%\n",a[3]*100);
        for(int i=10;i>0;i--)    a[4]+=dp[i][33]; printf("33: %.1lf%%\n",a[4]*100);
        for(int i=10;i>0;i--)    a[5]+=dp[i][38]; printf("38: %.1lf%%\n",a[5]*100);
        for(int i=10;i>0;i--)    a[6]+=dp[i][42]; printf("42: %.1lf%%\n",a[6]*100);
        for(int i=10;i>0;i--)    a[7]+=dp[i][46]; printf("46: %.1lf%%\n",a[7]*100);
        for(int i=10;i>0;i--)    a[8]+=dp[i][50]; printf("50: %.1lf%%\n",a[8]*100);
        for(int i=10;i>0;i--)    a[9]+=dp[i][55]; printf("55: %.1lf%%\n",a[9]*100);
        if (T) cout<<endl;
    }
    return 0;
}
