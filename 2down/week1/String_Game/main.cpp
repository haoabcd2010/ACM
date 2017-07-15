#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

#define MAX 200005

int lenp,lent;
char p[MAX];
char t[MAX];
int num[MAX];
bool vis[MAX];

int func(int w)
{
    memset(vis,0,sizeof(vis));
    for (int i=0;i<=w;i++) vis[num[i]-1]=1;
    int pos=0;
    for(int i=0;i<lenp;i++)
    {
        if (!vis[i]&&t[pos]==p[i])  pos++;
        if (pos==lent) return 1;
    }
    return 0;
}

int main()
{
    while(scanf("%s",p)!=EOF)
    {
        scanf("%s",t);
        lenp=strlen(p);
        lent=strlen(t);
        for (int i=0;i<lenp;i++)
            scanf("%d",&num[i]);
        int l=0,r=lenp-1;
        int ans=0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if (func(mid)) //去掉 到 mid 位置时还能包含 t
            {
                ans=mid+1; //字符的位置加1
                l=mid+1;
            }
            else
                r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
