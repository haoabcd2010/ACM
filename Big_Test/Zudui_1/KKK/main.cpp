#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 1000005
int n;
int num[MX];

int main()
{
    int T;
    cin>>T;
    for (int cnt=1;cnt<=T;cnt++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        int ans =0;
        int mmm = num[n];
        for (int i=n-1;i>=1;i--)
        {
            if (num[i]>mmm)
                ans++;
            else
                mmm = num[i];
        }
        printf("Case #%d: %d\n",cnt,ans);
    }
    return 0;
}
