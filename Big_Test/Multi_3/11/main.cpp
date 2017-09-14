#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <math.h>
#include <set>
using namespace std;
#define LL long long
#define MX 100005

int erlertb[MX];

void erler()
{
    for (int i=1;i<MX;i++)
        erlertb[i]=i;
    for (int i=2;i<=MX;i++)
        if (erlertb[i]==i)
            for (int j=i;j<MX;j+=i)
                erlertb[j] = erlertb[j]/i*(i-1);
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",erlertb[n]);
    }
    return 0;
}
