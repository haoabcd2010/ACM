#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3f
#define MX 100005
struct To
{
    int to;
    LL c;
};

int n;
int far;
LL step;
vector<To> road[MX];
LL dis[2][MX];

void Init()
{
    for (int i=1;i<=n;i++)
        road[i].clear();
}

void dfs(int x,int pre,LL s,int kk)//所在位置，从前，距离，第几次
{
    if (kk!=0) dis[kk-1][x]=s;

    if (s>step)
    {
        far=x;
        step=s;
    }
    for (int i=0;i<(int)road[x].size();i++)
    {
        if (road[x][i].to!=pre)
            dfs(road[x][i].to,x,road[x][i].c+s,kk);
    }
}

int main()
{
    while (~scanf("%d",&n))
    {
        Init();
        for (int i=0;i<n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            road[a].push_back((To){b,c});
            road[b].push_back((To){a,c});
        }

        step=0;
        dfs(1,0,0,0);

        step=0;
        dfs(far,0,0,1);
        step=0;
        dfs(far,0,0,2);

        LL ans = 0;
        for (int i=1;i<=n;i++)
            ans += max(dis[0][i],dis[1][i]);
        ans -= step;
        printf("%I64d\n",ans);
    }
    return 0;
}
