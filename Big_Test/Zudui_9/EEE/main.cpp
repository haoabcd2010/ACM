#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const int inf=1e9;
const int maxn=1000005;
int l[maxn], r[maxn];
int L, R, ans, n;

int main()
{
    while(~scanf("%d", &n)){
        L=-inf;
        R=-inf;
        for(int i=0;i<n;i++){
            scanf("%d%d", &l[i], &r[i]);
            L=max(L, l[i]);
            R=max(R, r[i]);
        }
        ans=0;
        for(int i=0;i<n;i++){
            if(l[i]>=L||r[i]>=L)ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
