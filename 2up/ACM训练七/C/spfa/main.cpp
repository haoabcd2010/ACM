/*
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int head[10000];

struct edge{
	int to,next,v;
}e[50000];

int n,p,k,cnt,l,r=10000000;
int ans=-1;
int dis[1001],q[1001],inq[1001];
int fa[10000];

void insert(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].v=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

bool spfa(int x)
{
     memset(dis,127/3,sizeof(dis));
     int t=0,w=1,i,now,s;//t 记录到队列哪个位置，w记录队列里有多少元素
     dis[1]=0;q[t]=1;inq[1]=1;
     while(t!=w)
     {
        now=q[t];t++;
        if(t==1001) t=0;
        i=head[now];
        while(i)
        {
            if(e[i].v>x) s=dis[now]+1;//如果 u -> v 这条边大于 x ，s=dis[u]+1;
            else s=dis[now];
            if(s<dis[e[i].to])
            {
                dis[e[i].to]=s;
                if(!inq[e[i].to])//避免重复入队
                {
                    q[w++]=e[i].to;
                    inq[e[i].to]=1;
                    if(w==1001)w=0;
                }
            }
            i=e[i].next;
        }
        inq[now]=0;//标记 now 这个点不在队列中
    }
    if(dis[n]<=k)return 1;//到n点最少有多少超过 x 长度的线
    return 0;
 }

int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for (int i=1;i<=p;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		insert(x,y,z);
		insert(y,x,z);
	}
	while (l<=r)
	{
		int mid=(l+r)>>1;
		//printf("%d\n",mid);
		if (spfa(mid)) // 1 左区间
        {
            ans=mid;
            r=mid-1;
        }
		else l=mid+1; //右区间
	}
	cout<<ans;
}
*/


#include <stdio.h>
#include <string.h>

#define MAXN 1005

struct Edge{
    int v,w;
    int next;
}edge[10005];
int headlist[MAXN];

int n,p,k,bian=0;

void join(int a,int b,int c)
{
    bian++;
    edge[bian].v=b;
    edge[bian].w=c;
    edge[bian].next=headlist[a];
    headlist[a]=bian;
}

int Q[1000];
int vis[MAXN];
int dis[MAXN];//大于limit的有多少个
int spfa(int limit)
{
    for (int i=1;i<=n;i++)
        dis[i]=10000000;//kanknkkkkkkkkkkkkk
    memset(vis,0,sizeof(vis));

    Q[0]=1;
    int l=0,r=1;
    dis[1]=0,vis[1]=1;
    while (l!=r)
    {
        int now=Q[l++];
        if (l==1000) l=0;
        vis[now]=0;
        int i=headlist[now];
        int mm=dis[now];
        while (i)
        {
            if (edge[i].w>limit) mm=dis[now]+1;
            else mm=dis[now];
            if (mm<dis[edge[i].v])
            {
                dis[edge[i].v]=mm;
                if (vis[edge[i].v]==0)
                {
                    Q[r++]=edge[i].v;
                    if (r==1000) r=0;
                    vis[edge[i].v]=1;
                }
            }
            i=edge[i].next;
        }
    }
    if (dis[n]<=k) return 1;//
    return 0;
}

int main()
{
    scanf("%d%d%d",&n,&p,&k);
    int a,b,c;
    for (int i=1;i<=p;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        join(a,b,c);
        join(b,a,c);
    }
    int l=0,r=1000000,ans=-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (spfa(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}

