#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 105

int n,m;
int cow[MX][MX];

int main()
{

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(cow,-1,sizeof(cow));
        for (int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            cow[a][b]=1;
            cow[b][a]=0;
        }
        for (int k=1;k<=n;k++)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)
                {
                    if (cow[i][k]==1&&cow[k][j]==1)
                        cow[i][j]=1;
                    if (cow[i][k]==0&&cow[k][j]==0)
                        cow[i][j]=0;
                }
            }
        }
        int ans =0;
        for (int i=1;i<=n;i++)
        {
            int ok=1;
            for (int j=1;j<=n;j++)
                if (i!=j&&cow[i][j]==-1)
                {
                    ok=0;
                    break;
                }
            if (ok) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
