#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define PI acos(-1.0)
#define lowbit(x) (x&(-x))
#define INF 0x3f3f3f3f      // 21 E
#define MEM 0x3f            // memset 都变为 INF
#define MOD 4999            // 模
#define eps 1e-9            // 精度
#define MX  25         // 数据范围

int s;
int mp[MX][5];
int vis[MX];
int route[MX];
int cnt;


void dfs(int x,int t)
{
    vis[x]++;
    route[t]=x;
    if (t==21)
    {
        printf("%d:  ",++cnt);
        for (int i=1;i<=20;i++)
            printf("%d ",route[i]);
        printf("%d\n",route[21]);
        return ;
    }
    for (int i=1;i<=3;i++)
    {
        if (!vis[mp[x][i]]||(t==20&&mp[x][i]==s))
        {
            dfs(mp[x][i],t+1);
            vis[mp[x][i]]--;
        }
    }
}

int main()
{
    for (int i=1;i<=20;i++)
    {
        scanf("%d%d%d",&mp[i][1],&mp[i][2],&mp[i][3]);
        sort(mp[i]+1,mp[i]+4);
    }
    while (scanf("%d",&s)&&s)
    {
        cnt = 0;
        memset(vis,0,sizeof(vis));
        dfs(s,1);
    }
    return 0;
}
