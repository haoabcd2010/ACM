#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=200005;

struct Node{
    int need, die;

    bool operator<(Node &cmp){
        return (need>cmp.need||(need==cmp.need&&die<cmp.die));
    }
}num[maxn];
int n;
LL ans;

int main()
{
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%d%d", &num[i].need, &num[i].die);
        }
        ans=0;
        for(int i=0;i<n;i++){
            if(ans<num[i].need){
                ans+=(num[i].need-ans);
            }

        }
    }
    return 0;
}
