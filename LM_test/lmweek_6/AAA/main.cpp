#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct Ans
{
    int s[10];
}ans;

int n;
int tot;
int lie[12];
int lxie[20]; //+10,б
int rxie[20]; //
queue<Ans> Q;

void dfs(int s)
{
    if (s==n+1)
    {
        tot++;
        Q.push(ans);
        return ;
    }
    for (int i=1;i<=n;i++)
    {
        if (lie[i]==0&&lxie[s-i+10]==0&&rxie[s+i]==0)
        {
            lie[i]=1;
            lxie[s-i+10]=1;
            rxie[s+i]=1;
            ans.s[s]=i;
            dfs(s+1);
            lie[i]=0;
            lxie[s-i+10]=0;
            rxie[s+i]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    tot=0;
    dfs(1);
    printf("%d\n",tot);
    while (!Q.empty())
    {
        Ans *p = &Q.front();
        for (int i=1;i<=n;i++)
            printf("%d ",p->s[i]);
        printf("\n");
        Q.pop();
    }
    return 0;
}
