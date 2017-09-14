#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
#define MX 100005
int a[MX];

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int mmm=0;
    int ok=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        mmm = max(mmm,a[i]);
        if (a[i]==m) ok=1;
    }

    int y = a[0];
    for (int i=1;i<n;i++)
    {
        y = gcd(y,a[i]);
    }
    if ((mmm>=m&&m%y==0)||ok)
        printf("POSSIBLE\n");
    else
        printf("IMPOSSIBLE\n");

    return 0;
}
