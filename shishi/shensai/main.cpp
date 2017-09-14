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
# define pi          pair
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
# define MX 200010
/**************************/
double s;
double cal(double x)
{
    return 1.0/3*PI*x*x*sqrt( (s/(PI*x)-x)*(s/(PI*x)-x) - x*x ) ;
}

int main()
{
    scanf("%lf",&s);
    double l = 0,r = 1e9;

    while (l+eps<r)
    {
        double san = (r-l)/3;
        double lm = l+san, rm = r-san;
        double lv = cal(lm) ,rv = cal(rm);
        if (lv+eps<rv) l = lm;
        else r = rm;
    }
    double ans = cal(l);
    printf("%.6f\n",ans);
    return 0;
}
