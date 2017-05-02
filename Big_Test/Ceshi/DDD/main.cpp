#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node
{
    char name[105];
    int e;
    int s;
    bool operator <(const Node &b)const
    {
        return e<b.e;
    }
}work[20];
int n;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%s",work[i].name);
            scanf("%d%d",&work[i].e,&work[i].s);
        }

    }
    return 0;
}
