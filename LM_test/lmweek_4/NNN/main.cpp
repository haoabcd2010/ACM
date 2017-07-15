#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MX 100005

int high[MX];
int dp[MX];
int h[MX];  // 长为 i 的上升序列最小是
int ans[MX];

int binary_find(int x,int mx)
{
    int l=1,r=mx;
    while (l<r)
    {
        int mid = (l+r)/2;
        if(x>h[mid]) l = mid +1;
        else r = mid;
    }
    return l;
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        scanf("%d",&n);

        for (int i=1;i<=n;i++)
            scanf("%d",&high[i]);

        int mx = 1;
        h[1] = high[1];
        dp[1]=1;
        for (int i=2;i<=n;i++)
        {
            if (high[i]>h[mx])
            {
                h[++mx] = high[i];
                dp[i] = mx;
            }
            else
            {
                int p = binary_find(high[i],mx);
                h[p] = high[i];
                dp[i] = p;
            }
        }

        memset(ans,0x3f,sizeof(ans));
        printf("%d\n",mx);
        int tmp = mx,mmm = INF;
        for (int i=n;i>=1;i--)
        {
            if(!tmp) break;
            if(dp[i]==tmp&&high[i]<mmm)
            {
                mmm=high[i];
                ans[tmp]=high[i];
                tmp--;
            }
        }
        for (int i=1;i<mx;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[mx]);
    }
    return 0;
}
