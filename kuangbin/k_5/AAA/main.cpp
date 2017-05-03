#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define MX 1010
struct Node
{
    double x,y;
}node[MX];
int n;
double d;
double edge[MX][MX];
int work[MX];
int f[MX];

int find_head(int x)
{
    if (x!=f[x])
        f[x]=find_head(f[x]);
    return f[x];
}

void fix(int x)
{
    for (int i=1;i<=n;i++)
    {
        if (work[i]&&edge[x][i]<=d)
        {
            int fx = find_head(x);
            int fi = find_head(i);
            if (fx==x)
                f[fx]=fi;
            else
                f[fi]=fx;
        }
    }
    work[x]=1;
}

int main()
{
    scanf("%d%lf",&n,&d);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&node[i].x,&node[i].y);
        for (int j=i-1;j>=1;j--)
        {
            double sss = sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
            edge[i][j]=edge[j][i]=sss;
        }
    }

    memset(work,0,sizeof(work));
    for (int i=1;i<=n;i++) f[i]=i;

    char op[3];
    while (scanf("%s",op)!=EOF)
    {
        if (op[0]=='O')
        {
            int x;
            scanf("%d",&x);
            fix(x);
        }
        if (op[0]=='S')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int fa = find_head(a);
            int fb = find_head(b);
            if (fa==fb)
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}
