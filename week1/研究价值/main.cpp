#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node
{
    int t;  //温度
    int c;  //0 等于 t, 1 大于 t
    int w;  //增减
    bool operator < (const Node b) const
    {
        if(t!=b.t)
            return t<b.t;
        if (c!=b.c)
            return c<b.c;
        return w<b.w;
    }
}node[100005];
int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        long long val=0,num=0;
        for (int i=0;i<n;i++)
        {
            int l,r,a,b,c;
            scanf("%d%d%d%d%d",&l,&r,&a,&b,&c); // 适中，超过，低于
            val+=c;
            node[num++]=(Node){l,0,a-c};
            node[num++]=(Node){r,1,b-a};
        }
        sort(node,node+num);
        long long ans=val;    //最低温度的价值
        for (int i=0;i<num;i++)
        {
            val+=node[i].w;
            ans=max(val,ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

/*
//自己想的比较差的算法 n^2

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct plant
{
    int l,r;
    int on,high,low;
    bool operator < (const plant & b) const
    {return l<b.l;}
}pl[50002];

int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d%d%d%d%d",&pl[i].l,&pl[i].r,&pl[i].on,&pl[i].high,&pl[i].low);
        sort(pl,pl+n);
        int ans=0;
        for (int i=0;i<n;i++)
        {
            int w1=0,w2=0;
            double s = (double)pl[i].l-0.5;
            int k = pl[i].l;
            for (int j=0;j<n;j++)
            {
                if (pl[j].l>s)
                    w1+=pl[j].low;
                else if (pl[j].l<s&&pl[j].r>s)
                    w1+=pl[j].on;
                else
                    w1+=pl[j].high;

                if (pl[j].l>k)
                    w2+=pl[j].low;
                else if (pl[j].l<=s&&pl[j].r>=s)
                    w2+=pl[j].on;
                else
                    w2+=pl[j].high;
            }
            ans=max(w1,ans);
            ans=max(w2,ans);
        }

        int w1=0,w2=0;
        int s = pl[n-1].r+1;
        int k = pl[n-1].r;
        for (int j=0;j<n;j++)
        {
            if (pl[j].l>s)
                w1+=pl[j].low;
            else if (pl[j].l<s&&pl[j].r>s)
                w1+=pl[j].on;
            else
                w1+=pl[j].high;

            if (pl[j].l>k)
                w2+=pl[j].low;
            else if (pl[j].l<=s&&pl[j].r>=s)
                w2+=pl[j].on;
            else
                w2+=pl[j].high;
        }
        ans=max(w1,ans);
        ans=max(w2,ans);

        printf("%d\n",ans);
    }
    return 0;
}
*/
