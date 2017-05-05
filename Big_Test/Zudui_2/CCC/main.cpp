#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MX 40005

int n,m;
int num[MX];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        int all = 0;
        int mm = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            all+=num[i];
            mm = max(mm,num[i]);
        }
        int ans;
        ans = all/m;
        if (all%m) ans++;
        printf("%d\n",max(ans,mm));
    }
    return 0;
}
