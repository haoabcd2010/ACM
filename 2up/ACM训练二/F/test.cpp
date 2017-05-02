#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define ll __int64
const ll MOD=1e9+7;

int main()
{
    ll n,m;
    scanf("%I64d%I64d",&n,&m);
    ll ans=(n%MOD)*(m%MOD)%MOD;
    ll temp=0,las=m+1;//记录哪些数没被减
    m=min(n,m);//n 余大于 n 的都等于 n
    ll nn=(ll)sqrt(n*1.0);
    for (ll i=1;i<=nn;i++)
    {
        ll l = n/(i+1)+1;
        ll r = n/i;

        r=min(r,m);//可能 r 比 m 大
        if (l>r) continue;

        las=min(las,l);

        ll s1=l+r , s2 =(r-l+1);//这里高斯求和有个坑，要先判断哪个数可以除2，再乘
        if (s1%2==0) s1/=2;     //直接用公式也不对，会超出ll限制
        else s2/=2;
        s1%=MOD;s2%=MOD;
        s1=(s1*s2)%MOD;
        s1=s1*i%MOD;
        temp=(temp+s1)%MOD;
    }
    ans=(ans+MOD-temp)%MOD;
    for (ll i=1;i<las;i++) //剩下的没被减得数，将n余之为0的最大整数减去
    {
        temp=n/i%MOD*i%MOD;
        ans=(ans+MOD-temp)%MOD;
    }
    printf("%I64d\n",ans);

    return 0;
}
