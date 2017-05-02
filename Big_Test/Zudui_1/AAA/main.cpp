#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MX 1000005
struct Node
{
    int x,y;
    bool operator <(const Node & b)const
    {
        return x<b.x;
    }
}node[MX];
int n;
int main()
{
    int T;
    cin>>T;
    for (int cnt=1;cnt<=T;cnt++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&node[i].x,&node[i].y);
        sort(node,node+n);
        double ans = 0;
        for(int i=2;i<=n;i++)
        {
            double x = fabs(1.0*node[i].y-node[i-1].y)/fabs(node[i].x-node[i-1].x);
            if (x>ans)
                ans = x;
        }
        printf("Case #%d: %.2f\n",cnt,ans);
    }
    return 0;
}
