#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define MAXN 100005

int vis[5005];
int num[MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        memset(vis,0,sizeof(vis));
        int total=0;
        int ok=0;
        for (int i=1;i<=n;i++)
        {
            total=(total+num[i])%m;
            vis[total]++;
            if (vis[0]||vis[total]==2)
            {
                ok=1;
                break;
            }
        }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

