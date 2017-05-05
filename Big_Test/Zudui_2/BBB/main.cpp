#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;
int a[15][15];
int dp[(1<<13)][510];//表示i种状态，获取j的快乐度的方案数
int f[15];
void init(){
    memset(dp,0,sizeof dp);
}
int main(){
    f[0]=1;
    for(int i=1;i<=13;i++){
        f[i]=f[i-1]*i;
    }
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        dp[0][0]=1;
        int tol=(1<<n);
        for(int i=0;i<=tol;i++)
        {//枚举状态
            int tmp=0;
            for(int j=1;j<=n;j++)
            {
                if( ( i&(1<<(j-1)) ) )
                    tmp++;
            }
            for(int j=1;j<=n;j++)
            {
                if(( i&(1<<(j-1)) )==0)
                for(int k=0;k<=m;k++)
                {
                    if(k+a[tmp+1][j]>=m)
                    {
                        dp[i+(1<<(j-1))][m]+=dp[i][k];
                    }
                    else
                    {
                        dp[i+(1<<(j-1))][k+a[tmp+1][j]]+=dp[i][k];
                    }
                }
            }
        }
        if(dp[tol-1][m]==0)
        {
            puts("No solution");
        }
        else
        {
            int res=__gcd(f[n],dp[tol-1][m]);
            printf("%d/%d\n",f[n]/res,dp[tol-1][m]/res);
        }
    }
    return 0;
}
