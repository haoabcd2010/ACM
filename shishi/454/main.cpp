#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MX 100005

int n,a,b;
int dat[MX];
bool use[MX];

int bi_search(int x)
{
    int l =1, r=n;
    while (l<=r)
    {
        int mid = (l+r)>>1;
        if (dat[mid]>x) r = mid - 1;
        else if (dat[mid]<x) l = mid + 1;
        else
        {
            if (use[mid]) return -1;
            return mid;
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for (int i=1;i<=n;i++)
        scanf("%d",&dat[i]);
    sort(dat+1,dat+1+n);
    bool ok =1;
    for (int i=1;i<=n;i++)
    {
        if (use[i]) continue;
        int x = bi_search(a-dat[i]);
        int y = bi_search(b-dat[i]);
        if (x==-1&&y==-1)
        {
            ok=0; break;
        }
        else if (x!=-1&&y!=-1)
        {
            int xx = bi_search(a-dat[y]);
            int yy = bi_search(b-dat[x]);
            if (xx!=-1)
                use[i] = use[x] = use[y] = use[xx] =1;
            else if (yy!=-1)
                use[i] = use[x] = use[y] = use[yy] =1;
            else
            {
                ok=0; break;
            }
        }
        else if (x!=-1)
            use[i]=use[x]=1;
        else if (y!=-1)
            use[i]=use[y]=1;
    }
    if (ok)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
