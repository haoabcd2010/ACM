#include <bits/stdc++.h>
using namespace std;
#define MX 1000005
#define LL long long

char str[MX];

LL getnum(int &i)
{
    int re = 0;
    while (str[i]>='0'&&str[i]<='9')
    {
        re+=str[i]-'0';
        re*=10;
        i++;
    }
    re/=10;
    i--;
    return re;
}

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s",str);
        int len = strlen(str);
        stack<LL> sum;
        LL res = 0;
        for (int i=0;i<len;i++)
        {
            if (str[i]>='0'&&str[i]<='9')
            {
                res += getnum(i);
            }
            else if (str[i]=='+'||str[i]=='-')
            {
                sum.push(res);
                res=0;

                int fu = str[i]=='-'?1:0;
                i++;
                res = getnum(i);
                if (fu) res=-res;
            }
            else if (str[i]=='*'||str[i]=='/')
            {
                int cheng = str[i]=='*'?1:0;
                i++;
                int tp = getnum(i);
                if (cheng) res*= tp;
                else res/= tp;
            }
        }
        while (!sum.empty())
        {
            res+=sum.top();
            sum.pop();
        }
        printf("%lld\n",res);
    }
    return 0;
}
