#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define MX 100005

struct Edge
{
    int u,v;
    int c;
};
struct To
{
    int to;
    int c;
};

int n;
int step;
int farx,fary;
vector<To> road[MX];

void Init()
{
    for (int i=1;i<=n;i++)
        road[i].clear();
}

void dfs(int x,int pre,int s)
{
    if (s>step)
    {
        farx=x;
        step=s;
    }
    for (int i=0;i<road[x].size();i++)
    {
        if (road[x][i].to!=pre)
            dfs(road[x][i].to,x,road[x][i].to+s);
    }
}

int main()
{
    while (~scanf("%d",&n))
    {
        Init();
        for (int i=0;i<n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            road[a].push_back((To){b,c});
            road[b].push_back((To){a,c});
        }

        step=0;
        dfs(1,0,0);
        fary = farx;
        step=0;
        dfs(farx,0,0);

        printf("%d %d %d\n",farx,fary,step);
    }
    return 0;
}
