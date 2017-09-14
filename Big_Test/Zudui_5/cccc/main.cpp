#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
#define MX 1000005

int a[MX];
int f[MX];

int main()
{
    int n,q;
    while (scanf("%d%d",&n,&q)&&(n+q))
    {
        map <int ,int> mp;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        f[n]=n+1;
        mp[a[n]]=n;
        for (int i=n-1;i>=1;i--)
        {
            if (mp.count(a[i]))
                f[i] = min(f[i+1],mp[a[i]]);
            else
                f[i] = f[i+1];
            mp[a[i]]=i;
        }
        while (q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if (f[l]<=r)
                printf("%d\n",a[f[l]]);
            else
                printf("OK\n");
        }
        printf("\n");
    }
    return 0;
}
