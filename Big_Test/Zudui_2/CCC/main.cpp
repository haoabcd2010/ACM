#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int maxn=40005;
int res[maxn], ans, t, n, m;

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++){
            scanf("%d", &res[i]);
        }
        sort(res,res+n);
        ans=0;
        for(int i=n-1-m;i>=0;i--){
            ans+=res[i]-res[i-1];

        }
    }
    return 0;
}
