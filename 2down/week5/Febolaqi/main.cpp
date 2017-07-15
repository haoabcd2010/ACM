#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MOD = 4999;

struct Ju
{
    int m[2][2];
}base,ans;

Ju Mult(Ju A,Ju B)
{
    Ju C;
    memset(C.m,0,sizeof(C.m));
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                C.m[i][j] = (C.m[i][j]+A.m[i][k]*B.m[k][j]%MOD)%MOD;
    return C;
}

int quick_mi(int n)
{
    ans.m[0][0]=ans.m[1][1]=1;
    ans.m[0][1]=ans.m[1][0]=0;
    base.m[0][0]=1,base.m[0][1]=1;
    base.m[1][0]=1,base.m[1][1]=0;
    int t = n-1;
    while (t)
    {
        if (t&1)
            ans = Mult(ans,base);
        base = Mult(base,base);
        t>>=1;
    }
    return ans.m[0][0];
}

int main()
{
    int n;
    while (cin>>n)
    {
        int res = quick_mi(n);
        printf("斐波拉契数列 %d 项: %d (MOD=%d)\n",n,res,MOD);
    }
    return 0;
}
