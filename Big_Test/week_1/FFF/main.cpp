#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define MAXN 1005
const double eps = 1e-8;

struct Pro
{
    double s;
    double r;
    double d;
}p[MAXN][MAXN];

int n,m;
double dp[MAXN][MAXN];

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%lf%lf%lf",&p[i][j].s,&p[i][j].r,&p[i][j].d);
        dp[n][m]=0;
        for (int i=n;i>=1;i--)
        for (int j=m;j>=1;j--)
        {
            if (i==n&&m==j) continue;
            if (1-p[i][j].s<eps) continue;
            dp[i][j]=(p[i][j].r*dp[i][j+1]
                     +p[i][j].d*dp[i+1][j]
                     +2)/(1-p[i][j].s);
        }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}
