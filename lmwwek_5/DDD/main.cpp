#include <bits/stdc++.h>
using namespace std;
#define MX 100005

int a[MX];
int b[MX];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        priority_queue<int> Q;
        for (int i=0;i<n;i++)
            Q.push(a[0]+b[i]);
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (a[i]+b[j]>=Q.top()) break;
                Q.push(a[i]+b[j]);
                Q.pop();
            }
        }
        stack<int> S;
        while (!Q.empty())
        {
            S.push(Q.top());
            Q.pop();
        }
        while (!S.empty())
        {
            printf("%d\n",S.top());
            S.pop();
        }
    }
    return 0;
}
