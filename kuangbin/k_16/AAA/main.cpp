#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int T;
    cin>>T;
    int n;
    for (int cnt=1;cnt<=T;cnt++)
    {
        scanf("%d",&n);
        int z=0,f=0;
        int fn=0;
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x<0)
            {
                f-=x;
                fn++;
            }
            else z+=x;
        }
        printf("Case %d: ",cnt);
        if (fn==n) printf("inf\n");
        else
        {
            int yue = gcd(z+f,n-fn);
            printf("%d/%d\n",(z+f)/yue,(n-fn)/yue);
        }
    }
    return 0;
}
