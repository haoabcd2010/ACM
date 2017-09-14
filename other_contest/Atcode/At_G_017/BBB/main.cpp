#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL long long
#define MX 500005

int main()
{
    LL n,a,b,c,d;
    scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);

    LL l=0,r=n-1;
    int ok=0;
    while(l<=r)
    {
        LL mid = (l+r)/2;
        LL y = n-1-mid;
        LL w = b-a;
        if (mid*c>w+y*d)
            r = mid-1;
        else if (mid*d<w+y*c)
            l = mid+1;
        else
        {
            ok=1;
            break;
        }
    }
    if (ok)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
