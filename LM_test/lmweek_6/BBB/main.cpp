#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MX 60
struct Node{
    int x,y,z;
    int s;
};

int n,l,r;
char mp[MX][MX][MX];
int vis[MX][MX][MX];
int sn,sl,sr;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int check(Node &tp)
{
    if (tp.y<1||tp.y>l||tp.z<1||tp.z>r)
        return 0;
    if (mp[tp.x][tp.y][tp.z]=='x'||vis[tp.x][tp.y][tp.z]==1)
        return 0;
    return 1;
}

void bfs(int x,int y,int z)
{
    queue<Node> Q;
    Q.push((Node){x,y,z,0});
    vis[x][y][z]=1;
    while (!Q.empty())
    {
        Node now = Q.front();Q.pop();
        if (mp[now.x][now.y][now.z]=='Y')
        {
            printf("%d\n",now.s);
            return ;
        }

        Node nex;
        if (mp[now.x][now.y][now.z]=='U')
        {
            nex=now;
            nex.x++;
            nex.s=now.s+1;
            if (check(nex))
            {
                Q.push(nex);
                vis[nex.x][nex.y][nex.z]=1;
            }
        }
        if (mp[now.x][now.y][now.z]=='D')
        {
            nex=now;
            nex.x--;
            nex.s=now.s+1;
            if (check(nex))
            {
                Q.push(nex);
                vis[nex.x][nex.y][nex.z]=1;
            }
        }
        for (int i=0;i<4;i++)
        {
            nex.x=now.x;
            nex.y=now.y+dir[i][0];
            nex.z=now.z+dir[i][1];
            nex.s=now.s+1;
            if (check(nex))
            {
                Q.push(nex);
                vis[nex.x][nex.y][nex.z]=1;
            }
        }
    }
    printf("-1\n");
}

int main()
{
    scanf("%d%d%d",&n,&l,&r);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=l;j++)
        {
            scanf("%s",mp[i][j]+1);
            for (int k=1;k<=r;k++)
            {
                if (mp[i][j][k]=='X')
                {
                    sn=i;
                    sl=j;
                    sr=k;
                }
            }
        }
    bfs(sn,sl,sr);
    return 0;
}
