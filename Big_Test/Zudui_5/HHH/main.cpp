#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MX 1005

int n;
char ban[4][MX][MX];
char data[MX][MX];
char ans[MX*MX];

void Xz(int x,int y)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            ban[y][j][n-1-i]=ban[x][i][j];
        }
    }
}

int main()
{
    while (scanf("%d",&n)&&n)
    {
        for (int i=0;i<n;i++)
            scanf("%s",ban[0][i]);
        for (int i=0;i<n;i++)
            scanf("%s",data[i]);
        for (int i=1;i<4;i++)
        {
            Xz(i-1,i);
        }

        int num=0;
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<n;j++)
            {
                for (int k=0;k<n;k++)
                {
                    if (ban[i][j][k]=='O')
                        ans[num++]=data[j][k];
                }
            }
        }
        ans[num++]='\0';
        printf("%s\n",ans);
    }

    return 0;
}
