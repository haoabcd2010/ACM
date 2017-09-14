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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL          long long
#define lowbit(x)   ((x)&(-x))
#define PI          acos(-1.0)
#define INF         0x3f3f3f3f
#define eps         1e-8
#define MOD         1000000007

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
#define MX 100005
/**************************/
char str[MX];
char tp[5000];

int main()
{
    int n = scan();
    for (int i=0;i<n;i++)
    {
        scanf("%s",str);
        int len = strlen(str);
    }

    LL ans = 0;
    dfs(0,n-1,1);
    printf("%lld\n",ans);
    return 0;
}
