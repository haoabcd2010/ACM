#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

LL n, k;
int T;

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", n+k-1);
    }
    return 0;
}
