/*
#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
#define MAX 100005

LL c[5],d[5];
LL dp[MAX];

/*
    dp[i]��ʾ��|������| Ӳ����Ŀ����ึ���
    ��ôֻ�轫
    dp[res]
    -d1������������ - d2������... - d3... - d4...
    + (d1��d2) + ... + (d3��d4)
    - (d1,d2,d3)
    + (d1+d2+d3+d4)
    ������
*/
/*
LL ans;

int main()
{
    for (int i=1;i<=4;i++)
    scanf("%lld",&c[i]);
    int tot;
    scanf("%lld",&tot);
    dp[0]=1;
    for (int i=1;i<=4;i++)
        for (int j=c[i];j<=100000;j++)
            dp[j]+=dp[j-c[i]];
    while (tot--)
    {
        LL res;
        for (int i=1;i<=4;i++)
        {
            scanf("%lld",&d[i]);
            d[i]++;//�������Ǹ��ѵ㣬һ��Ҫ�� 1 ���Ǹպù�����Ŀ���ֵ,���Ժ����ж��� res>=ʲô
        }

        scanf("%lld",&res);
        ans=dp[res];

        int i,j,k;
        for (i=1;i<=4;i++)
            if (res>=c[i]*d[i])
            ans-=dp[res-c[i]*d[i]];

        for (i=1;i<=3;i++)
            for (j=i+1;j<=4;j++)
            if (res>=c[i]*d[i]+c[j]*d[j])
            ans+=dp[res-c[i]*d[i]-c[j]*d[j]];
        for (i=1;i<=2;i++)
            for (j=i+1;j<=3;j++)
                for (k=j+1;k<=4;k++)
                if (res>=c[i]*d[i]+c[j]*d[j]+c[k]*d[k])
                ans-=dp[res-c[i]*d[i]-c[j]*d[j]-c[k]*d[k]];
        if (res>=c[1]*d[1]+c[2]*d[2]+c[3]*d[3]+c[4]*d[4])
            ans+=dp[res-c[1]*d[1]-c[2]*d[2]-c[3]*d[3]-c[4]*d[4]];

        printf("%lld\n",ans);

    }
    return 0;
}
*/


#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
#define MAX 100005

LL c[5],d[5];
LL dp[MAX];
LL ans;

void dfs(int x,int cnt,int s)
{
    if (s<0) return;
    if (x==5)
    {
        if (cnt%2==1)
            ans+=dp[s];
        else
            ans-=dp[s];
        return;
    }
    dfs(x+1,cnt+1,s-(d[x]+1)*c[x]);
    dfs(x+1,cnt,s);
}

int main()
{
    for (int i=1;i<=4;i++)
    scanf("%lld",&c[i]);
    int tot;
    scanf("%lld",&tot);
    dp[0]=1;
    for (int i=1;i<=4;i++)
        for (int j=c[i];j<=100000;j++)
            dp[j]+=dp[j-c[i]];
    while (tot--)
    {
        LL res;
        for (int i=1;i<=4;i++)
            scanf("%lld",&d[i]);
        scanf("%lld",&res);
        ans=0;
        dfs(1,0,res);//����λ�ã����޵ĸ��������
        printf("%lld\n",ans);

    }
    return 0;
}

