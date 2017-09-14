#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define MX 505
struct Edge{
    int u,v;
    int w;
    bool operator <(const Edge &b) const{
        return w<b.w;
    }
}edge[MX*MX];

int n,m;
int fa[MX];
int find_head(int x)
{
    if (fa[x]!=x)
        fa[x]=find_head(fa[x]);
    return fa[x];
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n); m = 0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                int w;
                scanf("%d",&w);
                edge[m++]=(Edge){i,j,w};
                edge[m++]=(Edge){j,i,w};
            }
        sort(edge,edge+m);
        for (int i=1;i<=n;i++) fa[i]=i;
        LL ans = 0;
        for (int i=0;i<m;i++)
        {
            int fx = find_head(edge[i].u);
            int fy = find_head(edge[i].v);
            if (fx!=fy)
            {
                fa[fx]=fa[fy];
                ans+=edge[i].w;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
