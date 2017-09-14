#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 1000005

int num[MX];
bool sav[MX];
int dp[MX];
int high[MX];

int bi_search(int x,int h)
{
    int l=1,r=h;
    int res=0;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (x>=high[mid])    //不减序列改为 x>=high[mid]
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res+1;
}

int calc(int l,int r)
{
    if (l>r) return 0;
    memset(high,0,sizeof(high)); //要为最界限值
    int h=1;
    dp[l]=1;
    high[1]=num[l];
    for (int i=l+1;i<=r;i++)
    {
        if (num[i]>=high[h]) //不减序列改为 x>=high[mid]
        {
            h++;
            dp[i]=h;
            high[h]=num[i];
        }
        else
        {
            int p=bi_search(num[i],h);
            dp[i]=p;
            high[p]=num[i];
        }
    }
    return h;
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n<=0)
        {
            printf("0\n");
            continue;
        }
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }

        int pre=num[1];
        memset(sav,0,sizeof(sav));
        sav[1]=1;
        for (int i=2;i<=n;i++)
        {
            if (num[i]>=pre)
            {
                sav[i]=1;
                pre=num[i];
            }
        }
        memset(dp,0,sizeof(dp));
        int mxlen=0;
        pre=1;
        for (int i=2;i<=n+1;i++)
        {
            if (sav[i]==1||i==n+1)
            {
                mxlen=max(mxlen,calc(pre+1,i-1));
                //printf("maxlen:%d\n",mxlen);
                pre=i;
            }
        }

        printf("%d\n",mxlen);
        printf("%d",num[1]);
        for (int i=2;i<=n;i++)
            if (sav[i])
                printf(" %d",num[i]);
        printf("\n");
    }
    return 0;
}
