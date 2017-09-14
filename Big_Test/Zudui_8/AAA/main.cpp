/*
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    int cnt=0;
    while (scanf("%d",&n)!=EOF)
    {
        cnt++;
        int x = n/10;
        int y = n%10;
        int a,b=0;
        if (y>=4)
            b=1;
        if (y>=7)
            b=2;
        int ans = x*3+b;
        printf("Case #%d: %d\n",cnt,ans);
    }
    return 0;
}
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
    int n;
    int cnt=0;
    while (scanf("%d",&n)!=EOF)
    {
        cnt++;
        int ans = (int)n*log10(2.0);
        printf("Case #%d: %d\n",cnt,ans);
    }
    return 0;
}

