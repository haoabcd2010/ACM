#include <stdio.h>
#include <math.h>

typedef long long LL;
const LL MOD=1e9+7;

int main()
{
    LL n,m;
    scanf("%lld%lld",&n,&m);
    LL ans=(n%MOD)*(m%MOD)%MOD;
    if (m>n) m=n;
    LL temp=0,las=m;
    LL sq=(LL)sqrt(n*1.0);
    for (LL i=1;i<=sq;i++)
    {
        LL l = n/(i+1)+1;
        LL r = n/i;

        if (r>las) r=las;
        if (l>r) continue;
        las=l-1;

        LL s1=l+r,s2=(r-l)+1;
        if (s1%2==0) s1/=2;
        else s2/=2;
        s1%=MOD;s2%=MOD;
        s1=(s1*s2)%MOD;
        s1=s1*i%MOD;
        temp=(temp+s1)%MOD;
    }
    for (LL i=1;i<=las;i++)
    {
        temp+=n/i*i%MOD;
        temp%=MOD;
    }
    ans=(ans+MOD-temp)%MOD;
    printf("%lld\n",ans);
    return 0;
}
