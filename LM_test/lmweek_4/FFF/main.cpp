#include <bits/stdc++.h>
using namespace std;
#define MX 205

int n,m;
int dp[MX][MX];
int b[MX];
int vis[MX];
vector<int> tree[MX];

void dfs(int x)
{
    if (vis[x])return ;
    vis[x]=1;
    dp[x][1]=b[x];
    for (int i=0;i<tree[x].size();i++)
    {
        int v = tree[x][i];
        dfs(v);
        for (int j=m;j>=2;j--)
        {
            for (int k=0;k<j;k++)
                dp[x][j] = max(dp[x][j],dp[v][k]+dp[x][j-k]);
        }
    }
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) break;
        m++;
        for (int i=0;i<=n;i++) tree[i].clear();
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++)
        {
            int a;
            scanf("%d%d",&a,&b[i]);
            tree[a].push_back(i);
        }
        dfs(0);
        printf("%d\n",dp[0][m]);
    }
    return 0;
}
