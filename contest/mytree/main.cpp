#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define MAXN 302

int n,m;
int G[MAXN][MAXN];
int tree[102][MAXN][MAXN]; // 颜色，行,列

int lowbit(int x) {return x&(-x);}

void update(int c,int x,int y,int add)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for (int j=y;j<=m;j+=lowbit(j))
            tree[c][i][j]+=add;
}

int getsum(int c,int x,int y)
{
    int ans =0;
    for (int i=x;i>0;i-=lowbit(i))
        for (int j=y;j>0;j-=lowbit(j))
            ans += tree[c][i][j];
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        scanf("%d",&G[i][j]);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        update(G[i][j],i,j,1);

    int q;
    scanf("%d",&q);
    while (q--)
    {
        int op;
        scanf("%d",&op);
        if (op==1)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            update(c,x,y,1);//c颜色x,y +1
            update(G[x][y],x,y,-1);//原来颜色xy -1
            G[x][y]=c;
        }
        if (op==2)
        {
            int x1,x2,y1,y2,c;
            scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
            int ans = getsum(c,x2,y2)+getsum(c,x1-1,y1-1);   //c 颜色 i行y1-y2;
            ans -= getsum(c,x1-1,y2);
            ans -= getsum(c,x2,y1-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
