#include <bits/stdc++.h>
using namespace std;
# define LL          long long
# define pr          pair
# define mkp         make_pair
# define lowbit(x)   ((x)&(-x))
# define PI          acos(-1.0)
# define INF         0x3f3f3f3f3f3f3f3f
# define eps         1e-6
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
# define MX 2005
/**************************/

int n, z, w;
int dat[MX];

int main()
{
    scanf("%d%d%d",&n,&z,&w);
    for (int i=1;i<=n;i++)
        scanf("%d",&dat[i]);
    int score = abs(dat[n] - w);
    if (n>1)
    {
        int tp = abs(dat[n-1] - dat[n]);
        score = max(tp,score);
    }
    if (n>2)
    {
        int tp = abs(dat[n-2] - dat[n]);
        int tp2 = abs(dat[n-1]-dat[n]);
        tp = min(tp2,tp);
        score = max(tp,score);
    }
    printf("%d\n",score);
    return 0;
}
