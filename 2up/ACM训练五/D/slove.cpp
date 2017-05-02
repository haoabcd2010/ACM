/* ***********************************************
��  �������������� ��
�������ߩ��������ߩ� ��
�������������������� ��
�������������������� ��
�������ש������ס��� ��
�������������������� ��
�����������ߡ������� ��
������������������ ��
�����������ա���������������������
�����������ꡡ���������� ��
�����������ڡ����������ǩ���
�����������Ĳ�������������
�����������������ש����� ��
�����������ϩϡ����ϩ� ��
�����������ߩ������ߩ� ��
*************************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int inf = 21e8;
const int maxn= 2e5+2;

int a[maxn];
int h[maxn];
int pos[maxn];
int l[maxn],r[maxn];
int n,m;

void up(int u)
{
    while (u>1)
    {
        if (a[h[u]]>a[h[u/2]])
        {
            swap(h[u],h[u/2]);
            swap(pos[h[u]],pos[h[u/2]]);
            u/=2;
        }
        else break;
    }
}

void down(int x)//�ڶ��е�����ı��
{
    int u;
    while (x*2<=n)
    {
        if (a[h[x*2]] > a[h[x*2+1]] || x*2==n) u=x*2;
        else u=x*2+1;
        if (a[h[x]]<a[h[u]])
        {
            swap(h[x],h[u]);
            swap(pos[h[x]],pos[h[u]]);
            x=u;
        }
        else break;
    }
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            l[i]=i-1;r[i]=i+1;
            h[i]=pos[i]=i;
            up(i);
        }
        l[1]=n;r[n]=1;
        if (m>n/2)
        {
            printf("Error!\n");
            continue;
        }
        int x,ans=0;
        for (i=1;i<=m;i++)
        {
            x=h[1];
            ans+=a[x];
            a[x]=a[l[x]]+a[r[x]]-a[x];      //��Ϊһ���µĵ�
            a[l[x]]=-inf;down(pos[l[x]]);
            a[r[x]]=-inf;down(pos[r[x]]);
            down(1);                        //������µĵ����λ��
            l[x]=l[l[x]];r[x]=r[r[x]]; //ɾ���������λ�ñ仯
            r[l[x]]=x;l[r[x]]=x;
        }
        printf("%d\n",ans);
    }
    return 0;
}
