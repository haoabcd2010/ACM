#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 12

int n;
double p;
int bomb[MAXN];

double base[2][2];
double res[2][2];

//[ p(x)   ]  =  [ p , 1-p ]^(x-1)  * [ 1 ]
//[ p(x-1) ]     [ 1 , 0   ]          [ 0 ]
void quick_mi(int x)
{
    double tp[2][2];
    while (x)
    {
        if (x%2==1)
        {
            for (int i=0;i<2;i++)
                 for (int j=0;j<2;j++)
                {
                    tp[i][j]=0;
                    for (int k=0;k<2;k++)
                        tp[i][j]+=res[i][k]*base[k][j];
                }
            for (int i=0;i<2;i++)
                for (int j=0;j<2;j++)
                res[i][j]=tp[i][j];
        }
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
            {
                tp[i][j]=0;
                for (int k=0;k<2;k++)
                    tp[i][j]+=base[i][k]*base[k][j];
            }
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
                base[i][j]=tp[i][j];
        x/=2;
    }
}

double Mi(int x)//处于位置1踩到位置 x 的概率
{
    if (x==0) return 0;
    base[0][0]=p,base[0][1]=1.0-p;
    base[1][0]=1,base[1][1]=0;
    res[0][0]=1;res[0][1]=0;
    res[1][0]=0;res[1][1]=1;
    quick_mi(x-1);
    return res[0][0];
}

int main()
{
    while (scanf("%d%lf",&n,&p)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&bomb[i]);
        sort(bomb,bomb+n);

        double xxx=Mi(bomb[0]);     //死了的概率
        double ans = 1.0-xxx;       //没死
        for (int i=1;i<n;i++)
        {
            xxx =Mi(bomb[i]-bomb[i-1]); //化简后
            ans *= (1.0-xxx);
        }
        printf("%.7lf\n",ans);
    }
    return 0;
}
