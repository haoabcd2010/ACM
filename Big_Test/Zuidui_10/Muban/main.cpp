#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define MX 100005

int main()
{
    freopen("bulls.in","r",stdin);
    freopen("bulls.out","w",stdout);

    char a[10];
    char b[10];
    while (scanf("%s%s",a,b)!=EOF)
    {
        int vis1[10];
        int vis2[10];
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        int same=0;
        for (int i=0;i<4;i++)
            if (a[i]==b[i])
        {
            vis1[i]=1;
            vis2[i]=1;
            same++;
        }
        int cuo=0;
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            {
                if (j==i) continue;
                if (vis1[i]) continue;
                if (vis2[j]) continue;
                if (a[i]==b[j])
                {
                    vis1[i]=1;
                    vis2[j]=1;
                    cuo++;
                }
            }
        }
        printf("%d %d\n",same,cuo);
    }
    return 0;
}
