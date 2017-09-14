#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define MX 100005

struct Node
{
    int l,r;
    int lazy;
    int sum;  //已经普法人数
    int len;  //实际人数
}node[MX*12];

struct Op
{
    int op;
    int l,r;
}opr[MX];

int n,q;
int point[MX*4];
map<int,int> dex;

void Init(int l,int r,int k)
{
    node[k]=(Node){l,r,0,0,point[r+1]-point[l]}; //区间实际人数
    if (l==r) return ;
    int mid = (l+r)/2;
    Init(l,mid,2*k);
    Init(mid+1,r,2*k+1);
}

void push_down(int k)
{
    node[k*2].lazy=1;
    node[k*2].sum=node[k*2].len;
    node[k*2+1].lazy=1;
    node[k*2+1].sum=node[k*2+1].len;
    node[k].lazy=0;
}

void update(int l,int r,int k)
{
    if (l==node[k].l&&r==node[k].r)
    {
        node[k].lazy=1;
        node[k].sum=node[k].len;
        return;
    }
    if (node[k].lazy) push_down(k);
    int mid = (node[k].l+node[k].r)/2;
    if (l>mid) update(l,r,2*k+1);
    else if (r<=mid) update(l,r,2*k);
    else
    {
        update(l,mid,2*k);
        update(mid+1,r,2*k+1);
    }
    node[k].sum = node[2*k].sum+node[2*k+1].sum;
}

int inquery(int l,int r,int k)
{
    if (l==node[k].l&&r==node[k].r)
    {
        return node[k].sum;
    }
    if (node[k].lazy) push_down(k);
    int mid = (node[k].l+node[k].r)/2;
    if (l>mid) return inquery(l,r,2*k+1);
    else if (r<=mid) return inquery(l,r,2*k);
    return inquery(l,mid,2*k)+inquery(mid+1,r,2*k+1);
}

int main()
{
    scanf("%d%d",&n,&q);
    int pn=1;
    for (int i=0;i<q;i++)
    {
        scanf("%d%d%d",&opr[i].op,&opr[i].l,&opr[i].r);
        point[pn++]=opr[i].l;
        point[pn++]=opr[i].r;
        point[pn++]=opr[i].r+1; // 很关键
    }
    pn--;
    sort(point+1,point+1+pn);
    pn = unique(point+1,point+1+pn)-(point+1);
    pn--; //最右边的端点[x,+++) 不会用到，不对它建树
    for (int i=1;i<=pn;i++)
        dex[point[i]]=i;
    Init(1,pn,1);

    for(int i=0;i<q;i++)
    {
        int l=dex[opr[i].l];
        int r=dex[opr[i].r];
        if (opr[i].op==1)
        {
            update(l,r,1);
        }
        else
        {
            printf("%d\n",opr[i].r-opr[i].l+1-inquery(l,r,1));
        }
    }
    return 0;
}
