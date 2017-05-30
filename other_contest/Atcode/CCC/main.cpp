#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define MX 2005

int n,m,q;
int ans;
char mp[MX][MX];
int d[MX][MX];  //点
int x[MX][MX];  //线
int up[MX][MX]; //上相连
int lef[MX][MX];//左相连

void slv()
{
    memset(x,0,sizeof(x));
    memset(d,0,sizeof(d));
    memset(up,0,sizeof(up));
    memset(lef,0,sizeof(lef));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
            x[i][j]=x[i-1][j]+x[i][j-1]-x[i-1][j-1];
            up[i][j]=up[i][j-1];
            lef[i][j]=lef[i-1][j];
            if (mp[i][j]=='1')
            {
                d[i][j]++;
                if (i>1&&mp[i-1][j]=='1') x[i][j]++;
                if (j>1&&mp[i][j-1]=='1') x[i][j]++;
                if (i>1&&mp[i-1][j]=='1') up[i][j]++;
                if (j>1&&mp[i][j-1]=='1') lef[i][j]++;
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);

    for (int i=1;i<=n;i++)
        scanf("%s",mp[i]+1);

    slv();

    while (q--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1>x2) swap(x1,x2);
        if (y1>y2) swap(y1,y2);
        int ans = d[x2][y2]-d[x2][y1-1]-d[x1-1][y2]+d[x1-1][y1-1];

        ans -= x[x2][y2]-x[x2][y1-1]-x[x1-1][y2]+x[x1-1][y1-1];
        ans += up[x1][y2]-up[x1][y1-1];
        ans += lef[x2][y1]-lef[x1-1][y1];

        cout<<ans<<endl;
    }
    return 0;
}
