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
# define MX 100005
/**************************/
struct Edge
{
    int v,nex;
}edge[MX*10];

int n,m,a,b,ip;
int hlist[MX];
LL dis[MX];
bool vis[MX];
void addedge(int u,int v)
{
    edge[ip]= (Edge){v,hlist[u]};
    hlist[u]=ip++;
    edge[ip]= (Edge){u,hlist[v]};
    hlist[v]=ip++;
}

void bfsB() // 1-n Á¬b±ß
{
    dis[n]=INF;
    memset(vis,0,sizeof(vis));
    queue<int> Q;
    Q.push(1);
    dis[1]=0;
    vis[1]=1;
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        for (int i=hlist[u];i!=-1;i=edge[i].nex)
        {
            int v = edge[i].v;
            if (!vis[v])
            {
                dis[v]=dis[u]+1;
                Q.push(v);
                vis[v]=1;
            }
        }
        if (dis[n]!=INF) break;
    }
    printf("%lld\n",min(dis[n]*a,(LL)b));
}

void bfsA() //1-n Á¬a±ß
{
    dis[n]=INF;
    set<int> st,ts;
    for (int i=2;i<=n;i++) st.insert(i);
    set<int>::iterator it;
    queue<int> Q;
    Q.push(1);
    dis[1]=0;
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        for (int i=hlist[u];i!=-1;i=edge[i].nex)
        {
            int v=edge[i].v;
            if (st.count(v)==0) continue;
            st.erase(v); ts.insert(v);
        }
        for (it=st.begin();it!=st.end();it++)
        {
            dis[*it] = dis[u]+1;
            Q.push(*it);
        }
        if (dis[n]!=INF) break;
        st.swap(ts);
        ts.clear();
    }
    printf("%lld\n",min(dis[n]*b,(LL)a));
}


int main()
{
    while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF)
    {
        memset(hlist,-1,sizeof(hlist));
        ip=0;
        bool flag=0;
        for (int i=0;i<m;i++)
        {
            int u = scan();
            int v = scan();
            addedge(u,v);
            if (u>v) swap(u,v);
            if (u==1&&v==n) flag=1;
        }
        if (flag)
        {
            if (a<b) printf("%d\n",a);
            else bfsA();
        }
        else
        {
            if (b<a) printf("%d\n",b);
            else bfsB();
        }
    }
    return 0;
}
