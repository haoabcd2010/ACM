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
# define eps         1e-15
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
# define MX 2500
/**************************/

int n,m;
int st[MX];

LL C(LL a,LL b)
{
    if (b<2) return 0;
    return b*(b-1)/2;
}

double gai(int a,int b)
{
    int all =0 ;
    int jiao =0;
    for (int i=0;i<m;i++)
    {
        if ( (a&(1<<i)) || (b&(1<<i)) ) all++;
        if ( (a&(1<<i)) && (b&(1<<i)) ) jiao++;
    }
    return (jiao*1.0)/all;
}

int main()
{


    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(st,0,sizeof(st));
        for (int i=1;i<=n;i++)
        {
            int num;
            scanf("%d",&num);
            int sb=0;
            for (int j=1;j<=num;j++)
            {
                int x;
                scanf("%d",&x);
                sb = (sb ^ (1<<(x-1)));
            }
            st[sb]++;
        }
        double p;
        scanf("%lf",&p);

        LL ans = 0;
        int ut = (1<<m);
        for (int i=1;i<ut;i++)
        {
            for (int j=i;j<ut;j++)
            {
                if (gai(i,j)-p>=eps)
                {
                    if (i==j) ans = ans+C(2,st[i]);
                    else ans = ans+((LL)st[i])*st[j];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
