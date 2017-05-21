#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MX 100005
#define LL long long

int n,m,c;
int num[MX];
LL sum[MX];

int main()
{
    while(~scanf("%d%d%d",&n,&m,&c))
    {
        sum[0]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            sum[i]=sum[i-1]+num[i];
        }
        sort(sum,sum+1+n);
        int l = 0 ,r = n;
        LL ans = 0;

        while (l<m&&sum[r]-sum[l]>c)
        {
            ans+=abs(sum[r]-sum[l])-c;
            l++,r--;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
