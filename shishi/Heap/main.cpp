#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MX 10005

int heap[MX];
int ans[MX];

void down(int n,int x)
{
    while (x*2<=n) //˵�����ж���
    {
        int u;
        if (x*2==n||heap[x*2]<heap[x*2+1]) u=x*2;
        else u=2*x+1;
        if (heap[u]<heap[x])
        {
            swap(heap[x],heap[u]);
            x=u;
        }
        else break;
    }
}

void Build_heap(int n)
{
    for (int i=n/2;i>=1;i--)//�����һ����Ҷ�ڵ㿪ʼ����
    {
        down(n,i);
    }
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&heap[i]);
        }
        Build_heap(n);
        for (int i=1;i<=n;i++)
        {
            printf("%d\n",heap[1]);
            heap[1]=INF;
            down(n,1);
        }
    }
    return 0;
}
