#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
#define MX 10005

int n,m;
int a,b;
int root,ok;
int in[MX]; // 入度
vector<int> edge[MX];
int f[MX];

void Init()
{
    for (int i=1;i<=n;i++)
        edge[i].clear();
    memset(in,0,sizeof(in));
}

int find_head(int x)
{
    return x==f[x]?f[x]:f[x]=find_head(f[x]);
}

void uni(int x,int y)
{
    x = find_head(x);
    y = find_head(y);
    if (x!=y)
        f[y]=x;     //这个顺序很重要，
}

void tarjan(int x)
{
    for (int i=0;i<(int)edge[x].size();i++)
    {
        tarjan(edge[x][i]);
        uni(x,edge[x][i]);
        if (ok) return;
        //每次合并完子集合后，就查询同一集合
        if (find_head(a)==find_head(b))
        {
            printf("%d\n",x);
            ok=1;
            return ;
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d",&n);
        Init();
        m=n-1;
        for (int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            in[v]++;
        }
        for (int i=1;i<=n;i++)
        {
            if (in[i]==0)
                root=i;
        }
        scanf("%d%d",&a,&b);
        for (int i=0;i<=n;i++) f[i]=i;
        ok=0;
        tarjan(root);
    }
    return 0;
}
