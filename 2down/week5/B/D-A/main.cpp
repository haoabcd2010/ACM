#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MOD 9973

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        b%=MOD;
        int c = b;
        for (int i=0;i<MOD-3;i++)
            c = (c*b)%MOD;
        a = (a*c)%MOD;
        printf("%d\n",a);
    }
    return 0;
}
