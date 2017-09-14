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
# define MX 100005
/**************************/

char one[200] = "xxxxx.....x.xxxxx.xxxxx.x...x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.";
char two[200] = "x...x.....x.....x.....x.x...x.x.....x.........x.x...x.x...x.";
char thr[200] = "x...x.....x.....x.....x.x...x.x.....x.........x.x...x.x...x.";
char fou[200] = "x...x.....x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.....x.xxxxx.xxxxx.";
char fiv[200] = "x...x.....x.x.........x.....x.....x.x...x.....x.x...x.....x.";
char six[200] = "x...x.....x.x.........x.....x.....x.x...x.....x.x...x.....x.";
char sev[200] = "xxxxx.....x.xxxxx.xxxxx.....x.xxxxx.xxxxx.....x.xxxxx.xxxxx.";

char str[10][200];

int cal(int p)
{
    int all =0;
    if (str[1][p+2]!='.') all++;
    if (str[2][p]!='.')   all++;
    if (str[2][p+4]!='.') all++;
    if (str[4][p+2]!='.') all++;
    if (str[5][p]!='.')   all++;
    if (str[5][p+4]!='.') all++;
    if (str[7][p+2]!='.') all++;
    return all;
}

int shi(int pos)
{
    if (str[2][pos+2]!='.') return -1; // +

    int res = cal(pos);
    if (res==2) return 1;
    if (res==3) return 7;
    if (res==4) return 4;
    if (res==5)
    {
         if (str[5][pos]!='.') return 2;
         if (str[2][pos]=='.') return 3;
         return 5;
    }
    if (res==6)
    {
        if (str[4][pos+2]=='.') return 0;
        if (str[5][pos]!='.') return 6;
        return 9;
    }
    return 8;
}

void prt(int x,int ha,int flag)
{
    int pos=x*6;
    for (int i=pos;i<pos+5+flag;i++)
    {
        if (ha==1) printf("%c",one[i]);
        if (ha==2) printf("%c",two[i]);
        if (ha==3) printf("%c",thr[i]);
        if (ha==4) printf("%c",fou[i]);
        if (ha==5) printf("%c",fiv[i]);
        if (ha==6) printf("%c",six[i]);
        if (ha==7) printf("%c",sev[i]);
    }
}

void print(LL x)
{
    int dat[20];
    int k=0;
    while (x)
    {
        dat[k++]=x%10;
        x/=10;
    }
    for (int i=1;i<=7;i++)
    {
        for (int j=k-1;j>=0;j--)
            prt(dat[j],i,j==0?0:1);
        printf("\n");
    }
}

int main()
{
    //freopen("d://in.txt", "r", stdin);
    for (int i=1;i<=7;i++)
        scanf("%s",str[i]);

    LL a=0,b=0;
    bool flag=0;
    for (int i=0;str[1][i];i+=6)
    {
        int x = shi(i);
        if (x==-1){flag=1;continue;}

        if (!flag)
        {
            a += x;
            a*=10;
        }
        else
        {
            b+= x;
            b*=10;
        }
    }
    a/=10; b/=10;
    print(a+b);

    return 0;
}
