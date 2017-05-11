#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define eps 1e-9            // ¾«¶È
#define MX  60

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int t1=0;
        for (int i=0;i<n-1;i++)
        {
            int x;
            scanf("%d",&x);
            t1+=x;
        }
        int t2=0;
        for (int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            t2+=x;
        }
        int l,r;
        if (t1%(n-1)==0)
        {
            r = t1/(n-1)-1;
        }
        else
        {
            r = t1/(n-1);
        }

        l = t2/m + 1;

        printf("%d %d\n",l,r);
    }
    return 0;
}
