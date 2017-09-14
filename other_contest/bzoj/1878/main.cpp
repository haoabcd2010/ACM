#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MXN 50005
#define MXM 200005
struct Que
{
    int l,r;
    int id;
    int ans;
}q[MXM];

int n,m;
int a[MXN];
int pos[1000005];
int nex[MXN];
int tree[MXN];

int lowbit(int x){return x&(-x);}
bool cmp1(const Que &a,const Que &b)
{
    return a.l<b.l;
}
bool cmp2(const Que &a,const Que &b)
{
    return a.id<b.id;
}

void update(int x,int k)
{
    for (int i=x;i<=n;i+=lowbit(i))
        tree[i]+=k;
}

int query(int x)
{
    int res=0;
    for (int i=x;i>0;i-=lowbit(i))
        res+=tree[i];
    return res;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=n;i>0;i--)
    {
        nex[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    for (int i=0;i<MXM;i++) //³õÊ¼»¯
        if (pos[i]) update(pos[i],1);


    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q,q+m,cmp1);

    int l=1;
    for (int i=0;i<m;i++)
    {
        while (l<q[i].l)
        {
            if (nex[l]) update(nex[l],1);
            l++;
        }
        q[i].ans = query(q[i].r)-query(q[i].l-1);
    }

    sort(q,q+m,cmp2);
    for (int i=0;i<m-1;i++)
        printf("%d\n",q[i].ans);
    printf("%d\n",q[m-1].ans);
    return 0;
}
