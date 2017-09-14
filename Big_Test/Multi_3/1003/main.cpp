#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <math.h>
#include <set>
using namespace std;
#define LL long long
#define MX 2010

LL num[MX];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
        }
        LL ans = 0;
        for (int i=1;i<=n;i++)
        {
            int kth=1;
            for (int j=i-1;j>=1;j--)
            {
                if (kth>k) break;
                if (num[j]<num[i]) kth++;
                if (kth==k)
                    ans+=num[i]*(n-i+1);
            }
        }
        printf("%lld",ans);
    }

    return 0;
}
