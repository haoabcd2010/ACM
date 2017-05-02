#include <iostream>
#include <stdio.h>
using namespace std;

int gold[105];
double dp[105];

int main()
{
    int t;
    cin>>t;
    for (int cnt=1;cnt<=t;cnt++)
    {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)
            scanf("%d",&gold[i]);
        dp[n]=gold[n];
        for (int i=n-1;i>=1;i--)
        {
            int c = 6;
            if (n-i<6)
                c = n-i;
            dp[i]=gold[i];
            double total=0;
            for (int j=1;j<=c;j++)
                total+=dp[i+j];
            total/=c;
            dp[i]+=total;
        }
        printf("Case %d: %.8f\n",cnt,dp[1]);
    }

    return 0;
}
