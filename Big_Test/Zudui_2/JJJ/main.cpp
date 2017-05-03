#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MEM 0x3f
#define MOD 7

char week[7][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int quick_mi(int a,int b)
{
    int res = 1;
    while(b)
    {
        if (b%2==1)
        {
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b/=2;
    }
    return res;
}

int biao[42];

int main()
{
    for (int i=1;i<=42;i++)
        biao[i-1]=quick_mi(i,i);

    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int x = n/42;
        int y = n%42;
        int ans =(x*6)%MOD;
        for (int i=0;i<y;i++)
            ans = (ans + biao[i])%MOD;
        if (ans!=0)
            printf("%s\n",week[ans-1]);
        else
            printf("%s\n",week[6]);
    }
    return 0;
}
