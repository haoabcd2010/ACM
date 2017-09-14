# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <bitset>
# include <set>
# include <cmath>
# include <algorithm>
using namespace std;
#define lowbit(x) ((x)&(-x))
#define pi acos(-1.0)
#define eps 1e-8
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LL long long
inline int Scan() {
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
inline void Out(int a) {
    if(a<0) {putchar('-'); a=-a;}
    if(a>=10) Out(a/10);
    putchar(a%10+'0');
}
#define MX 100005
//Code begin...
int n,k;
int a[MX];

LL qk_mi(LL x,LL y)
{
    LL res = 1;
    while (y)
    {
        if (y&1) res = res*x%MOD;
        x = x*x%MOD;
        y/=2;
    }
    return res;
}

LL C(LL x,LL y)// m   n
{
    if (x>y) return 0LL;
    LL res =1;
    for (int i=1;i<=y;i++)
        res = (res*i)%MOD;
    LL mj = 1,mnj = 1;
    for (int i=1;i<=x;i++)
        mj = (mj*i)%MOD;
    for (int i=1;i<=(y-x);i++)
        mnj = (mnj*i)%MOD;
    mj = qk_mi(mj,MOD-2); mnj = qk_mi(mnj,MOD-2);
    res = (res*mj%MOD) * mnj %MOD;
    return res;
}

LL slove(int x,int y)
{
    LL res = C(k,x+y);
    res = (res +MOD -C(k,x))%MOD;
    return res;
}

int main()
{
    int T=Scan();
    while(T--)
    {
        n = Scan();k = Scan();
        for (int i=0;i<n;i++)
            a[i] = Scan();
        LL ans = 0;
        for (int i=0;i<20;i++)
        {
            int zero=0,one=0;
            for (int j=0;j<n;j++)
                if ((a[j]>>i)&1) one++;
                else zero++;
            ans = (ans + (1LL<<i)*slove(zero,one)%MOD )%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
