#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define LL long long
#define MX 100005

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        LL ans = 1;
        for (int i=1;i<=n;i++)
        {
            LL l=1,r=n-i+1;
            while (l<=r)
            {
                LL mid = (l+r)>>1;
                LL ret = (i*2+mid-1)*mid/2;
                if (ret>n) r=mid-1;
                else if (ret<n) l=mid+1;
                else if (ret==n)
                {
                    ans = max(ans,mid);
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
