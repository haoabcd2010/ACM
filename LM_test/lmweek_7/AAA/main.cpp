#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define LL long long

LL C(int n,int m)
{
    LL a=1,b=1;
    LL ret=1;
    for (int i=2;i<=n;i++)
    {
        ret*=i;
        while (a<=m&&ret%a==0){ret/=a;a++;}
        while (b<=n-m&&ret%b==0){ret/=b;b++;}
    }
    return ret;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int m=min(n,k); // 最多选m种食材
    LL ans = 0;
    for (int i=1;i<=m;i++)
        ans += C(n,i)*C(k-1,i-1);
    cout<<ans<<endl;
    return 0;
}
