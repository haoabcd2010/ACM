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
# define MX 100005
/**************************/

int n;
LL ans;
int num[MX];
int AND[MX];
int OR[MX];
int tot[MX];

void dfs(int l,int r)
{
    if (l==r)
    {
        ans = (ans+(LL)num[l]*num[r]%MOD)%MOD;
        return;
    }
    int mid = (l+r+1)>>1;
    int pos = mid;
    tot[pos]=0; AND[pos]=OR[pos]=num[pos];
    for (int i=mid;i<=r;i++)
    {
        if ( (num[i]&AND[pos]) != AND[pos] || (num[i]|OR[pos]) != OR[pos] )
        {
            pos++;
            AND[pos] = (num[i]&AND[pos-1]);
            OR[pos] = (num[i]|OR[pos-1]);
            tot[pos]=1;
        }
        else tot[pos]++;
    }
    int tpA = num[mid-1];
    int tpO = num[mid-1];
    for (int i=mid-1;i>=l;i--)
    {
        tpA&=num[i], tpO|=num[i];
        for (int j=mid;j<=pos;j++)
            ans = (ans + ((tpA&AND[j])*(tpO|OR[j])%MOD) *tot[j]%MOD)%MOD;
    }
    dfs(mid,r);
    dfs(l,mid-1);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        num[i]=scan();
    ans = 0;
    dfs(1,n);
    printf("%I64d\n",ans);
    return 0;
}
