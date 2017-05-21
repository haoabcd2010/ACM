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
    bool operator < (const To& b)const
    {
        return c>b.c;
    }
};

int n;
int farx,fary;
LL step;
vector<To> road[MX];
LL dis[2][MX];

void Init()
{
    for (int i=1;i<=n;i++)
        road[i].clear();
}

void dfs(int x,int pre,LL s)
{
    if (s>step)
    {
        farx=x;
        step=s;
    }
    for (int i=0;i<(int)road[x].size();i++)
    {
        if (road[x][i].to!=pre)
            dfs(road[x][i].to,x,road[x][i].c+s);
    }
}

int vis[MX];
void dij(int s,int p)
{
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) dis[p][i]=INF;
    dis[p][s]=0;
    priority_queue<To> Q;
    Q.push((To){s,0});
    while (!Q.empty())
    {
        To now = Q.top();
        Q.pop();
        if (vis[now.to]) continue;
        int u = now.to;
        vis[u]=1;
        for (int i=0;i<(int)road[u].size();i++)
        {
            To &v = road[u][i];
            if (!vis[v.to]&&dis[p][u]+v.c<dis[p][v.to])
            {
                dis[p][v.to] = dis[p][u]+v.c;
                Q.push(v);
            }
        }
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
        dfs(1,0,0);
        fary = farx;
        step=0;
        dfs(farx,0,0);

        dij(farx,0);
        dij(fary,1);

        LL ans = 0;
        for (int i=1;i<=n;i++)
            ans += max(dis[0][i],dis[1][i]);
        ans -= step;
        printf("%I64d\n",ans);
    }
    return 0;
}
