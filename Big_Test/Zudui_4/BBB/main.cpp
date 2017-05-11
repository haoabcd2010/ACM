#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
#define MX 105
int n;
int A[MX];
int B[MX];

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int cnt=1;cnt<=T;cnt++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&A[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&B[i]);
        int p=B[n],q=A[n];
        int a,b;
        for (int i=n-1;i>=1;i--)
        {
            a = A[i],b = B[i];
            a = a*q + p;
            b = b*q;

            p = b ;
            q = a;
        }
        int yue = gcd(p,q);
        printf("Case #%d: %d %d\n",cnt,p/yue,q/yue);
    }
    return 0;
}
