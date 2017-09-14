#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define MX 100005

int n,m;
double pp[MX];

int main()
{
    freopen("kids.in","r",stdin);
    freopen("kids.out","w",stdout);
    while (cin>>n>>m)
    {
        pp[1]=1.0;
        for (int i=2;i<=m;i++)
        {
            pp[i]=pp[i-1]*(pp[i-1]-1.0/n);
            pp[i]+=(1.0-pp[i-1])*pp[i-1];
        }
        double ans = 0;
        for (int i=1;i<=m;i++)
            ans += pp[i];
        printf("%.9f\n",ans);
    }
    return 0;
}
