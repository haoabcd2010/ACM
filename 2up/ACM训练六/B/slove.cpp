/*暴力遍历
#include <stdio.h>
#include <string.h>

int n,m;
int ans;
int bian[1005][1005];//0为蓝,1为红

int func(int u)
{
    int i,j;
    int s1,s2,s3;
    for (i=u+1;i<=n;i++)
    {
        if (i==u) continue;
        s1=bian[u][i];
        for (j=i+1;j<=n;j++)
        {
            if (j==u) continue;
            s2=bian[i][j];
            if (s2==s1)
            {
                s3=bian[j][u];
                if (s2==s3)
                {
                    ans++;
                    //printf("%d %d %d\n",u,i,j);
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        memset(bian,0,sizeof(bian));
        scanf("%d",&m);
        int i;
        int u,v;
        for (i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            bian[u][v]=bian[v][u]=1;
        }

        ans=0;
        for (i=1;i<=n;i++)
        {
            func(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/

#include <stdio.h>
#include <string.h>

int dot[1005];
int n,m;

int C(int a,int b)//  a!/(a-b)!/b!
{
   return n*(n-1)*(n-2)/6;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(dot,0,sizeof(dot));
        scanf("%d",&n);
        scanf("%d",&m);
        int u,v;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            dot[u]++;
            dot[v]++;
        }
        int Q=0;
        for (int i=1;i<=n;i++)
            Q+=(n-1-dot[i])*dot[i];

        int ans=C(n,3)-Q/2;
        printf("%d\n",ans);
    }
    return 0;
}
