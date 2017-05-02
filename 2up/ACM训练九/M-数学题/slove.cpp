/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct Num
{
    int a,b;
    int z;
}num[1000];
int t;

bool cmp(Num x,Num y)
{
    return x.a<y.a;
}

void read(int x,int y)
{
    int a=x,b=y;
    int lenx=0,leny=0;
    while (a!=0)
    {
        lenx++;
        a/=10;
    }
    while (b!=0)
    {
        leny++;
        b/=10;
    }
    if (y==0) leny=1;
    num[t].a=x;
    num[t].b=y;
    num[t].z=lenx-1-leny;
    t++;
}

int main()
{
    int N;
    while (scanf("%d",&N)!=EOF)
    {
        t=0;
        for (int i=1;i<=N;i*=10)
        {
            int a=N/i/11;
            int b=N/i%11;

            if (b<10)
            {
                int c=(N-N/i*i)/2;
                if ((11*a+b)*i+2*c==N)
                    read( (10*a+b)*i+c , a*i+c );
            }
            b--;
            if (a+b&&b>=0)
            {
                int c=(N-N/i*i+i)/2;
                if ((11*a+b)*i+2*c==N)
                    read( (10*a+b)*i+c , a*i+c );
            }
        }
        sort(num,num+t,cmp);
        int real_t=0;
        for (int i=0;i<t;i++)
        {
            if (i!=0&&num[i].a==num[i-1].a) continue;
            real_t++;
        }
        printf("%d\n",real_t);
        for (int i=0;i<t;i++)
        {
            if (i!=0&&num[i].a==num[i-1].a) continue;
            printf("%d + ",num[i].a);
            for (int j=0;j<num[i].z;j++)
                printf("0");
            printf("%d = %d\n",num[i].b,N);
        }
    }
    return 0;
}
*/

/*
//检验错误的
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream in1("E:\\test.out");
    ifstream in2("E:\\ttt.out");
    string s1,s2;
    for (int i=1;i<10000;i++)
    {
        getline(in1,s1);
        getline(in2,s2);
        if (s1!=s2)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}
*/


/*
//别人的32ms代码
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 ll;
ll n;
int len,num;
ll ans[1000];
ll power[15] = {0,1,10,100,1000,10000,100000,1000000,10000000,100000000LL,1000000000LL,10000000000LL};

void dfs(int pos,int dp,ll s1,ll s2)
{
    //printf("%d %d:%d %d\n",pos,dp,s1,s2);
    //system("pause");
    if(dp == len + 1)
    {
//        int dig = s2/power[dp - 1];
//        s1 = dig * power[dp] + s1;
        if(s1 + s2 == n && s2/power[dp - 1] == 0)
            ans[num ++] = s2;
        return;
    }
    if(dp < pos)
    {
        for(int i = 0;i <= 9;i ++)
        {
            int t1 = i * power[dp] + s1;
            if((t1 + t1) % power[dp + 1] == n % power[dp + 1])
                dfs(pos,dp + 1,t1,t1);
        }
    }
    if(dp == pos)
    {
        for(int i = 0;i <= 9;i ++)
        {
            for(int j = 0;j <= 9;j ++)
            {
                int t1 = i * power[dp] + s1;
                int t2 = j * power[dp] + s2;
                if((t1 + t2) % power[dp + 1] == n % power[dp + 1])
                {
                    dfs(pos,dp + 1,t1,t2);
                    continue;
                }
            }
        }
    }
    if(dp > pos)
    {
        int dig = s2/power[dp - 1];
        s1 = dig * power[dp] + s1;
        for(int i = 0;i <= 9;i ++)
        {
            int t2 = i * power[dp] + s2;
            if((s1 + t2) % power[dp + 1] == n % power[dp + 1])
                dfs(pos,dp + 1,s1,t2);
        }
    }
}
int main()
{
    freopen("E:\\test.in","r",stdin);
    freopen("E:\\ttt.out","w",stdout);
    while(scanf("%I64d",&n) != EOF)
    {
        int m = n;
        len = num = 0;
        while(m)
        {
            len ++;
            m /= 10;
        }
        int i;
//        for(i = 0;i <= 9;i ++)
//            if((n + i) % 11 == 0 && n % 11 < 10)
//                ans[num ++] = n / 11;
        for(i = 1;i <= len;i ++)
            dfs(i,1,0,0);
        sort(ans,ans + num);
        int ttt = 0;
        for(i = num - 1;i >= 0;i --)
        {
            if(i < num - 1 && ans[i] == ans[i + 1])
                ttt ++;
            if(ans[i] + ans[i] == n)
                ttt ++;
        }
        printf("%d\n",num - ttt);
        for(i = num - 1;i >= 0;i --)
        {
            if(i < num - 1 && ans[i] == ans[i + 1])
                continue;
            if(ans[i] + ans[i] == n)
                continue;
            int tmp = ans[i];
            int cnt = 1;
            while(tmp/10)
            {
                cnt ++;
                tmp /= 10;
            }
            int cnt2 = 1;
            tmp = n - ans[i];
            while(tmp/10)
            {
                cnt2 ++;
                tmp /= 10;
            }
            printf("%I64d + ",n - ans[i]);
            for(int j = 1;j < cnt2 - cnt;j ++)//注意第二个数前面补0。。。
                printf("0");
            printf("%I64d",ans[i]);
            printf(" = %I64d\n",n);
        }
    }
    return 0;
}
*/
