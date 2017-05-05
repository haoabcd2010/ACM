#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define MX 5005

int n;
int mmm;
int num[MX];
int dp[MX]; //
int h[MX];  // 长为 i 的序列最小值

int bi_search(int x)
{
    int l = 1, r = mmm;
    while (l<r)
    {
        int mid = (l+r)/2;
        if (x>h[mid]) l = mid+1;
        else r = mid-1;
    }
    return l;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&num[i]);
    dp[0]=1;
    h[1]=num[0];
    mmm = 1;
    for (int i=1;i<n;i++)
    {
        if (num[i]>h[mmm])
        {
            dp[i]=++mmm;
            h[mmm]=num[i];
        }
        else
        {
            int p = bi_search(num[i]);
            dp[i] = p;
            h[p] = num[i];
        }
    }
    for (int i=0;i<n;i++)
            printf("%d ",dp[i]);
    return 0;
}
