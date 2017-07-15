#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAXN 10005

const double dot = 1e-9;//至少到 -9 不然 wa

struct F
{
    double a,b,c;
}f[MAXN];

double cal(double x,int n)
{
    double res = -1e20;
    for (int i=0;i<n;i++)
    {
        double p = f[i].a*x*x+f[i].b*x+f[i].c;
        if (p>res)
            res = p;
    }
    return res;
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%lf%lf%lf",&f[i].a,&f[i].b,&f[i].c);

        double l=0.0,r=1000.0;
        while (r-l>dot)
        {
            double mid = (l+r)/2;
            double mmid = (mid+r)/2;
            double m_v = cal(mid,n);
            double mm_v = cal(mmid,n);
            if (m_v>mm_v)
                l=mid;
            else
                r=mmid;
        }
        printf("%.4lf\n",cal(r,n));
    }
    return 0;
}
