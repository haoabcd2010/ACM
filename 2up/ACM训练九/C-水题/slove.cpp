/*
#include <stdio.h>
#include <math.h>

int main()
{
    double p,q;
    double l,r;
    while (scanf("%lf%lf",&p,&q)!=EOF)
    {
        for (int i=1;i<=100000;i++)
        {
            l=i*p/100;
            r=i*q/100;
            int L=floor(l);
            int R=floor(r);
            if (R>L&&fabs(L-l)>1e-6&&fabs(R-r)>1e-6)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
*/


#include <stdio.h>
#include <math.h>

int main()
{
    double p,q;
    double l,r;
    while (scanf("%lf%lf",&p,&q)!=EOF)
    {
        for (int i=1;i<=100000;i++)
        {
            l=i/(q/100);
            r=i/(p/100);
            int L=floor(l);
            int R=floor(r);
            if (R-L>=1&&fabs(L+1-l)>1e-8&&fabs((L+1)-r)>1e-8)
            {
                printf("%d\n",L+1);
                break;
            }
        }
    }
    return 0;
}

