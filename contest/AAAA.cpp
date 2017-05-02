/*
//st表求和
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

#define MAXN 500
#define lgn 10      //log(MAXN)+1就可以了

int num[MAXN];
int c[MAXN][lgn];

void new_st(int n)
{
    for (int i=1;i<=n;i++)
        c[i][0]=num[i];
    for (int j=1;(1<<j)<=n;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            c[i][j]=c[i][j-1]+c[i+(1<<(j-1))][j-1];
}

int query(int l,int r)
{
    if (l>r) return 0;
    int x = (r-l)+1;

    int w=-1;
    while (x) {x/=2;w++;}

    return c[l][w]+query(l+(1<<w),r);
}

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>num[i];
    new_st(n);

    int q;
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

#define MAXN 500

struct Node
{
    int l,r;
    int sum;
}tree[MAXN*4];

int n;
int a[MAXN];

int new_tree(int k,int l,int r)
{
    tree[k].l=l,tree[k].r=r;
    if (l==r)
    {
        tree[k].sum=a[l];
        return tree[k].sum;
    }
    int mid = (l+r)>>1;
    tree[k].sum = new_tree(2*k,l,mid)+new_tree(2*k+1,mid+1,r);
    return tree[k].sum;
}

int query(int k,int l,int r)
{
    if (l==tree[k].l&&r==tree[k].r)
    {
        return tree[k].sum;
    }
    int mid = (tree[k].l+tree[k].r)>>1;
    if (l>mid)
        return query(2*k+1,l,r);
    if (r<=mid)
        return query(2*k,l,r);
    return query(2*k,l,mid)+query(2*k+1,mid+1,r);
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    new_tree(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if (l>r) swap(l,r);
        if (l<=0||r>n)
        {
            cout<<"输入错误"<<endl;
        }
        cout<<query(1,l,r)<<endl;
    }
    return 0;
}

