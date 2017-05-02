
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node
{
    double l,r;
}node[10005];

bool cmp(Node a,Node b)
{
    return a.r>b.r;
}

int main()
{
    int n;
    while (cin>>n)
    {
        double L,W;
        cin>>L>>W;
        int i;
        for (i=0;i<n;i++)
        {
            double p,r;
            cin>>p>>r;
            node[i].l=p-sqrt(r*r-W*W/4);
            node[i].r=p+sqrt(r*r-W*W/4);
        }
        sort(node,node+n,cmp);
        /*
        for (i=0;i<n;i++)
        {
            cout<<node[i].l<<" "<<node[i].r<<endl;
        }
        */
        double k=0;
        int num=0;
        while(k<L)
        {
            for (i=0;i<n;i++)
            {
                if (node[i].l<=k&&node[i].r>k)
                {
                    k=node[i].r;
                    num++;
                    break;
                }
            }
            if (i==n) break;
        }
        if (k<L) cout<<"-1"<<endl;
        else cout<<num<<endl;
    }
    return 0;
}
