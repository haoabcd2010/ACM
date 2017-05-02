#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int maxn=200005;
struct Bian
{
    int e;
    int num;
};
vector <Bian> G[maxn];
vector <int> ans[maxn];
int all_day;

void dfs(int now,int pre,int cnt)
{
    int day=0;
    int i;
    for (i=0;i<G[now].size();i++)
    {
        if (G[now][i].e==pre) continue;
        day++;
        if (cnt==day) //今天正在修
        day++;
        all_day=max(day,all_day);
        ans[day].push_back(G[now][i].num);//这天没事
        dfs(G[now][i].e,now,day);
    }
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        for (i=1;i<=n;i++)
        {
            G[i].clear();
            ans[i].clear();
        }

        for (i=1;i<n;i++)
        {
            Bian k;
            int u,v;
            scanf("%d%d",&u,&v);
            k.num=i;
            k.e=v;
            G[u].push_back(k);
            k.e=u;
            G[v].push_back(k);
        }
        all_day=0;
        dfs(1,0,0);
        printf("%d\n",all_day);
        for (i=1;i<=all_day;i++)
        {
            printf("%d",ans[i].size());
            for (j=0;j<ans[i].size();j++)
                printf(" %d",ans[i][j]);
            printf("\n");
        }
    }

	return 0;
}
