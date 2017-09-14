#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define LL long long
#define MX 100005

char ss[MX];

int main()
{
    int k;
    scanf("%d",&k);
    scanf("%s",ss);
    int len = strlen(ss);
    sort(ss,ss+len);
    int all=0;
    for (int i=0;i<len;i++)
        all+=ss[i]-'0';

    for (int i=0;i<=len;i++)
    {
        if (all>=k)
        {
            printf("%d\n",i);
            break;
        }
        all+=9-(ss[i]-'0');
    }
    return 0;
}
