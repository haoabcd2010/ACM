#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define MX 500005

char s[MX];
int main()
{
    while(~scanf("%s",s))
    {
        int n=strlen(s),num=0,res=0,cnt,gg=0;
        for(int i=0;i<n;i++)
            if(s[i]=='(')res++;
            else if(s[i]==')')res--;
            else num++;
        if(abs(res)>num||(num-abs(res))%2!=0)gg=1;
        else
        {
            cnt=(num-res)/2; // 对于多出的 ？ ，变为 ( 的个数
            res=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='?')
                {
                    if(cnt) s[i]='(',cnt--;
                    else s[i]=')';
                }
                if(s[i]=='(')res++;
                else
                {
                    res--;
                    if(res<0)
                    {
                        gg=1;
                        break;
                    }
                }
            }
        }
        if(gg)printf("Impossible\n");
        else printf("%s\n",s);
    }
    return 0;
}
