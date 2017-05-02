#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Ke
{
    int s,e;
    bool operator < (const Ke& b) const {return e<b.e;}
}ke[105];

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
            cin>>ke[i].s>>ke[i].e;
        sort (ke,ke+n);
        int all=0;
        int time=0;
        for (int i=0;i<n;i++)
        {
            if (time<=ke[i].s)
            {
                time = ke[i].e;
                all++;
            }
        }
        cout<<all<<endl;
    }
    return 0;
}
