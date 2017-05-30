#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define MX 100005

char str[MX];

int main()
{
    scanf("%s",str);
    int n = strlen(str);

    LL ans =0;
    int i;
    for (i=0;str[i];i++)
    {
        if (str[i]=='U')
            ans+= n-i-1;
        else
            ans+=2*(n-i-1);
    }
    for (i--;i>=0;i--)
    {
        if (str[i]=='D')
            ans+=i;
        else
            ans+=2*i;
    }
    cout<<ans<<endl;
}
