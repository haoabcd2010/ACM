#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MX 0x3f3f3f3f
#define MX 10005

int n,m;
int x[MX];

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        while (m--)
        {
            int l,r,p;
            scanf("%d%d%d",&l,&r,&p);
            priority_queue<int ,vector<int>, greater<int> > Q;
            for (int i=l;i<=r;i++)
                Q.push(x[i]);

            int tis = p-l;
            while (tis--) Q.pop();
            if (Q.top()==x[p])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
