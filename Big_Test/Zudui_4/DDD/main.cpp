#include <iostream>
#include <cstdio>
using namespace std;

int cnt, x, cas;
int ans[25]={0,
0,0,0,1,1,
2,3,3,4,5,
6,7,7,8,9,
10,11,12,13,14};

int main()
{
    scanf("%d", &cas);
    for(int i=1;i<=cas;i++){
        scanf("%d", &x);
        printf("Case #%d: %d\n", i, ans[x]);
    }
    return 0;
}
