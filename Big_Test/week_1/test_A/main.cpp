/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAXN 100010
#define INF 1000000000
struct Node
{
    int x;
    int p;  //原位置
}num[MAXN];
int n;
int c[MAXN];    //原位置对应排序的位置
int li[MAXN];
int pre[MAXN];
int nex[MAXN];

bool cmp(Node a,Node b)
{
    return a.x<b.x;
}

int calc(int x)
{
    int x1=-INF,x2=INF;
    if(pre[x]>=1)
        x1=li[pre[x]];
    if(nex[x]<=n)
        x2=li[nex[x]];
    return min(abs(li[x]-x1),abs(li[x]-x2));
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i].x);
            num[i].p=i;
        }
        sort(num+1,num+1+n,cmp);
        int ed = num[n].x;
        for(int i=1;i<=n;i++)
        {
            li[i]=num[i].x;
            c[num[i].p]=i;
            pre[i]=i-1;
            nex[i]=i+1;
        }
        int ans = 0 ;
        for (int i=1;i<n;i++)
        {
            ans += calc(c[i]);
                nex[pre[c[i]]] = nex[c[i]];
                pre[nex[c[i]]] = pre[c[i]];
        }
        ans += ed;
        printf("%d\n",ans);
    }
    return 0;
}
*/

#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxn 100000+10
const int INF=1000000000;
struct Node
{
    int x,p;
    bool operator <(const Node&b)const
    {return x<b.x;}
}num[maxn];
int n;
int c[maxn];
int li[maxn];
int pre[maxn];
int nex[maxn];


int calc(int x)
{
    int res = INF;
    if(pre[x]>=1)
        res = min (res,li[x]-li[pre[x]]);
    if(nex[x]<=n)
        res = min (res,li[nex[x]]-li[x]);
    return res;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i].x);
            num[i].p=i;
        }
        sort(num+1,num+n+1);
        for(int i=1;i<=n;i++)
        {
            li[i]=num[i].x;
            c[num[i].p]=i;
            pre[i]=i-1;
            nex[i]=i+1;
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            ans+=calc(c[i]);
            pre[nex[c[i]]]=pre[c[i]];//更新链表
            nex[pre[c[i]]]=nex[c[i]];//
        }
        ans +=li[c[n]];
        printf("%d\n",ans);
    }
    return 0;
}
