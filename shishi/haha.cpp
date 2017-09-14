# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <bitset>
# include <set>
# include <cmath>
# include <algorithm>
using namespace std;
#define lowbit(x) ((x)&(-x))
#define pi acos(-1.0)
#define eps 1e-8
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LL long long
inline int Scan() {
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
//Code begin...
struct Edge
{
    int a,b,c,t;
    int nex;
}edge[MX];
struct Node
{
    int e;
    int xian;
};
int hlist[MX];
int vis[MX];
int dis[MX];

void spfa()
{
    memset(dis,0x3f,sizeof(dis));
    queue<Node> Q;
    Q.push( (Node){1,-1} );
    dis[1]=0;
    while(!Q.empty())
    {
        Node now = Q.front();
        Q.pop();
        for (int i=hlist[now.e];i!=-1;i = edge[i].nex)
        {
            int v = edge[i].b , w = edge[i].t;
            if (now.xian!=edge[i].c) w+=abs(now.xian-edge[i].c);

            if (now.xian==-1) w = edge[i].t;
            if (dis[v]<dis[now.e]+w)
            {
                dis[v]=dis[now.e]+w;
                Q.push((Node){v,edge[i].c});
            }
        }
    }
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(hlist,-1,sizeof(hlist));
        int r_m=0;
        for (int i=1;i<=m;i++)
        {
            int a=Scan();
            int b=Scan();
            int c=Scan();
            int t=Scan();
            edge[r_m]=(Edge){a,b,c,t,hlist[a]};
            hlist[a]=r_m; r_m++;
            edge[r_m]=(Edge){b,a,c,t,hlist[b]};
            hlist[b]=r_m; r_m++;
        }
        spfa();
        printf("%d\n",dis[n]);
    }
    return 0;
}
