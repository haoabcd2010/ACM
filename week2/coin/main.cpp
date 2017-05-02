#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define M 100005
#define LL long long
using namespace std;
LL f[M],ans;
int d[5],c[5],t,s;
LL F(int x)
{
    return x>=0?f[x]:0LL;
}
void RC()
{
    for (int i=1;i<=4;i++)
        ans-=F(s-c[i]*(d[i]+1));
    for (int i=1;i<=4;i++)
        for (int j=i+1;j<=4;j++)
            ans+=F(s-c[i]*(d[i]+1)-c[j]*(d[j]+1));
    int now;
    for (int i=1;i<=4;i++)
    {
        now=0;
        for (int j=1;j<=4;j++)
            if (j!=i) now+=c[j]*(d[j]+1);
        ans-=F(s-now);
    }
    ans+=F(s-now-c[4]*(d[4]+1));
}
int main()
{
        scanf("%d%d%d%d%d",&c[1],&c[2],&c[3],&c[4],&t);
    f[0]=1;
    for (int j=1;j<=4;j++)
        for (int i=1;i<=100000;i++)
            if (i>=c[j]) f[i]+=f[i-c[j]];
    while (t--)
    {
        for (int i=1;i<=4;i++)
            scanf("%d",&d[i]);
        scanf("%d",&s);
        ans=f[s];
        RC();
        printf("%lld\n",ans);
    }
    return 0;
}
