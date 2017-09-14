#include <iostream>
#include <cstdio>
using namespace std;

int n, ans, cas=0;
long long k;

int main()
{
    while(~scanf("%d%lld", &n, &k)){
        if(k<=n-1)ans=k;
        else{
            k-=n;
            long long mod=k%(2*n-2);
            if(mod==0)ans=n;
            else if(mod>=1&&mod<=n-1)ans=mod;
            else if(mod>=n)ans=mod-n+1;
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
