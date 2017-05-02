#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 500005
int n,m;
int a[MX];  //数
int sum[MX];//和
int f[MX];  //dp 序列
int q[MX];  //队列，解集

int Y(int a,int b)
{
    return f[b]-f[a]+sum[b]*sum[b]-sum[a]*sum[a];
}
int X(int a,int b)
{
    return sum[b]-sum[a];
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(f,0,sizeof(f));
        memset(sum,0,sizeof(sum));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        int head=0,tail=0;
        for (int i=1;i<=n;i++)
        {
            int si = 2*sum[i];
            while (head<tail&&Y(q[head],q[head+1])<=si*X(q[head],q[head+1]))
                head++;
            f[i]=f[q[head]]+m+X(q[head],i)*X(q[head],i);
            while (head<tail&&Y(q[tail-1],q[tail])*X(q[tail],i) >= Y(q[tail],i)*X(q[tail-1],q[tail]))
                tail--;
            tail++; q[tail]=i;
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
