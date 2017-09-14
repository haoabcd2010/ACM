#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define LL long long
#define MX 100005
struct Tu
{
    int t,v;
    bool operator < (const Tu& b)const
    {
        return t<b.t;
    }
}tu[MX];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&tu[i].t);
    for (int i=0;i<n;i++)
        scanf("%d",&tu[i].v);
    sort(tu,tu+n);
    priority_queue<int ,vector<int>,greater<int> > Q;
    for (int i=0;i<n;i++)
    {
        if (tu[i].t>Q.size())
        {
            Q.push(tu[i].v);
        }
        else
        {
            Q.push(tu[i].v);
            Q.pop();
        }
    }
    int ans = 0;
    while (!Q.empty()) ans+=Q.top(),Q.pop();
    printf("%d\n",ans);
    return 0;
}
