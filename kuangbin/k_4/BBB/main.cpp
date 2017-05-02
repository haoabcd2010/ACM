#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define eps 1e-8
#define INF 0x3fffffff
#define MX 205
struct Node
{
    double x,y;
}node[MX];
int n;
double mp[MX][MX];
double dis[MX]; //dis[i] 代表去 i 点的最小距离
int vis[MX];

double dij(double x)//在这个限制下跑dij
{
    memset(vis,0,sizeof(vis));
    for (int i=0;i<n;i++) dis[i]=INF;
    dis[0]=0;
    for (int i=0;i<n;i++)
    {
        double mmm = INF;
        int mmxx;
        for (int j=0;j<n;j++)
        {
            if (!vis[j]&&dis[j]<x&&dis[j]<mmm)
            {
                mmm=dis[j];
                mmxx = j;
            }
        }
        if (mmm==INF) break;
        vis[mmxx]=1;
        for (int j=0;j<n;j++)
        {
            if (!vis[j]&&mp[mmxx][j]<dis[j])
                dis[j] = mp[mmxx][j];
        }
        if (dis[1]<x) return 1;
    }
    return 0;
}

int main()
{
    int cas = 1;
    while (scanf("%d",&n)&&n)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%lf%lf",&node[i].x,&node[i].y);
            for (int j=i;j>=0;j--)
            {
                double dis = sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
                mp[i][j]=mp[j][i]=dis;
            }
        }
        double left = 0,right = 2000;
        while (right-left>eps)
        {
            double mid = (left+right)/2;
            if (dij(mid)) right = mid;
            else left = mid;
        }
        printf("Scenario #%d\n",cas++);
        printf("Frog Distance = %.3f\n\n",left);
    }
    return 0;
}
