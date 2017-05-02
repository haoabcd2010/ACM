/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 1000005
#define int_INF 2147483647

int n,k;
int ans;

struct Zhu
{
    int pos;
    int kind;
    bool operator < (const Zhu b)const{return pos<b.pos;}
}zhu[MAXN];

int k_num;
int kind[100];

int bi_search(int x,int y)
{
    memset(kind,0,sizeof(kind));
    k_num=0;
    for (int i=x;i<=y;i++)
    {
        if(kind[zhu[i].kind]==0)
        {
            kind[zhu[i].kind]=1;
            k_num++;
        }
        if (k_num==k)
        {
            if (zhu[y].pos-zhu[x].pos<ans)//¸üÐÂ´ð°¸
                ans = zhu[y].pos-zhu[x].pos;
            return 1;
        }
    }
    return 0;
}

void erfen(int p)
{
    int x=0,y=p-1;//×ó

    while (x<=y)
    {
        int mid = (x+y)/2;
        if (bi_search(mid,p))
            x=mid+1;
        else
            y=mid-1;
    }

    x=p+1,y=n-1;//ÓÒ
    while (x<=y)
    {
        //printf("%d %d\n",x,y);
        int mid = (x+y)/2;
        if (bi_search(p,mid))
            y=mid-1;
        else
            x=mid+1;
    }
}

int main()
{
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        int num=0;
        for (int i=0;i<k;i++)
        {
            int x;
            scanf("%d",&x);
            while (x--)
            {
                int p;
                scanf("%d",&p);
                zhu[num++]=(Zhu){p,i};
            }
        }
        sort(zhu,zhu+n);

        ans = int_INF;

        for (int i=0;i<n;i++)
            erfen(i);

        printf("%d\n",ans);
    }
    return 0;
}
*/
/*
6 3
1 2
2 3 3
3 6 5 5
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 1000005
#define int_INF 2147483647

struct Zhu
{
    int pos;
    int kind;
    bool operator < (const Zhu b)const{return pos<b.pos;}
}zhu[MAXN];

int n,k;
int ans;
int kind_n;
int kind[100];

int main()
{
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        int num=0;
        for (int i=0;i<k;i++)
        {
            int x;
            scanf("%d",&x);
            while (x--)
            {
                int p;
                scanf("%d",&p);
                zhu[num++]=(Zhu){p,i};
            }
        }
        sort(zhu,zhu+n);

        ans = int_INF;

        memset(kind,0,sizeof(kind));
        kind_n=0;
        int l=0,r=0;
        while (1)
        {
            while(kind_n<k&&r<)
        }

        printf("%d\n",ans);
    }
    return 0;
}
