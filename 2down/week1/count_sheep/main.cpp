#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int x,y,m;
long long ans;
vector<int> boy[100005];
vector<int> girl[100005];

void init()
{
    for (int i=0;i<=x;i++)
        boy[i].clear();
    for (int i=0;i<=y;i++)
        girl[i].clear();
}

void count_b()
{
    for (int i=1;i<=x;i++) //第一个点
    {
        for (int j=0;j<boy[i].size();j++)
        {
            int er=boy[i][j];  //第二个点
            for (int k=0;k<girl[er].size();k++)
            {
                int san=girl[er][k]; //第三个点
                if (san==i) continue;
                ans+=boy[san].size()-1;
            }
        }
    }
}

void count_g()
{
    for (int i=1;i<=y;i++)
    {
        for (int j=0;j<girl[i].size();j++)
        {
            int er=girl[i][j];
            for (int k=0;k<boy[er].size();k++)
            {
                int san=boy[er][k];
                if (san==i) continue;
                ans+=girl[san].size()-1;
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
        scanf("%d%d%d",&x,&y,&m);
        init();
        int a,b;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            boy[a].push_back(b);
            girl[b].push_back(a);
        }
        ans=0;
        count_b();
        count_g();
        printf("%lld\n",ans);
    }
    return 0;
}
