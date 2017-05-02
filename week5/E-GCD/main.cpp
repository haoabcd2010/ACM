// ST
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;

#define LL long long
#define MAXN 100005

int n;
int num[MAXN];
int mn[MAXN];
int dp[MAXN][20];
map<int,LL> res;

int gcd(int a,int b)
{   return b==0?a:gcd(b,a%b);}

void Init()
{
    mn[0]=-1;
    for (int i=1;i<=n;i++)
    {
        mn[i]=((i&(i-1))==0)?mn[i-1]+1:mn[i-1];  // i&(i-1) i�ض��� 2^k (k = 0,1,2,3...)
        dp[i][0]=num[i];
    }
    for (int j=1;j<=mn[n];j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
        {
            dp[i][j]=gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
}

int st_calc(int l,int r)
{
    int k = mn[r-l+1];
    return gcd(dp[l][k],dp[r-(1<<k)+1][k]);
}

void erfen()//���ߴ������й�Լ��������n^2�ᳬʱ,��һ��n^log(n)�ķ�������
{
    res.clear();
    for (int i=1;i<=n;i++)  //��iΪ��������������й�Լ��
    {
        int cur = i , gc = num[i];  //�ö������
        while (cur <= n)
        {
            int l=cur,r=n;
            while(l<r)
            {
                int mid = (l+r+1)>>1;   // +1 �ܹؼ���������ʹֻ�������� mid Ϊ�ұߵ�
                if (st_calc(i,mid)==gc) l=mid;
                else r = mid -1;
            }
            if (res.count(gc)) res[gc]+=l-cur+1;
            else res[gc]=l-cur+1;
            cur = l + 1;
            if (cur<=n)
                gc = gcd(gc,num[cur]);
        }
    }
}

int main()
{
    int t;
    int cas=0;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        Init();

        erfen();

        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",++cas);
        while (q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int kk = st_calc(x,y);
            printf("%d %lld\n",kk,res[kk]);
        }
    }
    return 0;
}
