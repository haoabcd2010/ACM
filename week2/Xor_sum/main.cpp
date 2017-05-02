#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

struct Node
{
    int v;
    Node * p[2];
    Node ()
    {
        v=-1;
        p[0]=p[1]=NULL;
    }
}head;
int n,m;

void del(Node * p)
{
    if (p->p[0]) del(p->p[0]);
    if (p->p[1]) del(p->p[1]);
    delete(p);
}

void Init()
{
    if (head.p[0]) del(head.p[0]);
    if (head.p[1]) del(head.p[1]);
    head.v=-1;
    head.p[0]=head.p[1]=NULL;
}

void Build(int x)
{
    int t=x;
    int w[50];
    int k=0;
    while (t)
    {
        w[k++]=t%2;
        t/=2;
    }
    while (k<33)    w[k++]=0;

    Node * Q=&head;
    for (int i=k-1;i>=0;i--)
    {
        if (Q->p[w[i]]==NULL)
            Q->p[w[i]]=new (Node);
        Q=Q->p[w[i]];
    }
    Q->v=x;
}

int bi[50];
int func(int dep,Node *p)
{
    if (dep==-1)
        return p->v;
    int to =bi[dep];
    if (p->p[to]!=NULL)
        return func(dep-1,p->p[to]);
    to=!to;
    if (p->p[to]!=NULL)
        return func(dep-1,p->p[to]);
    return -1;
}

int Sousuo(int num)
{
    int t=num;
    int k=0;
    while (t)
    {
        bi[k++]=!(t%2);
        t/=2;
    }
    while (k<33)    bi[k++]=1;  //异或的最大的数

    int res = func(32,&head);
    return res;
}

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        Init();
        scanf("%d%d",&n,&m);
        int temp;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            Build(temp);
        }

        printf("Case #%d:\n",t);
        for (int i=0;i<m;i++)
        {
            scanf("%d",&temp);
            printf("%d\n",Sousuo(temp));
        }
    }
    Init();
    return 0;
}
