#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n,m,k;
    while (scanf("%d%d%d",&n,&k,&m)&&(n||m||k))
    {
        int s = 0;
        for (int i=2;i<=n-1;i++)
        {
            s = (s+k)%i;
        }
        s = (s+m)%n;
        printf("%d\n",s+1);
    }
    return 0;
}
