
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int W,H,T,q,ans;
int Map[102][102][102];// (x,y) 时间z
struct Node
{
    int x,y;
    Node(int a,int b):x(a),y(b)
    {}
};
vector<Node> G[102];

int dx[]={0, 0,1,-1,0};
int dy[]={1,-1,0, 0,0};
int dfs(int x,int y,int tt)
{

    if (Map[x][y][tt]!=-1)//如果这个状态的情况已经确定了
        return Map[x][y][tt];
    if (tt==T)//到最后封锁时间，说明这个状态可以
    {
        ans++;
        Map[x][y][tt]=1;
        G[tt].push_back(Node(x,y));
        return 1;
    }
    Map[x][y][tt]=0;
    for (int i=0;i<5;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if (tx>=1&&tx<=W&&ty>=1&&ty<=H)
        {
            if (dfs(tx,ty,tt+1)==1)//如果接下来的状态可以到，说明自己也可以到
                Map[x][y][tt]=1;
        }
    }
    if (Map[x][y][tt]==1)
    {
        G[tt].push_back(Node(x,y));
    }
    return Map[x][y][tt];
}

int main()
{
    int cas=1;
    while(scanf("%d%d%d",&W,&H,&T)&&W+H+T)
    {
        memset(Map,-1,sizeof(Map));
        scanf("%d",&q);
        for (int i=1;i<=q;i++)
        {
            int t,lx,ly,rx,ry;
            scanf("%d%d%d%d%d",&t,&lx,&ly,&rx,&ry);
            for (int j=lx;j<=rx;j++)
                for (int k=ly;k<=ry;k++)
                    Map[j][k][t]=0;
        }
        for (int i=1;i<=T;i++) G[i].clear();
        ans=0;
        for (int i=1;i<=W;i++)
        {
            for (int j=1;j<=H;j++)
                if (Map[i][j][1]==-1)
                {
                    dfs(i,j,1);
                }
        }
        printf("Robbery #%d:\n",cas++);
        if (ans==0)
            printf("The robber has escaped.\n");
        else
        {
            int res=0;
            for (int i=1;i<=T;i++)
            if (G[i].size()==1)
            {
                res++;
                printf("Time step %d: The robber has been at %d,%d.\n",i,G[i][0].x,G[i][0].y);
            }
            if (res==0)
                printf("Nothing known.\n");
        }
        printf("\n");
    }
    return 0;
}



/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=105;
int dp[maxn][maxn][maxn];
int n,m,t,cnt;
int dx[]={0, 0, 1,-1, 0};
int dy[]={1,-1, 0, 0, 0};

struct node{
    int x,y;
    node(){}
    node(int a,int b):x(a),y(b){}
};

vector<node> ans[maxn];

int dfs(int x, int y, int tt)
{
    if(dp[x][y][tt] != -1) return dp[x][y][tt];
    if(tt>=t)
    {
        cnt ++;
        ans[t].push_back(node(x,y));
        return dp[x][y][t] = 1;
    }
    dp[x][y][tt] = 0;
    for(int i=0; i<5; i++)
    {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(tx>0 && tx<=n && ty>0 && ty<=m)
        {
            if(dfs(tx, ty, tt+1)) dp[x][y][tt] = 1;
        }
    }
    if(dp[x][y][tt]){
           ans[tt].push_back(node(x,y));
    }
    return dp[x][y][tt];
}


int main(){
    int cas=1;
    while(~scanf("%d%d%d",&n,&m,&t)&&n+m+t){
        int q;
        scanf("%d",&q);
        cnt=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<maxn;i++)ans[i].clear();
        int tt,a,b,c,d;
        while(q--){
            scanf("%d%d%d%d%d",&tt,&a,&b,&c,&d);
            for(int i=a;i<=c;i++)
              for(int j=b;j<=d;j++)
                dp[i][j][tt]=0;
        }
        for(int i=1;i<=n;i++)
          for(int j=1;j<=m;j++)
            if(dp[i][j][1]<0)
              dfs(i,j,1);

        printf("Robbery #%d:\n",cas++);
        if(cnt==0)
              printf("The robber has escaped.\n");
        else{
            bool ok=1;
            for(int i=1;i<=t;i++)
              if(ans[i].size()==1){
                  ok=0;
                  printf("Time step %d: The robber has been at %d,%d.\n", i, ans[i][0].x, ans[i][0].y);
              }
            if(ok)
              printf("Nothing known.\n");
        }
        puts("");
    }
    return 0;
}
*/

