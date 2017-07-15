#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define MX 100005

struct TreeNode
{
    int l,r;
    int lazy;
    int sum;  //已经普法人数
    int len; //区间实际人数
}node[MX*8];
struct Op
{
    int op;
    int l,r;
}opr[MX];
int n,q;
set<int> post;
map<int,int> pos; //对应多少编号
map<int,int> pot; //编号对应实际

void Init(int l,int r,int k)
{
    node[k]={l,r,0,0,pot[r]-pot[l]};
    if (l==r) return ;
    int mid = (l+r)/2;
    Init(l,mid,2*k);
    Init(mid+1,r,2*k+1);
}

int update(int l,int r,int k)
{
    if (l==node[k].l&&r==node[k].r)
    {
        node[k].lazy=1;
        node[k].sum=len;
        return
    }
}

int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&opr[i].op,&opr[i].l,&opr[i].r);
        post.insert(opr[i].l);
        post.insert(opr[i].r);
    }
    post.insert(n+1); //右边界
    int num=0;
    for (set<int>::iterator it=post.begin();it!=post.end();it++)
    {
        num++;
        pos[*it]=num;
        pot[num]=*it;
    }

    Init(1,num,1);
    for(int i=1;i<=q;i++)
    {
        int l=pos[opr[i].l];
        int r=pos[opr[i].r];
        if (opr[i].op==1)
        {
            update(l,r,1);
        }
        else if (opr[i].op==2)
        {
            printf("%d\n",query(l,r,1));
        }
    }
    return 0;
}
