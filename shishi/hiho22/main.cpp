#include <iostream>
#include <stdio.h>
#include <math.h>
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
        int ans = 1;
        int util =sqrt(n*1.0);

        for (int i=1;i<=util;i++)
        {
            if (n%i==0)
            {
                int tp = n/i;
                if (i%2==1)
                {
                    int len = (i-1)/2;
                    if (tp+len<=n&&tp-len>=1)
                        ans = max(ans,i);

                    int ll = i/2;
                    if (ll+1-tp>=1&&ll+tp<=n)
                        ans = max(ans,tp*2);
                }
                if (tp%2==1)
                {
                    int len = (tp-1)/2;
                    if (i+len<=n&&i-len>=1)
                        ans = max(ans,tp);

                    int ll = tp/2;
                    if (ll+1-i>=1&&ll+i<=n)
                            ans = max(ans,i*2);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
