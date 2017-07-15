/*
//AAA
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 100010

int a[MX];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int sum1=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum1+=x;
            if (x) a[i]=-1;
            else a[i]=1;
        }
        int mmm=-1,rec=0;   //mmm=-1 因为必须要翻一次,全为 1 时
        for (int i=1;i<=n;i++)
        {
            if (rec>0) rec+=a[i];
            else rec=a[i];
            mmm = max(rec,mmm);
        }
        printf("%d\n",mmm+sum1);
    }
    return 0;
}
*/

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MX 1005
struct Node
{
    int u,v;
    int d;
    bool operator < (const Node &b)const{
        return d>b.d;
    }
};
int n,m,w;
char str[MX][15];
priority_queue<Node> Q;
int f[MX];

int find_h(int x){
    if (x!=f[x])
        f[x]=find_h(f[x]);
    return f[x];
}

void krus()
{
    for (int i=0;i<n;i++)
        f[i]=i;
    int res = m; //star at 0
    int num=1;
    while (!Q.empty())
    {
        Node tp = Q.top();
        Q.pop();
        int x=find_h(tp.u),y=find_h(tp.v);
        if (x!=y)
        {
            res+=tp.d;
            f[x]=y;
            num++;
        }
        if (num==n) break;
    }
    printf("%d\n",res);
}

int main()
{
    while (scanf("%d%d%d",&n,&m,&w)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%s",str[i]);
        while (!Q.empty()) Q.pop();
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (i==j) continue;
                int cp=0;
                for (int k=0;k<m;k++)
                    if (str[i][k]!=str[j][k])
                        cp++;
                Q.push((Node){i,j,min(m,cp*w)});
            }
        }
        krus();
    }
    return 0;
}

/*
//lang
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define MX 100005

struct Edge{
    int u,v,cost;
    int nex;
}edge[MX];

int n,m,S,E;
int r_m;
int headlist[MX];
int end_e[MX];
int vis[MX];
int dis[MX];

void add_edge(int u,int v,int c)
{
    edge[r_m]=(Edge){u,v,c,headlist[u]};
    headlist[u]=r_m;
    r_m++;
}

int spfa(int star)
{
    queue<int> Q;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    Q.push(star);
    vis[star]=1;dis[star]=0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u]=0;
        for (int i=headlist[u];i!=-1;i=edge[i].nex)
        {
            int v=edge[i].v,w=edge[i].cost;
            if (dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if (!vis[v])
                {
                    Q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    int ret=INF;
    for (int i=0;i<n;i++)
    {
        if (end_e[i]&&dis[i]<ret)
            ret = dis[i];
    }
    return ret;
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        r_m=0;
        memset(headlist,-1,sizeof(headlist));
        for (int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,c);
        }
        scanf("%d",&S);
        for (int i=0;i<S;i++)
        {
            int x;
            scanf("%d",&x);
            add_edge(n+1,x,0);
        }
        scanf("%d",&E);
        memset(end_e,0,sizeof(end_e));
        for (int i=0;i<E;i++)
        {
            int x;
            scanf("%d",&x);
            end_e[x]=1;
        }
        printf("%d\n",spfa(n+1));
    }
    return 0;
}
*/

/*
//HHH
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 1000005

int num[MX];
int sav[MX];

int calc(int l,int r)
{
    if (l>r) return 0;
    int mmm=1;
    int tp=1;
    for (int i=l+1;i<=r;i++)
    {
        if (num[i]>=num[i-1]) tp++;
        else tp=1;
        mmm = max(mmm,tp);
    }
    return mmm;
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n<=0)
        {
            printf("0\n");
            continue;
        }
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }

        int pre=num[1];
        memset(sav,0,sizeof(sav));
        sav[1]=1;
        for (int i=2;i<=n;i++)
        {
            if (num[i]>=pre)
            {
                sav[i]=1;
                pre=num[i];
            }
        }
        int mxlen=0;
        pre=1;
        for (int i=2;i<=n+1;i++)
        {
            if (sav[i]==1||i==n+1)
            {
                mxlen=max(mxlen,calc(pre+1,i-1));
                pre=i;
            }
        }

        printf("%d\n",mxlen);
        printf("%d",num[1]);
        for (int i=2;i<=n;i++)
        {
            if (sav[i])
            {
                printf(" %d",num[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
*/
