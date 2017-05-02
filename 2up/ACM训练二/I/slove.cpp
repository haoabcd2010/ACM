/*
#include <stdio.h>
#include <map>
using namespace std;

map<int,int> num;
int data[300005];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        num.clear();
        int i;
        int ok=0;
        int l,r;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&data[i]);
            if (!ok)
            {
                if (num[data[i]]!=0)//有这个大小
                {
                    l=num[data[i]];
                    r=i;
                    ok=1;
                }
                num[data[i]]=i;
            }
        }
        if (ok)
        {
            if (l>1&&r<n)
            {
                printf("3\n");
                printf("%d %d\n",1,l-1);
                printf("%d %d\n",l,r);
                printf("%d %d\n",r+1,n);
            }
            if (l==1&&r<n)
            {
                printf("2\n");
                printf("%d %d\n",1,r);
                printf("%d %d\n",r+1,n);
            }
            if (l>1&&r==n)
            {
                printf("2\n");
                printf("%d %d\n",1,l-1);
                printf("%d %d\n",l,n);
            }
            if (l==1&&r==n)
            {
                printf("1\n");
                printf("%d %d\n",1,n);
            }
        }
        else printf("-1\n");

    }
    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define MAXN 300015

map<int,int> m;
int data[MAXN];

struct node
{
 int l,r;
}ans[MAXN/2];

int main()
{
    int n,k,st;
    while (scanf("%d", &n)!=EOF)
    {
        m.clear();
        st=0;
        k=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d", &data[i]);
            if (m[data[i]]==1)
            {
                k++;
                ans[k].l=st+1;
                ans[k].r=i;
                st=i;
                m.clear();
            }
            else m[data[i]]=1;
        }
        if (k==0) printf("%d",-1);
        else
        {
            printf("%d\n",k);
            for (int i=1;i<k;i++)
                printf("%d %d\n", ans[i].l, ans[i].r);
            printf("%d %d\n", ans[k].l,n);
        }
    }
    return 0;
}
