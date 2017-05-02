#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node
{
    int v,w;
}node[100];

int cmp(Node a,Node b)
{
    return a.v>b.v;
}

int main()
{
    int v,n;
    while (cin>>v)
    {
        if (!v) break;
        cin>>n;
        int i;
        for (i=0;i<n;i++)
            cin>>node[i].v>>node[i].w;
        sort(node,node+i,cmp);
        int ans=0;
        int fu=0;
        for (i=0;i<n;i++)
        {
            if (fu<v)
            {
                while (fu<v&&node[i].w>0)
                {
                    ans+=node[i].v;
                    fu++;
                    node[i].w--;
                }
            }
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
