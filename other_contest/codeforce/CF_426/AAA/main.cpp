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
#define MX 50005

set<int> sb[MX];

int main()
{

    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        sb[i]=sb[i-1];
        sb[i].insert(a);
    }
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        set<int> mabi;
        set_difference( sb[r].begin(), sb[r].end(),
                                sb[l-1].begin(), sb[l-1].end(),
                                   inserter( mabi, mabi.begin() ) );
        cout<<mabi.size()<<endl;
    }
    return 0;
}
