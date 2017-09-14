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
#define MX 5005
struct Vec
{
    int x1,y1;
    int x2,y2;
    int vx,vy;
}xx[MX];

int n;

int main()
{
    freopen("lshape.in","r",stdin);
    freopen("lshape.out","w",stdout);
    while (scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&xx[i].x1,&xx[i].y1,&xx[i].x2,&xx[i].y2);
            xx[i].vx = xx[i].x2-xx[i].x1;
            xx[i].vy = xx[i].y2-xx[i].y1;
        }

        int ans =0;
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (xx[i].vx * xx[j].vx + xx[i].vy*xx[j].vy==0)
                {
                    if((xx[i].x1==xx[j].x1&&xx[i].y1==xx[j].y1)||
                       (xx[i].x1==xx[j].x2&&xx[i].y1==xx[j].y2)||
                       (xx[i].x2==xx[j].x1&&xx[i].y2==xx[j].y1)||
                       (xx[i].x2==xx[j].x2&&xx[i].y2==xx[j].y2))
                            ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
