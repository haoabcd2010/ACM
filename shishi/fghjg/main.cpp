#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
using namespace std;
#define LL long long
#define MX 200005

int main ()
{
    LL k;
    scanf("%lld",&k);
    LL t = k/50;
    LL m = k%50;
    printf("50\n");
    for (int i=0;i<49;i++)
    {
        if (i<m)
            printf("%lld ",t+i+50-(m-1));
        else
            printf("%lld ",t+i-m);
    }
    printf("%lld\n",t+49-m);
    return 0;
}
