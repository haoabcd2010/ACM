/*
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MX 100005

int n;
LL A[MX];
LL C[MX];
int lowbit(int x){
    return x&(-x);
}

void update(int p)
{
    while (p<=n)
    {
        C[p]=A[p];
        for (int i=1;i<lowbit(p);i<<=1)
            C[p]=max(C[p],C[p-i]);
        p+=lowbit(p);
    }
}

LL query(int x,int y)
{
    LL ret = 0;
    while (y>=x)
    {
        ret = max(ret,A[y]);
        y--;
        while (y-lowbit(y)>=x)
        {
            ret = max (ret,C[y]);
            y-=lowbit(y);
        }
    }
    return ret;
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        int q;
        scanf("%d",&q);
        memset(A,0,sizeof(A));
        memset(C,0,sizeof(C));
        while (q--)
        {
            int op;
            scanf("%d",&op);
            if (op==1)
            {
                int p,x;
                scanf("%d%d",&p,&x);
                A[p]+=x;
                update(p);
            }
            else if (op==2)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%lld\n",query(x,y));
            }
        }
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MX 100005
struct Node
{
    int l,r;
    LL m;
}tree[MX*4];
int n;

void Init(int l,int r,int k)
{
    tree[k].l=l,
    tree[k].r=r;
    tree[k].m=0;
    if (l==r) return ;

    int mid = (l+r)>>1;
    Init(l,mid,2*k);
    Init(mid+1,r,2*k+1);
}

LL update(int l,int r,int k,int w)
{
    if (l==tree[k].l&&tree[k].r==r)
    {
        tree[k].m+=w;
        return tree[k].m;
    }
    int mid = (tree[k].l+tree[k].r)>>1;
    if (r<=mid) update(l,r,2*k,w);
    else if (l>=mid+1) update(l,r,2*k+1,w);
    else update(l,mid,2*k,w),update(mid+1,r,2*k+1,w);
    tree[k].m= max(tree[2*k].m,tree[2*k+1].m);
    return tree[k].m;
}

LL query(int l,int r,int k)
{
    if (tree[k].l==l&&tree[k].r==r)
    {
        return tree[k].m;
    }
    int mid = (tree[k].l+tree[k].r)>>1;
    if (r<=mid) return query(l,r,2*k);
    else if (l>=mid+1) return query(l,r,2*k+1);
    return max(query(l,mid,2*k),query(mid+1,r,2*k+1));
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        Init(1,n,1);
        int q;
        cin>>q;
        while (q--)
        {
            int op;
            scanf("%d",&op);
            if(op==1)
            {
                int q,x;
                scanf("%d%d",&q,&x);
                update(q,q,1,x);
            }
            else if (op==2)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%lld\n",query(x,y,1));
            }
        }
    }
    return 0;
}
