#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int dian;
        cin>>dian;
        double x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        int i;
        double x,y;
        double sumarea=0.0,sumx=0.0,sumy=0.0;
        for (i=2;i<dian;i++)
        {
            cin>>x>>y;
            double s=( (x2-x1) * (y-y1) - (x-x1) * (y2-y1) ) / 2;
            // s= ( (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) ) / 2
            //向量的点积
            sumarea+=s;
            sumx+=s*(x1+x2+x)/3;
            sumy+=s*(y1+y2+y)/3;
            x2=x;
            y2=y;
        }
        printf("%.2lf %.2lf\n",sumx/sumarea,sumy/sumarea);
    }
    return 0;
}
