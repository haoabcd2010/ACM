#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=1000005;
int p;
LL ans[maxn];

int main()
{
    while(~scanf("%d", &p)){
        memset(ans, -1, sizeof(ans));
        ans[0]=0;
        for(int i=1;i<p;i++){
            LL t=i;
            t=(t*t)%p;
            ans[t]=i;
        }
        for(int i=0;i<p;i++){
            printf("%lld", ans[i]);
            if(i==p-1)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
