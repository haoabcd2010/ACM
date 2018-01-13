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
using namespace std;
# define LL          long long
# define pr          pair
# define mkp         make_pair
# define lowbit(x)   ((x)&(-x))
# define PI          acos(-1.0)
# define INF         0x3f3f3f3f3f3f3f3f
# define eps         1e-8
# define MOD         1000000007

inline LL scan() {
    LL x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
inline void Out(int a) {
    if(a<0) {putchar('-'); a=-a;}
    if(a>=10) Out(a/10);
    putchar(a%10+'0');
}
# define MX 100005
/**************************/

int n,p;
LL sum[3][MX];

int main()
{
    n=scan(); p=scan();
    for (int i=0;i<3;i++)
    {
        for (int j=1;j<=n;j++)
        {
            sum[i][j]=scan();
            sum[i][j]=(sum[i][j]+sum[i][j-1])%p;
        }
    }
    int ans = (sum[0][1]+sum[1][1]+sum[1][n])%p;
    set<int> s;
    for (int i=1;i<=n;i++)
    {
        int tp = (sum[0][i]-sum[1][i-1]+p)%p;
        s.insert( tp );
        int dat = (sum[1][i]+sum[2][n]-sum[2][i-1]+p)%p;
        set<int>::iterator it = s.lower_bound(p-dat);
        if (it!=s.end())
        {
            if (it!=s.begin())
            {
                it--;
                ans = max((LL)ans,(*it+sum[1][i]+sum[2][n]-sum[2][i-1]+p)%p);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
