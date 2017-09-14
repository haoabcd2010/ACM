#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n,m,k;
int h,w;
char ab[55][55];
char dt[155][855];
char pi[105][805];

int check(int a,int b)
{
    for (int i=1;i<=h;i++)
    {
        for (int j=1;j<=w;j++)
        {
            if (dt[i+a-1][j+b-1]!=pi[i][j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",ab[i]+1);
    }

    for (int i=1;i<=150;i++)
        for (int j=1;j<=850;j++)
        {
            int x=i%n,y=j%m;
            if (i%n==0) x=n;
            if (y%m==0) y=m;
            dt[i][j]=ab[x][y];
        }

    while (k--)
    {
        scanf("%d%d",&h,&w);

        for (int i=1;i<=h;i++)
            scanf("%s",pi[i]+1);

        int ok=0;
        for (int i=n+1;i>=1;i--)
        {
            for (int j=m+1;j>=1;j--)
            {
                ok = check(i,j);
                if (ok) break;
            }
            if (ok) break;
        }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
