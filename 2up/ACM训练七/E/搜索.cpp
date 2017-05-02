/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num[31]={0,2,3,5,7,11,13,17,19,23,29,31,33};
long long  i,j,n,ans,best;
void dfs (long long x,long long y,int z)//x ��Լ���ĸ�����y �����ֵĴ�С��z �Ǽ�¼����������
{
	if (x>best)
	{
	  best=x;
	  ans=y;
	}
	if (x==best&&ans>y)//x > best �Ļ��϶����ڣ���������
	{
	   ans=y;
	}
	if (z>11)  return;
	for (int i=1;i<=50;i++)
	{
	  if (y*num[z]>n)   break;
	  dfs(x*(i+1),y*num[z],z+1);
	  y*=num[z];
	}
}
int main()
{
	scanf("%lld",&n);
	ans=10000000;
	dfs(1,1,1);
	printf("%lld",ans);
}

*/

/*
#include <iostream>
#include <cstdio>
using namespace std;
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
unsigned long long ans,n;
int Max;

void dfs(int dep,long long now,int num)
{
    if(dep >= 16) return; //��Ҷ�ӽ�㣬����
    if(num > Max)//num��¼���Ӹ����������������������ĸ���
    {
        Max = num;
        ans = now;
    }
    if(num==Max&&ans>now) ans=now;//�����Ӹ�����ͬʱ��ȡֵ��С��
    for(int i=1;i<=50;i++)  //ö��ָ��
    {
        if(p[dep]*now>n) break;
        dfs(dep+1,now*=p[dep],num*(i+1));
    }
}

int main()
{
    cin>>n;
    ans=~0ULL;
    Max=0;
    dfs(0,1,1);
    cout<<ans<<endl;
return 0;
}
*/



#include <stdio.h>
typedef long long LL;

const int p[12]={2,3,5,7,11,13,17,19,23,29,31,37};
LL n,ans,m_yue;

void dfs(int dep,LL num,LL yue)
{
    if (dep>=12) return;
    if (yue>m_yue)
    {
        ans=num;
        m_yue=yue;
        //printf("??? %lld\n",ans);
    }
    if (m_yue==yue&&num<ans) ans=num;
    for (int i=1;i<=50;i++)//i ������ٴη�
    {
        if (num*p[dep]>n) break;
        dfs(dep+1,num*=p[dep],yue*(i+1));
    }
}

int main()
{
    scanf("%lld",&n);
    ans=1,m_yue=1;
    dfs(0,1,1);//��ȣ����֣�Լ������
    printf("%lld\n",ans);
    return 0;
}








