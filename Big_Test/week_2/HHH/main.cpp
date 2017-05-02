#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 1005
int n,m;
int h[MX][MX];
int L[MX][MX];
int R[MX][MX];
char mp[MX][MX];

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                char sss[20];
                scanf("%s",sss);
                mp[i][j]=sss[0];
            }
        }
        set_h();
        set_LR();
        int ans = 0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                int area = (R[i][j]-L[i][j]+1)*h[i][j];
                if (area>ans) ans = area;
            }
        }
        printf("%d\n",ans*3);
    }
    return 0;
}
