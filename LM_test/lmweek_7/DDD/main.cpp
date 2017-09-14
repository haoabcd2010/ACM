#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MX 1005
struct Edge{
    int to;
    int w;
};

int n,m;
vector<Edge> G[MX];
int dis[MX];
int vis[MX];

void spfa(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    vis[s]=1;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();Q.pop();
        vis[u]=0;
        for (int i=0;i<(int)G[u].size();i++)
        {
            int v = G[u][i].to, w = G[u][i].w;
            if (dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                if (!vis[v])
                {
                    Q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    printf("%d\n",dis[t]);
}

int main()
{
    while (~scanf("%d%d",&m,&n))
    {
        for (int i=0;i<=n;i++) G[i].clear();

        for (int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            G[a].push_back((Edge){b,c});
            G[b].push_back((Edge){a,c});
        }
        spfa(1,n);
    }
    return 0;
}
