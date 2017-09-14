#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define LL long long
#define MXN 10000005
#define MXM 105

int num[MXM];
LL prt[MXM];
LL data[MXN];
bool vis[MXN];

int n,m;
unsigned x,y,z;
unsigned rng61(){
  LL t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}

void qk_sort(int l,int r,int k)
{
    if (l>=r) return;
    int a=l, b=r;
    while (a<b)
    {
        while (a<b&&data[b]>=data[l]) b--;
        while (a<b&&data[a]<=data[l]) a++;
        swap(data[a],data[b]);
    }
    swap(data[l],data[a]);
    vis[a]=1;
    if (k==a) return;
    if (k<a) qk_sort(l,a-1,k);
    if (k>a) qk_sort(a+1,r,k);
}

int main()
{
    int cnt=1;
    while (scanf("%d%d%u%u%u",&n,&m,&x,&y,&z)!=EOF)
    {
        for (int i=0;i<m;i++)
            scanf("%d",&num[i]);
        for (int i=0;i<n;i++)
            data[i]=(LL)rng61();

        memset(vis,0,sizeof(vis));

        for (int i=0;i<m;i++)
        {
            int l =num[i],r=num[i];
            while (l>=0&&vis[l]==0) l--;
            l++;
            while (r<n&&vis[r]==0) r++;
            r--;
            qk_sort(l,r,num[i]);
            prt[i] = data[num[i]];
        }
        printf("Case #%d:",cnt++);
        for (int i=0;i<m;i++)
            printf(" %lld",prt[i]);
        printf("\n");
    }
    return 0;
}
