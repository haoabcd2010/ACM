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
struct Node
{
    int l,r;
    int sum;
}tree[MX*40];
int n,m;
int tcnt,newn;  //结点数
int root[MX];   //每颗树的起点
int dat[MX];    //原始数据
int cpy[MX];    //离散数据

int getid(int x){return lower_bound(cpy+1,cpy+1+newn,x)-cpy;}

int update(int l,int r,int yy,int pos)
{
    tcnt++;
    tree[tcnt].sum = tree[yy].sum+1;
    int sav = tcnt;
    if (l==r) return sav;
    int mid = (l+r)/2;
    if (pos<=mid)
    {
        tree[sav].l = update(l,mid,tree[yy].l,pos);
        tree[sav].r = tree[yy].r;
    }
    else
    {
        tree[sav].l = tree[yy].l;
        tree[sav].r = update(mid+1,r,tree[yy].r,pos);
    }
    return sav;
}

int query(int x,int y,int k,int l,int r)
{
    if (l==r) return l;
    int sum = tree[ tree[y].l ].sum - tree[ tree[x].l ].sum;
    int mid = (l+r)/2;
    if (sum>=k)
        return query(tree[x].l,tree[y].l,k,l,mid);
    else
        return query(tree[x].r,tree[y].r,k-sum,mid+1,r);
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            dat[i] = scan();
            cpy[i] = dat[i];
        }
        sort(cpy+1,cpy+1+n);
        newn = unique(cpy+1,cpy+1+n) - (cpy+1);
        for (int i=1;i<=n;i++)
        {
            root[i] = update(1,newn,root[i-1],getid(dat[i]));
        }
        while(m--)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",cpy[query(root[l-1],root[r],k,1,newn)]);
        }
    }
    return 0;
}
