#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MXN 1005
#define MXM 100005
struct Edge
{
    int u,v;
    int w;
    int nex;
}edge[2*MXM];

int n,m,X;
int hlist1[MXN];
int hlist2[MXN];
int far[MXN];
int dis[MXN];
int vis[MXN];

void spfa(int s,int op)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> Q;
    vis[s]=1;
    dis[s]=0;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();Q.pop();
        vis[u]=0;
        int i;
        if (op==1) i = hlist1[u];
        else i = hlist2[u];
        while (i!=-1)
        {
            int to = edge[i].v,w = edge[i].w;
            if (dis[to]>dis[u]+w)
            {
                dis[to]=dis[u]+w;
                if (!vis[to])
                {
                    Q.push(to);
                    vis[to]=1;
                }
            }
            i = edge[i].nex;
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&X);
    memset(hlist1,-1,sizeof(hlist1));
    memset(hlist2,-1,sizeof(hlist2));
    int r_m=0;
    for (int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        edge[r_m]=(Edge){a,b,c,hlist1[a]};
        hlist1[a]=r_m;

        edge[r_m+1]=(Edge){b,a,c,hlist2[b]};
        hlist2[b]=r_m+1;

        r_m+=2;
    }
    spfa(X,1);
    for (int i=1;i<=n;i++)
        far[i]=dis[i];
    spfa(X,2);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if(far[i]+dis[i]>ans)
            ans = far[i]+dis[i];
    }
    printf("%d\n",ans);
    return 0;
}
