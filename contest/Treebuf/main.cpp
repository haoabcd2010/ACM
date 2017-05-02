#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define MAXN 1000

int n;
int A[MAXN];
int C[MAXN];

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int add) //A[x]����
{
    while (x<=n)
    {
        C[x]+=add;
        x+=lowbit(x);
    }
}

void new_tree(int n)   //����,ֱ������update
{
    memset(C,0,sizeof(C));
    for (int i=1;i<=n;i++)
        update(i,A[i]);
}

int getsum(int x)//[1--x]�ĺ�
{
    int sum=0;
    while(x>0)
    {
        sum+=C[x];
        x -= lowbit(x); //����1
    }
    return sum;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    new_tree(n);

    int l,r;
    scanf("%d %d",&l,&r);
    printf("%d\n",getsum(r)-getsum(l-1)); //l--r �ĺ�

    return 0;
}
