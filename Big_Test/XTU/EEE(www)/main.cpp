#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <stack>
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
const int MAX=1e5+5;
const int INF=1e9+5;
const double M=4e18;
using namespace std;
const int MOD=1e9+7;
typedef pair<int,int> pii;
typedef pair<int,long long> pil;
const double eps=0.000000001;
int n;
vector<pil> edge[MAX];
int a,b;
ll c;
ll d[MAX];
bool vi[MAX];
int lo1,lo2;
ll oh;
int findlong(int st)
{
    memset(vi,false,sizeof(vi));
    vi[st]=true;
    queue<pil> que;
    ll dismax=0,dis;
    int an,tem;
    que.push(mp(st,0LL));
    while(!que.empty())
    {
        tem=que.front().first;
        dis=que.front().second;
        pil lin;
        que.pop();
        for(int i=0;i<edge[tem].size();i++)
        {
            lin=edge[tem][i];
            if(!vi[lin.first])
            {
                vi[lin.first]=true;
                if(dismax<dis+lin.second)
                {
                    dismax=dis+lin.second;
                    an=lin.first;
                }
                que.push(mp(lin.first,dis+lin.second));
            }
        }
    }
    oh=dismax;
    return an;
}
void dfs(int st)
{
    memset(vi,false,sizeof(vi));
    vi[st]=true;
    queue<pil> que;
    int tem;
    ll dis;
    que.push(mp(st,0LL));
    while(!que.empty())
    {
        tem=que.front().first;
        dis=que.front().second;
        pil lin;
        que.pop();
        d[tem]=max(d[tem],dis);
        for(int i=0;i<edge[tem].size();i++)
        {
            lin=edge[tem][i];
            if(!vi[lin.first])
            {
                vi[lin.first]=true;
                que.push(mp(lin.first,dis+lin.second));
            }
        }
    }
}
ll finan;
int main()
{
    while(~scanf("%d",&n))
    {
        if(n==1)
        {printf("0\n");continue;}
        oh=0LL;
        for(int i=1;i<=n;i++)
        {
            edge[i].clear();
            d[i]=0LL;
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%I64d",&a,&b,&c);
            edge[a].push_back(mp(b,c));
            edge[b].push_back(mp(a,c));
        }
        lo1=findlong(1);
        lo2=findlong(lo1);
        dfs(lo1);dfs(lo2);
        finan=0;
        for(int i=1;i<=n;i++)
        {
            finan+=d[i];
        }
        finan-=oh;
        cout<<finan<<"\n";
    }
}
