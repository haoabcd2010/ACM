#include <bits/stdc++.h>
using namespace std;
#define MX 1005
double dp[MX][MX];

void slv(int w,int b)
{
    for (int i=1;i<=w;i++)
    {
        for (int j=0;j<=b;j++)
        {
            double p1=0.0,p2=0.0;
            if(i>=1)
                p1 = (1.0*i)/(i+j);
            if(j>=2)
                p2 = (1.0-p1)*(j-1.0)/(i+j-1);

            double bai = 0.0,hei = 0.0;
            if (i>=1&&j>=2) bai = (i*1.0)/(i+j-2);
            if (j>=3) hei = (j-2.0)/(i+j-2);
            dp[i][j] = p1;
            if (j>=2) dp[i][j]+= p2*bai*dp[i-1][j-2];
            if (j>=3) dp[i][j]+= p2*hei*dp[i][j-3];
        }
    }
}

int main()
{
    int w,b;
    scanf("%d%d",&w,&b);
    slv(w,b);
    printf("%.9f\n",dp[w][b]);
    return 0;
}
