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
# define MX 1005
/**************************/
struct Point{
    int id;
    int to;
    int x,y;
    bool operator<(Point &b)const{
        if (x!=b.x) return x<b.x;
        return y<b.y;
    }
}pt[MX];

double xie(int a,int b)
{
    return (1.0*pt[a].y-pt[b].y)/(pt[a].x-pt[b].x);
}

int main()
{
    int  n = scan();
    for (int i=1;i<=n;i++)
    {
        pt[i].x=scan();
        pt[i].y=scan();
        pt[i].id=i;
    }
    sort(pt+1,pt+n+1);
    int ok=-1;
    if (n==2) ok=0;
    else
    {
        double sb = xie(2,1);
        for (int i=3;i<=n;i++)
        {
            double xx = xie(i,i-1);
            if( fabs(sb-xx)>eps)
                ok=1;
        }
        if (ok==-1) ok=0;
    }

    if (ok==0)
        printf("-1\n");
    else
    {
        for (int i=1;i<n;i++)
            pt[i].to=pt[i+1].id;

        if (pt[n-1].x!=pt[n].x)
        {
            pt[n].to=pt[n-2].id;
        }
        else
        {
            for (int i=n-1;i>=1;--i)
            if (pt[i].x!=pt[n].x)
            {
                pt[n].to=pt[i].id;
                break;
            }
        }
        for (int i=1;i<=n;i++)
            printf("%d %d\n",pt[i].id,pt[i].to);
    }
    return 0;
}
