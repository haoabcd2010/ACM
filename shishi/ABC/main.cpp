# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <bitset>
# include <sstream>
# include <set>
# include <cmath>
# include <algorithm>
# pragma  comment(linker,"/STACK:102400000,102400000")
using namespace std;
# define LL          long long
# define pr          pair
# define mkp         make_pair
# define lowbit(x)   ((x)&(-x))
# define PI          acos(-1.0)
# define INF         0x3f3f3f3f3f3f3f3f
# define eps         1e-8
# define MOD         1000000007

inline int scan() {
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
inline void Out(int a) {
    if(a<0) {putchar('-'); a=-a;}
    if(a>=10) Out(a/10);
    putchar(a%10+'0');
}
#define MX 1000050
/**************************/
int lens,lent;
char S[MX];
char T[MX];
int num[MX];
int fail[MX];

void get_next(char * t,int l)
{
    int i=0,j=-1;
    fail[0]=-1;
    while(i<l)
    {
        if (j==-1||T[i]==T[j])
            fail[++i]=++j;
        else
            j=fail[j];  //»ØËÝ
    }
}

void KMP(char *s,char *t)
{
    memset(num,0,sizeof(num));
    get_next(t,lent);
    int i=0,j=0;
    while (i<lens)
    {
        if (j==-1||S[i]==T[j])
        {
            i++,j++;
        }
        else j = fail[j];
        num[j]++;
        if (j==lent) j = fail[j];
    }
}

int main()
{
    int cas = scan();
    while (cas--)
    {
        scanf("%s",S);
        scanf("%s",T);
        lens = strlen(S);
        lent = strlen(T);
        reverse(S,S+lens);
        reverse(T,T+lent);
        KMP(S,T);
        LL ans = 0;
        for (int i=lent;i>0;i--)
        {
            num[fail[i]]+=num[i];
            ans = (ans + ((LL)i*num[i])%MOD)%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
