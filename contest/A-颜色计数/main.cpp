#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int n;

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        int x = n;
        int ans = 0;
        for (int i=1;i<=n;i++)
        {
            double f = sqrt(n*1.0-i*i*1.0);
            int cmp = floor(f+0.5);
            if (fabs(f-cmp)<1e-8)
                ans++;
        }
        ans*=4;
        printf("%d\n",ans);
    }
    return 0;
}


/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
#define MAXN 305

struct Node
{
    int se[101];
    int l,r;
}head[MAXN][4*MAXN];//第几行的树

int n,m;
int G[MAXN][MAXN];

void new_tree(int k,int l,int r,int x)
{
    for (int i=l;i<=r;i++)
        head[x][k].se[G[x][i]]++;
    head[x][k].l=l;
    head[x][k].r=r;
    int mid = (l+r)/2;
    new_tree(2*k,l,mid,x);
    new_tree(2*k+1,mid+1,r,x);
}

void update(int x,int y,int c)
{

}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            scanf("%d",&G[i][j]);
    }
    for (int i=1;i<=n;i++)//建树
        new_tree(1,1,m,i);
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
            update(x,y,c);
        }
        else
        {
            int x1,x2,y1,y2,c;
            scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
            //look();
        }
    }
    //free_tree(n);
    return 0;
}
*/
