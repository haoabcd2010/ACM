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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL          long long
#define lowbit(x)   ((x)&(-x))
#define PI          acos(-1.0)
#define INF         0x3f3f3f3f
#define eps         1e-8
#define MOD         1000000007

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
#define MX 100005
/**************************/
int n,m;
LL ans;
int a[MX];
int b[MX];
vector<int> G[MX];
bool vis[MX];
int w[MX];

void dfs(int x)
{
    vis[x]=1;
    w[x]=b[x];
    for (int i=0;i<G[x].size();i++)
    {
        if (!vis[G[x][i]]) dfs(G[x][i]);

        w[x]= (w[x] + w[G[x][i]]);
        ans = ((ans + (LL)a[x]*w[G[x][i]])%MOD)%MOD;
    }
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            a[i] = scan();
            b[i] = scan();
        }
        for (int i=1;i<=m;i++) G[i].clear();
        for (int i=1;i<=m;i++)
        {
            int u,v;
            u = scan(); v = scan();
            G[u].push_back(v);
        }
        memset(vis,0,sizeof(vis));

        ans = 0;
        for (int i=1;i<=n;i++)
        {
            if (!vis[i]) dfs(i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
