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
# include <time.h>
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
# define MX          1005
/**************************/

vector<int> ve[MX];

int main()
{
    int n,H;
    scanf("%d%d",&n,&H);
    for (int i=1;i<=n;i++)
    {
        int h,p;
        scanf("%d%d",&h,&p);
        int c = min(n,H-h); //最多放在第几层
        ve[c].push_back(p);
    }
    priority_queue<int > Q;
    int ans = 0, s  = 0;
    for (int i=1;i<=n;i++) //在i层的最大效益
    {
        while (Q.size()>=i)
        {
            s+=Q.top();
            Q.pop();
        }
        for (int j=0;j<ve[i].size();j++)
        {
            s+=ve[i][j];
            Q.push(-ve[i][j]);
        }
        while (Q.size()>i+1) //超过限制
        {
            s+=Q.top();
            Q.pop();
        }
        ans = max(ans,s);
    }
    printf("%d\n",ans);
    return 0;
}
