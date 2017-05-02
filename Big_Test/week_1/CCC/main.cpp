#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAXN 600

int n, k1, k2, k3, a, b, c;
double A[MAXN],B[MAXN];
double p0;
double p[100];

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&a,&b,&c);
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        memset(p,0,sizeof(p));

        p0=1.0/(k1*k2*k3);   //单位概率，变为 0 的概率
        for (int j1=1;j1<=k1;j1++)
        for (int j2=1;j2<=k2;j2++)
        for (int j3=1;j3<=k3;j3++)
            if(j1!=a||j2!=b||j3!=c)
            p[j1+j2+j3]+=p0;  //掷出某一个和的概率

        for (int i=n;i>=0;i--)//因为要循环到大于 n
        {
            for (int j=1;j<=k1+k2+k3;j++)
            {
                A[i]+=p[j]*A[i+j];
                B[i]+=p[j]*B[i+j];
            }
            A[i]+=p0;
            B[i]+=1.0;
        }
        double ans = B[0]/(1.0-A[0]);
        printf("%.15lf\n",ans);
    }
    return 0;
}
