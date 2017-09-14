#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define MX 1005
struct Node
{
    int to,w;
};

int n,m;
int G[MX][MX];
int vis[MX];
int dis[MX];

void dij()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    dis[1]=INF;
    for (int i=0;i<n;i++)
    {
        int mmm=0,mx;
        for (int j=1;j<=n;j++)
        {
            if (!vis[j]&&dis[j]>mmm)
            {
                mmm=dis[j];
                mx=j;
            }
        }
        vis[mx]=1;
        for (int j=1;j<=n;j++)
        {
            if (!vis[j]&&G[mx][j]>dis[j])
            {
                int tp = min(G[mx][j],dis[mx]);
                dis[j]= max(dis[j],tp);
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int cnt=1;cnt<=T;cnt++)
    {
        scanf("%d%d",&n,&m);
        memset(G,0,sizeof(G));
        for (int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            G[a][b]=c;
            G[b][a]=c;
        }
        dij();
        printf("Scenario #%d:\n",cnt);
        printf("%d\n\n",dis[n]);
    }
    return 0;
}
