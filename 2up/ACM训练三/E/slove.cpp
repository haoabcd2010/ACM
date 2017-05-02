#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char mp[4][4];
int vis[4][4];
int n;
int ans;

void fang(int x,int y)//放下
{
    vis[x][y]=1;
    int i;
    i=x;
    while (i+1<n&&mp[i+1][y]=='.')
    {
        i++;
        vis[i][y]++;
    }
    i=x;
    while (i-1>=0&&mp[i-1][y]=='.')
    {
        i--;
        vis[i][y]++;
    }
    i=y;
    while (i+1<n&&mp[x][i+1]=='.')
    {
        i++;
        vis[x][i]++;
    }
    i=y;
    while (i-1>=0&&mp[x][i-1]=='.')
    {
        i--;
        vis[x][i]++;
    }
}

void che(int x,int y)//撤走
{
    vis[x][y]=0;
    int i;
    i=x;
    while (i+1<n&&mp[i+1][y]=='.')
    {
        i++;
        vis[i][y]--;
    }
    i=x;
    while (i-1>=0&&mp[i-1][y]=='.')
    {
        i--;
        vis[i][y]--;
    }
    i=y;
    while (i+1<n&&mp[x][i+1]=='.')
    {
        i++;
        vis[x][i]--;
    }
    i=y;
    while (i-1>=0&&mp[x][i-1]=='.')
    {
        i--;
        vis[x][i]--;
    }
}

int dfs(int l,int cnt)//去l行放置
{
    if (cnt>ans)
    {
        ans=cnt;
    }
    if (l>=n) return 0; //出界

    int i;
    for (i=0;i<n;i++)
    {
        if (mp[l][i]=='.'&&vis[l][i]==0)
        {
            fang (l,i);
            dfs(l,cnt+1);   //继续在这行放置，因为可能还可以放
            che(l,i);
        }
    }
    dfs(l+1,cnt);           //这一行都放完了就去下一行
    return 0;
}

int main()
{
    while (cin>>n&&n)
    {
        getchar();
        int i,j;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
                cin>>mp[i][j];
            getchar();
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        dfs(0,0);           //从第0行开始放，放置的个数初始值为 0
        cout<<ans<<endl;
    }
    return 0;
}
