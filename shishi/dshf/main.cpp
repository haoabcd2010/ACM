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
using namespace std;
# define LL          long long
# define pr          pair
# define mkp         make_pair
# define lowbit(x)   ((x)&(-x))
# define PI          acos(-1.0)
# define INF         0x3f3f3f3f3f3f3f3f
# define eps         1e-12
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
struct Point{
    long double x,y;
    Point(){x=0,y=0;}
    Point(long double _x,long double _y){
        x=_x;
        y=_y;
    }
    long double operator ^(const Point &b)const{
        return x*b.y-y*b.x;
    }
    Point operator -(const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    Point operator /(const double &k)const{
        return Point(x/k,y/k);
    }
}pt[5];

struct Line{
    Point s,e;
    Line(Point _s,Point _e){
        s=_s;
        e=_e;
    }
    Point crosspoint(Line v){
        long double a1 = (v.e-v.s)^(s-v.s);
        long double a2 = (v.e-v.s)^(e-v.s);
        return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
    }
};

void prt(Point b)
{
    cout<<b.x<<' '<<b.y<<endl;
}

Line cal(Point a,Point b) //求垂直平分线
{
    long double midx = (a.x+b.x)/2;
    long double midy = (a.y+b.y)/2;
    if (a.x!=b.x&&a.y!=b.y){
        long double kci = (b.y-a.y)/(b.x-a.x);
        long double canb = midy+midx/kci;
        if (midx!=1){
            long double yyy = -1.0/kci+canb;
            Line res(Point(midx,midy),Point(1.0,yyy));
            return res;
        } else {
            long double yyy = -2.0/kci+canb;
            Line res(Point(midx,midy),Point(2.0,yyy));
            return res;
        }
    }
    if (a.x==b.x){
        if (a.x!=1){
            Line res(Point(a.x,midy), Point(1,midy));
            return res;
        } else {
            Line res(Point(a.x,midy), Point(2,(a,midy)));
            return res;
        }
    }

    if (b.y!=1){
        Line res(Point(midx,1),Point(midx,b.y));
        return res;
    }
    Line res(Point(midx,2),Point(midx,b.y));
    return res;
}

Point funct()
{
    Line fir = cal(pt[1],pt[2]);
    Line sec = cal(pt[2],pt[3]);
    return fir.crosspoint(sec);
}

int main()
{
    std::ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while (T--)
    {
        for (int i=1;i<=4;i++)
        {
            long double x,y;
            cin>>x>>y;
            pt[i] = Point(x,y);
        }

        Point circle;
        circle = funct(); //计算圆心

        long double dis = (circle.x-pt[1].x)*(circle.x-pt[1].x)+(circle.y-pt[1].y)*(circle.y-pt[1].y);
        long double sb = (circle.x-pt[4].x)*(circle.x-pt[4].x)+(circle.y-pt[4].y)*(circle.y-pt[4].y);

        if (sb < dis+eps)
            cout<<"Rejected"<<endl;
        else
            cout<<"Accepted"<<endl;
    }
    return 0;
}
