#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define MAXN 105

int C (int n,int m)
{
    int res = 1;
    for (int i=2;i<=n;i++) res*=i;

}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i =0;i<n;i++)
            scanf("%d",&x[i]);
        Init();
        int ans =0;
        for (int i=0;i<n;i++)
            if (L[i]+R[i]>ans)
                ans =L[i]+R[i];
        printf("%d\n",n-(ans-1));
    }
    return 0;
}
