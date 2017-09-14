#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MX 105
const double eps = 1e-5;
struct Edge
{
    int u,v;
    double r;
    double con;
    int nex;
}edge[MX*2];

int n,m,s;
double money;
int hlist[MX];
double dis[MX];
int vis[MX];
int num[MX];

int spfa()
{
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(num,0,sizeof(num));
    dis[s] = money;
    vis[s] = 1;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int now = Q.front();Q.pop();
        vis[now]=0;
        for (int i=hlist[now];i!=-1;i=edge[i].nex)
        {
            int to = edge[i].v;
            double r = edge[i].r , c = edge[i].con;
            double qian =(dis[now]-c)*r;
            if (qian - dis[to] > eps)
            {
                dis[to] = qian;
                if (!vis[to])
                {
                    Q.push(to);
                    vis[to]=1;
                    num[to]++;
                    if (num[to]>n-1) return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d%d%d%lf",&n,&m,&s,&money);
    memset(hlist,-1,sizeof(hlist));
    int r_m;
    for (int i=0;i<m;i++)
    {
        int a,b;
        double ra,ca;
        double rb,cb;
        scanf("%d%d%lf%lf%lf%lf",&a,&b,&ra,&ca,&rb,&cb);
        edge[r_m]=(Edge){a,b,ra,ca,hlist[a]};
        hlist[a]=r_m;
        edge[r_m+1]=(Edge){b,a,rb,cb,hlist[b]};
        hlist[b]=r_m+1;
        r_m+=2;
    }
    if (spfa())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
