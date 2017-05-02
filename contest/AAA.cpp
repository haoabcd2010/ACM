/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    map<int,int> mp;
    mp[6]=10;
    mp.clear();
    cout<<mp.count(6)<<endl;
    if (mp.count(6))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int l,r;
    int v;
    bool operator <(const Edge & b)const
    {return r<b.r;}
}edge[1005];
int dp[1005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[i].l=min(a,b);
        edge[i].r=max(a,b);
        edge[i].v=c;
    }
    sort(edge,edge+n);
    for (int i=0;i<n;i++)
    {
        for (int j=i-1;j>=0;j--)
        {
            if (edge[j].r<=edge[i].l)
                dp[i]=max(dp[j]+edge[i].v,dp[i]);
        }
        dp[i]=max(edge[i].v,dp[i]);
    }
    int ans=0;
    for (int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
