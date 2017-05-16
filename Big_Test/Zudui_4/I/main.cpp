#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define LL long long

LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    LL n,m;
    while (scanf("%I64d%I64d",&n,&m)!=EOF)
    {
        LL p = gcd(n,m);
        LL q = n*m*2;
        LL yue = gcd(p,q);
        printf("%I64d/%I64d\n",p/yue,q/yue);
    }
    return 0;
}
