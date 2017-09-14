# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <cmath>
# include <algorithm>
using namespace std;
# define lowbit(x) ((x)&(-x))
# define pi acos(-1.0)
# define eps 1e-3
# define MOD 100000007
# define INF 1000000000
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(int i=a; i<=n; ++i)
# define FO(i,a,n) for(int i=a; i<n; ++i)
# define bug puts("H");
# define lch p<<1,l,mid
# define rch p<<1|1,mid+1,r
# define mp make_pair
# define pb push_back
typedef pair<int,int> PII;
typedef vector<int> VI;
# pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long LL;
int Scan() {
    int res=0, flag=0;
    char ch;
    if((ch=getchar())=='-') flag=1;
    else if(ch>='0'&&ch<='9') res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')  res=res*10+(ch-'0');
    return flag?-res:res;
}
void Out(int a) {
    if(a<0) {putchar('-'); a=-a;}
    if(a>=10) Out(a/10);
    putchar(a%10+'0');
}
const int N=100005;
//Code begin...

struct qnode{
    int v;
    LL c;
    qnode(int _v=0, LL _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const{return c>r.c;}
};
struct Edge{int p, next, w;}edge[N<<1];
struct Node{int u, v, w;}node[N];
int head[N], cnt=1, id[N];
LL dist[N];
bool vis[N];
priority_queue<qnode>que;
const int P=16;

void add_edge(int u, int v, int w){
    edge[cnt].p=v; edge[cnt].next=head[u];
    edge[cnt].w=w; head[u]=cnt++;
}
void init(){mem(head,0); cnt=1;}
void Dijkstra(int n, int start){
    mem(vis,false); FOR(i,0,n) dist[i]=(LL)1<<60;
    dist[start]=0; que.push(qnode(start,0));
    qnode tmp;
    while (!que.empty()) {
        tmp=que.top(); que.pop();
        int u=tmp.v;
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=head[u]; i; i=edge[i].next) {
            int v=edge[i].p, cost=edge[i].w;
            if (!vis[v]&&dist[v]>dist[u]+cost) {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
int main ()
{
    int T, n, m, u, v, w, s, t, K;
    scanf("%d",&T);
    FOR(cas,1,T) {
        LL ans=(LL)1<<60;
        scanf("%d%d",&n,&m); s=0; t=n+1;
        FOR(i,1,m) scanf("%d%d%d",&node[i].u,&node[i].v,&node[i].w);
        scanf("%d",&K);
        FOR(i,1,K) scanf("%d",id+i);
        FOR(i,0,P) {
            init();
            FOR(j,1,m) add_edge(node[j].u,node[j].v,node[j].w);
            FOR(j,1,K) {
                if ((id[j]>>i)&1) add_edge(s,id[j],0);
                else add_edge(id[j],t,0);
            }
            if (!head[s]) continue;
            Dijkstra(t,s);
            ans=min(ans,dist[t]);
        }
        FOR(i,0,P) {
            init();
            FOR(j,1,m) add_edge(node[j].u,node[j].v,node[j].w);
            FOR(j,1,K) {
                if ((id[j]>>i)&1) add_edge(id[j],t,0);
                else add_edge(s,id[j],0);
            }
            if (!head[s]) continue;
            Dijkstra(t,s);
            ans=min(ans,dist[t]);
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
