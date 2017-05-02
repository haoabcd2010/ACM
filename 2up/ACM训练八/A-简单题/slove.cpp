/*
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int n,max_;
int num[100005];
int vis[100005];

int func(int x,int p)
{
    if (x==p) return 0;
    queue<int> Q;
    memset(vis,-1,sizeof(vis));
    Q.push(x);
    vis[x]=0;
    while (!Q.empty())
    {
        int e=Q.front();
        Q.pop();
        int n_e=e*2;
        if (n_e<=100000&&vis[n_e]==-1)
        {
            vis[n_e]=vis[e]+1;
            Q.push(n_e);
        }
        n_e=e/2;
        if (n_e>=1&&vis[n_e]==-1)
        {
            vis[n_e]=vis[e]+1;
            Q.push(n_e);
        }
        if (vis[p]!=-1) return vis[p];
    }
    return vis[p];
}

int main()
{
    scanf("%d",&n);
	max_=0;
	int i,j;
	for (i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		if (num[i]>max_) max_=num[i];
	}
	int ans=1e8;
	int pos;//����
	for (i=1;i<max_;i*=2)
	{
		int all=0;
		for (j=0;j<n;j++)
		{
			int step = func(num[j],i); //num[j] ��Ϊ i ��Ҫ���������ܵ��򷵻� -1
			if (step==-1) break;//�в��ܵ������֣��˳�ѭ��
			all+=step;
		}
		if (j==n&&all<ans)//˵��ȫ�����Ե�
		{
			pos=i;//����
			ans=all;
		}
	}
	printf("����� %d ����Ҫ %d ��\n",pos,ans);//����
	//printf("%d\n",ans);
	return 0;
}
*/



#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int n,max_;
int num[100005];
int times[100005];//�м���ֵ���Ե������
int vis[100005];//����ֵ������ֵ��Ҫ�Ĳ�����

struct Step
{
    int e;//ֵ
    int s;//����
};

bool v[100005];//��ʱ����bfs��
void func(int x)
{
    queue<Step> Q;
    memset(v,0,sizeof(v));

    Step k;
    k.e=x;
    k.s=0;

    Q.push(k);
    times[k.e]++;
    v[k.e]=1;

    while (!Q.empty())
    {
        k=Q.front();
        Q.pop();
        Step next;
        next.e=k.e*2;
        next.s=k.s+1;
        if (next.e<=100000&&v[next.e]==0)
        {
            vis[next.e]+=next.s;
            times[next.e]++;
            v[next.e]=1;
            Q.push(next);
        }
        next.e=k.e/2;
        if (next.e>=1&&v[next.e]==0)
        {
            vis[next.e]+=next.s;
            times[next.e]++;
            v[next.e]=1;
            Q.push(next);
        }
    }
}

int main()
{
    scanf("%d",&n);
	int i,j;
	for (i=0;i<n;i++)
		scanf("%d",&num[i]);

    //memset(vis,0,sizeof(vis));
    //memset(times,0,sizeof(times));
    for (i=0;i<n;i++)
    {
        func(num[i]);//ÿ�������ȥ�ĵط�
    }
    int ans=1e8;
    for (i=1;i<=100000;i++)
    {
        if (times[i]==n&&vis[i]<ans)//�Ǹ�ֵ����Ҫ��n�������Ե���
            ans=vis[i];
    }
    printf("%d\n",ans);
	return 0;
}
