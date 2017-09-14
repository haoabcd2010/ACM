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
#define MX 1000006

int main()
{
    LL c,hr,hb,wr,wb;
    scanf("%lld%lld%lld%lld%lld",&c,&hr,&hb,&wr,&wb);
    LL ans=0;
    int time = sqrt(c*1.0);
    for (int i=0;i<time;i++)
    {
        if (i*wr<=c)
            ans = max(ans,i*hr+(c-i*wr)/wb*hb);
        if (i*wb<=c)
            ans = max(ans,i*hb+(c-i*wb)/wr*hr);
    }

    cout<<ans<<endl;
    return 0;
}
