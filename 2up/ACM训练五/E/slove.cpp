//快速幂
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=100003;
long long hanshu(long long a,long long b)
{
    long long ans=1;
    a%=mod;
    while(b)
    {
        if(b%2==1) ans=ans*a%mod;
        b/=2;
        a=a*a%mod;
    }
    return ans;
}
int main()
{
    long long m,n;
    scanf("%lld%lld",&m,&n);
    long long ss=(hanshu(m,n)-m*hanshu(m-1,n-1)+mod)%mod;
    printf("%lld\n",ss);
    return 0;
}
//

/*
#include <stdio.h>
#include <math.h>

typedef long long LL;
const int mod = 100003;

int main()
{
    LL n,m;
    while (scanf("%lld%lld",&m,&n)!=EOF)
    {
        if (n==1)//还好老子机智
        {
            printf("0\n");
            continue;
        }
        LL ans;
        int i;
        //公式很容易想到 M^N-M*(M-1)^(N-1)
        //关键是怎么实现
        int n_sq =sqrt(n*1.0);
        LL temp=1;
        LL t = m%mod;
        for (i=0;i<n_sq;i++)
        {
            temp*=t;
            temp%=mod;
        }
        t=temp;
        int k=n/n_sq;
        for (i=0;i<k-1;i++)//自己算 1
        {
            temp*=t;
            temp%=mod;
        }
        int las = n-k*n_sq;
        t=m%mod;
        for (i=0;i<las;i++)
        {
            temp*=t;
            temp%=mod;
        }
        ans=temp;
        //*******分割线**********//*
        //下面要注意细节 N-1
        temp=1;
        t =(m-1)%mod;
        n_sq=sqrt((n-1)*1.0);
        for (i=0;i<n_sq;i++)
        {
            temp*=t;
            temp%=mod;
        }

        t=temp;
        k=(n-1)/n_sq;
        for (i=0;i<k-1;i++)//自己算 1
        {
            temp*=t;
            temp%=mod;
        }
        las = (n-1)-k*n_sq;
        t=(m-1)%mod;
        for (i=0;i<las;i++)
        {
            temp*=t;
            temp%=mod;
        }
        t=m%mod;
        temp*=t;
        temp%=mod;

        ans+=mod;
        ans-=temp;
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
*/
