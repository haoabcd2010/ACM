/*
//常规算法 (n^3)
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

const int N=205;
const int INF=0x7fffffff;
int n;
int a[N],sum[N],dp[N][N];

/*dp[i][j]代表i到j堆的最优值
sum[i]代表第1堆到第i堆的数目总和
有dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j])+sum[j]-sum[i-1]
*/
/*
void f()
{
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
    for(int r=1;r<n;r++)
    {
        for(int i=1;i<=n-r;i++)
        {
            int j=i+r;
            dp[i][j]=INF;
            for(int k=i;k<=j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
            dp[i][j]+=sum[j]-sum[i-1];
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        f();
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
*/

/*
//四边形算法 32ms
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

const int N=205;
const int INF=0x7fffffff;
int n;
int a[N],sum[N],dp[N][N],s[N][N];

void f();

int main()
{
    while(~scanf("%d",&n))
    {
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        f();
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
void f()
{
    for(int i=1;i<=n;i++) dp[i][i]=0,s[i][i]=i;
    for(int r=1;r<n;r++)
    {
        for(int i=1;i<n;i++)
        {
            int j=i+r;
            if(j>n) break;
            dp[i][j]=INF;
            for(int k=s[i][j-1];k<=s[i+1][j];k++)
            {
                if(dp[i][j]>dp[i][k]+dp[k+1][j])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j];
                    s[i][j]=k;
                }
            }
            dp[i][j]+=sum[j]-sum[i-1];
        }
    }
}
*/


//GarsiaWachs算法 0ms
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 205;
int stone[N];
int n,t,ans;

void combine(int k);

int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",stone+i);
        t = 1;
        ans = 0;
        for(int i=1;i<n;i++)
        {
            stone[t++] = stone[i];
            while(t >= 3 && stone[t-3] <= stone[t-1])
                combine(t-2);
        }
        while(t > 1)//大于1堆，从最右边那堆开始向左合并
            combine(t-1);
        printf("%d\n",ans);
    }
    return 0;
}
void combine(int k)
{
    int tmp = stone[k] + stone[k-1];
    printf("%d\n",tmp);
    ans += tmp;
    for(int i=k;i<t-1;i++)//后面的往前移，移到位置 k
        stone[i] = stone[i+1];
    t--;

    int j = 0;
    for(j=k-1;j>0 && stone[j-1] < tmp;j--)//厉害了，不断往前移坑，
        stone[j] = stone[j-1];
    stone[j] = tmp;//填坑

    while(j >= 2 && stone[j] >= stone[j-2])//如果调整后，又比前2个大，即又是那个条件达成了
    {
        int d = t - j;//记录与堆数的差值
        combine(j-1);
        j = t - d;//少了几堆就向前移动了几次，位置也变为几
    }
}

