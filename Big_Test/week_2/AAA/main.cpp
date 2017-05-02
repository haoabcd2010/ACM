#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define LL long long
#define MX 55
const int INF = 1e8;
struct Node
{
    int x,y;
    int s;  //耗时
    bool operator <(const Node& b)const
    {
        return s>b.s;//优先队列权大在前
    }
};
int n;
int mp[MX][MX];
int dis[MX][MX];
int vis[MX][MX];
LL res[MX][MX]; //答案
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void bfs()
{
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dis[i][j]=INF;
    priority_queue<Node> Q;
    vis[n][n]=1;
    dis[n][n]=mp[n][n];
    Node now = (Node){n,n,mp[n][n]};
    Q.push(now);
    while (!Q.empty())
    {
        now = Q.top();Q.pop();
        Node nex;
        for (int i=0;i<4;i++)
        {
            nex.x = now.x+dir[i][0];
            nex.y = now.y+dir[i][1];
            if (nex.x>=1&&nex.x<=n&&nex.y>=1&&nex.y<=n&&!vis[nex.x][nex.y])
            {
                nex.s = now.s+mp[nex.x][nex.y];
                vis[nex.x][nex.y]=1;
                dis[nex.x][nex.y]=nex.s;
                Q.push(nex);
            }
        }
    }
}

LL dfs(int x,int y)
{
    if (x==n&&y==n) return 1;
    if (res[x][y]!=-1) return res[x][y];
    res[x][y]=0;
    int nx,ny;
    for (int i=0;i<4;i++)
    {
        nx = x+dir[i][0];
        ny = y+dir[i][1];
        if (nx>=1&&nx<=n&&ny>=1&&ny<=n&&dis[nx][ny]<dis[x][y])
            res[x][y]+=dfs(nx,ny);
    }
    return res[x][y];
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&mp[i][j]);
        bfs();
        memset(res,-1,sizeof(res));
        dfs(1,1);//搜路径个数
        printf("%I64d\n",res[1][1]);
    }
    return 0;
}

