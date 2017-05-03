#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MX 35
struct Node
{
    int h,x,y;
    int s;
};

int h,n,m;
int ok;
int sh,sx,sy;
char mp[MX][MX][MX];
int vis[MX][MX][MX];
int dir[6][3]={{1,0,0},{-1,0,0},{0,-1,0},{0,1,0},{0,0,1},{0,0,-1}};

int check(Node &x)
{
    if (x.h<=0||x.h>h||x.x<=0||x.x>n||x.y<=0||x.y>m)
        return 0;
    if (mp[x.h][x.x][x.y]=='#'||vis[x.h][x.x][x.y])
        return 0;
    return 1;
}

void bfs()
{
    Node now = (Node){sh,sx,sy,0};
    memset(vis,0,sizeof(vis));
    vis[sh][sx][sy]=1;
    queue<Node> Q;
    Q.push(now);
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        //printf("%d %d %d %d\n",now.h,now.x,now.y,now.s);
        if (mp[now.h][now.x][now.y]=='E')
        {
            ok=now.s;
            return ;
        }
        Node nex;
        for (int i=0;i<6;i++)
        {
            nex.h=now.h+dir[i][0];
            nex.x=now.x+dir[i][1];
            nex.y=now.y+dir[i][2];
            nex.s=now.s+1;
            if (check(nex))
            {
                Q.push(nex);
                vis[nex.h][nex.x][nex.y]=1;
            }
        }
    }
}

int main()
{
    while (scanf("%d%d%d",&h,&n,&m)&&(n||m||h))
    {
        for (int i=1;i<=h;i++)
        {
            for (int j=1;j<=n;j++)
                scanf("%s",&mp[i][j][1]);
        }
        for (int i=1;i<=h;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=m;k++)
                    if (mp[i][j][k]=='S')
                    {
                        sh=i;
                        sx=j;
                        sy=k;
                    }

        ok=0;
        bfs();
        if (ok)
            printf("Escaped in %d minute(s).\n",ok);
        else
            printf("Trapped!\n");
    }
    return 0;
}
