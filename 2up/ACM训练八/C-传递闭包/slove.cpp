/*
#include <stdio.h>
#include <string.h>

struct Vis
{
    int flag;
    int x,y;
}vis[105];
int num[105][105];
int ans,n,m;
int real[105][105];

int tuopu(int x)
{
    vis[x].flag=2;
    for (int i=1;i<=n;i++)
    {
        if (real[x][i])
        {
            if (vis[i].flag==0)
                tuopu(i);
            else
            {
                int k=1;
                while (num[vis[i]-1][k]) k++;
                num[]=x;
                continue;
            }
        }
    }
    num[ans--]=x;
    vis[x]=ans+1;
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(real,0,sizeof(real));
    while (m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        real[a][b]=1;
    }
    ans=100;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
    {
        if (vis[i]==0)
            tuopu(i);
    }
    //printf("%d\n",100-ans);
    return 0;
}
*/


#include <iostream>
#include <cstdio>
using namespace std;
int f[105][105],n,m;

int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin >> x >> y;
        f[x][y]=1;
    }
    for (int k=1;k<=n;k++)
      for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
          if (f[i][k]+f[k][j]==2)
            f[i][j]=1;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int total=0;
        for (int j=1;j<=n;j++)
          if (f[i][j] || f[j][i]) total++;
        if (total==n-1) ans++;
    }
    cout << ans << endl;
}
