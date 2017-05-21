#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF (1LL<<62)

LL slv(LL x,LL y,LL s)
{
    LL X = x/2,Y = y/2;
    return min (
        max( max(abs(X*y-s),abs((x-X)*y-s)), abs(X*y-(x-X)*y) ),
        max( max(abs(x*Y-s),abs((y-Y)*x-s)), abs(Y*x-(y-Y)*x) )
    );
}

int main()
{
    LL h,w;
    cin>>h>>w;
    LL ans = INF;
    for (int i=1;i<=h;i++)
        ans = min (ans,slv(h-i,w,i*w));
    for (int i=1;i<=w;i++)
        ans = min (ans, slv(w-i,h,i*h));
    cout<<ans<<endl;
    return 0;
}
