#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int maxn=40005;
int res[maxn];
int t, n, m;
int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++){
            scanf("%d", res[i]);
        }
        sort(res+1, res+1+n);
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=res[i];
        }
    }
    return 0;
}
