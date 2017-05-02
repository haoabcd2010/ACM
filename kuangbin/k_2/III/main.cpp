#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MX 12
struct Node
{
    int h,x,y;
    int s;
};

int n,m,t;
int ok;
char mp[2][MX][MX];
int vis[2][MX][MX];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int check(Node &b)
{
    if (b.x<0||b.x>=n||b.y<0||b.y>=m||b.s>t)
        return 0;
    if (vis[b.h][b.x][b.y])
        return 0;
    if (mp[b.h][b.x][b.y]=='*')
        return 0;
    if (mp[b.h][b.x][b.y]=='#'&&mp[(b.h+1)%2][b.x][b.y]=='#')
        return 0;
    if (mp[b.h][b.x][b.y]=='#'&&mp[(b.h+1)%2][b.x][b.y]=='*')
        return 0;
    return 1;
}

void bfs()
{
    memset(vis,0,sizeof(vis));
    queue<Node> Q;
    vis[0][0][0]=1;
    Q.push((Node){0,0,0,0});
    while (!Q.empty())
    {
        Node now = Q.front();
        Q.pop();
        if (mp[now.h][now.x][now.y]=='P')
        {
            ok=1;
            break;
        }
        Node nex;
        for (int i=0;i<4;i++)
        {
            nex.x = now.x+dir[i][0];
            nex.y = now.y+dir[i][1];
            nex.s = now.s+1;
            nex.h = now.h;
            if (check(nex))
            {
                if (mp[nex.h][nex.x][nex.y]=='#')   //如果可以上去
                    nex.h=(nex.h+1)%2;
                Q.push(nex);
                vis[nex.h][nex.x][nex.y]=1;
            }
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&t);
        for (int i=0;i<n;i++)
            scanf("%s",mp[0][i]);
        for (int i=0;i<n;i++)
        {
            scanf("%s",mp[1][i]);
        }

        ok=0;
        bfs();
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
