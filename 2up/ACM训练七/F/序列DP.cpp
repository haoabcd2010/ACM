/*
//理解错题意，我觉得也是个很棒的算法。。。
//我理解的意思是 要输出数值小的上升序列 而不是位置小
#include <stdio.h>

#define INF 1000000000
int num[10005];//数据
int dp[10005];//记录到这最大上升长度
int ans[10005];//存储答案的
int cp[10005];//存储暂时的
int n,m;

void Init()
{
    scanf("%d",&n);
    int i,j;
    for (i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for (i=1;i<=n;i++)
    {
        dp[i]=1;
        for (j=i-1;j>=1;j--)
        {
            if (num[j]<num[i]&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
            }
        }
    }
}

int compare(int len)//比较两个数组谁字典序更小
{
    for (int i=len;i>=1;i--)
    {
        if (cp[i]<ans[i])
        {
            //ans=cp;
            for (int j=1;j<=len;j++)
                ans[j]=cp[j];
            return 1;
        }
        else if (cp[i]==ans[i])
            continue;
        else
            return 0;
    }
    return 0;
}

int main()
{
    Init();
    scanf("%d",&m);
    while (m--)
    {
        int i,j,l,ok=0;
        scanf("%d",&l);

        for (i=1;i<=l;i++)
            ans[i]=INF;

        int pos;
        for (i=1;i<=n;i++)
        {
            if (dp[i]>=l)
            {
                int pre=i;
                pos=1;
                cp[1]=num[i];
                if (pos==l)//只有 1 个数，有点特殊
                {
                    if (compare(l))
                    ok=1;
                    continue;
                }
                for (j=i-1;j>=1;j--)
                {
                    if (num[j]<num[pre]&&dp[j]>=l-pos)
                    {
                        cp[++pos]=num[j];
                        pre=j;
                        if (pos==l&&compare(l))
                        {
                            ok=1;
                            break;
                        }
                    }
                }
            }
        }

        if (ok==0)
            printf("Impossible\n");
        else
        {
            //逆序输出长度为 l 的数组
            for (i=l;i>1;i--)
                printf("%d ",ans[i]);
            printf("%d\n",ans[1]);
        }
    }
    return 0;
}
*/


//我的 3540 ms
#include <stdio.h>

#define INF 1000000000
int num[10005];//数据
int dp[10005];//记录到这最大上升长度
int ans[10005];//存储答案的
int n,m;

void Init()
{
    scanf("%d",&n);
    int i,j;
    for (i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for (i=n;i>=1;i--)
    {
        dp[i]=1;
        for (j=i+1;j<=n;j++)
        {
            if (num[j]>num[i]&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
            }
        }
    }
}

int main()
{
    Init();
    scanf("%d",&m);
    while (m--)
    {
        int i,j,l,ok=0;
        scanf("%d",&l);

        int pos;
        for (i=1;i<=n;i++)
        {
            if (ok==0&&dp[i]>=l)
            {
                int tmp=1;
                ans[1]=num[i];
                if (tmp==l)
                {
                    ok=1;
                    break;
                }
                int pre=i;
                for (j=i+1;j<=n;j++)
                {
                    if (num[j]>num[pre]&&dp[j]>=l-tmp)
                    {
                        ans[++tmp]=num[j];
                        pre=j;
                        if (tmp==l)
                        {
                            ok=1;
                            break;
                        }
                    }
                }
            }
        }
        if (ok==0)
            printf("Impossible\n");
        else
        {
            for (i=1;i<l;i++)
                printf("%d ",ans[i]);
            printf("%d\n",ans[l]);
        }

    }
    return 0;
}



/*
//2272 ms 别人的算法,有时间看看
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1000000000
using namespace std;

int n,m,cnt;
int a[100005],f[100005],best[100005];
void solve(int x)
{
	int last=0;
	for(int i=1;i<=n;i++)
		if(f[i]>=x&&a[i]>last)
		{
			printf("%d",a[i]);
			if(x!=1)printf(" ");
			last=a[i];
			x--;
			if(!x)break;
		}
	printf("\n");
}
int find(int x)
{
	int l=1,r=cnt,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(best[mid]>x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
void pre()
{
	for(int i=n;i;i--)
	{
		int t=find(a[i]);
		f[i]=t+1;
		cnt=max(cnt,t+1);
		if(best[t+1]<a[i])
			best[t+1]=a[i];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	pre();
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x<=cnt) solve(x);
		else puts("Impossible");
	}
	return 0;
}
*/

