#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define PI acos(-1.0)
#define lowbit(x) (x&(-x))
#define INF 0x7f7f7f7f      // 21 E
#define MEM 0x7f            // memset ����Ϊ INF
#define MOD 4999            // ģ
#define eps 1e-9            // ����
#define MX  1000005         // ���ݷ�Χ

int read() {    //�������
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
// code... ...

double area(double x1,double y1,double r1,double x2,double y2,double r2)
{
    double d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    if(d>=(r1+r2)*(r1+r2)) return 0;
    if(d<=(r1-r2)*(r1-r2)) return r1<r2 ? PI*r1*r1 : PI*r2*r2;
    d=sqrt(d);
    double a1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
    double a2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
    double s1=a1*r1*r1; //����s
    double s2=a2*r2*r2;
    double sinx = sqrt(1-cos(a1)*cos(a1));
    double t = sinx * d * r1;   //������
    return s1+s2-t;
}

int main()
{
    int T;
    cin>>T;
    for (int cnt=1;cnt<=T;cnt++)
    {
        double x1,y1,x2,y2,r1,r2;
        scanf("%lf%lf",&r1,&r2);
        scanf("%lf%lf",&x1,&y1);
        scanf("%lf%lf",&x2,&y2);
        double ans = area(x1,y1,r2,x2,y2,r2);
        ans -= 2*area(x1,y1,r1,x2,y2,r2);
        ans += area(x1,y1,r1,x2,y2,r1);
        printf("Case #%d: %.6f\n",cnt,ans);
    }
}
