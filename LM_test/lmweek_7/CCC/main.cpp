#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define LL long long
#define MX 105

int n;
int j[MX];
int a[MX];

LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL r = exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d%d",&j[i],&a[i]);
    if (n==1)
    {
        printf("%d\n",a[0]%j[0]);
        return 0;
    }

    int ok=1;
    LL pos=a[0]%j[0],jump=j[0];
    for (int i=1;i<n;i++)
    {
        LL x,y,z = a[i]-pos;
        LL g = exgcd(jump,j[i],x,y);
        if (z%g!=0)
        {
            ok=0;
            break;
        }
        LL k = z/g;
        LL mo = j[i]/g;
        x = ((x*k%mo)+mo)%mo;
        pos = pos+x*jump;
        jump = jump*j[i]/g;
    }
    if (ok)
        printf("%lld\n",pos);
    else
        printf("-1\n");
    return 0;
}
