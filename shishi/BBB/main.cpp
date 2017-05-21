#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF (1LL<<62)
#define MX 100005*3

LL a[MX];
LL ma[MX];
LL mi[MX];

int main()
{
    LL n;
    cin>>n;

    for (int i=1;i<=3*n;i++)
        scanf("%lld",&a[i]);
    priority_queue <LL> Q;
    LL sum = 0;
    for (int i=1;i<=2*n;i++)
    {
        Q.push(-a[i]);
        sum+=a[i];

        if (i>n) sum += Q.top(),Q.pop();
        ma[i]=sum;
    }

    while (!Q.empty()) Q.pop();
    sum=0;
    for (int i=3*n;i>=n+1;i--)
    {
        Q.push(a[i]);
        sum+=a[i];

        if (i<=2*n) sum -= Q.top(),Q.pop();
        mi[i]=sum;
    }

    LL ans = -INF;
    for (int i=n;i<=2*n;i++)
        ans = max (ans, ma[i]-mi[i+1]);
    cout<<ans<<endl;
    return 0;
}
