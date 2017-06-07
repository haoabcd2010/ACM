#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MX 100005

int main()
{
    LL n,a,b;
    cin>>n>>a>>b;
    priority_queue<LL> Q;
    for (int i=0;i<n;i++)
    {
        LL h;
        scanf("%lld",&h);
        Q.push(h);
    }
    LL damage=0;
    LL t=0;
    while (!Q.empty())
    {
        LL h =Q.top();
        if (h-damage-a<=0)
        {
            Q.pop();
            damage+=b;
            while (!Q.empty()&&Q.top()-damage<=0) Q.pop();
        }
        else
        {
            Q.pop();
            h-=a-b;
            damage+=b;
            Q.push(h);
        }
        t++;
    }
    printf("%lld\n",t);
}
