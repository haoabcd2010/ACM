#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int cnt=1;cnt<=T;cnt++)
    {
        int n ,k;
        scanf("%d%d",&n,&k);
        printf("Case #%d:",cnt);
        for (int i=1;i<=k;i++)
            printf(" %d",i*2);
        for (int i=1;i<=n;i++)
        {
            if (i%2==0&&i<=2*k) continue;
            printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}
