#include <stdio.h>

double a,b,c,k,h;
double x1,x2,x3,y1,y2,y3;

double func(double up)
{
    return (a*up*up*up/3.0)-(2.0*a*h+k)*up*up/2.0+(a*h*h+c-b)*up;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lf%lf",&x1,&y1);
        scanf("%lf%lf",&x2,&y2);
        scanf("%lf%lf",&x3,&y3);

        c=y1;
        h=x1;
        a=(y2-y1)/(x2-h)/(x2-h);

        k=(y3-y2)/(x3-x2);
        b=y2-k*x2;

        double ans=func(x3)-func(x2);

        printf("%.2lf\n",ans);
    }
    return 0;
}

