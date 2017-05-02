/* ***********************************************
┆  ┏┓　　　┏┓ ┆
┆┏┛┻━━━┛┻┓ ┆
┆┃　　　　　　　┃ ┆
┆┃　　　━　　　┃ ┆
┆┃　┳┛　┗┳　┃ ┆
┆┃　　　　　　　┃ ┆
┆┃　　　┻　　　┃ ┆
┆┗━┓　马　┏━┛ ┆
┆　　┃　勒　┃　　┆　　　　　　
┆　　┃　戈　┗━━━┓ ┆
┆　　┃　壁　　　　　┣┓┆
┆　　┃　的草泥马　　┏┛┆
┆　　┗┓┓┏━┳┓┏┛ ┆
┆　　　┃┫┫　┃┫┫ ┆
┆　　　┗┻┛　┗┻┛ ┆
************************************************ */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define maxn 100002
typedef long long LL;
void sqr_tree_all(int left,int right,int k);

struct Node
{
    int l,r;
    LL data;
    int e;
}node[4*maxn];

int data[maxn];

void InitTree(int left,int right,int k)
{
    node[k].l=left;
    node[k].r=right;
    node[k].e=0;
    if (left==right)
    {
        node[k].data=data[left];
        if (node[k].data==1||node[k].data==0)
            node[k].e=1;
        return;
    }
    int mid = (left+right)/2;
    InitTree(left,mid,k*2);
    InitTree(mid+1,right,k*2+1);
    node[k].data=node[k*2].data+node[k*2+1].data;
    if (node[k*2].e==1&&node[k*2+1].e==1)
        node[k].e=1;
    return;
}

LL enquir(int left,int right,int k)
{
    if (left==node[k].l && right==node[k].r)
    {
        return node[k].data;
    }
    int mid =(node[k].l+node[k].r)/2;
    if (right<=mid) return enquir(left,right,k*2);//说明在左区间
    if (left>mid) return enquir(left,right,k*2+1);
        return enquir(left,mid,2*k)+enquir(mid+1,right,2*k+1);
}

void sqr_tree(int left,int right,int k)
{
    //如果这个区间开根号没效果了
    if (node[k].e==1 && left>=node[k].l&&right<=node[k].r)
        return ;
    if (left==right&&left==node[k].l&&right==node[k].r)//必须找到叶节点才更新
    {
        node[k].data=sqrt(node[k].data);
        if (node[k].data==1||node[k].data==0)
            node[k].e=1;
        return;
    }

    int mid = (node[k].l+node[k].r)/2;
    if (right<=mid)
        sqr_tree(left,right,k*2);//说明在左区间
    else if (left>mid)
        sqr_tree(left,right,k*2+1);
    else
    {
        sqr_tree(left,mid,2*k);
        sqr_tree(mid+1,right,2*k+1);
    }
    node[k].data=node[k*2].data + node[k*2+1].data;
    if (node[k*2].e==1&&node[k*2+1].e==1)
        node[k].e=1;
    return;
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&data[i]);
        InitTree(1,n,1);
        int m;
        scanf("%d",&m);
        int x,l,r;
        while (m--)
        {
            scanf("%d%d%d",&x,&l,&r);
            if (x==1)
            {
                LL ans = enquir(l,r,1);
                printf("%lld\n",ans);
            }
            else
                sqr_tree(l,r,1);
        }
    }
    return 0;
}
