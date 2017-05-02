#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define PI acos(-1.0)
#define lowbit(x) (x&(-x))
#define INF 0x7f7f7f7f      // 21 E
#define MEM 0x7f            // memset 都变为 INF
#define MOD 4999            // 模
#define eps 1e-9            // 精度
#define MX  205         // 数据范围

int read() {    //输入外挂
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
void Out(int a) {    //输出外挂
    if(a < 0) { putchar('-'); a = -a; }
    if(a >= 10) Out(a / 10);
    putchar(a % 10 + '0');
}
// code... ...

int n;
int d[MX];
int e[MX];
int dp[MX][MX];

int main()
{
    int T=read();
    for (int cnt=1;cnt<=T;cnt++)
    {
        n=read();
        for (int i=1;i<=n;i++)
            d[i]=read();
        for (int i=1;i<=n;i++)
            e[i]=read();
        e[0]=0;e[n+1]=0;
        for (int i=1;i<=n;i++)
            dp[i][i]=d[i]+e[i-1]+e[i+1];
        for (int l=2;l<=n;l++)
        {
            for (int i=1;i+l-1<=n;i++)
            {
                int r = i+l-1;
                dp[i][r]=INF;
                for (int k=i;k<r;k++)   //分成两段
                {
                    int tmp = min(e[i-1]-e[k],e[r+1]-e[k+1]);
                    dp[i][r]=min(dp[i][r],dp[i][k]+dp[k+1][r]+tmp);
                }
            }
        }
        printf("Case #%d: %d\n",cnt,dp[1][n]);
    }
    return 0;
}
