#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
#define MAXN 10005
#define MAXM 20005

struct Node
{
    int s,e;
    int v;
    bool operator < (const Node& b)const {return v<b.v;}
}r1[MAXM],r2[MAXM];

int n,k,m,r1_n,r2_n;
int f[MAXN];

int Find(int x)
{
    if (x!=f[x])
        f[x]=Find(f[x]);
    return f[x];
}

int krus(int cost)
{
    for (int i=1;i<=n;i++) f[i]=i;

    int road=0;
    int L = 1;

    for (int i=0;i<r1_n;i++)    //一级公路
    {
        if (r1[i].v>cost) break;
        int xx = Find(r1[i].s);
        int yy = Find(r1[i].e);
        if (f[xx]!=f[yy])
        {
            road++;
            f[xx]=f[yy];
            L++;    //连通的个数
        }
        if (L==n) break;
    }
    for (int i=0;i<r2_n;i++)    //二级公路
    {
        if (r2[i].v>cost) break;
        int xx = Find(r2[i].s);
        int yy = Find(r2[i].e);
        if (f[xx]!=f[yy])
        {
            f[xx]=f[yy];
            L++;    //连通的个数
        }
        if (L==n) break;
    }
    if (road>=k&&L==n)
        return 1;
    return 0;
}

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    r1_n=0;
    r2_n=0;
    for (int i=0;i<m-1;i++)
    {
        int a,b,c1,c2;
        scanf("%d%d%d%d",&a,&b,&c1,&c2);
        r1[r1_n++]=(Node){a,b,c1};
        r2[r2_n++]=(Node){a,b,c2};
    }
    sort(r1,r1+r1_n);
    sort(r2,r2+r2_n);

    int l=0,r=30000;
    int ans;

    while (l<=r)
    {
        int mid = (l+r)/2;
        if (krus(mid))
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);

    return 0;
}
