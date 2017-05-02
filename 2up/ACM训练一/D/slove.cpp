#include <iostream>
#include <cstdio>
using namespace std;

#define inf 0x3f3f3f3f
#define ll long long

const int maxn=1e2+10;
const int dis[4][2]={{0,1},{-1,0},{0,-1},{1,0}};

ll gcd(ll p,ll q)
{
    return q==0?p:gcd(q,p%q);
}
int n,m,x[2],y[2];
char a[maxn][maxn];
bool check()
{
    int i,j;

    for (i=0;i<=1;i++)
        for (j=0;j<=1;j++)
        if(a[x[i]][y[i]]!='1')
        return false;

    //rep(i,x[0]+1,x[1]-1)
    for (i=x[0]+1;i<=x[1]-1;i++)
    if(a[i][y[0]]!='2')
    return false;

    //rep(i,x[0]+1,x[1]-1)
    for (i=x[0]+1;i<=x[1]-1;i++)
        if(a[i][y[1]]!='2')
            return false;

    //rep(i,y[0]+1,y[1]-1)
    for (i=y[0]+1;i<=y[1]-1;i++)
        if(a[x[0]][i]!='2')
            return false;

    //rep(i,y[0]+1,y[1]-1)
    for (i=y[0]+1;i<=y[1]-1;i++)
    if(a[x[1]][i]!='2')
        return false;

    //rep(i,x[0]+1,x[1]-1)
    //rep(j,y[0]+1,y[1]-1)
    for (i=x[0]+1;i<=x[1]-1;i++)
        for (j=y[0]+1;j<=y[1]-1;j++)
            if(a[i][j]!='4')
            return false;

    return true;
}
int main()
{
    int i,j,k,t;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    scanf("%s",a[i]);
    x[0]=y[0]=inf;
    x[1]=y[1]=-1;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        if(a[i][j]!='0')
        {
            x[0]=min(x[0],i);
            x[1]=max(x[1],i);
            y[0]=min(y[0],j);
            y[1]=max(y[1],j);
        }
    if(check())
        puts("Yes");
    else
        puts("No");
    return 0;
}
