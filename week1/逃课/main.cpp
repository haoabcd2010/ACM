#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Word
{
    char s[20];
    int v;
    int operator < (const Word b) const
    {
        int op=strcmp(s,b.s);
        if (op!=0) return op<0;
        return v>b.v;
    }
}w[105];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%s %d",w[i].s,&w[i].v);
        sort(w,w+n);
        int ans=0;
        for (int i=0;i<n;i++)
        {
            if (i<2)
                ans+=w[i].v;
            else
            {
                if (strcmp(w[i].s,w[i-2].s)==0)
                    continue;
                else
                    ans+=w[i].v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
