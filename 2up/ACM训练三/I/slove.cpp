#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int l,w;
}node[5005],setup[5005];

bool cmp(Node a,Node b)
{
    if (a.l==b.l)
        return a.w<b.w;
    return a.l<b.l;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        int i,j;
        cin>>n;
        for (i=0;i<n;i++)
        {
            cin>>node[i].l>>node[i].w;
        }
        sort(node,node+n,cmp);
        int ans=1;
        setup[0].l=node[0].l;
        setup[0].w=node[0].w;

        for (i=1;i<n;i++)
        {
            int ok=0;
            for (j=0;j<ans;j++)
            {
                if (setup[j].l<=node[i].l&&setup[j].w<=node[i].w)
                {
                    setup[j].l=node[i].l;
                    setup[j].w=node[i].w;
                    ok=1;
                    break;
                }
            }
            if (ok==0)
            {
                setup[ans].l=node[i].l;
                setup[ans].w=node[i].w;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
