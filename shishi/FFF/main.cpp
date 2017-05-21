#include <iostream>
#include <cstdio>
#define LL long long
#define INF 1000000000000000000
#define MX 1000005
using namespace std;

LL a[MX];
LL L[MX];
LL R[MX];

int main()
{
    LL n,x;
    int T;
    cin>>T;
    while (T--)
    {
        cin>>n>>x;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        L[0]=R[n+1]=0;
        for (int i=1;i<=n;i++)
            L[i]=max(L[i-1]+a[i],a[i]);
        for (int i=n;i>=1;i--)
            R[i]=max(R[i+1]+a[i],a[i]);
        LL ans = -INF;
        for (int i=1;i<=n;i++)
        {
            if (i>1)
                ans=max(L[i-1],ans);
            if (i<n)
                ans=max(R[i+1],ans);
            ans=max(L[i]+R[i]-2*a[i]+x,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
