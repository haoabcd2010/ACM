#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

typedef long long LL;

int main()
{
    int q,op;
    LL u,v,w;
    scanf("%d",&q);
    map<LL,LL> M;
    while (q--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            map<LL,int> vis;
            scanf("%lld%lld%lld",&u,&v,&w);
            while (u!=1)
            {
                M[u]+=w;
                vis[u]=1;
                u/=2;
            }
            while (v!=1)
            {
                if (vis[v]==1)
                {
                    while (v!=1)
                    {
                        M[v]-=w;
                        v/=2;
                    }
                    break;
                }
                M[v]+=w;
                v/=2;
            }
        }
        else if (op==2)
        {
            scanf("%lld%lld",&u,&v);
            LL ans=0;

            map<LL,int> vis;
            while (u!=1)
            {
                ans+=M[u];
                //printf("%lld\n",ans);
                vis[u]=1;
                u/=2;
            }
            //printf("!!!\n");
            while (v!=1)
            {
                if (vis[v]==1)
                {
                    while(v!=1)
                    {
                        ans-=M[v];
                        //printf("%lld\n",ans);
                        v/=2;
                    }
                    break;
                }
                ans+=M[v];
                v/=2;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
