#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MX 105

int sum[MX];

int get(int sc)
{
    if (sc>=1&&sc<=399) return 1;
    if (sc>=400&&sc<=799) return 2;
    if (sc>=800&&sc<=1199) return 3;
    if (sc>=1200&&sc<=1599) return 4;
    if (sc>=1600&&sc<=1999) return 5;
    if (sc>=2000&&sc<=2399) return 6;
    if (sc>=2400&&sc<=2799) return 7;
    if (sc>=2800&&sc<=3199) return 8;
    return 0; // ziyou
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[get(x)]++;
    }
    int a=0,b=0;
    for (int i=1;i<=8;i++)
    {
        if (sum[i])
        {
            a++;
            b++;
        }
    }
    a+=sum[0];
    if (b==0&&sum[0]!=0) b=1;

    printf("%d %d\n",b,a);
    return 0;
}
