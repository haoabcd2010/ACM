#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
#define MX 1000005

int data[MX];
map<int ,int> num;
map<int ,int> wt[MX];

int main()
{
    int n,q;
    while (scanf("%d%d",&n,&q)&&(n+q))
    {
        for (int i=0;i<MX;i++) wt[i].clear();
        num.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&data[i]);
            num[data[i]]++;
            int k = num[data[i]];
            wt[k][data[i]]=i;
        }
        for (int cnt=0;cnt<q;cnt++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int ok=0;
            for (int i=r;i>l;i--)
            {
                int val = num[data[i]];
                for (int k=1;k<=val;k++)
                {
                    if (ok) break;
                    int pos = wt[k][data[i]];
                    if (pos>=l&&pos<i)
                    {
                        ok=1;
                        printf("%d\n",data[i]);
                    }
                }
                if (ok) break;
            }
            if (!ok)
                printf("OK\n");
        }
    }
    return 0;
}
