#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
using namespace std;
#define LL long long
#define MX 200005

LL num[MX];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        LL ans = 0;
        LL tp=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
            if (num[i]>tp)
            {
                ans+=num[i]-tp;
                tp=num[i];
            }
            else
                tp=num[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
