#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = 0x6f6f6f6f;
int n;
struct Idiom
{
    int spend;
    char s[5];
    char e[5];
}idiom[1005];

int spe[1005][1005];

int read(int x)
{
    int s,i,j;
    char str[100];
    scanf("%d%s",&s,str);
    idiom[x].spend=s;
    int len=strlen(str);
    for (i=0;i<4;i++)
        idiom[x].s[i]=str[i];
    idiom[x].s[i]='\0';
    for (i=len-4;i<len;i++)
        idiom[x].e[i-(len-4)]=str[i];
    idiom[x].e[i]='\0';
}

int vis[1005],dis[1005];
void Dijkstra()
{
    int i,j,mmm,m;
    memset(vis,0,sizeof(vis));
    memset(dis,0x6f,sizeof(dis));
    dis[1] = 0;
    for(i = 0; i<n; i++)
    {
        mmm = INF;
        for(j = 1; j<=n; j++)
        {
            if(dis[j]<mmm &&!vis[j])
            {
                m = j;
                mmm = dis[j];
            }
        }
        vis[m] = 1;
        for(j = 1; j<=n; j++)
        {
            if(dis[m]+spe[m][j]<dis[j]&&!vis[j])
                dis[j] = dis[m]+spe[m][j];
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n)&&n)
    {
        for(i = 1; i<=n; i++)
            read(i);
        memset(spe,0x6f,sizeof(spe));
        for(i = 1; i<=n; i++)
        {
            for(j = 1; j<=n; j++)
            {
                if(strcmp(idiom[i].e,idiom[j].s)==0)
                    spe[i][j]=idiom[i].spend;
            }
        }
        Dijkstra();
        if (dis[n]!=INF)
            printf("%d\n",dis[n]);
        else
            printf("-1\n");
    }
    return 0;
}
