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
struct note
{
    int v,next;
}edge[MX*10];

int n,m,vis[MX];
LL a,b,dis[MX];
set<int>st,ts;
set<int>::iterator it;
int head[MX],ip;

void init()
{
    memset(head,-1,sizeof(head));
    ip=0;
}
void addedge(int u,int v)
{
    //edge[ip].v=v,edge[ip].next=head[u],head[u]=ip++;
    edge[ip]=(note){v,head[u]};
    head[u]=ip++;
}
void spfa()
{
    queue<int>q;
    for(int i=0;i<=n;i++)dis[i]=INF;
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    printf("%lld\n",min(dis[n]*a,b));
}
void bfs()
{
    dis[n]=INF;
    st.clear(),ts.clear();
    for(int i=2;i<=n;i++)st.insert(i);
    queue<int>q;
    q.push(1);
    dis[1]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(st.count(v)==0)continue;
            st.erase(v),ts.insert(v);
        }
        for(it=st.begin();it!=st.end();it++)
        {
            q.push(*it);
            dis[*it]=dis[u]+1;
        }
        st.swap(ts);
        ts.clear();
    }
    printf("%lld\n",min(dis[n]*b,a));
}
int main()
{
    while(~scanf("%d%d%lld%lld",&n,&m,&a,&b))
    {
        init();
        int flag=0;
        for(int i=0;i<m;i++)
        {
            int u =scan();
            int v =scan();
            if(u>v) swap(u,v);
            addedge(u,v);
            addedge(v,u);
            if(u==1&&v==n) flag=1;
        }
        if(flag)
        {
            if (a<b) printf("%d\n",a);
            else bfs();
        }
        else
        {
            if (b<a) printf("%d\n",b);
            else spfa();
        }
    }
    return 0;
}
