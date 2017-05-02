#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MOD 9901

int a,b,z;
int p[10000];   //质数
int p_n[10000];//质数个数

void Zhi()
{
    int t = a;
    for (int i=2;i*i<=a;i++)
    {
        if (t%i==0)
        {
            p[z]=i;
            p_n[z]=1;
            t/=i;
            while (t%i==0)
            {
                p_n[z]++;
                t/=i;
            }
            z++;
        }
        if (t==1) break;
        if (i!=2)
            i++;//2.3.5.7.9...
    }
    if (t!=1)//本身就是质数
    {
        p[z]=t;
        p_n[z]=1;
        z++;
    }
}

int Mi(int a, int b)//快速幂
{
    int res = 1;
    a %= MOD;
    while (b)
    {
        if (b%2==1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b /= 2;
    }
    return res;
}

int Erfen(int p , int n)//求 1 + p + p^2 + p^3+ ... +p^n
{
    if (n==0) return 1;
    if (n%2==1)
        return ((Mi(p,n/2+1)+1)  * Erfen(p,n/2))%MOD;
    else
        return ((1+Mi(p,n/2+1)) * Erfen(p,n/2-1) + Mi(p,n/2))%MOD;
}

int main()
{
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        z=0;//质数个数
        Zhi();

        int ans = 1;
        for (int i=0;i<z;i++)
        {
            ans = (ans * Erfen(p[i],p_n[i]*b))%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}

