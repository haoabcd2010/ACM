#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define LL long long
#define MX 100010

int n;
int total;
vector<int> G[MX];
int colr[MX];

void DFS(int x,int pre,int c,int &tot)
{
    if (colr[x]==-c) return;
    tot++;
    for (int i=0;i<G[x].size();i++)
        if (G[x][i]!=pre)
            DFS(G[x][i],x,c,tot);
}

void dfs(int u,int pre,int s,int &ok)
{
    if (u==n)
    {
        ok=s;
        return;
    }
    for (int i=0;i<G[u].size();i++)
    {
        if (ok) break;
        if (G[u][i]!=pre)
            dfs(G[u][i],u,s+1,ok);
    }
    if (ok)
    {
        if (u!=1&&s<=ok/2) colr[u]=1;
        if (u!=n&&s>ok/2) colr[u]=-1;
    }
    return;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    colr[1]=1; //hei
    colr[n]=-1;//bai

    int ok=0;
    dfs(1,-10,0,ok);
/*
    for (int i=1;i<=n;i++)
        printf("%d ",colr[i]);
    printf("\n");
*/

    int num_1=0;
    DFS(1,-10,1,num_1);
    int num_2=0;
    DFS(n,-10,-1,num_2);
    if (num_1-num_2>=1)
        printf("Fennec\n");
    else
        printf("Snuke\n");
    return 0;
}
