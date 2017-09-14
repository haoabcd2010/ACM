# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <bitset>
# include <sstream>
# include <set>
# include <cmath>
# include <algorithm>
# pragma  comment(linker,"/STACK:102400000,102400000")
using namespace std;
# define LL          long long
# define pr          pair
# define mkp         make_pair
# define lowbit(x)   ((x)&(-x))
# define PI          acos(-1.0)
# define INF         0x3f3f3f3f3f3f3f3f
# define eps         1e-8
# define MOD         1000000007

inline int scan() {
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
#define MX 10
/**************************/
struct Mat
{
    LL m[MX][MX];
}unit,di,fir;

LL n,k;

Mat mult(Mat a,Mat b)
{
    Mat c;
    for (int i=0;i<MX;i++)
        for (int j=0;j<MX;j++)
        {
            c.m[i][j]=0;
            for (int k=0;k<MX;k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
        }
    return c;
}

Mat cal(LL p)
{
    Mat ret = unit, b = di;
    while (p)
    {
        if (p&1) ret = mult(ret,b);
        b = mult(b,b);
        p/=2;
    }
    return ret;
}

void Init()
{
    for (int i=0;i<MX;i++)
        unit.m[i][i]=1;
    for (int i=1;i<MX;i++)
    {
        if (i<=k)
            fir.m[i][0]=1;
    }
    for (int i=0;i<MX;i++)
    {
        for (int j=0;j<MX;j++)
        {
            if (i<=k&&j<=k&&i*j<=k)
                di.m[i][j]=di.m[j][i]=1;
        }
    }
}

int main()
{
    scanf("%lld%lld",&n,&k);
    Init();
    Mat sa = fir;
    Mat sb = cal(n-1);
    sb = mult(sb,sa);

    LL ans = 0;
    for (int i=0;i<MX;i++)
    {
        ans = (ans + sb.m[i][0])%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
