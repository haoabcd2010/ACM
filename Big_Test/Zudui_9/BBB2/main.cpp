#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define LL long long
#define MX 200005
struct Node
{
    LL a;
    LL b;
    bool operator <(const Node& xb)const
    {
        return a-b>xb.a-xb.b;
    }
}dr[MX];

int n;

int check(LL xxx)
{
    LL alv = xxx;
    for (int i=1;i<=n;i++)
    {
        if (alv>=dr[i].a) alv-=dr[i].b;
        else return 0;
    }
    return 1;
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&dr[i].a,&dr[i].b);
        }
        sort(dr+1,dr+1+n);
        LL l=1,r=INF;
        LL ans;
        while (l<=r)
        {
            LL mid = (l+r)/2;
            if ((check(mid)))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
