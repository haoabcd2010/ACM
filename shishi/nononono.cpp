#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 1005
double dp[MAXN][MAXN];

void Init()
{
    for (int i=1;i<MAXN;i++)
    {
        for (int j=0;j<MAXN;j++)
        {
            double p1=0,p2=0;
            if (i>=1) p1 = (i*1.0)/(i+j);   //¹«Ö÷Ó®
            if (j>=2) p2 = (1-p1)*(j-1.0)/(i+j-1);   //Áú×¥ºÚ

            double p3 = 0,p4 = 0;
            if (i>=1&&j>=2) p3 = (i*1.0)/(i+j-2);
            if (j>=3) p4 =(j-2.0)/(i+j-2);

            dp[i][j]= p1;
            if (j>=2) dp[i][j]+=p2*p3*dp[i-1][j-2];
            if (j>=3) dp[i][j]+=p2*p4*dp[i][j-3];
        }
    }
}

int main()
{
    Init();
    int w,b;
    scanf("%d%d",&w,&b);
    printf("%.12lf\n",dp[w][b]);
    return 0;
}
