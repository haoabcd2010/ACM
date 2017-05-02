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
    ll temp=0,las=m+1;//��¼��Щ��û����
    m=min(n,m);//n ����� n �Ķ����� n
    ll nn=(ll)sqrt(n*1.0);
    for (ll i=1;i<=nn;i++)
    {
        ll l = n/(i+1)+1;
        ll r = n/i;

        r=min(r,m);//���� r �� m ��
        if (l>r) continue;

        las=min(las,l);

        ll s1=l+r , s2 =(r-l+1);//�����˹����и��ӣ�Ҫ���ж��ĸ������Գ�2���ٳ�
        if (s1%2==0) s1/=2;     //ֱ���ù�ʽҲ���ԣ��ᳬ��ll����
        else s2/=2;
        s1%=MOD;s2%=MOD;
        s1=(s1*s2)%MOD;
        s1=s1*i%MOD;
        temp=(temp+s1)%MOD;
    }
    ans=(ans+MOD-temp)%MOD;
    for (ll i=1;i<las;i++) //ʣ�µ�û������������n��֮Ϊ0�����������ȥ
    {
        temp=n/i%MOD*i%MOD;
        ans=(ans+MOD-temp)%MOD;
    }
    printf("%I64d\n",ans);

    return 0;
}
