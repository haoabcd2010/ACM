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
#define MX  10         // 数据范围

int read() {    //输入外挂
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
// code... ...
int n,m,k;
int ok;
int color[MX*MX];
int num[MX][MX];

void dfs(int x,int y)
{
    if (x>n) ok=1;
    for (int i=1;i<=k;i++)
    {
        int remain = n*m-((x-1)*m+y-1)+1;
        if (color[i]>remain/2) return;
    }
    for (int i=1;i<=k;i++)
    {
        if (color[i]>0&&num[x-1][y]!=i&&num[x][y-1]!=i)
        {
            num[x][y]=i;
            color[i]--;
            if (y==m) dfs(x+1,1);
            else dfs(x,y+1);
            color[i]++;
            if (ok) return;
        }
    }
}

int main()
{
    int T=read();
    for (int cnt=1;cnt<=T;cnt++)
    {
        n=read();m=read();k=read();
        for (int i=1;i<=k;i++)
            color[i]=read();
        ok = 0;
        memset(num,0,sizeof(num));
        dfs(1,1);
        printf("Case #%d:\n",cnt);
        if (ok)
        {
            printf("YES\n");
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<m;j++)
                    printf("%d ",num[i][j]);
                printf("%d\n",num[i][m]);
            }
        }
        else printf("NO\n");
    }
    return 0;
}
