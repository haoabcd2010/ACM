#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MX 1000005

int n,m,p;
int ans;
int t[MX];
vector<int> zu[MX];
int net[MX];

void Init()
{
    for (int i=0;i<=n;i++)
        zu[i].clear();
}

void get_next()
{
    int i=0,j=-1;
    net[0]=-1;
    while (i<m)
    {
        if (j==-1||t[i]==t[j]) net[++i]=++j;
        else j = net[j];
    }
}

void KMP(int x)
{
    int i=0,j=0;
    int len = zu[x].size();
    while(i<len)
    {
        if (j==-1||zu[x][i]==t[j])
        {
            i++,j++;
        }
        else j=net[j];
        if (j==m)
        {
            ans++;
            j = net[j];
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d",&n,&m,&p);
        Init();
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            zu[i%p].push_back(x);
        }
        for (int i=0;i<m;i++)
            scanf("%d",&t[i]);
        get_next();

        ans = 0;
        for (int i=0;i<p;i++) KMP(i);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
