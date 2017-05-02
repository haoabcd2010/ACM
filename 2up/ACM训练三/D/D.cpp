#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++)
    {
        int a,b;
        double ans;
        scanf("%d%d",&a,&b);
        ans=a*b;
        if (a*b%2==1) ans+=sqrt(2.0)-1;
        printf("Scenario #%d:\n",i);
        printf("%.2lf\n",ans);
        if (i!=n) printf("\n");
    }
    return 0;
}
