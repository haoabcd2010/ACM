#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define MX 35
struct Mat
{
    int a,b,c,d;
    int area;
}mat[5000];

int n;
int x[MX];
int y[MX];
int G[205][205];

int check(int u,int v)
{
    int xxx = min(min(x[mat[u].a],x[mat[u].b]),min(x[mat[u].c],x[mat[u].d]));
    int xxy = min(min(y[mat[u].a],y[mat[u].b]),min(y[mat[u].c],y[mat[u].d]));
    int ddx = max(max(x[mat[u].a],x[mat[u].b]),max(x[mat[u].c],x[mat[u].d]));
    int ddy = max(max(y[mat[u].a],y[mat[u].b]),max(y[mat[u].c],y[mat[u].d]));

    int xx = min(min(x[mat[v].a],x[mat[v].b]),min(x[mat[v].c],x[mat[v].d]));
    int xy = min(min(y[mat[v].a],y[mat[v].b]),min(y[mat[v].c],y[mat[v].d]));
    int dx = max(max(x[mat[v].a],x[mat[v].b]),max(x[mat[v].c],x[mat[v].d]));
    int dy = max(max(y[mat[v].a],y[mat[v].b]),max(y[mat[v].c],y[mat[v].d]));


    if (xxx>dx||xxy>dy||ddx<xx||ddy<xy)//在 右上左下
        return mat[v].area+mat[u].area;

    if (xxx>xx&&ddx<dx&&xxy>xy&&ddy<dy)//包含
        return max(mat[v].area,mat[u].area);
    if (xxx<xx&&ddx>dx&&xxy<xy&&ddy>dy)
        return max(mat[v].area,mat[u].area);

    return 0;
}

int main()
{
    while (scanf("%d",&n)&&n)
    {
        memset(G,-1,sizeof(G));
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            G[x[i]][y[i]]=i;
        }
        int m=0;
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (x[i]==x[j]||y[i]==y[j]) continue;
                int fir,sec;
                if (G[x[i]][y[j]]!=-1) fir=G[x[i]][y[j]];
                else continue;
                if (G[x[j]][y[i]]!=-1) sec=G[x[j]][y[i]];
                else continue;

                int lon=abs(x[i]-x[j]);
                int kua=abs(y[i]-y[j]);
                mat[m++]=(Mat){fir,sec,i,j,lon*kua};
            }
        }
        int ans = 0;
        for (int i=0;i<m;i++)
        {
            for (int j=i+1;j<m;j++)
            {
                ans = max(ans,check(i,j));
            }
        }
        if (ans!=0)
            printf("%d\n",ans);
        else
            printf("imp\n");
    }
    return 0;
}
