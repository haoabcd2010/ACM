#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
using namespace std;
#define MX 200005

int num[MX];
int pre[MX];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        pre[0]=-1;
        num[0]=-1;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            pre[i]=max(pre[i-1],num[i-1]);
        }
        int ans = num[];
        for (int i=2;i<=n;i++)
        {
            int tp = num[i]-num[i-1];
            if (tp>=1)
                ans+=tp;
            if (num[i]>pre[i])
                ans+=num[i]-pre[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
