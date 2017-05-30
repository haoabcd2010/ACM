#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MX 0x3f3f3f3f
#define MX 500

int main()
{
    LL a,b;
    while (scanf("%I64d%I64d",&a,&b)!=EOF)
    {
        int t_a=0,t_b=0;
        LL l=1,r=10000000;
        while (l<=r)
        {
            LL mid = (l+r)/2;
            if (mid*mid<=a)
            {
                t_a = mid;
                l = mid+1;
            }
            else r = mid-1;
        }

        l=1,r=10000000;
        while (l<=r)
        {
            LL mid = (l+r)/2;
            if (mid*mid+mid<=b)
            {
                t_b = mid;
                l = mid+1;
            }
            else r = mid-1;
        }

        if (t_a>t_b)
            printf("Valera\n");
        else
            printf("Vladik\n");
    }
    return 0;
}
