#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
using namespace std;
#define MX 200005

int n,m;
set<int> G[MX];
int vis[MX];

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++)
            G[i].clear();
        for (int i=1;i<=n;i++)
            vis[i]=1;
        for (int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].insert(b);
            G[b].insert(a);
        }
        int mim = MX *2;
        int dex;
        for (int i=1;i<=n;i++)
        {
            int tp = G[i].size();
            if (tp<mim)
            {
                dex=i;
                mim=tp;
            }
        }
        vis[dex]=0;
        for (set<int>::iterator it=G[dex].begin();it!=G[dex].end();it++)
        {
            vis[*it]=0;
        }
        for (int i=1;i<n;i++)
            printf("%d ",vis[i]);
        printf("%d\n",vis[n]);
    }
    return 0;
}
