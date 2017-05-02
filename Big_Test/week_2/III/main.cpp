#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100005
#define LL long long
LL L[MAXN];
LL R[MAXN];
LL h[MAXN];

int main()
{
    int n;
    while (scanf("%d",&n)&&n)
    {
        for (int i=1;i<=n;i++)
            scanf("%I64d",&h[i]);
        h[0]=h[n+1]=-1;
        for (int i=1;i<=n;i++)
        {
            L[i]=i;
            while (h[L[i]-1]>=h[i])
                L[i]=L[L[i]-1];
        }
        for (int i=n;i>=1;i--)
        {
            R[i]=i;
            while (h[R[i]+1]>=h[i])
                R[i]=R[R[i]+1];
        }
        LL ans = 0;
        for (int i=1;i<=n;i++)
        {
            LL area = (R[i]-L[i]+1)*h[i];
            if(area>ans) ans = area;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
