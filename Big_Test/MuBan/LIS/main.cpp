#include <iostream>
#include <stdio.h>
using namespace std;
#define MX 505

int n;
int num[MX];
int dp[MX];//LIS
int h[MX]; //h[i] 长为 i 的上升序列最小值

int bi_search(int x)
{
    int l=1,r=n;
    while (l<r)
    {
        int mid = (l+r)>>1;
        if (x>h[mid]) l = mid+1;
        else r = mid;// 很关键
    }
    return l;
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        int len = 1;
        dp[1]=1;
        h[len] = num[1];
        for (int i=2;i<=n;i++)
        {
            if (num[i]>h[len])
            {
                dp[i]=++len;
                h[len]=num[i];
            }
            else
            {
                int p = bi_search(num[i]);
                dp[i]=p;
                h[p] = num[i];
            }
        }
        for (int i=1;i<=n;i++)
            printf("%d ",dp[i]);
        printf("\n");
    }
    return 0;
}
