//ST��(����)
//Ԥ���� O(n*lgn) , ��ѯ O(1)
#include <iostream>
#include <stdio.h>
using namespace std;
#define MX 10005

int n;
int a[MX];
int st[MX][20]; // st[i][j] �ǵ� i ����Ϊ��˵㳤Ϊ 2^j ��������ֵ
int lgn[MX]; //lgn[i] �� lgn(i) ��ֵ

void Init()
{
    lgn[0]=-1;
    for (int i=1;i<=n;i++)
    {
        if ((i&(i-1))==0) lgn[i]=lgn[i-1]+1;
        else lgn[i]=lgn[i-1];
        st[i][0]=a[i];
    }
    for (int i=1;i<=lgn[n];i++) //���䳤Ϊ 2^i �η�
        for (int j=1;j+(1<<i)-1<=n;j++)
            st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}

int inquery(int a,int b)
{
    int k = lgn[b-a+1];
    return max(st[a][k],st[b-(1<<k)+1][k]);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    Init();
    int m;
    scanf("%d",&m);
    while (m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",inquery(l,r));
    }
    return 0;
}
