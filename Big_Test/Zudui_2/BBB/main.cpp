#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MEM 0x3f
#define MX 15
#define LL long long

int n,m;
LL ans;
int xx[MX][MX];
int lie[MX];
int J[MX];
int dp[MX][MX]; // dp[i][j] 第 i 题 放 j 位置可以有多少解

LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}

LL Jie(int x)
{
    LL res=1;
    for (int i=2;i<=x;i++)
        res*=i;
    return res;
}

void dfs(int x,int kk)
{
    if (kk>=m)
    {
        ans += J[n+1-x];
        return;
    }
    if (x>n) return;

    for(int i=1;i<=n;i++)
    {
        if (!lie[i])
        {
            lie[i]=1;
            dfs(x+1,kk+xx[x][i]);
            lie[i]=0;
        }
    }
}

int main()
{
    for (int i=0;i<MX;i++)
        J[i]=Jie(i);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&xx[i][j]);
        ans = 0;
        memset(lie,0,sizeof(lie));
        memset(dp,-1,sizeof(dp));
        dfs(1,0);
        if (ans==0)
        {
            printf("No solution\n");
            continue;
        }
        int yue = gcd(ans,J[n]);
        LL ansy = J[n]/yue;
        LL ansx = ans/yue;
        printf("%I64d/%I64d\n",ansy,ansx);
    }
    return 0;
}
/*

12 500
31 20 51 64 51 26 7  78 19 91 15 42
24 24 34 42 54 46 23 58 89 10 12 54
14 27 37 42 85 66 73 17 19 10 42 46
10 21 43 14 95 16 75 81 91 10 71 1
45 46 36 71 51 61 7  99 45 12 45 41
81 24 22 44 94 46 45 1  97 46 15 52
54 74 48 42 98 6  71 2  92 12 12 12
51 25 55 64 56 68 9  71 56 51 7  12
21 7  99 4  35 66 1  11 21 51 15 51
14 24 31 41 51 61 71 87 9  10 12 41
84 15 20 55 21 50 14 6  2  64 61 62
15 45 84 62 32 89 11 22 69 45 22 33

*/
