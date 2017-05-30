#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f

int main()
{
    LL n,a,b;
    while(cin>>n>>a>>b)
    {
        if ((n==1&&a!=b)||a>b)
            printf("0\n");
        else
        {
           LL x = a+b+(n-2)*a;
           LL y = a+b+(n-2)*b;
           cout<<y-x+1<<endl;
        }
    }
    return 0;
}
