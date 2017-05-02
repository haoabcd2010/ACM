#include <stdio.h>

int gcd (int a,int b)
{
    return b==0? a : gcd(b,a%b);
}

int main()
{
    int N;
    while (scanf("%d",&N)!=EOF)
    {
        long long G=0;
        int i,j;
        for(i = 1 ; i < N ; i++)
            for(j = i+1 ; j <= N ; j++)
            G+=gcd(i,j);
        printf("%lld\n",G);
    }

    return 0;
}
