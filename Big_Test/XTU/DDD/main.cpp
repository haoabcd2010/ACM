#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 205

int num[MX][MX];
int ans[MX][MX];


int main()
{
    int n,m,a,b;
    while (scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            char str[20];
            scanf("%s",str);
            for (int j=1;j<=m;j++)
                num[i][j]=str[j-1]-'0';
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                for (int x=1;x<=a;x++)
                    for (int y=1;y<=b;y++)
                        ans[(i-1)*a+x][(j-1)*b+y]=num[i][j];
        for (int i=1;i<=n*a;i++)
        {
            for (int j=1;j<=m*b;j++)
                printf("%d",ans[i][j]);
            putchar(10);
        }
    }
    return 0;
}
